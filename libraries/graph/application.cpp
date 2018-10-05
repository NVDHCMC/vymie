#include "application.h"

Application::Application(): start_time(0), current_time(0) {
  screen.lcd = new LiquidCrystal(8, 9, 4, 5, 6, 7);
  screen.lcd->begin(16, 2);
  screen.lcd->blink();
  start_time = millis();
  this->childList->current_graph = NULL;
  this->childList->next = NULL;
}

Application::~Application() {}

void Application::addChild(Graph *graph, GraphProperty p) {
  if (graph != NULL) {
    if (p == GRAPH_HOME) {
      top_graph = graph;
    }
    if (this->childList->current_graph == NULL) {
      this->childList->current_graph = graph;
    }
    else {
      this->childList->next = this->childList;
      this->childList->current_graph = graph;
    }
  }
}

void Application::handle() {
  current_time = millis();
  if (current_time - start_time >= 100) {
    screen.lcd->print("Hello world");
    int i = 0;
    int buttonState = 0;
    Event event;
    while ((buttonState = digitalRead(buttons[i])) && (!buttonState) && (i < 5)) {
      if (i = 0) {
        event = {SEL_BUTTON, screen.cx, screen.cy};
      }
      else {
        event = {NAV_BUTTON, screen.cx, screen.cy};
        switch (i) {
          case 1: {
            if (screen.cx > 0) {
                screen.cx -= 1;
            }
            screen.lcd->setCursor(screen.cx, screen.cy);
            break;
          }
          case 2: {
            if (screen.cy > 0) {
              screen.cy -= 1;
            }
            screen.lcd->setCursor(screen.cx, screen.cy);
            break;
          }
          case 3: {
            if (screen.cy < 1) {
              screen.cy += 1;
            }
            screen.lcd->setCursor(screen.cx, screen.cy);
            break;
          }
          case 4: {
            if (screen.cx < 16) {
              screen.cy += 1;
            }
            screen.lcd->setCursor(screen.cx, screen.cy);
            break;
          }
          default: {
            break;
          }
        }
      }

      eventHandler(event);
      i++;
    } // while loop

    // Draw top graph on screen;
    this->top_graph->draw(screen);
  } // if loop for screen refresh
}

void Application::eventHandler(Event event) {
  if (event.t == SEL_BUTTON) {
    top_graph->eventHandler(screen, event);
  }
}

void Application::goToGraph(const char* graph_name) {
  GraphList* temp = this->childList;
  while (temp != NULL) {
    if (strcmp(graph_name, temp->current_graph->_name)) {
      this->top_graph = temp->current_graph;
      break;
    }
    temp = temp->next;
  }
}
