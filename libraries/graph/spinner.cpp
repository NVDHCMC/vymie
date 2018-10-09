#include "spinner.h"

Spinner::Spinner(int px, int py, SpinnerType pt, objectCallbackFn callback, void* params) \
  : GraphObject(), selected(false), blinkRate(0), blinkPos(0), originalContent(NULL), modifiedContent(NULL), len(4), blink(false), chosen(false) {
  GraphObject::px = px;
  GraphObject::py = py;
  GraphObject::t = OBJ_SPINNER;
  GraphObject::w = len;
  this->pt = pt;
  if (originalContent == NULL) {
    originalContent = (char*) malloc(sizeof(char)*4);
  }

  if (modifiedContent == NULL) {
    modifiedContent = (char*) malloc(sizeof(char)*4);
  }
  for (int i = 0; i < 4; i++) {
    originalContent[i] = ' ';
    modifiedContent[i] = ' ';
  }
  GraphObject::content = modifiedContent;
}

void Spinner::select() {
  originalContent[0] = '>';
  selected = true;
}

void Spinner::deselect() {
  originalContent[0] = ' ';
  selected = false;
}

void Spinner::choose() {
  chosen = !chosen;
}

void Spinner::draw(Screen* screen) {
  memcpy(modifiedContent, originalContent, len);
  if (pt == SPINNER_NUMBER_DIAL) {
    if (blink) {
      modifiedContent[blinkPos + 1] = ' ';
    }
  }
  else if (pt == SPINNER_TEXT_DIAL) {
  }

  if (chosen) {
    blinkRate++;
    if (blinkRate >= 17) {
      blink = !blink;
      blinkRate = 0;
    }
  }
  else {
    modifiedContent[blinkPos + 1] = originalContent[blinkPos + 1];
  }

  GraphObject::draw(screen);
}

void Spinner::addEntry(int max, int min) {
  if (max > 100) {max = 100;}
  if (min < 0) {min = 0;}
  this->max = max;
  this->min = min;
  if (originalContent != NULL) {
    sprintf(originalContent + 1, "%3d", min);
    for (int i = 0; i < 3; i++) {
      if (originalContent[i + 1] == ' ') {originalContent[i + 1] = '0';}
    }
  }
}

void Spinner::eventHandler(Screen* screen, Event event) {
  if (event.t == SEL_BUTTON) {
    this->choose();
  }
  else {
    if (this->chosen) {
      switch (event.t) {
        case NAV_BUTTON_UP: {
          originalContent[blinkPos + 1]++;
          break;
        }
        case NAV_BUTTON_DOWN: {
          originalContent[blinkPos + 1]--;
          break;
        }
        case NAV_BUTTON_LEFT: {
          if (blinkPos > 0) {blinkPos--;}
          break;
        }
        case NAV_BUTTON_RIGHT: {
          if (blinkPos < 2) {blinkPos++;}
          break;
        }
      }
    }
  }
}

bool Spinner::isSelected() {
  return selected;
}

void Spinner::setCallback(objectCallbackFn callback, void* params) {
  this->_callback = callback;
  this->_callback_params = params;
}
