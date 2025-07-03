#include "wiringPi.h"
#include "dht11.h"

//FUNCTION 
void set_pin_output()
{
    pinMode(DHT_PIN,OUTPUT);
}
//
void set_pin_input()
{
    pinMode(DHT_PIN,INPUT);
}
//
void write_low()
{
    digitalWrite(DHT_PIN, LOW);
}
//
void write_high()
{
    digitalWrite(DHT_PIN, HIGH);
}
//
int wait_for_state(int expected, int time_out)
{
    int count = 0 ;
    while(digitalRead(DHT_PIN) != expected)
    {
        delayMicroseconds(1);
        if(++count >= time_out) return 0;
    }
    return 1;
}
//
int read_sensor(uint8_t *tem, uint8_t *hum)
{
    uint8_t data[5] ={0};
    // MCU START
    set_pin_output();
    write_low();
    delay(18);
    write_high();
    delayMicroseconds(30);
    set_pin_input();
    // DHT RESPONSE
    if(!wait_for_state(0,80)) return -1; // Turn Low
    if(!wait_for_state(1,80)) return -1; // Turn High
    if(!wait_for_state(0,80)) return -1; // Turn Low wait for transmission
    // READ 5 BYTE
    for(int i = 0; i < 40; i++)
    {
        if(!wait_for_state(1,50)) return -1;
        delayMicroseconds(60);
        if(digitalRead(DHT_PIN))
        data[i/8] |= (1<< (7 - (i % 8)));
        if(!wait_for_state(0,60)) return -5; // Turn Low wait for Read

    }
    //CHECKSUM
    if ((data[0] + data[1] + data[2] + data[3]) != data[4])
    return -6;
    *hum = data[0];
    *tem = data[2];
    return 0;
}