#include "scroll_graph.h"

ScrollGraph::ScrollGraph(const char* name): Graph(name), title(NULL) {

}

void ScrollGraph::eventHandler(Screen* screen, Event event) {
  Graph::eventHandler(screen, event);
}

void ScrollGraph::draw(Screen* screen) {
  if (this->title == NULL) {
    this->title = new Title("Default");
  }
  this->title->draw(screen);

}

void ScrollGraph::addTitle(Title* title) {
  if (title != NULL) {
    this->title = title;
  }
}
