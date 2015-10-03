/*
USB(mega2560)-to-BLE sketch

Apploader project
http://www.apploader.info

Anton Smirnov
2015
*/

int led = 13;
int ledHIGH = 0;

void setup() {
  // init
  Serial.begin(115200);  // USB
  Serial1.begin(115200); // BLE
  pinMode(led, OUTPUT);
}

void loop() {
  // read from BLE (HM-10)
  if (Serial1.available()) {
    Serial.write("ble: ");
    while (Serial1.available()) {
        ledHIGH = 1 - ledHIGH;
        int inByte = Serial1.read();
        digitalWrite(led, ledHIGH);
     
        Serial.write(inByte);
        Serial1.write(inByte);
        delay(2);
     }
     Serial.write('\n');
  }

  // read from USB (Arduino Terminal)
  if (Serial.available()) {
    Serial.write("usb: ");
    while (Serial.available()) {
      ledHIGH = 1 - ledHIGH;
      int inByte = Serial.read();
      digitalWrite(led, ledHIGH);
    
      Serial.write(inByte); // echo
      Serial1.write(inByte);
      delay(2);
    }
    Serial.write('\n');
  }
}
