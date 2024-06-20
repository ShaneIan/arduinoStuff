# Raspberry Pi and Arduino Uno R4 I2C Communication Example

This repository provides an example of setting up and using I2C communication between a Raspberry Pi 4 (master) and an Arduino Uno R4 (slave). This setup allows for controlling an LED connected to the Arduino Uno from the Raspberry Pi using I2C protocol.

## Physical Connection

### Components Needed:

- Raspberry Pi 4 with Raspbian OS (or compatible Linux distribution)
- Arduino Uno R4 (or compatible Arduino board)
- Jumper wires
- Breadboard
- 220-ohm resistor
- LED

### Steps to Connect:

1. **Connect I2C Pins:**
   - Connect the I2C pins between Raspberry Pi and Arduino Uno:
     - **Raspberry Pi**:
       - GPIO2 (SDA) to Arduino Uno A4 pin (SDA)
       - GPIO3 (SCL) to Arduino Uno A5 pin (SCL)
     - Connect GND pins between Raspberry Pi and Arduino for common ground.

2. **Setup Breadboard:**
   - Place the LED on the breadboard.
   - Connect the longer leg (anode) of the LED to digital pin 13 (LED pin) on the Arduino Uno.
   - Connect the shorter leg (cathode) of the LED to the breadboard ground rail using a 220-ohm resistor.

3. **Power Up:**
   - Power the Raspberry Pi and Arduino Uno via their respective power sources (USB or external power supply).

## Usage

1. **Upload Arduino Sketch:**
   - Upload the provided Arduino sketch (`IC2connect.ino`) to the Arduino Uno using the Arduino IDE.

2. **Run Python Script on Raspberry Pi:**
   - Use the provided Python script (`IC2connect.py`) on the Raspberry Pi to control the LED connected to the Arduino Uno via I2C.

3. **Control LED:**
   - Execute the Python script and follow the prompts to enter commands (1 for ON, 0 for OFF) to control the LED state on the Arduino Uno.

