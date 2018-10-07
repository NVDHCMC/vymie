#include <LiquidCrystal.h>
#include <Arduino.h>

#ifndef _COMMON_H
#define _COMMON_H

enum EventType {NAV_BUTTON_LEFT, NAV_BUTTON_DOWN, NAV_BUTTON_UP, NAV_BUTTON_RIGHT, SEL_BUTTON, SET_ACTIVE, NONE};
enum GraphProperty {GRAPH_HOME, GRAPH_OTHER};
enum SpinnerType {SPINNER_NUMBER_DIAL, SPINNER_TEXT_DIAL};
enum buttonType {Select, Left, Down, Up, Right, None};
enum ObjectType {OBJ_BUTTON, OBJ_SPINNER, OBJ_TEXT};

struct Event {
  EventType t;
  int px;
  int py;
};

class Screen {
public:
  Screen();
  ~Screen();
  int cx;
  int cy;
  void updateScreen(int px, int py, char* content, int len);
  void drawScreen();
  void clear();
private:
  LiquidCrystal* lcd;
  char* screen;
  byte aU[8] = {
    0b00100,
    0b01110,
    0b11111,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
  };

  byte aD[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b11111,
    0b01110,
    0b00100
  };
};

#endif // _COMMON_H
