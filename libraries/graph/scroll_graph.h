#include "graph.h"

#ifndef _SCROLL_GRAPH_H
#define _SCROLL_GRAPH_H

class Title: public TextBox {
public:
  Title(const char* title): TextBox(0, 0, title) {}
  ~Title() {}
};

class ScrollGraph: public Graph {
public:
  ScrollGraph(const char* name);
  ~ScrollGraph() {if(title != NULL) {free(title);}}
  void eventHandler(Screen* screen, Event event);
  void draw(Screen* screen);
  void addTitle(Title* title);
  void addChild(GraphObject* graphObject);
  void scrollUp();
  void scrollDown();
private:
  Title* title;
  int scrollMax;
  int scrollNow;
};

#endif // _SCROLL_GRAPH_H
