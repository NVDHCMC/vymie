#include "graph_object.h"

void GraphObject::draw(Screen* screen) {
  screen->lcd->setCursor(px, py);
  screen->lcd->print(content);
  //screen->cx = px + w;
  //screen->cy = py + h;
}

void GraphObject::setCallback(objectCallbackFn callback, void* params) {
  this->_callback = callback;
  this->_callback_params = params;
}

void GraphObject::eventHandler(Event event) {
  _callback(this->_callback_params);
}

bool GraphObject::haveCallback() {
  bool ans = true;
  if (_callback == NULL) {
    ans = false;
  }
  return ans;
}

int GraphObject::getX() {
  return px;
}

int GraphObject::getY() {
  return py;
}
