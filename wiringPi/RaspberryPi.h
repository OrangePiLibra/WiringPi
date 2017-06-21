#ifndef _RASPBERRYPI_H
#define _RASPBERRYPI_H

#define BCM2708_PERI_BASE                        0x20000000
#define GPIO_PADS			(BCM2708_PERI_BASE + 0x00100000)
#define CLOCK_BASE			(BCM2708_PERI_BASE + 0x00101000)
#define GPIO_TIMER			(BCM2708_PERI_BASE + 0x0000B000)
#define GPIO_PWM			(BCM2708_PERI_BASE + 0x0020C000)

extern int pinToGpioR1[64];
extern int pinToGpioR2[64];
extern int physToGpioR1[64];
extern int physToGpioR2[64];
extern int pinToGpioR3[64];
extern int physToGpioR3[64];
extern int physToPinR3[64];
#endif
