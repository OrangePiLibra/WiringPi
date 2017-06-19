#include "wiringPi.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "OrangePi.h"

#ifdef CONFIG_ORANGEPI

#ifdef CONFIG_ORANGEPI_2G_IOT
int pinToGpioOrangePi[64] =
{
  17, 18, 27, 22, 23, 24, 25, 4,    // From the Original Wiki - GPIO 0 through 7:   wpi  0 -  7
   2,  3,               // I2C  - SDA0, SCL0                wpi  8 -  9
   8,  7,               // SPI  - CE1, CE0              wpi 10 - 11
  10,  9, 11,               // SPI  - MOSI, MISO, SCLK          wpi 12 - 14
  14, 15,               // UART - Tx, Rx                wpi 15 - 16
  -1, -1, -1, -1,           // Rev 2: New GPIOs 8 though 11         wpi 17 - 20
   5,  6, 13, 19, 26,           // B+                       wpi 21, 22, 23, 24, 25
  12, 16, 20, 21,           // B+                       wpi 26, 27, 28, 29
   0,  1,               // B+                       wpi 30, 31

// Padding:

  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 47
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 63
};

int physToGpioOrangePi[64] =//head num map to OrangePi
{
  -1,       // 0
  -1, -1,   // 1, 2
   2, -1,
   3, -1,
   4, 14,
  -1, 15,
  17, 18,
  27, -1,
  22, 23,
  -1, 24,
  10, -1,
   9, 25,
  11,  8,
  -1,  7,   // 25, 26

  0,   1,   //27, 28
  5,  -1,  //29, 30
  6,  12,  //31, 32
  13, -1, //33, 34
  19, 16, //35, 36
  26, 20, //37, 38
  -1, 21, //39, 40
// Padding:

  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 56
  -1, -1, -1, -1, -1, -1, -1,   // ... 63
};

int physToPinOrangePi[64] = //return wiringPI pin
{
  -1,       // 0
  -1, -1,   // 1, 2
   8, -1,  //3, 4
   9, -1,  //5, 6
   7, 15,  //7, 8
  -1, 16, //9,10
  0, 1, //11,12
  2, -1, //13,14
  3, 4, //15,16
  -1, 5, //17,18
  12, -1, //19,20
   13, 6, //21,22
  14, 10, //23, 24
  -1,  11,  // 25, 26

  30,   31,   //27, 28
  21,  -1,  //29, 30
  22,  26,  //31, 32
  23, -1, //33, 34
  24, 27, //35, 36
  25, 28, //37, 38
  -1, 29, //39, 40
// Padding:

  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 56
  -1, -1, -1, -1, -1, -1, -1,   // ... 63
};

int ORANGEPI_PIN_MASK[4][32] =  //[BANK]  [INDEX]
{
 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},//PA
 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},//PB
 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},//PC
 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},//PD
};

#endif /* CONFIG_ORANGEPI_2G_IOT */

#ifdef CONFIG_ORANGEPI_PC2
int pinToGpioOrangePi[64] =
{
  17, 18, 27, 22, 23, 24, 25, 4,    // From the Original Wiki - GPIO 0 through 7:   wpi  0 -  7
   2,  3,               // I2C  - SDA0, SCL0                wpi  8 -  9
   8,  7,               // SPI  - CE1, CE0              wpi 10 - 11
  10,  9, 11,               // SPI  - MOSI, MISO, SCLK          wpi 12 - 14
  14, 15,               // UART - Tx, Rx                wpi 15 - 16
  -1, -1, -1, -1,           // Rev 2: New GPIOs 8 though 11         wpi 17 - 20
   5,  6, 13, 19, 26,           // B+                       wpi 21, 22, 23, 24, 25
  12, 16, 20, 21,           // B+                       wpi 26, 27, 28, 29
   0,  1,               // B+                       wpi 30, 31

// Padding:

  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 47
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 63
};

int physToGpioOrangePi[64] =//head num map to OrangePi
{
  -1,       // 0
  -1, -1,   // 1, 2
   2, -1,
   3, -1,
   4, 14,
  -1, 15,
  17, 18,
  27, -1,
  22, 23,
  -1, 24,
  10, -1,
   9, 25,
  11,  8,
  -1,  7,   // 25, 26

  0,   1,   //27, 28
  5,  -1,  //29, 30
  6,  12,  //31, 32
  13, -1, //33, 34
  19, 16, //35, 36
  26, 20, //37, 38
  -1, 21, //39, 40
// Padding:

  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 56
  -1, -1, -1, -1, -1, -1, -1,   // ... 63
};

int physToPinOrangePi[64] = //return wiringPI pin
{
  -1,       // 0
  -1, -1,   // 1, 2
   8, -1,  //3, 4
   9, -1,  //5, 6
   7, 15,  //7, 8
  -1, 16, //9,10
  0, 1, //11,12
  2, -1, //13,14
  3, 4, //15,16
  -1, 5, //17,18
  12, -1, //19,20
   13, 6, //21,22
  14, 10, //23, 24
  -1,  11,  // 25, 26

  30,   31,   //27, 28
  21,  -1,  //29, 30
  22,  26,  //31, 32
  23, -1, //33, 34
  24, 27, //35, 36
  25, 28, //37, 38
  -1, 29, //39, 40
// Padding:

  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 56
  -1, -1, -1, -1, -1, -1, -1,   // ... 63
};

int ORANGEPI_PIN_MASK[4][32] =  //[BANK]  [INDEX]
{
 { 0, 1, 2, 3,-1,-1, 6, 7, 8, 9,10,11,12,13,14,-1,-1,-1,18,19,20,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PA
 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},//PB
 { 0, 1, 2, 3, 4,-1,-1, 7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PC
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PD
};

#endif /* CONFIG_ORANGEPI_2G_IOT */

volatile uint32_t *OrangePi_gpio;
volatile uint32_t *OrangePi_gpioC;

/*
 * Read register value helper  
 */
unsigned int readR(unsigned int addr)
{
#ifdef CONFIG_ORANGEPI_2G_IOT
    unsigned int val = 0;
    unsigned int mmap_base = (addr & ~MAP_MASK);
    unsigned int mmap_seek = (addr - mmap_base);

	if (mmap_base == 0x11a08000) /* Group C */
		val = *((char *)OrangePi_gpioC + mmap_seek);
	else                         /* Group A, B and D */
		val = *((char *)OrangePi_gpio + mmap_seek);
    return val;
#elif CONFIG_ORANGEPI_PC
	uint32_t val = 0;
	uint32_t mmap_base = (addr & ~MAP_MASK);
	uint32_t mmap_seek = ((addr - mmap_base) >> 2);
				      
	val = *(OrangePi_gpio + mmap_seek);
	return val;
#else
	return -1;
#endif
}

/*
 * Wirte value to register helper
 */
void writeR(unsigned int val, unsigned int addr)
{
#ifdef CONFIG_ORANGEPI_2G_IOT
    unsigned int mmap_base = (addr & ~MAP_MASK);
    unsigned int mmap_seek = (addr - mmap_base);

	if (mmap_base == 0x11a08000)
		*((char *)OrangePi_gpioC + mmap_seek) = val;
	else
		*((char *)OrangePi_gpio + mmap_seek) = val;
#elif CONFIG_ORANGEPI_PC2
	unsigned int mmap_base = (addr & ~MAP_MASK);
	unsigned int mmap_seek = ((addr - mmap_base) >> 2);
		        
	*(OrangePi_gpio + mmap_seek) = val;
#else
	/* Non-Operand */
#endif
}

/*
 * Set GPIO Mode on OrangePi 2G-IOT  
 */
int OrangePi_set_gpio_mode(int pin, int mode)
{
    unsigned int regval = 0;
    unsigned int bank   = pin >> 5;
    unsigned int index  = pin - (bank << 5);
    unsigned int phyaddr = 0;
#ifdef CONFIG_ORANGEPI_2G_IOT
	unsigned int base_address = 0;
#elif CONFIG_ORANGEPI_PC2
	int offset = ((index - ((index >> 3) << 3)) << 2);

	phyaddr = GPIO_BASE + (bank * 36) + ((index >> 3) << 2);
#endif

#ifdef CONFIG_ORANGEPI_2G_IOT
    /* Offset of register */
	if (bank == 0)            /* group A */
		base_address = GPIOA_BASE;
	else if (bank == 1)       /* group B */
		base_address = GPIOB_BASE;
	else if (bank == 2)       /* group C */
		base_address = GPIOC_BASE;
	else if (bank == 3)       /* group D */
		base_address = GPIOD_BASE;
	else
		printf("Bad pin number\n");

	if (mode == INPUT) 
		phyaddr = base_address + SET_IN_REGISTER;
	else if (mode == OUTPUT)
		phyaddr = base_address + OEN_SET_OUT_REGISTER;
	else
		printf("Invalid mode\n");
#endif
    /* Ignore unused gpio */
    if (ORANGEPI_PIN_MASK[bank][index] != -1) {
        if (wiringPiDebug)
            printf("Register[%#x]: %#x index:%d\n", phyaddr, regval, index);

        /* Set Input */
        if(INPUT == mode) {
#ifdef CONFIG_ORANGEPI_2G_IOT
            writeR(GPIO_BIT(index), phyaddr);
#elif CONFIG_ORANGEPI_PC2
			regval &= ~(7 << offset);
			writeR(regval, phyaddr);
            regval = readR(phyaddr);
            if (wiringPiDebug)
                printf("Input mode set over reg val: %#x\n",regval);
#endif
        } else if(OUTPUT == mode) { /* Set Output */
#ifdef CONFIG_ORANGEPI_2G_IOT
            writeR(GPIO_BIT(index), phyaddr);
			/* Set default value as 0 */
			writeR(GPIO_BIT(index), base_address + CLR_REGISTER);
#elif CONFIG_ORANGEPI_PC2
			regval &= ~(7 << offset);
			regval |=  (1 << offset);
			if (wiringPiDebug)
				printf("Out mode ready set val: 0x%x\n",regval);
			writeR(regval, phyaddr);
            regval = readR(phyaddr);
            if (wiringPiDebug)
                printf("Out mode ready set val: 0x%x\n",regval);
#endif
        } else {
            printf("Unknow mode\n");
        }
    } else
        printf("Pin mode failed!\n");
    return 0;
}

/*
 * OrangePi Digital write 
 */
int OrangePi_digitalWrite(int pin, int value)
{
    unsigned int bank   = pin >> 5;
    unsigned int index  = pin - (bank << 5);
    unsigned int phyaddr = 0;
#ifdef CONFIG_ORANGEPI_2G_IOT
	unsigned int base_address = 0;
#elif CONFIG_ORANGEPI_PC2
    unsigned int regval = 0;
	
	phyaddr = GPIO_BASE + (bank * 36) + 0x10;
#endif

#ifdef CONFIG_ORANGEPI_2G_IOT
	/* version 0.1 only support GPIOC output on OrangePi 2G-IOT */
	if (bank == 2) { /* group C */
		int fd;
		char buf[20];

		if (value == 1) 
			fd = open("/sys/bus/platform/drivers/rda-gpioc/rda-gpioc/gpo_set", O_RDWR);
		else
			fd = open("/sys/bus/platform/drivers/rda-gpioc/rda-gpioc/gpo_clear", O_RDWR);
		if (fd < 0) {
			printf("ERROR: can't operate GPIOC-%d\n", index);
			return -1;
		}
		sprintf(buf, "%d", index);

		write(fd, buf, strlen(buf));

		close(fd);
		return 0;
	}
#endif
#ifdef CONFIG_ORANGEPI_2G_IOT
    /* Offset of register */
	if (bank == 0)            /* group A */
		base_address = GPIOA_BASE;
	else if (bank == 1)       /* group B */
		base_address = GPIOB_BASE;
	else if (bank == 2)       /* group C */
		base_address = GPIOC_BASE;
	else if (bank == 3)       /* group D */
		base_address = GPIOD_BASE;
	else
		printf("Bad pin number\n");

	if (value == 0) 
		phyaddr = base_address + CLR_REGISTER;
	else if (value == 1)
		phyaddr = base_address + SET_REGISTER;
	else
		printf("Invalid value\n");

#endif
    /* Ignore unused gpio */
    if (ORANGEPI_PIN_MASK[bank][index] != -1) {
#ifdef CONFIG_ORANGEPI_2G_IOT
		writeR(GPIO_BIT(index), phyaddr);
#elif CONFIG_ORANGEPI_PC2
		regval = readR(phyaddr);
		if (wiringPiDebug)
			printf("befor write reg val: 0x%x,index:%d\n", regval, index);
		if(0 == value) {
			regval &= ~(1 << index);
			writeR(regval, phyaddr);
			regval = readR(phyaddr);
			if (wiringPiDebug)
				printf("LOW val set over reg val: 0x%x\n", regval);
		} else {
			regval |= (1 << index);
			writeR(regval, phyaddr);
			regval = readR(phyaddr);
			if (wiringPiDebug)
				printf("HIGH val set over reg val: 0x%x\n", regval);
		}
#endif
    } else
        printf("Pin mode failed!\n");
    return 0;
}

/*
 * OrangePi Digital Read
 */
int OrangePi_digitalRead(int pin)
{
	int bank = pin >> 5;
	int index = pin - (bank << 5);
	int val;

#ifdef CONFIG_ORANGEPI_2G_IOT
	unsigned int base_address = 0;
	unsigned int phys_OEN_R;
	unsigned int phys_SET_R;
	unsigned int phys_VAL_R;

	/* version 0.1 not support GPIOC input function */
	if (bank == 2)
		return -1;

    /* Offset of register */
	if (bank == 0)            /* group A */
		base_address = GPIOA_BASE;
	else if (bank == 1)       /* group B */
		base_address = GPIOB_BASE;
	else if (bank == 2)       /* group C */
		base_address = GPIOC_BASE;
	else if (bank == 3)       /* group D */
		base_address = GPIOD_BASE;
	else
		printf("Bad pin number\n");

	phys_OEN_R = base_address + OEN_VAL_REGISTER;
	phys_SET_R = base_address + SET_REGISTER;
	phys_VAL_R = base_address + VAL_REGISTER;
#endif

#ifdef CONFIG_ORANGEPI_2G_IOT
	if (readR(phys_OEN_R) & GPIO_BIT(index))   /* Input */ 
		val = (readR(phys_VAL_R) & GPIO_BIT(index)) ? 1 : 0;
	else                                       /* Ouput */
		val = (readR(phys_SET_R) & GPIO_BIT(index)) ? 1 : 0;
	return val;
#endif
}

/*
 * Probe OrangePi Platform.
 */
int isOrangePi(void)
{
	FILE *cpuFd;
	char line [120];
	char *d;
#ifdef CONFIG_ORANGEPI_2G_IOT
	/* Support: OrangePi 2G-IOT and OrangePi i96 */
	char *OrangePi_string = "rda8810";
#elif CONFIG_ORANGEPI_PC2
	/* Support: OrangePi PC2 */
	char *OrangePi_string = "sun50iw2";
#else
	/* Non-support */
	char *OrangePi_string = "none";
#endif

	if ((cpuFd = fopen("/proc/cpuinfo", "r")) == NULL)
		piBoardRevOops ("Unable to open /proc/cpuinfo") ;
    
	while (fgets(line, 120, cpuFd) != NULL) {
		if (strncmp(line, "Hardware", 8) == 0)
			break;
	}

	fclose(cpuFd);
	if (strncmp(line, "Hardware", 8) != 0)
		piBoardRevOops("No \"Hardware\" line");

	for (d = &line [strlen (line) - 1]; (*d == '\n') || (*d == '\r') ; --d)
		*d = 0;

	if (wiringPiDebug)
		printf("piboardRev: Hardware string: %s\n", line);

	if (strstr(line, OrangePi_string) != NULL) {
		if (wiringPiDebug)
			printf("Hardware:%s\n",line);
		return 1;
	} else {
		if (wiringPiDebug)
			printf("Hardware:%s\n",line);
		return 0;
	}
}

#endif /* CONFIG_ORANGEPI */
