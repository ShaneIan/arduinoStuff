from bluepy3 import btle

# MAC address of your Arduino BLE device
arduino_mac_address = "F4:12:FA:9C:80:C1"

# UUIDs for the BLE service and characteristic
lcd_service_uuid = btle.UUID("19B10000-E8F2-537E-4F6C-D104768A1214")
text_char_uuid = btle.UUID("19B10001-E8F2-537E-4F6C-D104768A1214")

cmds = ["pet", "feed", "play", "wash", "yell", "spray", "ignore"]

def main():
    try:
        # Connect to the Arduino BLE device
        arduino_device = btle.Peripheral(arduino_mac_address)

        # Find characteristics of interest within the LCD service
        lcd_service = arduino_device.getServiceByUUID(lcd_service_uuid)
        text_char = lcd_service.getCharacteristics(forUUID=text_char_uuid)[0]

        print("Welcome to budgetToma!")

        # Send text input to Arduino to display on LCD
        while True:
            text = input("Enter a command to interact with your Toma: ")
            if text.lower() == "help":
                print("Allowed commands are pet, feed, play, wash, and exit!")
                continue
            if text.lower() == "exit":
                text = "Goodbye!"
                text_char.write(str.encode(text), withResponse=True)
                break
            if text.lower() not in cmds:
                print("Please only enter allowed commands!")
                print("Ask for help if you've never played before!")
                continue
            text_char.write(str.encode(text), withResponse=True)
            print(f"Sent '{text}' to Toma")
            if text == 'exit':
                break

    except btle.BTLEException as e:
        print(f"Bluetooth connection error: {e}")

    finally:
        if 'arduino_device' in locals():
            arduino_device.disconnect()

if __name__ == "__main__":
    main()
