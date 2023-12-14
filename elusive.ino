#include <EEPROM.h>
#include <WiFi.h>

#include "eMemory.h"

String  d = "Elusive";
String  b = "Password";
String  ssid = "";
String  pass = "";

void setup() {
  Serial.begin(9600);


  Serial.println("");

  while(!Serial);

  EEPROM.begin(EEPROM_SIZE);
  // for (int i = 0 ; i < EEPROM.length() ; i++) {
  //   EEPROM.write(i, 0);
  // }


  // clearEEPROM();

  writeStrToEEPROM(SSID_ADDRESS, d);
  writeStrToEEPROM(PASSWORD_ADDRESS, b);
  Serial.println("EEPROM Done!");

  delay(3000);
  if (EEPROM.read(SSID_ADDRESS) && EEPROM.read(PASSWORD_ADDRESS)) {
  //   Serial.println("Connecting to wifi");
    
    ssid = readEEPROMToStr(SSID_ADDRESS);
    pass = readEEPROMToStr(PASSWORD_ADDRESS);

  //   Serial.println(ssid);
  //   Serial.println(pass);

  //   delay(1000);
    IPAddress apIP(192, 168, 0, 1);                              //Static IP for wifi gateway
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));  //set Static IP gateway on NodeMCU
    WiFi.softAP(ssid, pass);                                     //turn on WIFI

    Serial.printf("Create network %s , %s\n",ssid,pass);
  } else {
    Serial.printf("value: %s , %s\n",ssid,pass);
    Serial.println("No ssid pass word");
    Serial.println(readEEPROMToStr(PASSWORD_ADDRESS));
  }
  
}

void loop() {
}