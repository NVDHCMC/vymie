#include <LiquidCrystal.h>
#include <Arduino.h>
#include "common.h"

#ifndef _GRAPH_OBJECT_H
#define _GRAPH_OBJECT_H

typedef void (*objectCallbackFn)(void *params);

class GraphObject {
public:
  GraphObject(): px(0), py(0), w(0), h(0), content(NULL), _callback(NULL), _callback_params(NULL), t(OBJ_TEXT) {}
  virtual ~GraphObject() {}
  bool haveCallback();
  void eventHandler(Event event);
  void draw(Screen* screen);
  void setCallback(objectCallbackFn callback, void* params);
  int getX();
  int getY();
  ObjectType t;
  char * content;
private:
  void* _callback_params;
  objectCallbackFn _callback;
protected:
  int px;
  int py;
  int w;
  int h;

};
#endif // _GRAPH_OBJECT_H
