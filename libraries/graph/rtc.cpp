#include "rtc.h"

RTC::RTC(): hour(0), minute(0), sec(0), weekDay(0), day(0), month(0), year(0), DS1307(0x68), NumberOfFields(7) {
  Wire.begin();
  //setTime(20, 58, 00, 3, 9, 10, 18); // 10:35:45 t2 08-10-2017
  outputString = (char*) malloc(sizeof(char)*18);
  memset(outputString, 0x00, 18);
}

RTC::~RTC() {}

int RTC::bcd2dec(byte num) {
  return ((num/16 * 10) + (num % 16));
}

int RTC::dec2bcd(byte num)
{
  return ((num/10 * 16) + (num % 10));
}

void RTC::setTime(byte hr, byte min, byte sc, byte wkDay, byte d, byte m, byte y) {
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0x00)); // đặt lại pointer
  Wire.write(dec2bcd(sc));
  Wire.write(dec2bcd(min));
  Wire.write(dec2bcd(hr));
  Wire.write(dec2bcd(wkDay)); // day of week: Sunday = 1, Saturday = 7
  Wire.write(dec2bcd(d));
  Wire.write(dec2bcd(m));
  Wire.write(dec2bcd(y));
  Wire.endTransmission();
}

void RTC::readDS1307() {
  Wire.beginTransmission(DS1307);
  Wire.write((byte)0x00);
  Wire.endTransmission();
  Wire.requestFrom(DS1307, NumberOfFields);

  sec     = bcd2dec(Wire.read() & 0x7f);
  minute  = bcd2dec(Wire.read() );
  hour    = bcd2dec(Wire.read() & 0x3f); // chế độ 24h.
  weekDay = bcd2dec(Wire.read() );
  day     = bcd2dec(Wire.read() );
  month   = bcd2dec(Wire.read() );
  year    = bcd2dec(Wire.read() );
  year   += 0;
  sprintf(outputString, "%2d:%2d:%2d %2d-%2d-%2d", hour, minute, sec, day, month, year);
  for (int i = 0; i < 18; i++) {
    if (outputString[i] == ' ') {
      outputString[i] = '0';
    }
  }
  outputString[8] = ' ';
}

char* RTC::digitalClockDisplay(){
  // digital clock display of the time
  return outputString;
}
