#ifndef ardu_h
#define ardu_h

#include <Arduino.h>

enum pin_e {
   pin_red_button    = 2,
   pin_red_led       = 3,
   pin_yellow_button = 4,
   pin_yellow_led    = 5,
   pin_blue_button   = 6,
   pin_blue_led      = 7,
   pin_green_button  = 8,
   pin_green_led     = 9,
   pin_white_button  = 10,
   pin_white_led     = 11,
   pin_buzzer        = 12
   /** Todo: Add light and distance sensors here */
};
typedef enum pin_e pin_t;

enum button_state_e {
   button_state_pressed = LOW,
   button_state_released = HIGH
};
typedef enum button_state_e button_state_t;

enum led_state_e {
   led_state_off = LOW,
   led_state_on  = HIGH
};
typedef enum led_state_e led_state_t;

enum buzzer_state_e {
   buzzer_state_off = LOW,
   buzzer_state_on  = HIGH
};
typedef enum buzzer_state_e buzzer_state_t;

#endif /* ardu_h */
