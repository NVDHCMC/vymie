#include "button.h"

Button::Button(int px, int py, const char* content, objectCallbackFn callback, void* params)\
  : GraphObject(), selected(false), _callback(NULL), _callback_params(NULL) {
  GraphObject::t = OBJ_BUTTON;
  GraphObject::px = px;
  GraphObject::py = py;
  char* temp = reinterpret_cast<char*>(malloc(sizeof(char)*5));
  for (int i = 0; i < 5; i++) {
    temp[i] = 0x0;
  }
  int len = strlen(content);
  if (len > 3) {
    len = 3;
  }
  for (int i = 0; i < len; i++) {
    temp[i] = content[i];
  }
  temp[3] = 0;

  GraphObject::content = temp;

  GraphObject::w = len;
  GraphObject::h = 1;
  if (callback != NULL) {
    this->setCallback(callback, params);
  }
}

Button::~Button() {}

void Button::select() {
  if (!selected) {
    for (int i = 4; i > 0; i--) {
      GraphObject::content[i] = GraphObject::content[i-1];
    }
    GraphObject::content[0] = '>';
    GraphObject::w++;
    selected = true;
  }
}

void Button::deselect() {
  if (selected) {
    for (int i = 0; i < 4; i++) {
      GraphObject::content[i] = GraphObject::content[i+1];
    }
    GraphObject::w--;
    selected = false;
  }
}

void Button::setCallback(objectCallbackFn callback, void* params) {
  this->_callback = callback;
  this->_callback_params = params;
}

void Button::eventHandler(Screen* screen, Event event) {
  if (this->_callback != NULL) {
    _callback(this->_callback_params);
  }
}
