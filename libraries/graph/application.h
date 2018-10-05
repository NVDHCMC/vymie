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
  int buttons[5] = {13, 14, 15, 16, 17};
  uint32_t current_time;
  uint32_t start_time;
  Graph* top_graph;
  struct GraphList {
    Graph* current_graph;
    GraphList* next;
  };

  Screen screen;
  struct GraphList* childList;
};

#endif // _APPLICATION_H
