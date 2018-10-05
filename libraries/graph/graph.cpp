#include <graph.h>

Graph::Graph(const char* name) {
  this->objectList->current_object = NULL;
  this->objectList->next = NULL;
  this->_name = name;
}

Graph::~Graph() {}

void Graph::handle() {
  // Print a message to the LCD.
}

void Graph::addChild(GraphObject *graphObject) {
  if (graphObject != NULL) {
    if (this->objectList->current_object == NULL) {
      this->objectList->current_object = graphObject;
    }
    else {
      this->objectList->next = this->objectList;
      this->objectList->current_object = graphObject;
    }
  }
}

void Graph::draw(Screen& screen) {
  ObjectList *temp = this->objectList;
  while (temp != NULL) {
    temp->current_object->draw(screen);
    temp = temp->next;
  }
}

void Graph::eventHandler(Screen& screen, Event event) {
  ObjectList *temp = this->objectList;
  while (temp != NULL) {
    if (!temp->current_object->isCallbackNull()) {
      if(temp->current_object->eventHandler(screen, event)) {
        // Successfully handled
        break;
      }
    }

    temp = temp->next;
  }
}
