#include "button.h"

Button::Button() {}

Button::Button(int px, int py, char* content): GraphObject(), content(NULL) {
  GraphObject::px = px;
  GraphObject::py = py;
  this->content = content;

  int len = strlen(content);
  if (len > 3) {
    len = 3;
    *(content + 3) = 0;
  }

  GraphObject::w = len;
  GraphObject::h = 1;
}

Button::~Button() {
  if (content != NULL) {
    free(content);
  }
}

void Button::draw(LiquidCrystal* lcd) {
  lcd->setCursor(px, py);
  lcd->print(content);
}
