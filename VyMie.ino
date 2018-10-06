#include <application.h>

Application* app;

void OK_button_callback(void *params) {
  app->goToGraph("pwm_settings");
} 

//void *CANCEL_button_callback(void *params) {
//  printf("Cancel button is pressed");
//}

void BACK_button_callback(void *params) {
  app->goToGraph("mainGUI");
}

void setup() {
  app = new Application();
  Graph* mainGui = new Graph("mainGUI");
  // Button* button;
  // button = new Button(0, 1, "OK", OK_button_callback, NULL);
  mainGui->addChild(new Button(0, 1, "OK", OK_button_callback, NULL));
  mainGui->addChild(new Button(5, 0, "PWM", NULL, NULL));
  mainGui->addChild(new Button(1  , 0, "SD", NULL, NULL));
//  mainGui.addChild(new Button(4, 1, "CNL", CANCEL_button_callback, NULL));
//  mainGui.addChild(new Button(8, 1, "PWM", PWM_Settings_button_callback, NULL));
  Graph* pwmSettings = new Graph("pwm_settings");
  pwmSettings->addChild(new Button(0, 1, "BACK", BACK_button_callback, NULL));

  app->addChild(mainGui, GRAPH_HOME);
  app->addChild(pwmSettings);
}

void loop() {
  // put your main code here, to run repeatedly:
  app->handle();
}

