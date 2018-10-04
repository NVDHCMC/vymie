// Author:
// Date:

#ifndef _GRAPH_H
#define _GRAPH_H

#include <LiquidCrystal.h>
#include <Arduino.h>
#include "graph_object.h"
#include "button.h"

struct ObjectList {
  GraphObject *current_object;
  GraphObject *next;
};

class graph {
public:
  graph(LiquidCrystal* lcd);
  ~graph();
  void handle();
  void update_display();
private:
  ObjectList *objectList;
  LiquidCrystal* lcd;
  uint32_t current_time;
  uint32_t start_time;
};

#endif // _GRAPH_H
