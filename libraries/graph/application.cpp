#include "application.h"

Application::Application(): start_time(0), current_time(0) {
  screen = reinterpret_cast<Screen*>(malloc(sizeof(Screen)));
  screen->lcd = new LiquidCrystal(8, 9, 4, 5, 6, 7);
  screen->lcd->begin(16, 2);
  screen->cx = 0;
  screen->cy = 0;
  // create a new character
  screen->lcd->createChar(0, aU);
  // create a new character
  screen->lcd->createChar(1, aD);

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
   adc_key_in = analogRead(0);      // read the value from the sensor
   // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
   // we add approx 50 to those values and check to see if we are close
   if (adc_key_in > 1000) return None; // We make this the 1st option for speed reasons since it will be the most likely result

   // For V1.0 comment the other threshold and use the one below:

   if (adc_key_in < 50)   return Right;
   if (adc_key_in < 195)  return Up;
   if (adc_key_in < 380)  return Down;
   if (adc_key_in < 555)  return Left;
   if (adc_key_in < 790)  return Select;



   return None;  // when all others fail, return this...
}

void Application::handle() {
  current_time = millis();
  if ((current_time - start_time) >= 50) {
    start_time = current_time;
    int buttonState = 0;
    Event event = {NONE, screen->cx, screen->cy};
    buttonState = read_LCD_buttons();
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
    //screen->lcd->clear();
    this->top_graph->draw(screen);
  } // if loop for screen refresh
}

void Application::eventHandler(Event event) {
  if (event.t == SEL_BUTTON) {
    top_graph->eventHandler(screen, event);
  }
  else if (event.t != NONE) {
    top_graph->eventHandler(screen, event);
  }
}

void Application::goToGraph(const char* graph_name) {
  GraphList* temp = this->childList;
  while (temp != NULL) {
    if (strcmp(graph_name, temp->current_graph->_name) == 0) {
      this->top_graph = temp->current_graph;
      break;
    }
    temp = temp->next;
  }
}
