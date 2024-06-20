# Raspberry Pi to Arduino Communication via Bluetooth LE and LCD Display

## Overview
This project demonstrates communication between a Raspberry Pi 4 Model B and an Arduino Uno R4 WiFi using Bluetooth Low Energy (BLE). The Raspberry Pi sends data to the Arduino, which is displayed on a 16x2 LCD screen. The communication setup utilizes ArduinoBLE library on the Arduino side and BluePy3 for Bluetooth capabilities on the Raspberry Pi.

## Hardware Setup
- **Raspberry Pi 4 Model B:** Acts as the central device sending data.
- **Arduino Uno R4 WiFi:** Acts as the peripheral device receiving data.
- **16x2 LCD Screen:** Displays the received data.
- **Breadboard:** Used for wiring the LCD screen to the Arduino.

## Software Components
- **Arduino Code:** Uses ArduinoBLE library to set up the Arduino as a BLE peripheral and receive data from the Raspberry Pi.
- **Raspberry Pi Code:** Utilizes BluePy3 to enable BLE communication and send data to the Arduino.
- **LCD Display:** Connected to the Arduino via the breadboard to visually output received data.

## Dependencies
- **ArduinoBLE Library:** Required for Bluetooth Low Energy functionality on the Arduino.
- **BluePy3:** Python library for Bluetooth LE on the Raspberry Pi.
- **Arduino IDE:** For uploading code to the Arduino.
- **Raspberry Pi OS:** Operating system for the Raspberry Pi.

## Usage
1. **Setup Hardware:**
   - Wire the 16x2 LCD screen to the Arduino following the provided schematic.
   - ![image](https://github.com/ShaneIan/arduinoStuff/assets/94504883/7c2aec95-8c49-4b1e-8456-558010c6c59a)
   - https://lastminuteengineers.com/arduino-1602-character-lcd-tutorial/


2. **Upload Arduino Sketch:**
   - Open the Arduino IDE.
   - Upload the provided Arduino sketch (`arduinoToma.ino`) to the Arduino Uno.

3. **Run Raspberry Pi Script:**
   - Find the MAC address of your Arduino and replace it with mine.
   - Ensure BluePy3 is installed on your Raspberry Pi.
   - Run the Python script (`launchToma.py`) on the Raspberry Pi.

5. **View Output:**
   - The Raspberry Pi will send data to the Arduino.
   - Data received by the Arduino will be displayed on the connected LCD screen.

## Files Included
- `arduinoToma.ino`: Arduino sketch for BLE communication and LCD display handling.
- `launchToma.py`: Python script to send data from Raspberry Pi to Arduino via BLE.

