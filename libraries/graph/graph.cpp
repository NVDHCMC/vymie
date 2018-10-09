#include <graph.h>

Graph::Graph(const char* name): selectedObject(NULL) {
  this->objectList = reinterpret_cast<ObjectList*>(malloc(sizeof(ObjectList)));
  this->objectList->current_object = NULL;
  this->objectList->next = NULL;
  this->_name = name;
}

Graph::~Graph() {}

void Graph::addChild(GraphObject *graphObject) {
  if (graphObject != NULL) {
    if (this->objectList->current_object == NULL) {
      this->objectList->current_object = graphObject;
    }
    else {
      ObjectList* temp = reinterpret_cast<ObjectList*>(malloc(sizeof(ObjectList)));
      temp->next = this->objectList;
      temp->current_object = graphObject;
      this->objectList = temp;
    }
  }
}

void Graph::draw(Screen* screen) {
  ObjectList *temp = Graph::objectList;
  while (temp != NULL) {
    temp->current_object->draw(screen);
    temp = temp->next;
  }
}

void Graph::eventHandler(Screen* screen, Event event) {
  if (event.t == SEL_BUTTON) {
    if (selectedObject != NULL) {
      selectedObject->eventHandler(screen, event);
    }
  } // if
  else {
    bool handled = false;
    if (selectedObject != NULL) {
      if (selectedObject->t == OBJ_SPINNER) {
        if(reinterpret_cast<Spinner*>(selectedObject)->isChosen()) {
          selectedObject->eventHandler(screen, event);
          handled = true;
        }
      }
      if (!handled) {
        selectedObject->deselect();
      }
    }

    if (!handled) {
      // Look through object list to find the current selected object
      ObjectList *temp = this->objectList;
      int minDis = 1000;
      while (temp != NULL) {
        if ((temp->current_object->t == OBJ_BUTTON) || (temp->current_object->t == OBJ_SPINNER)) {
          switch (event.t) {
            case NAV_BUTTON_LEFT: {
              if (screen->cy == temp->current_object->getY()) {
                signed int dis = screen->cx - temp->current_object->getX();
                if (dis > 0) {
                  if (minDis > dis) {
                    minDis = dis;
                    selectedObject = temp->current_object;
                  }
                }
              }
              break;
            }
            case NAV_BUTTON_RIGHT: {
              if (screen->cy == temp->current_object->getY()) {
                signed int dis = temp->current_object->getX() - screen->cx;
                if (dis > 0) {
                  if (minDis > dis) {
                    minDis = dis;
                    selectedObject = temp->current_object;
                  }
                }
              }
              break;
            }
            case NAV_BUTTON_UP: {
              if (temp->current_object->getY() == 0) {
                int dis = abs(screen->cx - temp->current_object->getX());
                if (minDis > dis) {
                  minDis = dis;
                  selectedObject = temp->current_object;
                }
              }
              break;
            }
            case NAV_BUTTON_DOWN: {
              if (temp->current_object->getY() == 1) {
                unsigned int dis = abs(screen->cx - temp->current_object->getX());
                if (minDis > dis) {
                  minDis = dis;
                  selectedObject = temp->current_object;
                }
              }
              break;
            }
          } // switch case

        }

        temp = temp->next;
      } //while loop
    }// check if event is handled
  } // If select button
  if (selectedObject != NULL) {
    selectedObject->select();
    screen->cy = selectedObject->getY();
    screen->cx = selectedObject->getX();
  }
}
