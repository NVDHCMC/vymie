#include <Arduino.h>

#include "graph.h"
#include "graph_object.h"
#include "button.h"
#include "common.h"

#ifndef _APPLICATION_H
#define _APPLICATION_H

class Application {
public:
  Application();
  ~Application();
  void addChild(Graph* graph, GraphProperty p = GRAPH_OTHER);
  void handle();
  void eventHandler(Event event);
  void goToGraph(const char* graph_name);
private:
  int read_LCD_buttons();
  uint32_t current_time;
  uint32_t start_time;
  Graph* top_graph;
  struct GraphList {
    Graph* current_graph;
    GraphList* next;
  };
  struct Screen* screen;
  struct GraphList* childList;

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

#endif // _APPLICATION_H
