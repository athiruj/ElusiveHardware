#include <EEPROM.h>

bool writeStrToEEPROM(int address, String value) {
  if (value.length() > 64) return 0;

  for (int i = 0; i < value.length(); i++) {
    EEPROM.write(address + i, value[i]);
    Serial.printf("write: %c\n", value[i]);
  }

  EEPROM.write(address + value.length(), '\n');
  EEPROM.commit();
  return 1;
}

String readEEPROMToStr(int address) {
  String value = "";
  char v = 0;

  for (int i = 0; i < 64; i++) {
    v = EEPROM.read(address + i);
    if (v == '\n' || v == 255) break;
    value += v;
    Serial.printf("read: %c, %c, %s\n", v, value[i], value);
  }
  return value;
}

void clearEEPROM() {
  for (int i = 0; i < EEPROM.length(); i++) {
    EEPROM.write(i, 0);
  }
}