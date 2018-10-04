#include <graph.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);;
graph main_gui(&lcd);
graph pwm_level_settings(&lcd);
graph pwm_time_settings(&lcd);

void setup() {
  // put your setup code here, to run once:
  Button move_to_pwm_level_settings(0, 1, "OK");
  move_to_pwm_level_settings.draw(&lcd);
  Button move_to_time_settings(3, 1, "TIME");
  move_to_time_settings.draw(&lcd);
  // main_gui.add_object(move_to_pwm_level_settings);
}

void loop() {
  // put your main code here, to run repeatedly:
  main_gui.handle();
}
