#ifndef _ORANGEPI_H
#define _ORANGEPI_H

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

#define OEN_VAL_REGISTER                   (0x00)
#define OEN_SET_OUT_REGISTER               (0x04)
#define SET_IN_REGISTER                    (0x08)
#define VAL_REGISTER                       (0x0C)
#define SET_REGISTER                       (0x10)
#define CLR_REGISTER                       (0x14)

#define MEM_INFO                           (512)
#define MAP_SIZE_L                         (4 * 4096)

#endif /* CONFIG_ORANGEPI_2G_IOT */

#ifdef CONFIG_ORANGEPI_PC2
/************** OrangePi H5 ***********************/
#define GPIOA_BASE                         (0x01C20000)
#define GPIO_NUM                           (0x40)
#define GPIO_BASE_MAP                      (0x01C20800)
#define MEM_INFO                           (1024)
#define MAP_SIZE_L                         (4096 * 2)
#endif

/************** OrangePi A64 ***********************/
#ifdef CONFIG_ORANGEPI_A64
#define GPIOA_BASE                         (0x01C20000)
#define GPIO_NUM                           (0x40)
#define GPIO_BASE_MAP                      (0x01C20800)
#define MEM_INFO                           (1024)
#define GPIOL_BASE                         (0x01F02c00)
#define GPIOL_BASE_MAP                     (0x01F02000)  
#define MAP_SIZE_L                         (4096 * 2)
#endif

/************** OrangePi H3 ***********************/
#ifdef CONFIG_ORANGEPI_H3
#define GPIOA_BASE                         (0x01C20000)
#define GPIO_NUM                           (0x40)
#define GPIO_BASE_MAP                      (0x01C20800)
#define MEM_INFO                           (1024)
#define MAP_SIZE_L                         (4096 * 2)
#endif

/************** OrangePi Zero ***********************/
#ifdef CONFIG_ORANGEPI_ZERO
#define GPIOA_BASE                         (0x01C20000)
#define GPIO_NUM                           (0x40)
#define GPIO_BASE_MAP                      (0x01C20800)
#define MEM_INFO                           (1024)
#define MAP_SIZE_L                         (4096 * 2)
#endif

/****************** Global data *********************/
/* Current version */
#define PI_MAKER_ORANGEPI  4
#define MAX_PIN_NUM        GPIO_NUM
#define MAP_SIZE           MAP_SIZE_L
#define MAP_MASK           (MAP_SIZE - 1)
#define PI_GPIO_MASK       (~(GPIO_NUM - 1))
#define GPIO_BASE          GPIOA_BASE
#define ORANGEPI_MEM_INFO  MEM_INFO


extern int pinToGpioOrangePi[64];
extern int physToGpioOrangePi[64];
extern int physToPinOrangePi[64];
extern int physToWpiOrangePi[64];
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

#ifdef CONFIG_ORANGEPI
extern const char *piModelNames[6];
#endif

#ifdef CONFIG_ORANGEPI_2G_IOT
extern int ORANGEPI_PIN_MASK[4][32];
#elif CONFIG_ORANGEPI_PC2
extern int ORANGEPI_PIN_MASK[9][32];
#elif CONFIG_ORANGEPI_A64
extern int ORANGEPI_PIN_MASK[12][32];
#elif CONFIG_ORANGEPI_H3
extern int ORANGEPI_PIN_MASK[9][32];
#elif CONFIG_ORANGEPI_ZERO
extern int ORANGEPI_PIN_MASK[12][32];
#endif
#endif
