#!/usr/bin/env python3
"""
Comprehensive BSM debugging script
Run this on your comma device while driving
"""

import time
from cereal import messaging

def main():
    print("=== Blind Spot Monitoring Debug ===\n")

    # Get CarParams
    print("1. Checking CarParams...")
    sm = messaging.SubMaster(['carParams', 'carState'])

    timeout = 10
    start = time.time()
    while not sm.updated['carParams'] and time.time() - start < timeout:
        sm.update(1000)

    if not sm.updated['carParams']:
        print("❌ Timeout waiting for CarParams")
        return

    cp = sm['carParams']
    print(f"✓ Car: {cp.carFingerprint}")
    print(f"✓ enableBsm: {cp.enableBsm}\n")

    if not cp.enableBsm:
        print("❌ BSM is not enabled in CarParams!")
        print("   The fingerprinting fix didn't work or device needs restart.\n")
        return

    # Monitor CAN messages
    print("2. Monitoring CAN messages for 10 seconds...")
    print("   Looking for BLINDSPOTS_REAR_CORNERS (0x1ba = 442)")
    can_sock = messaging.sub_sock('can')

    msg_count = 0
    start_time = time.time()

    try:
        while time.time() - start_time < 10:
            can_recv = messaging.recv_sock(can_sock, wait=True)
            if can_recv is not None:
                for msg in can_recv.can:
                    if msg.address == 0x1ba:  # BLINDSPOTS_REAR_CORNERS
                        msg_count += 1
                        if msg_count == 1:
                            print(f"   ✓ Found message 0x1ba on bus {msg.src}!")
                            print(f"     Data length: {len(msg.dat)} bytes")
                            print(f"     First data: {' '.join(f'{b:02x}' for b in msg.dat[:8])}")
    except KeyboardInterrupt:
        pass

    if msg_count > 0:
        print(f"   ✓ Received {msg_count} BLINDSPOTS messages in 10 seconds")
        print(f"     Rate: ~{msg_count/10:.1f} Hz\n")
    else:
        print("   ❌ NO BLINDSPOTS messages received!")
        print("      Your car might not have this message.\n")
        return

    # Check CarState
    print("3. Checking CarState blind spot status...")
    print("   Drive with a car in your blind spot to test...\n")

    start_time = time.time()
    last_left = None
    last_right = None

    while time.time() - start_time < 15:
        sm.update(100)
        if sm.updated['carState']:
            cs = sm['carState']
            left = cs.leftBlindspot
            right = cs.rightBlindspot

            if left != last_left or right != last_right:
                status = []
                if left:
                    status.append("LEFT")
                if right:
                    status.append("RIGHT")

                if status:
                    print(f"   🚗 BLIND SPOT DETECTED: {' + '.join(status)}")
                else:
                    print(f"   ✓ No blind spot detected")

                last_left = left
                last_right = right

    print("\n=== Summary ===")
    print(f"enableBsm: {cp.enableBsm}")
    print(f"CAN messages received: {msg_count > 0}")
    print(f"If blind spot was detected during test: Check above")

if __name__ == "__main__":
    main()
