#include "mbed.h"
#include "FXOS8700Q.h"
#include "math.h"
#include "Map.hpp"
#define PI 3.1416

    I2C i2c(PTE25, PTE24);
    Serial pc(USBTX,USBRX);
    /*DigitalOut led(LED1);
    DigitalOut led2(LED2);
    DigitalOut led3(LED3);*/
    FXOS8700QAccelerometer acc(i2c, FXOS8700CQ_SLAVE_ADDR1);    // Configured for the FRDM-K64F with onboard sensors
   
 
int main()
{
    pc.baud(9600);
    

    // Create an accelerometer instance
    acc.enable();

    while (true) {

        float x, y, z;
        acc.getX(x);
        acc.getY(y);
        acc.getZ(z);


        // Calculate pitch and roll. 
        //float pitch = atan(x / sqrt(y * y + z * z));
        //float roll = atan(y / sqrt(x * x + z * z));
        float pitch = 180*atan2(x, sqrt(y*y + z*z))/PI;
        float roll = 180*atan2(y, sqrt(x*x + z*z))/PI;
        float yaw = atan2(-y,x)*180/PI;
        pc.printf("x_angle = %2.2f° y_angle = %2.2f° \n\r",pitch, roll);
      
        //pc.printf("x %2.2f \n\r",val);
       
        
        wait(.3);

       
    }
}