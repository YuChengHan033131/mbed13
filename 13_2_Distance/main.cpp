#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
Ticker encoder_ticker;
PwmOut pin8(D8), pin9(D9);
DigitalIn pin3(D3);
Serial pc(USBTX, USBRX);

BBCar car(pin8, pin9, servo_ticker);

int main() {
    parallax_encoder encoder0(pin3, encoder_ticker);
    while(1){
        encoder0.reset();
        car.goStraight(10);
        while(encoder0.get_cm()<10){
            wait_ms(1);
            pc.printf("%d\r\n",encoder0.get_steps());
        }
        encoder0.reset();
        car.stop();
        wait(1);
        car.goStraight(-10);
        while(encoder0.get_cm()<10){
            wait_ms(1);
            pc.printf("%d\r\n",encoder0.get_steps());
        }
        car.stop();
        wait(1);
    }
    
}