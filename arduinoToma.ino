#include <ArduinoBLE.h>
#include <LiquidCrystal.h>

// Constants for BLE and LCD
BLEService lcdService("19B10000-E8F2-537E-4F6C-D104768A1214"); // create LCD service
BLEStringCharacteristic textCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite, 20); // create text characteristic
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD object

byte happymouth[8] =
{
0b00000,
0b00000,
0b10001,
0b10101,
0b10101,
0b01010,
0b00000,
0b00000
};


byte sadmouth[8] =
{
0b00000,
0b00000,
0b01010,
0b10101,
0b10001,
0b10001,
0b00000,
0b00000
};


void setup() {
  lcd.begin(16, 2); // Initialize LCD: 16 columns, 2 rows
  lcd.clear(); // Clear LCD screen

  lcd.createChar(0, happymouth);
  lcd.createChar(1, sadmouth);
  
  // begin BLE stack
  BLE.begin();

  // set advertised local name and service UUID
  BLE.setLocalName("LCD Display - IAN");
  BLE.setAdvertisedService(lcdService);

  // add characteristics to the service
  lcdService.addCharacteristic(textCharacteristic);

  // add service
  BLE.addService(lcdService);

  // start advertising
  BLE.advertise();

  Serial.begin(9600);
  Serial.println("BLE LCD Display Peripheral");
}

void loop() {
  // listen for BLE peripherals to connect:
  BLEDevice central = BLE.central();

  // if a central is connected to the peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());

    // while the central is still connected to the peripheral:
    while (central.connected()) {
      // if the remote device wrote to the characteristic,
      // use the value to display on the LCD:
      if (textCharacteristic.written()) {
        String text = textCharacteristic.value();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("CMD: " + text);

        lcd.setCursor(0, 1);
        lcd.print("         ");

        bool happyFound = false;
        bool sadFound = false;

        // Arrays of happy and sad words
        String happyWords[] = {"pet", "feed", "wash", "play"};
        String sadWords[] = {"yell", "spray", "ignore"};

        // Check if received text matches any happy word
        for (int i = 0; i < sizeof(happyWords) / sizeof(happyWords[0]); i++) {
          if (text.equalsIgnoreCase(happyWords[i])) {
            lcd.print("( ^");
            lcd.write(byte(0));  // Display happy face
            lcd.print("^ )  ");
            happyFound = true;
            break;
          }
        }

        // Check if received text matches any sad word
        if (!happyFound) {
          for (int i = 0; i < sizeof(sadWords) / sizeof(sadWords[0]); i++) {
            if (text.equalsIgnoreCase(sadWords[i])) {
              lcd.print("( ^");
              lcd.write(byte(1));  // Display sad face
              lcd.print("^ )  ");
              sadFound = true;
              break;
            }
          }
        }

        Serial.print("Received text: ");
        Serial.println(text);
      }
    }

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}
