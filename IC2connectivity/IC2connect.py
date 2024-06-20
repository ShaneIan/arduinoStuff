import smbus
import time

# Define Arduino's I2C address
arduino_address = 0x8

# Create a smbus instance for I2C communication
bus = smbus.SMBus(1)  # 1 indicates /dev/i2c-1, which is the default I2C bus on Raspberry Pi

def send_command(value):
    # Send a single byte command to Arduino
    bus.write_byte(arduino_address, value)

def main():
    try:
        while True:
            # Prompt user for LED control (1 for ON, 0 for OFF)
            command = int(input("Enter command (1 for ON, 0 for OFF): "))
            
            # Send command to Arduino
            send_command(command)
            
            # Wait for Arduino to process (adjust delay based on Arduino sketch)
            time.sleep(0.1)  # Delay in seconds
            
    except KeyboardInterrupt:
        print("\nExiting program.")

if __name__ == "__main__":
    main()
