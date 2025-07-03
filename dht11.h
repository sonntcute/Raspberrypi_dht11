#ifndef DHT11_H
#define DHT11_H

#include "stdint.h"
#define DHT_PIN 7
// FUNCTION
void set_pin_output();
void set_pin_input();
void write_low();
void write_high();
int wait_for_state(int expected, int time_out);
int read_sensor(uint8_t *tem, uint8_t *hum);
//
#endif