# ESP32 BLE Anti-Stalker & Tracker Detector

ESP32 project for scanning nearby Bluetooth Low Energy (BLE) devices in real time and alerting via an active buzzer when a device is in close proximity.

## Overview
This system continuously scans the 2.4 GHz spectrum for active BLE signals emitted by smartphones, wearables, beacons, and trackers. It parses device names, MAC addresses, and RSSI (Received Signal Strength Indicator) values, triggering a buzzer alert when a device crosses the configured proximity threshold.

## Hardware Components
* ESP32 Development Board
* Active Buzzer Module (Connected to GPIO 23)
* USB Cable for Power & Serial Monitoring (115200 baud)

## Setup & Deployment
1. Open `danialproject02.ino` in Arduino IDE.
2. Select **ESP32 Dev Module** and the correct COM port.
3. Upload the sketch to the board.
4. Open the Serial Monitor at **115200 baud** to view scanned devices and monitor proximity alerts.
