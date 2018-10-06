// Author:
// Date:

#ifndef _GRAPH_H
#define _GRAPH_H

#include <LiquidCrystal.h>
#include "graph_object.h"
#include "button.h"
#include "common.h"

struct ObjectList {
  GraphObject *current_object;
  ObjectList *next;
};

class Graph {
public:
  Graph(const char* name);
  ~Graph();
  void handle();
  void addChild(GraphObject* graphObject);
  void draw(Screen* screen);
  void eventHandler(Screen* screen, Event event);
  const char* _name;
private:
  GraphObject* selectedButton;
  ObjectList *objectList;
};

#endif // _GRAPH_H
