#include "mbed.h"
 #include "bbcar.h"

 DigitalOut led1(LED_BLUE);
 PwmOut pin9(D9), pin8(D8);
 DigitalInOut pin10(D10);
 Ticker servo_ticker;

 BBCar car(pin8, pin9, servo_ticker);

 int main() {
     parallax_ping  ping1(pin10);
    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table0[] = {-16.753208, -16.349260, -15.286240, -12.054656, -5.889135,0.042521, 5.400146, 11.289281,14.861031,16.200437,16.689427};
    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table1[] = {-17.008333, -16.668167, -15.690188, -12.543646, -6.271823, 0.021260,5.251323,11.459365,15.116156,16.561864,17.220937};
    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);
     
     while(1){
        if((float)ping1<10){
            led1 = 1;
            car.setServo_cm(0,0);
            wait(1);
            car.setServo_cm(5,5);
            wait(1);
            led1=0;
        }else{
            car.setServo_cm(-5,5);
        }
        wait(.01);
     }
 }