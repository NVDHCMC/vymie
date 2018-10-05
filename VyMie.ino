#include <application.h>

Application app;

void *OK_button_callback(void *params) {
  printf("Ok button is pressed");
}

//void *CANCEL_button_callback(void *params) {
//  printf("Cancel button is pressed");
//}
//
//void *PWM_Settings_button_callback(void *params) {
//  app.goToGraph("pwm_settings");
//}

void setup() {
  Graph mainGui("mainGUI");
  mainGui.addChild(new Button(0, 1, "OK", OK_button_callback, NULL));
//  mainGui.addChild(new Button(4, 1, "CNL", CANCEL_button_callback, NULL));
//  mainGui.addChild(new Button(8, 1, "PWM", PWM_Settings_button_callback, NULL));
  Graph pwmSettings("pwm_settings");

  app.addChild(&mainGui);
}

void loop() {
  // put your main code here, to run repeatedly:
  app.handle();
}
