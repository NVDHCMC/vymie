#include <graph.h>

Graph::Graph(const char* name): selectedButton(NULL) {
  this->objectList = reinterpret_cast<ObjectList*>(malloc(sizeof(ObjectList)));
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
      ObjectList* temp = reinterpret_cast<ObjectList*>(malloc(sizeof(ObjectList)));
      temp->next = this->objectList;
      temp->current_object = graphObject;
      this->objectList = temp;
    }
  }
}

void Graph::draw(Screen* screen) {
  ObjectList *temp = this->objectList;
  while (temp != NULL) {
    temp->current_object->draw(screen);
    temp = temp->next;
  }
}

void Graph::eventHandler(Screen* screen, Event event) {
  if (event.t == SEL_BUTTON) {
    ObjectList *temp = this->objectList;
    if (selectedButton != NULL) {
      if(selectedButton->haveCallback()) {
        selectedButton->eventHandler(event);
      }
    }
  } // if
  else {
    screen->lcd->setCursor(14, 0);
    screen->lcd->print(screen->cx);
    screen->lcd->setCursor(14, 1);
    screen->lcd->print(screen->cy);
    if (selectedButton != NULL) {
      reinterpret_cast<Button*>(selectedButton)->deselect();
    }
    ObjectList *temp = this->objectList;
    int minDis = 1000;
    while (temp != NULL) {
      if (temp->current_object->t == OBJ_BUTTON) {
        switch (event.t) {
          case NAV_BUTTON_LEFT: {
            if (screen->cy == temp->current_object->getY()) {
              int dis = screen->cx - temp->current_object->getX();
              if (dis < 0) {
                if (minDis > dis) {
                  minDis = dis;
                  selectedButton = temp->current_object;
                }
              }
            }
          }
          case NAV_BUTTON_RIGHT: {
            if (screen->cy == temp->current_object->getY()) {
              int dis = temp->current_object->getX() - screen->cx;
              if (dis > 0) {
                if (minDis > dis) {
                  minDis = dis;
                  selectedButton = temp->current_object;
                }
              }
            }
          }
        //   case NAV_BUTTON_UP: {
        //     if (temp->current_object->getY() == 0) {
        //       int dis = abs(screen->cx - temp->current_object->getX());
        //       if (minDis > dis) {
        //         minDis = dis;
        //         selectedButton = temp->current_object;
        //       }
        //     }
        //   }
        //   case NAV_BUTTON_DOWN: {
        //     if (temp->current_object->getY() == 1) {
        //       unsigned int dis = abs(screen->cx - temp->current_object->getX());
        //       if (minDis > dis) {
        //         minDis = dis;
        //         selectedButton = temp->current_object;
        //       }
        //     }
        //   }
        } // switch case

      }

      temp = temp->next;
    } //while loop

    if (selectedButton != NULL) {
      reinterpret_cast<Button*>(selectedButton)->selected();
      screen->lcd->setCursor(10, 0);
      screen->lcd->print("2");
      screen->cy = selectedButton->getY();
      screen->cx = selectedButton->getX();
    }
  }
}
