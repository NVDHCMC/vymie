#include "button.h"

Button::Button(int px, int py, char* content, objectCallbackFn callback, void* params): GraphObject() {
  GraphObject::px = px;
  GraphObject::py = py;
  GraphObject::content = content;

  int len = strlen(content);
  if (len > 3) {
    len = 3;
    *(content + 3) = 0;
  }

  GraphObject::w = len;
  GraphObject::h = 1;
  if (callback != NULL) {
    setCallback(callback, params);
  }
}

Button::~Button() {
  if (content != NULL) {
    free(content);
  }
}

void Button::draw(Screen& screen) {
  GraphObject::draw(screen);
}
