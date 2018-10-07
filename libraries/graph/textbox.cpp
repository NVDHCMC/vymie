#include "textbox.h"

TextBox::TextBox(int px, int py, const char* content): GraphObject() {
  GraphObject::t = OBJ_TEXT;
  GraphObject::px = px;
  GraphObject::py = py;

  int len = strlen(content);
  char* temp = reinterpret_cast<char*>(malloc(sizeof(char)*len));
  memcpy(temp, content, len);

  GraphObject::content = temp;
  GraphObject::w = len;
  GraphObject::h = 1;
}

TextBox::~TextBox() {}
