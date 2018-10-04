#include <graph.h>

graph::graph(LiquidCrystal* lcd) {
  this->lcd = lcd;
  lcd->begin(16, 2);
  lcd->blink();

  start_time = millis();
}

graph::~graph() {}

void graph::handle() {
  // Print a message to the LCD.
  current_time = millis();
  if (current_time - start_time > 100) {
    update_display();
    start_time = current_time;
  }
}

void graph::update_display() {
  lcd->setCursor(0, 0);
  lcd->print("hello, world!");
}
