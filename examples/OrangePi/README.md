OrangePi WiringPi UserManual
------------------------------------------------------------------

### Contents

  * OrangePi 2G-IOT

  * OrangePi PC2


-------------------------------------------------------------------

#### OrangePi 2G-IOT

  OrangePi 2G-IOT contains GPIOA, GPIOB, GPIOC and GPIOD. Each of group has 32 gpio,
  The type of GPIO is "Input", "Output" and "specify function" such as "I2C", "I2S" and 
  so on.

  On board, OrangePi 2G-IOT exports 40 pins as different function. User can uitlize these 
  GPIO on different application scenarios. For example, User can configure the type of GPIO
  as "Input", and get current voltage from program. Another hand, User can configure GPIO
  as specify function, such as "Uart", "I2C" and "SPI". 

  Note! On OrangePi 2G-IOT, GPIOA, GPIOB and GPIOD tract as general GPIO, but GPIOC as non-general
  GPIO. Because of some hardware design, The host of GPIOC is modem not CPU. So, If CPU wanna control
  GPIOC, it must send message to Modem, and Moden get message and control GPIOC, it's not good news.
  So. on version 0.1, GPIOC only support "OUTPUT" mode. but we will do more try to let GPIOC work well.
  The size of GPIOx group is 32, so we can get gpio map:
  ```
     GPIOA: 0   -  31
     GPIOB: 32  -  63
     GPIOC: 64  -  95
     GPIOD: 96  -  127
  ```
  Each gpio have a unique ID, and the way of caculate as follow:
  ```
     GPIO_A_x:   ID = 0   + x
     GPIO_B_x:   ID = 32  + x
     GPIO_C_x:   ID = 64  + x
     GPIO_D_x:   ID = 96  + x
  ```
  Final, this section will introduce how to configure GPIO on OrangePi 2G-IOt.

  * Input Mode
    As General GPIO, we only offer the number of GPIOx. then, use library of wiringPi, User can
    easily to control GPIO. Note! GPIOC not support "Input" mode.
     
    the demo code as follow:
    ```
       #include <wiringPi.h>

       /* Defind unique ID */
       #define PA1         1
       #define PB5         37
       #define PD2         98

       int main(void)
       {
           unsigned int vol;

           /* Setup wiringPi */
           wiringPiSetup();

           /* Set Input Mode */
           pinMode(PA1, INPUT);
           pinMode(PB5, INPUT);
           pinMode(PD2, INPUT);

           /* Get value from GPIO */
           vol = digitalRead(PA1);
           vol = digitalRead(PB5);
           vol = digitalRead(PD2);

           return 0;
       }
    ```

  * Output Mode

    All GPIO support "OUTPUT" mode. The demo code as follow:
    ```
       #include <wiringPi.h>

       /* Defind unique ID */
       #define PA1        1
       #define PB5        37
       #define PC27       91
       #defien PD2        98

       int main(void)
       {
           /* Setup wiringPi */
           wiringPiSetup();

           /* Set GPIO Mode */
           pinMode(PA1,  OUTPUT);
           pinMode(PB5,  OUTPUT);
           pinMode(PC27, OUTPUT);
           pinMode(PD2,  OUTPUT);

           digitalWrite(PA1,  HIGH);
           digitalWrite(PB5,  LOW);
           digitalWrite(PC27, HIGH);
           digitalWrite(PD2,  LOW);

           return 0;
       }
    ```
    
--------------------------------------------------------------------------

#### OrangePi PC2
