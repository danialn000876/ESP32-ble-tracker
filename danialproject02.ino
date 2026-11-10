#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

#define BUZZER_PIN 23

int scanTime = 5;
BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      int rssi = advertisedDevice.getRSSI();
      
      Serial.print("Device: ");
      if (advertisedDevice.haveName()) {
        Serial.print(advertisedDevice.getName().c_str());
      } else {
        Serial.print("Unknown/Hidden");
      }
      
      Serial.print(" | MAC: ");
      Serial.print(advertisedDevice.getAddress().toString().c_str());
      Serial.print(" | RSSI: ");
      Serial.println(rssi);

      if (rssi > -45) {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(150);
        digitalWrite(BUZZER_PIN, LOW);
      }
    }
};

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("[*] Anti-Stalker BLE Detector Started");

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true);
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);
}

void loop() {
  Serial.println("[*] Scanning area for nearby BLE devices...");
  pBLEScan->start(scanTime);
  pBLEScan->clearResults();
  delay(2000);
}