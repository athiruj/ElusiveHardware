
// set eeprom size
#define EEPROM_SIZE 512

#define SSID_ADDRESS 0
#define PASSWORD_ADDRESS 128

bool writeStrToEEPROM(int address, String value);

String readEEPROMToStr(int address);

void clearEEPROM();