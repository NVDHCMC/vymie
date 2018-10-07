#include "graph_object.h"
#include <LiquidCrystal.h>
#include <Arduino.h>
#include <stdlib.h>
#include <string.h>

#ifndef _BUTTON_H
#define _BUTTON_H

class Button: public GraphObject {
public:
  Button(int px, int py, const char* content) {
    Button(px, py, content, NULL, NULL);
  }
  Button(int px, int py, const char* content, objectCallbackFn callback, void* params);
  ~Button();
  void select();
  void deselect();
  void setCallback(objectCallbackFn callback, void* params);
  void eventHandler(Screen* screen, Event event);
private:
  void* _callback_params;
  objectCallbackFn _callback;
  bool selected;
};

#endif // _BUTTON_H
