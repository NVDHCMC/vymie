#include <LiquidCrystal.h>
#include "common.h"

#ifndef _GRAPH_OBJECT_H
#define _GRAPH_OBJECT_H

typedef void (*objectCallbackFn)(void *params);

class GraphObject {
public:
  GraphObject(): px(0), py(0), w(0), h(0), content(NULL) {}
  virtual ~GraphObject() {}
  bool isCallbackNull();
  bool eventHandler(Screen& screen, Event event);
  void draw(Screen& screen);
  void setCallback(objectCallbackFn callback, void* params);
private:
  void* _callback_params;
  objectCallbackFn _callback;
protected:
  int px;
  int py;
  int w;
  int h;
  char * content;
};
#endif // _GRAPH_OBJECT_H
