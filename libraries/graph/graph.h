// Author:
// Date:

#ifndef _GRAPH_H
#define _GRAPH_H

#include <LiquidCrystal.h>
#include "graph_object.h"
#include "spinner.h"
#include "button.h"
#include "textbox.h"
#include "common.h"

class Graph {
public:
  Graph(const char* name);
  virtual ~Graph();
  virtual void addChild(GraphObject* graphObject);
  virtual void draw(Screen* screen);
  virtual void eventHandler(Screen* screen, Event event);
  const char* _name;
protected:
  struct ObjectList {
    GraphObject *current_object;
    ObjectList *next;
  };
  ObjectList *objectList;
  GraphObject* selectedObject;
};

#endif // _GRAPH_H
