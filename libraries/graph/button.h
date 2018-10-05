#include "graph_object.h"
#include <LiquidCrystal.h>
#include <Arduino.h>
#include <stdlib.h>
#include <string.h>

#ifndef _BUTTON_H
#define _BUTTON_H

class Button: public GraphObject {
public:
  Button(int px, int py, char* content) {
    Button(px, py, content, NULL, NULL);
  }
  Button(int px, int py, char* content, objectCallbackFn callback, void* params);
  ~Button();
  void draw(Screen& screen);
};

#endif // _BUTTON_H
