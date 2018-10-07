#include "basic_graph.h"

BasicGraph::BasicGraph(const char* name): Graph(name) {

}

BasicGraph::~BasicGraph() {}

void BasicGraph::draw(Screen* screen) {
  Graph::draw(screen);
}

void BasicGraph::eventHandler(Screen* screen, Event event) {
  Graph::eventHandler(screen, event);
}
