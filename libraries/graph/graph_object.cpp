#include "graph_object.h"

void GraphObject::draw(Screen& screen) {
  screen.lcd->setCursor(px, py);
  screen.lcd->print(content);
  screen.cx += w;
}

void GraphObject::setCallback(objectCallbackFn callback, void* params) {
  this->_callback = callback;
  this->_callback_params = params;
}

bool GraphObject::eventHandler(Screen& screen, Event event) {
  if (((screen.cx - this->px) > 0) && ((screen.cy - this->py) > 0)) {
    _callback(this->_callback_params);
    return true;
  }
  else {
    return false;
  }
}

bool GraphObject::isCallbackNull() {
  bool ans = false;
  if (_callback == NULL) {
    ans = true;
  }
  return ans;
}
