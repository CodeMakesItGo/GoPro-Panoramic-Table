#include <EEPROM.h>

#define EEPROM_KEY 0xABCD       //Magic Key so we know EEPROM is valid

//The eeprom magic number
int eepromKey = 0;

void WriteInt(int p_address, int p_value)
{
  byte b1 = ((p_value >> 0) & 0xFF);
  byte b2 = ((p_value >> 8) & 0xFF);
  byte b3 = ((p_value >> 16) & 0xFF);
  byte b4 = ((p_value >> 24) & 0xFF);
  
  EEPROM.write(p_address + 0, b1);
  EEPROM.write(p_address + 1, b2);
  EEPROM.write(p_address + 2, b3);
  EEPROM.write(p_address + 3, b4);
  EEPROM.commit();
}

int ReadInt(int p_address)
 {
   byte b1 = EEPROM.read(p_address + 0);
   byte b2 = EEPROM.read(p_address + 1);
   byte b3 = EEPROM.read(p_address + 2);
   byte b4 = EEPROM.read(p_address + 3);
  
   return (int)((b1 << 0) & 0xFF) + ((b2 << 8) & 0xFF00) + ((b3 << 16) & 0xFF0000) + ((b4 << 24) & 0xFF000000);
 }

 void EEPromInit()
 {
   EEPROM.begin(512);
   eepromKey = ReadInt(0);
   
   if(eepromKey != EEPROM_KEY)
   {
    eepromKey = EEPROM_KEY;
    WriteInt(0, eepromKey);
    WriteInt(sizeof(int), stepperDelay);
    WriteInt(sizeof(int) * 2, highPowerMode);
    WriteInt(sizeof(int) * 3, clockwiseMode);
   }
   
   stepperDelay = ReadInt(sizeof(int));
 }

