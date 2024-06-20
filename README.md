# Raspberry Pi 4 and Arduino Uno R4 Communication Examples

This repository contains examples of communication setups between a Raspberry Pi 4 and an Arduino Uno R4. The examples cover various master-to-slave connection methods, including I2C and BLE (Bluetooth Low Energy).

## Introduction

This GitHub repository serves as a collection of basic communication setups between a Raspberry Pi 4 and an Arduino Uno R4. The examples provided demonstrate how to establish master-to-slave connections using different protocols, facilitating communication and control between these two popular development platforms.

## Connections

### Supported Connections:

1. **I2C (Inter-Integrated Circuit):**
   - The examples showcase how to establish communication via I2C, where the Raspberry Pi acts as the master and the Arduino Uno as the slave.
   - Folder: `IC2connectivity`

2. **BLE (Bluetooth Low Energy):**
   - There are examples demonstrating basic BLE communication between the Raspberry Pi and Arduino Uno, leveraging BLE capabilities for wireless communication.
   - Folder: `BLEconnectivity`

## Setup Instructions

### Requirements:

- Raspberry Pi 4 with Raspbian OS (or compatible Linux distribution)
- Arduino Uno R4 or compatible board
- Necessary peripherals (e.g., LEDs, resistors, sensors)
- Python (for Raspberry Pi scripts)
- Arduino IDE (for uploading sketches to Arduino)

### Instructions:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/your-repository.git
   cd your-repository
   
2. **Navigate to Specific Example Directory:**
   - Choose either `IC2connectivity` or `BLEconnectivity` directory based on the connection method you want to explore.
   ```bash
   cd IC2connectivity
   
3. **Follow README in Example Directory:**
   - Each example directory (`IC2connectivity` or `BLEconnectivity`) contains a README file with specific setup instructions and usage details.

