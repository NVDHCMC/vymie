#ifndef _COMMON_H
#define _COMMON_H

#include "LiquidCrystal.h"

enum EventType {NAV_BUTTON, SEL_BUTTON};
enum GraphProperty {GRAPH_HOME, GRAPH_OTHER};
enum SpinnerType {SPINNER_NUMBER_DIAL, SPINNER_TEXT_DIAL};
enum buttonType {Select, Left, Down, Up, Right, None};

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
