#include <stdio.h>
#include <stdint.h>
#include <wiringPi.h>
#include "dht11.h"

int main() {
    wiringPiSetupPhys();
    uint8_t t, h;

    while (1) {
        int result = read_sensor(&t, &h);
        if (result == 0)
            printf("Nhiệt độ: %d°C, Độ ẩm: %d%%\n", t, h);
        delay(1000);
    }

    return 0;
}
