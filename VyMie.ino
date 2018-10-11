#include <application.h>
#include <rtc.h>

Application* app;
RTC *rtc;
uint32_t currentTime, startTime = 0;
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
  rtc = new RTC();
  rtc->readDS1307();
  app = new Application();

  BasicGraph* mainGui = new BasicGraph("mainGUI");
  mainGui->addChild(new Button(0, 1, "OK", OK_button_callback, NULL));
  TextBox* dateTime = new TextBox(0, 0, rtc->digitalClockDisplay());
  mainGui->addChild(dateTime);

  ScrollGraph* pwmSettings = new ScrollGraph("pwm_settings");
  pwmSettings->addTitle(new Title("PWM Level Settings"));
  Spinner* pwm1 = new Spinner(0, 1, SPINNER_NUMBER_DIAL, NULL, NULL);
  Spinner* pwm2 = new Spinner(0, 2, SPINNER_NUMBER_DIAL, NULL, NULL);
  Spinner* pwm3 = new Spinner(0, 3, SPINNER_NUMBER_DIAL, NULL, NULL);
  Spinner* pwm4 = new Spinner(0, 4, SPINNER_NUMBER_DIAL, NULL, NULL);
  Spinner* pwm5 = new Spinner(0, 5, SPINNER_NUMBER_DIAL, NULL, NULL);
  Spinner* pwm6 = new Spinner(0, 6, SPINNER_NUMBER_DIAL, NULL, NULL);
  pwm1->addEntry(100, 50);
  pwm2->addEntry(90, 0);
  pwm3->addEntry(80, 0);  
  pwm4->addEntry(100, 0);
  pwm5->addEntry(100, 0);
  pwm6->addEntry(100, 0);
  pwmSettings->addChild(pwm1);
  pwmSettings->addChild(pwm2);
  pwmSettings->addChild(pwm3);
  pwmSettings->addChild(pwm4);
  pwmSettings->addChild(pwm5);
  pwmSettings->addChild(pwm6);
  pwmSettings->addChild(new TextBox(8, 1, "PWM1")); 
  pwmSettings->addChild(new TextBox(8, 2, "PWM2")); 
  pwmSettings->addChild(new TextBox(8, 3, "PWM3"));
  pwmSettings->addChild(new TextBox(8, 4, "PWM4"));
  pwmSettings->addChild(new TextBox(8, 5, "PWM5"));
  pwmSettings->addChild(new TextBox(8, 6, "PWM6"));

  app->addChild(mainGui, GRAPH_HOME);
  app->addChild(pwmSettings);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis();
  if (currentTime - startTime >= 1000) {
    startTime = currentTime;
    rtc->readDS1307();
  }
  app->handle();
}
