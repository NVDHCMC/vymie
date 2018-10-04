#include <graph.h>

graph::graph() {
  const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
  lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);
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
