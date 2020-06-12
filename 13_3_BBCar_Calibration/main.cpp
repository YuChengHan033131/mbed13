#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker,encoder_ticker;
PwmOut pin8(D8), pin9(D9);
DigitalIn pin3(D4);
BBCar car(pin8, pin9, servo_ticker);
parallax_encoder encoder(pin3,encoder_ticker);
Serial pc(USBTX, USBRX);
int main() {
    // please contruct you own calibration table with each servo
    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table0[] = {-16.753208, -16.349260, -15.286240, -12.054656, -5.889135,0.042521, 5.400146, 11.289281,14.861031,16.200437,16.689427};
    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table1[] = {-17.008333, -16.668167, -15.690188, -12.543646, -6.271823, 0.021260,5.251323,11.459365,15.116156,16.561864,17.220937};

    // first and fourth argument : length of table
    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

    Timer t;
    t.start();
    /*encoder.reset();
    car.setServoPwm(0,150);
    while(t.read()<30){}
    pc.printf("%f\r\n",encoder.get_cm()/30.0);
    car.setServoPwm(0,0);*/
    while (1) {
        car.goStraightCalib(20);
        wait(1);
        car.goStraightCalib(0);
        wait(1);
        car.goStraightCalib(-20);
        wait(1);
        car.goStraightCalib(0);
        wait(3);
    }
}