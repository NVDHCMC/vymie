#include "stdlib.h"

#include "string.h"
#include "graph_object.h"
#include "common.h"

#ifndef _SPINNER_H
#define _SPINNER_H

class Spinner: public GraphObject {
public:
  Spinner(int px, int py, SpinnerType t) {
    Spinner(px, py, t, NULL, NULL);
  }
  Spinner(int px, int py, SpinnerType t, objectCallbackFn callback, void* params);
  ~Spinner() {};
  void draw(Screen* screen);
  void choose();
  void select();
  void deselect();
  void addEntry(int max, int min);
  void eventHandler(Screen* screen, Event event);
  bool isSelected();
  bool isChosen() {return chosen;}
  void setCallback(objectCallbackFn callback, void* params);
  SpinnerType t;
private:
  void* _callback_params;
  objectCallbackFn _callback;
  int len;
  int max;
  int min;
  char* originalContent;
  char* modifiedContent;
  bool selected;
  bool chosen;
  int blinkRate;
  int blinkPos;
  bool blink;
};

#endif // _SPINNER_H
