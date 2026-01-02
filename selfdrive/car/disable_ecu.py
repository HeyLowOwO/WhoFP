#!/usr/bin/env python3
import time
import datetime

from openpilot.selfdrive.car.isotp_parallel_query import IsoTpParallelQuery
from openpilot.common.swaglog import cloudlog

EXT_DIAG_REQUEST = b'\x10\x03'
EXT_DIAG_RESPONSE = b'\x50\x03'
COM_CONT_RESPONSE = b''

# SecurityAccess constants
SECURITY_ACCESS_SEED_REQUEST = b'\x27\x01'
SECURITY_ACCESS_SEED_RESPONSE = b'\x67\x01'

ECU_LOG_FILE = "/data/ecu_disable.log"


def ecu_log(msg):
  timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]
  line = f"[{timestamp}] {msg}"
  cloudlog.warning(msg)
  try:
    with open(ECU_LOG_FILE, "a") as f:
      f.write(line + "\n")
  except Exception:
    pass


def compute_security_key(seed: bytes, algorithm: int = 0) -> bytes:
  if not seed:
    return b''

  if algorithm == 0:
    return bytes([b ^ 0x4A for b in seed])
  elif algorithm == 1:
    return bytes([~b & 0xFF for b in seed])
  elif algorithm == 2:
    return bytes([b ^ 0xCA for b in seed])
  elif algorithm == 3:
    return bytes([b ^ 0x4A for b in reversed(seed)])
  elif algorithm == 4:
    return bytes([(b + 1) & 0xFF for b in seed])
  elif algorithm == 5:
    return bytes([(b - 1) & 0xFF for b in seed])
  elif algorithm == 6:
    pattern = [0xDE, 0xAD, 0xBE, 0xEF]
    return bytes([seed[i] ^ pattern[i % 4] for i in range(len(seed))])
  elif algorithm == 7 and len(seed) == 8:
    return bytes([seed[i] ^ seed[i + 4] for i in range(4)] + list(seed[4:]))
  elif algorithm == 8:
    pattern = [0x71, 0x7B]
    return bytes([seed[i] ^ pattern[i % 2] for i in range(len(seed))])

  return bytes(seed)


def perform_security_access(logcan, sendcan, bus, addr, sub_addr, timeout=0.2, security_level=0x01):
  seed_request = bytes([0x27, security_level])
  seed_response_expected = bytes([0x67, security_level])
  key_sublevel = security_level + 1

  ecu_log("security access: requesting seed")

  query = IsoTpParallelQuery(sendcan, logcan, bus, [(addr, sub_addr)], [seed_request], [b''])
  responses = query.get_data(timeout)

  for _, data in responses.items():
    if len(data) >= 2 and data[:2] == seed_response_expected:
      seed = data[2:]
      ecu_log(f"seed: {seed.hex()}")

      if not seed:
        ecu_log("already unlocked")
        return True

      for algo in range(9):
        key = compute_security_key(seed, algo)
        ecu_log(f"trying algo {algo}, key={key.hex()}")

        key_req = bytes([0x27, key_sublevel]) + key
        key_query = IsoTpParallelQuery(sendcan, logcan, bus, [(addr, sub_addr)], [key_req], [b''])
        key_res = key_query.get_data(timeout)

        for _, d in key_res.items():
          if len(d) >= 2 and d[0] == 0x67 and d[1] == key_sublevel:
            ecu_log("security access granted")
            return True

  ecu_log("security access failed")
  return False


def disable_ecu(logcan, sendcan, bus=0, addr=0x7d0, sub_addr=None,
                com_cont_req=b'\x28\x83\x01', timeout=0.1, retry=10,
                security_access=False):

  ecu_log(f"=== ECU DISABLE START addr={hex(addr)} bus={bus} ===")

  for i in range(retry):
    try:
      ecu_log(f"attempt {i+1}/{retry}: diag session")
      query = IsoTpParallelQuery(sendcan, logcan, bus,
                                 [(addr, sub_addr)],
                                 [EXT_DIAG_REQUEST],
                                 [EXT_DIAG_RESPONSE])

      for _ in query.get_data(timeout).items():
        ecu_log("diag session OK")

        time.sleep(0.05)

        ecu_log("sending CommunicationControl")
        cc = IsoTpParallelQuery(sendcan, logcan, bus,
                                [(addr, sub_addr)],
                                [com_cont_req],
                                [b''])
        resp = cc.get_data(timeout)

        for _, data in resp.items():
          if data and data[0] == 0x68:
            ecu_log("ECU DISABLE CONFIRMED")
            return True
          elif len(data) >= 3 and data[0] == 0x7F:
            ecu_log(f"CC rejected NRC=0x{data[2]:02x}")
            return False

        ecu_log("ECU DISABLE SENT (no response)")
        return True

    except Exception as e:
      ecu_log(f"exception: {e}")

    time.sleep(0.1)

  ecu_log("=== ECU DISABLE FAILED ===")
  return False