// Author:
// Date:

#ifndef _GRAPH_H
#define _GRAPH_H

#include <LiquidCrystal.h>

class graph {
public:
  graph();
  ~graph();
  void handle();
private:
  LiquidCrystal* lcd;
};

#endif // _GRAPH_H
