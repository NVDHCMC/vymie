#include "scroll_graph.h"

ScrollGraph::ScrollGraph(const char* name): Graph(name), title(NULL), scrollMax(0), scrollNow(0) {

}

void ScrollGraph::eventHandler(Screen* screen, Event event) {
  // Graph::eventHandler(screen, event);
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
    if (!(selectedObject->isChosen())) {
      switch (event.t) {
        case NAV_BUTTON_UP: {
          if ((screen->cy == selectedObject->getY()) && (screen->cx == selectedObject->getX())) {
            scrollUp();
          }
          break;
        }
        case NAV_BUTTON_DOWN: {
          if ((screen->cy == selectedObject->getY()) && (screen->cx == selectedObject->getX())) {
            scrollDown();
          }
          break;
        }
      }
    }
    screen->cy = selectedObject->getY();
    screen->cx = selectedObject->getX();
  }
}

void ScrollGraph::scrollUp() {
  ObjectList *temp = this->objectList;
  if (scrollNow > 0) {
    scrollNow--;
    while (temp != NULL) {
      temp->current_object->shiftUp();
      temp = temp->next;
    }
  }
}

void ScrollGraph::scrollDown() {
  ObjectList *temp = this->objectList;
  if (scrollNow < scrollMax) {
    scrollNow++;
    while (temp != NULL) {
      temp->current_object->shiftDown();
      temp = temp->next;
    }
  }
}

void ScrollGraph::draw(Screen* screen) {
  if (this->title == NULL) {
    this->title = new Title("Default");
    this->addChild(this->title);
  }
  // Graph::draw(screen);
  ObjectList *temp = Graph::objectList;
  while (temp != NULL) {
    if ((temp->current_object->getY() == 0) || (temp->current_object->getY() == 1)) {
      temp->current_object->draw(screen);
    }
    temp = temp->next;
  }
}

void ScrollGraph::addTitle(Title* title) {
  if (title != NULL) {
    this->title = title;
    this->addChild(this->title);
  }
}

void ScrollGraph::addChild(GraphObject* graphObject) {
  if (graphObject != NULL) {
    int tempY = graphObject->getY() - 1;
    if (scrollMax < tempY) {
      scrollMax = tempY;
    }
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
