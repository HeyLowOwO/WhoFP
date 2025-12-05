#!/usr/bin/env python3
"""
Debug script to see actual BSM signal values
Run this on your comma device while driving
"""

import time
from cereal import messaging
from opendbc.car.hyundai.values import CAR
from opendbc.car.hyundai.hyundaicanfd import CanBus
from opendbc.can.parser import CANParser

def main():
    print("=== BSM Signal Value Debug ===\n")

    # Get CarParams
    sm = messaging.SubMaster(['carParams'])
    timeout = 10
    start = time.time()
    while not sm.updated['carParams'] and time.time() - start < timeout:
        sm.update(1000)

    if not sm.updated['carParams']:
        print("❌ Timeout waiting for CarParams")
        return

    CP = sm['carParams']
    print(f"Car: {CP.carFingerprint}")
    print(f"enableBsm: {CP.enableBsm}\n")

    if not CP.enableBsm:
        print("❌ BSM not enabled!")
        return

    # Create parser for BLINDSPOTS message
    from opendbc.car.hyundai.values import DBC
    from opendbc.car import Bus

    signals = [
        ("BLINDSPOTS_REAR_CORNERS", 20),
    ]

    parser = CANParser(DBC[CP.carFingerprint][Bus.pt], signals, CanBus(CP).ECAN)
    can_sock = messaging.sub_sock('can')

    print("Monitoring BLINDSPOTS_REAR_CORNERS signals for 20 seconds...")
    print("Drive with a car in your blind spot!\n")

    last_values = {}
    start_time = time.time()
    msg_count = 0

    while time.time() - start_time < 20:
        can_msgs = messaging.recv_sock(can_sock, wait=True)
        if can_msgs:
            parser.update_strings(can_msgs.as_builder().to_bytes())

            # Get all signal values
            vl = parser.vl["BLINDSPOTS_REAR_CORNERS"]

            current_values = {
                'FL_INDICATOR': vl.get('FL_INDICATOR', 'N/A'),
                'FR_INDICATOR': vl.get('FR_INDICATOR', 'N/A'),
                'FL_INDICATOR_ALT': vl.get('FL_INDICATOR_ALT', 'N/A'),
                'FR_INDICATOR_ALT': vl.get('FR_INDICATOR_ALT', 'N/A'),
                'LEFT_BLOCKED': vl.get('LEFT_BLOCKED', 'N/A'),
                'RIGHT_BLOCKED': vl.get('RIGHT_BLOCKED', 'N/A'),
            }

            # Only print when values change
            if current_values != last_values:
                msg_count += 1
                print(f"\n[{msg_count}] Signal values changed:")
                for key, value in current_values.items():
                    print(f"  {key:20s}: {value}")
                last_values = current_values

    print("\n=== Summary ===")
    print(f"Total value changes detected: {msg_count}")
    print(f"Final values: {last_values}")

    # Show what carstate.py would see
    print("\nWhat carstate.py reads:")
    print(f"  leftBlindspot  = {last_values.get('FL_INDICATOR', 0) != 0}")
    print(f"  rightBlindspot = {last_values.get('FR_INDICATOR', 0) != 0}")

if __name__ == "__main__":
    main()
