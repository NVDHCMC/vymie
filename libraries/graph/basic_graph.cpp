#include "basic_graph.h"

BasicGraph::BasicGraph(const char* name): Graph(name) {

}

BasicGraph::~BasicGraph() {}

void BasicGraph::draw(Screen* screen) {
  ObjectList *temp = Graph::objectList;
  while (temp != NULL) {
    temp->current_object->draw(screen);
    temp = temp->next;
  }
}

void BasicGraph::eventHandler(Screen* screen, Event event) {
  Graph::eventHandler(screen, event);
}
