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
  ~Spinner();
  void draw(Screen& screen);
private:
  bool selected;
};

#endif // _SPINNER_H
