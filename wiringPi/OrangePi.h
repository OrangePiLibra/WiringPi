#ifndef _ORANGEPI_H
#define _ORANGEPI_H

#define ORANGEPI      8888


#ifdef CONFIG_ORANGEPI_2G_IOT
/********** OrangePi 2G-IOT *************/
/*
 * GPIOA_BASE                         0x20930000
 * GPIOB_BASE                         0x20931000
 * GPIOC_BASE                         0x11A08000
 * GPIOD_BASE                         0x20932000
 */

/********* local data ************/
#define GPIOA_BASE                         0x20930000
#define GPIOB_BASE                         0x20931000
#define GPIOC_BASE                         0x11A08000
#define GPIOD_BASE                         0x20932000
#define GPIO_NUM                           (0x80)
#define GPIO_BIT(x)                        (1UL << (x))

/* Group A */
#define GPIOA_OEN_VAL                      ((GPIOA_BASE) + 0x00)
#define GPIOA_OEN_SET_OUT                  ((GPIOA_BASE) + 0x04) 
#define GPIOA_SET_IN                       ((GPIOA_BASE) + 0x08)
#define GPIOA_VAL                          ((GPIOA_BASE) + 0x0C)
#define GPIOA_SET                          ((GPIOA_BASE) + 0x10)
#define GPIOA_CLR                          ((GPIOA_BASE) + 0x14)

/* Group B */
#define GPIOB_OEN_VAL                      ((GPIOB_BASE) + 0x00)
#define GPIOB_OEN_SET_OUT                  ((GPIOB_BASE) + 0x04) 
#define GPIOB_SET_IN                       ((GPIOB_BASE) + 0x08)
#define GPIOB_VAL                          ((GPIOB_BASE) + 0x0C)
#define GPIOB_SET                          ((GPIOB_BASE) + 0x10)
#define GPIOB_CLR                          ((GPIOB_BASE) + 0x14)

/* Group C */
#define GPIOC_OEN_VAL                      ((GPIOC_BASE) + 0x00)
#define GPIOC_OEN_SET_OUT                  ((GPIOC_BASE) + 0x04) 
#define GPIOC_SET_IN                       ((GPIOC_BASE) + 0x08)
#define GPIOC_VAL                          ((GPIOC_BASE) + 0x0C)
#define GPIOC_SET                          ((GPIOC_BASE) + 0x10)
#define GPIOC_CLR                          ((GPIOC_BASE) + 0x14)

/* Group D */
#define GPIOD_OEN_VAL                      ((GPIOD_BASE) + 0x00)
#define GPIOD_OEN_SET_OUT                  ((GPIOD_BASE) + 0x04) 
#define GPIOD_SET_IN                       ((GPIOD_BASE) + 0x08)
#define GPIOD_VAL                          ((GPIOD_BASE) + 0x0C)
#define GPIOD_SET                          ((GPIOD_BASE) + 0x10)
#define GPIOD_CLR                          ((GPIOD_BASE) + 0x14)

#define OEN_VAL_REGISTER                   (0x00)
#define OEN_SET_OUT_REGISTER               (0x04)
#define SET_IN_REGISTER                    (0x08)
#define VAL_REGISTER                       (0x0C)
#define SET_REGISTER                       (0x10)
#define CLR_REGISTER                       (0x14)

#endif /* CONFIG_ORANGEPI_2G_IOT */

#ifdef CONFIG_ORANGEPI_PC2
/************** OrangePi H5 ***********************/
#define GPIOA_BASE                         (0x01C20800)
#define GPIO_NUM                           (0x60)


#endif

/****************** Global data *********************/
/* Current version */
#define PI_MODEL_ORANGEPI  1
#define PI_MAKER_ORANGEPI  0xfffff
#define MAX_PIN_NUM        GPIO_NUM
#define MAP_SIZE           (4 * 4096) 
#define MAP_MASK           (MAP_SIZE - 1)
#define PI_GPIO_MASK       (~(GPIO_NUM - 1))
#define GPIO_BASE          GPIOA_BASE

extern int pinToGpioOrangePi[64];
extern int physToGpioOrangePi[64];
extern int physToPinOrangePi[64];
extern int ORANGEPI_PIN_MASK[4][32];
extern volatile uint32_t *OrangePi_gpio;
extern volatile uint32_t *OrangePi_gpioC;

extern unsigned int readR(unsigned int addr);
extern void writeR(unsigned int val, unsigned int addr);
extern int OrangePi_set_gpio_mode(int pin, int mode);
extern int isOrangePi_2G_IOT(void);
extern int isOrangePi(void);
extern unsigned int readR(unsigned int addr);
extern void writeR(unsigned int val, unsigned int addr);
extern int OrangePi_digitalWrite(int pin, int value);
extern int OrangePi_digitalRead(int pin);

#endif
