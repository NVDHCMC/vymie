#include "graph_object.h"

#ifndef _TEXT_BOX_H
#define _TEXT_BOX_H

class TextBox: public GraphObject {
public:
  TextBox(int px, int py, const char* content);
  virtual ~TextBox();
private:

};

#endif // _TEXT_BOX_H
