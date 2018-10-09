// Author:
// Date:

#ifndef _RTC_H
#define _RTC_H

#include <Wire.h>
#include <Arduino.h>

class RTC {
public:
  RTC();
  ~RTC();
  void setTime(byte hr, byte min, byte sc, byte wkDay, byte d, byte m, byte y);
  int bcd2dec (byte num);
  int dec2bcd (byte num);
  void readDS1307();
  char* digitalClockDisplay();
  int hour;
  int minute;
  int sec;
  int weekDay;
  int day;
  int month;
  int year;
private:
  char* outputString;
    const byte DS1307;
    const byte NumberOfFields;
};

#endif // _RTC_H
