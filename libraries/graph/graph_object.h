#include <LiquidCrystal.h>
#include <Arduino.h>
#include "common.h"

#ifndef _GRAPH_OBJECT_H
#define _GRAPH_OBJECT_H

typedef void (*objectCallbackFn)(void *params);

class GraphObject {
public:
  GraphObject(): px(0), py(0), w(0), h(0), content(NULL), t(OBJ_TEXT) {}
  virtual ~GraphObject() {free(content);}
  virtual void eventHandler(Screen* screen, Event event) {}
  virtual void draw(Screen* screen);
  virtual void setCallback(objectCallbackFn callback, void* params) {}
  virtual bool isChosen() {return false;}
  int getX();
  int getY();
  ObjectType t;
  virtual void select() {}
  virtual void deselect() {}
  virtual bool isSelected() {return false;}
  void shiftUp();
  void shiftDown();
protected:
  int px;
  int py;
  int w;
  int h;
  char * content;
};
#endif // _GRAPH_OBJECT_H
