#include "graph_object.h"

void GraphObject::draw(Screen* screen) {
  screen->updateScreen(px, py, content, w);
}

int GraphObject::getX() {
  return px;
}

int GraphObject::getY() {
  return py;
}
