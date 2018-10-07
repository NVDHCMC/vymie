#include "graph.h"

#ifndef _BASIC_GRAPH_
#define _BASIC_GRAPH_

class BasicGraph: public Graph {
public:
  BasicGraph(const char* name);
  ~BasicGraph();
  void draw(Screen* screen);
  void eventHandler(Screen* screen, Event event);
private:

};

#endif // _BASIC_GRAPH_
