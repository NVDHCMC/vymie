#include "graph_object.h"
#include <LiquidCrystal.h>
#include <Arduino.h>
#include <stdlib.h>
#include <string.h>

#ifndef _BUTTON_H
#define _BUTTON_H

class Button: public GraphObject {
public:
  Button();
  Button(int px, int py, char* content);
  ~Button();
  void draw(LiquidCrystal* lcd);
private:
  char * content;
};

#endif // _BUTTON_H
