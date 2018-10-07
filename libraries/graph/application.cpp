#include "application.h"

Application::Application(): start_time(0), current_time(0), buttonSamplingRate(0), previouslySelectedButton(NONE) {
  screen = new Screen();
  start_time = millis();
  this->childList = reinterpret_cast<GraphList*>(malloc(sizeof(GraphList)));
  this->childList->current_graph = NULL;
  this->childList->next = NULL;
}

Application::~Application() {
  free(screen);
}

void Application::addChild(Graph *graph, GraphProperty p) {
  if (graph != NULL) {
    if (p == GRAPH_HOME) {
      top_graph = graph;
    }
    if (this->childList->current_graph == NULL) {
      this->childList->current_graph = graph;
    }
    else {
      GraphList* temp = reinterpret_cast<GraphList*>(malloc(sizeof(GraphList)));
      temp->next = this->childList;
      temp->current_graph = graph;
      this->childList = temp;
    }
  }
}

// read the buttons
int Application::read_LCD_buttons()
{
   int adc_key_in  = 0;
   adc_key_in = analogRead(0);
   if (adc_key_in > 1000) return None;
   if (adc_key_in < 50)   return Right;
   if (adc_key_in < 195)  return Up;
   if (adc_key_in < 380)  return Down;
   if (adc_key_in < 555)  return Left;
   if (adc_key_in < 790)  return Select;

   return None;  // when all others fail, return this...
}

void Application::handle() {
  current_time = millis();
  if ((current_time - start_time) >= 30) {
    start_time = current_time;
    int buttonState = 0;
    Event event = {NONE, screen->cx, screen->cy};
    buttonState = None;
    if (buttonSamplingRate < 4) {
      buttonSamplingRate++;
    }
    else {
      buttonSamplingRate = 0;
      buttonState = read_LCD_buttons();
    }
    if (buttonState == Select) {
      event.t = SEL_BUTTON;
    }
    else {
      switch (buttonState) {
        case Left: {
          event.t = NAV_BUTTON_LEFT;
          break;
        }
        case Down: {
          event.t = NAV_BUTTON_DOWN;
          break;
        }
        case Up: {
          event.t = NAV_BUTTON_UP;
          break;
        }
        case Right: {
          event.t = NAV_BUTTON_RIGHT;
          break;
        }
        default: {
          break;
        }
      }
    }
    eventHandler(event);

    // Draw top graph on screen;
    screen->clear();
    this->top_graph->draw(screen);
    screen->drawScreen();
  } // if loop for screen refresh
}

void Application::eventHandler(Event event) {
  if (event.t != NONE) {
    top_graph->eventHandler(screen, event);
  }
}

void Application::goToGraph(const char* graph_name) {
  GraphList* temp = this->childList;
  while (temp != NULL) {
    if (strcmp(graph_name, temp->current_graph->_name) == 0) {
      this->top_graph = temp->current_graph;
      Event event = {SET_ACTIVE, screen->cx, screen->cy};
      this->top_graph->eventHandler(screen, event);
      break;
    }
    temp = temp->next;
  }
}
