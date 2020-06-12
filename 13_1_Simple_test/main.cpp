#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin9(D9), pin8(D8);
BBCar car(pin8, pin9, servo_ticker);

int main() {
    float way=1;
    while(1){
           car.goStraight(100*way);
           wait(1);
           car.stop();
           wait(1);
           way*=-1;
    }
}