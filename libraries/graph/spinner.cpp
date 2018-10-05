#include "spinner.h"

Spinner::Spinner(int px, int py, SpinnerType t, objectCallbackFn callback, void* params): GraphObject(), selected(false) {
  GraphObject::px = px;
  GraphObject::py = py;
  setCallback(callback, params);
}
