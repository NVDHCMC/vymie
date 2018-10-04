// Author:
// Date:

#ifndef _GRAPH_H
#define _GRAPH_H

#include <LiquidCrystal.h>
#include <Arduino.h>

class graph {
public:
  graph();
  ~graph();
  void handle();
  void update_display();
private:
  LiquidCrystal* lcd;
  uint32_t current_time;
  uint32_t start_time;
};

#endif // _GRAPH_H
