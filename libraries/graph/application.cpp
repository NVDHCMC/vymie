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

// read the buttons
int read_LCD_buttons()
{
   int adc_key_in  = 0;
   adc_key_in = analogRead(0);      // read the value from the sensor
   // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
   // we add approx 50 to those values and check to see if we are close
   if (adc_key_in > 1000) return None; // We make this the 1st option for speed reasons since it will be the most likely result
   // For V1.1 us this threshold
   if (adc_key_in < 50)   return Right;
   if (adc_key_in < 250)  return Up;
   if (adc_key_in < 450)  return Down;
   if (adc_key_in < 650)  return Left;
   if (adc_key_in < 850)  return Select;

   // For V1.0 comment the other threshold and use the one below:
  /*
   if (adc_key_in < 50)   return btnRIGHT;
   if (adc_key_in < 195)  return btnUP;
   if (adc_key_in < 380)  return btnDOWN;
   if (adc_key_in < 555)  return btnLEFT;
   if (adc_key_in < 790)  return btnSELECT;
  */


   return None;  // when all others fail, return this...
}

void Application::handle() {
  current_time = millis();
  if ((current_time - start_time) >= 1000) {
    printf("COC");
    start_time = current_time;
    screen.lcd->print("Hello world");
    int i = 0;
    int buttonState = 0;
    Event event;
    while ((buttonState = read_LCD_buttons()) && (!buttonState)) {
      if (Select) {
        event = {SEL_BUTTON, screen.cx, screen.cy};
      }
      else {
        event = {NAV_BUTTON, screen.cx, screen.cy};
        switch (buttonState) {
          case Left: {
            if (screen.cx > 0) {
                screen.cx -= 1;
            }
            //screen.lcd->setCursor(screen.cx, screen.cy);
            break;
          }
          case Down: {
            if (screen.cy > 0) {
              screen.cy -= 1;
            }
            //screen.lcd->setCursor(screen.cx, screen.cy);
            break;
          }
          case Up: {
            if (screen.cy < 1) {
              screen.cy += 1;
            }
            //screen.lcd->setCursor(screen.cx, screen.cy);
            break;
          }
          case Right: {
            if (screen.cx < 16) {
              screen.cy += 1;
            }
            //screen.lcd->setCursor(screen.cx, screen.cy);
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
    screen.lcd->setCursor(screen.cx, screen.cy);
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
