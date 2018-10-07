#include "common.h"

Screen::Screen(): cx(-1), cy(0) {
  screen = (char*) malloc(sizeof(char)*34);
  this->clear();
  lcd = new LiquidCrystal(8, 9, 4, 5, 6, 7);
  lcd->begin(16, 2);
  lcd->createChar(0, aU);
  lcd->createChar(1, aD);
}

Screen::~Screen() {
  free(lcd);
  free(screen);
}

void Screen::clear() {
  for (int i = 0; i < 34; i++) {
    this->screen[i] = ' ';
  }
}

void Screen::drawScreen() {
  lcd->setCursor(0, 0);
  lcd->print(screen);
  lcd->setCursor(0, 1);
  lcd->print(screen + 17);
}

void Screen::updateScreen(int px, int py, char* content, int len) {
  if (py == 0) {
    if ((px + len) < 16) {
      memcpy(screen + px, content, len);
    }
    else {
      memcpy(screen + px, content, 16 - px);
    }
  }
  else if (py == 1) {
    if ((px + len) < 16) {
      memcpy(screen + 17 + px, content, len);
    }
    else {
      memcpy(screen + 17 + px, content, 16 - px);
    }
  }
}
