#include "textbox.h"

TextBox::TextBox(int px, int py, char* content): GraphObject() {
  GraphObject::t = OBJ_TEXT;
  GraphObject::px = px;
  GraphObject::py = py;

  int len = strlen(content);

  GraphObject::content = content;
  GraphObject::w = len;
  GraphObject::h = 1;
}

TextBox::~TextBox() {}
