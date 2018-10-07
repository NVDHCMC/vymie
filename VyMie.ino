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
  
  BasicGraph* mainGui = new BasicGraph("mainGUI");
  mainGui->addChild(new Button(0, 1, "OK", OK_button_callback, NULL));
  mainGui->addChild(new Button(5, 0, "PWM", NULL, NULL));
  mainGui->addChild(new Button(0  , 0, "SD", NULL, NULL));
  
  ScrollGraph* pwmSettings = new ScrollGraph("pwm_settings");
  pwmSettings->addTitle(new Title("PWM Level Settings"));
  Spinner* pwm1 = new Spinner(0, 1, SPINNER_NUMBER_DIAL, NULL, NULL);
  pwm1->addEntry(0, 100);
  pwmSettings->addChild(pwm1);

  app->addChild(mainGui, GRAPH_HOME);
  app->addChild(pwmSettings);
}

void loop() {
  // put your main code here, to run repeatedly:
  app->handle();
}
