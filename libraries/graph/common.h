#include "LiquidCrystal.h"

#ifndef _COMMON_H
#define _COMMON_H

enum EventType {NAV_BUTTON_LEFT, NAV_BUTTON_DOWN, NAV_BUTTON_UP, NAV_BUTTON_RIGHT, SEL_BUTTON, NONE};
enum GraphProperty {GRAPH_HOME, GRAPH_OTHER};
enum SpinnerType {SPINNER_NUMBER_DIAL, SPINNER_TEXT_DIAL};
enum buttonType {Select, Left, Down, Up, Right, None};
enum ObjectType {OBJ_BUTTON, OBJ_SPINNER, OBJ_TEXT};

struct Event {
  EventType t;
  int px;
  int py;
};

struct Screen {
  LiquidCrystal* lcd;
  int cx;
  int cy;
};

#endif // _COMMON_H
