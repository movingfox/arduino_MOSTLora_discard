//////////////////////////////////////////////////////
// This sample code is used for ShareCourse on MOSTLink protocol
//
//
//////////////////////////////////////////////////////

#include "MOSTLora.h"
#include "MLutility.h"

MOSTLora lora;

int szBuf = 0;
byte buf[256] = {0};

void setup() {
  Serial.begin(9600);  // use serial port for log monitor
  
  lora.begin();
  // custom LoRa config by your environment setting
//  lora.writeConfig(915000, 0, 0, 7, 5);
  lora.setMode(E_LORA_NORMAL);         // E_LORA_NORMAL

  delay(1000);
  lora.sendData("Hi, how are you.");
}

void loop() {
  if (lora.available()) {
    szBuf = lora.receData();

  }
  delay(10);

  // command to send
  if (Serial.available())
    inputBySerial();
}

void inputBySerial()
{
  int countBuf = MLutility::readSerial((char*)buf);
  if (countBuf > 0) {
    buf[countBuf] = 0;
    Serial.print("chat> ");
    Serial.println((char*)buf);
    lora.sendData((char*)buf);
  }  
}
