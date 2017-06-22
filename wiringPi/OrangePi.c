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
	70,  37,      // 0, 1
	14,  15,      // 2, 3
	69,  89,      // 4  5
	16,  56,      // 6, 7
	62,  63,      // 8, 9
	5,    6,      //10,11
	4,    3,      //12,13
	2,   72,      //14,15
	71,  -1,      //16,17
	-1,  -1,      //18,19
	-1,  90,      //20,21
	91,  92,      //22,23
	93,  94,      //24,25
	41,  40,      //26,27
	38,  39,    //28,29
	1,    0,    //30,31

	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // ... 47
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,// ... 63
};

int physToGpioOrangePi[64] =//head num map to OrangePi
{
	-1,       // 0
	-1, -1,   // 1, 2
	62, -1,   // 3, 4
	63, -1,   // 5, 6
	56, 72,   // 7, 8
	-1, 71,   // 9, 10
	70, 37,   // 11, 12
	14, -1,   // 13, 14
	15, 69,   // 15, 16
	-1, 89,   // 17, 18
	 4, -1,   // 19, 20
	 3, 16,   // 21, 22
	 2,  5,   // 23, 24
	-1,  6,   // 25, 26
	 1,  0,   // 27, 28
	90, -1,   // 29, 30
	91, 41,   // 31, 32
	92, -1,   // 33, 34
	93, 40,   // 35, 36
	94, 38,   // 37, 38
	-1, 39,   // 39, 40
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
	1,110,     // 0, 1
	0,  3,     // 2, 3
	68, 71,    // 4  5
	2,  6,     // 6, 7
	12, 11,    // 8, 9
	13, 21,    //10,11
	15, 16,    //12,13
	14, 69,    //14,15
	70, -1,    //16,17
	-1, -1,    //18,19
	-1,  7,    //20,21
	8,  9,     //22,23
	10,107,    //24,25
	200,201,   //26,27
	198,199,    //28,29
	19, 18,    //30,31

	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // ... 47
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,// ... 63
};

int physToGpioOrangePi[64] =//head num map to OrangePi
{
	-1,          // 0
	-1,    -1,   // 1, 2
	12,    -1,   // 3, 4
	11,    -1,   // 5, 6
	6,     69,   // 7, 8
	-1,    70,   // 9, 10
	1,    110,   //11, 12
	0,     -1,   //13, 14
	3,     68,   //15, 16
	-1,    71,   //17, 18
	15,    -1,   //19, 20
	16,     2,   //21, 22
	14,    13,   //23, 24
	-1,    21,   //25, 26
	19,    18,   //27, 28
	7,     -1,   //29, 30
	8,    200,   //31, 32
	9,     -1,   //33, 34
	10,   201,   //35, 36
	107,  198,   //37, 38
	-1,   199,   //39, 40
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
	-1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
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

int ORANGEPI_PIN_MASK[9][32] =  //[BANK]  [INDEX]
{
  { 0, 1, 2, 3,-1,-1, 6, 7, 8, 9,10,11,12,13,14,15,16,-1,18,19,20,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PA
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PB
  { 0, 1, 2, 3, 4, 5, 6, 7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PC
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,11,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PD
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PE
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PF
  {-1,-1,-1,-1,-1,-1, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PG
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PH
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PI
};
#endif /* CONFIG_ORANGEPI_2G_IOT */

#ifdef CONFIG_ORANGEPI_A64
int pinToGpioOrangePi [64] =
{
	229,  100,    // 0, 1
	228,  231,    // 2, 3
	361,   68,    // 4  5
	230,  362,    // 6, 7
	227,  226,    // 8, 9
	96,   102,    //10,11
	98,    99,    //12,13
	97,   354,    //14,15
	355,   -1,    //16,17
	-1,    -1,    //18,19
	-1,    36,    //20,21
	37,    38,    //22,23
	39,   101,    //24,25
	34,    35,    //26,27
	32,    33,    //28,29
	143,  142,    //30,31

	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // ... 47
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,// ... 63
};

int physToGpioOrangePi[64] =
{
	-1,           // 0
	-1,     -1,   // 1, 2
	227,    -1,   // 3, 4
	226,    -1,   // 5, 6
	362,   354,   // 7, 8
	-1,    355,   // 9, 10
	229,   100,   //11, 12
	228,    -1,   //13, 14
	231,   361,   //15, 16
	-1,     68,   //17, 18
	98,     -1,   //19, 20
	99,    230,   //21, 22
	97,     96,   //23, 24
	-1,    102,   //25, 26
	143,   142,   //27, 28
	36,     -1,   //29, 30
	37,     34,   //31, 32
	38,     -1,   //33, 34
	39,     35,   //35, 36
	101,    32,   //37, 38
	-1,     33,   //39, 40
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
	-1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};

int physToPinOrangePi [64] = 
{
  -1,        // 0
  -1,  -1,   // 1, 2
   8,  -1,   // 3, 4
   9,  -1,   // 5, 6
   7,  15,   // 7, 8
  -1,  16,   // 9, 10
   0,   1,   //11, 12
   2,  -1,   //13, 14
   3,   4,   //15, 16
  -1,   5,   //17, 18
  12,  -1,   //19, 20
  13,   6,   //21, 22
  14,  10,   //23, 24
  -1,  11,   //25, 26
  30,  31,   //27, 28
  21,  -1,   //29, 30
  22,  26,   //31, 32
  23,  -1,   //33, 34
  24,  27,   //35, 36
  25,  28,   //37, 38
  -1,  29,   //39, 40
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
   -1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};

int ORANGEPI_PIN_MASK[12][32] =  //[BANK]  [INDEX]
{
 { 0, 1, 2, 3,-1,-1, 6, 7, 8, 9,10,11,12,13,14,15,16,-1,18,19,20,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PA
 { 0, 1, 2, 3, 4, 5, 6, 7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PB
 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PC
 { 0, 1, 2, 3, 4, 5, 6,-1,-1,-1,-1,11,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PD
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PE
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PF
 {-1,-1,-1,-1,-1,-1, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PG
 {-1,-1, 2, 3, 4, 5, 6, 7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PH
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PI
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PJ
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PK
 {-1,-1, 2, 3,-1,-1,-1,-1,-1, 9,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PL
};
#endif

#ifdef CONFIG_ORANGEPI_H3
int pinToGpioOrangePi [64] =
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

int physToGpioOrangePi [64] =
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

int physToPinOrangePi [64] = //return wiringPI pin
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

int ORANGEPI_PIN_MASK[9][32] =  //[BANK]  [INDEX]
{
 { 0, 1, 2, 3,-1,-1, 6, 7, 8, 9,10,11,12,13,14,-1,-1,-1,18,19,20,21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PA
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PB
 { 0, 1, 2, 3, 4,-1,-1, 7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PC
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PD
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PE
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PF
 {-1,-1,-1,-1,-1,-1, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PG
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PH
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PI
};
#endif

#ifdef CONFIG_ORANGEPI_ZERO
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

int physToGpioOrangePi[64] =
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

int physToPinOrangePi[64] = 
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

int ORANGEPI_PIN_MASK[12][32] =  //[BANK]  [INDEX]
{
 { 0, 1, 2, 3,-1,-1, 6, 7,-1,-1,10,11,12,13,14,15,16,17,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PA
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PB
 { 0, 1, 2, 3, 4,-1,-1, 7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PC
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PD
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PE
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PF
 {-1,-1,-1,-1,-1,-1, 6, 7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PG
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PH
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PI
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PJ
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PK
 {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},//PL
};
#endif

/*
 * Data for use with the boardId functions.
 * The order of entries here to correspond with the PI_MODEL_X
 * and PI_VERSION_X defines in wiringPi.h
 * Only intended for the gpio command - use at your own risk!
 */

const char *piModelNames[6] =
{
    "Unknown",
    "Model A",
    "Model B",
    "Model B+",
    "Compute Module",
#ifdef CONFIG_ORANGEPI_2G_IOT
	"OrangePi 2G-IOT",
#elif CONFIG_ORANGEPI_PC2
	"OrangePi PC2",
#elif CONFIG_ORANGEPI_A64
	"OrangePi Win/Winplus",
#elif CONFIG_ORANGEPI_H3
	"OrangePi H3 family",
#elif CONFIG_ORANGEPI_ZERO
	"OrangePi Zero",
#endif
};

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
#else
	uint32_t val = 0;
	uint32_t mmap_base = (addr & ~MAP_MASK);
	uint32_t mmap_seek = ((addr - mmap_base) >> 2);

	if (addr >= GPIOL_BASE) {
		unsigned int mask_addr = 0xFF;
		mmap_seek = addr & mask_addr;
		val = *(OrangePi_gpioC + mmap_seek + 0xC00);
	} else		
		val = *(OrangePi_gpio + mmap_seek);
	return val;
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
#else
	unsigned int mmap_base = (addr & ~MAP_MASK);
	unsigned int mmap_seek = ((addr - mmap_base) >> 2);
		        
	if (addr >= GPIOL_BASE) {
		unsigned int mask_addr = 0xFF;

		mask_addr = addr & mask_addr;
		*(OrangePi_gpioC + mmap_seek + 0xC00) = val;
	} else
		*(OrangePi_gpio + mmap_seek) = val;
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
#else
	int offset = ((index - ((index >> 3) << 3)) << 2);

	if (bank == 11) {
		bank = 0;
		phyaddr = GPIOL_BASE + (bank * 36) + ((index >> 3) << 2);
	}
	else
		phyaddr = GPIO_BASE_MAP + (bank * 36) + ((index >> 3) << 2);
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
#ifndef CONFIG_ORANGEPI_2G_IOT 
		regval = readR(phyaddr);
			if (wiringPiDebug)
				printf("Before read reg val: 0x%x offset:%d\n",regval,offset);
#endif
        if (wiringPiDebug)
            printf("Register[%#x]: %#x index:%d\n", phyaddr, regval, index);

        /* Set Input */
        if(INPUT == mode) {
#ifdef CONFIG_ORANGEPI_2G_IOT
            writeR(GPIO_BIT(index), phyaddr);
#else
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
#else
			regval &= ~(7 << offset);
			regval |=  (1 << offset);
			if (wiringPiDebug)
				printf("Out mode ready set val: 0x%x\n",regval);
			writeR(regval, phyaddr);
            regval = readR(phyaddr);
            if (wiringPiDebug)
                printf("Out mode get value: 0x%x\n",regval);
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
#else
    unsigned int regval = 0;
	
	if (bank == 11) {
		bank = 0;
		phyaddr = GPIOL_BASE + (bank * 36) + 0x10;
	}
	else
		phyaddr = GPIO_BASE_MAP + (bank * 36) + 0x10;
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
#else
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
#ifndef CONFIG_ORANGEPI_2G_IOT
	unsigned int phyaddr;
	
	if (bank == 11) {
		bank = 0;
		phyaddr = GPIOL_BASE + (bank * 36) + 0x10;
	}
	else
		phyaddr = GPIO_BASE_MAP + (bank * 36) + 0x10;
#endif

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
	if (ORANGEPI_PIN_MASK[bank][index] != -1) {
#ifndef CONFIG_ORANGEPI_2G_IOT
		val = readR(phyaddr);
		val = val >> index;
		val &= 1;
		if (wiringPiDebug)
			printf("Read reg val: 0x%#x, bank:%d, index:%d\n", val, bank, index);
		return val;
#else
		if (readR(phys_OEN_R) & GPIO_BIT(index))   /* Input */ 
			val = (readR(phys_VAL_R) & GPIO_BIT(index)) ? 1 : 0;
		else                                       /* Ouput */
			val = (readR(phys_SET_R) & GPIO_BIT(index)) ? 1 : 0;
		return val;
#endif
	}
	return 0;
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
#elif CONFIG_ORANGEPI_A64
	/* Support: OrangePi Win/Win plus */
	char *OrangePi_string = "sun50iw1";
#elif CONFIG_ORANGEPI_H3
	/* Support: OrangePi Win/Win plus */
	char *OrangePi_string = "sun8iw7";
#elif CONFIG_ORANGEPI_ZERO
	/* Support: OrangePi zero */
	char *OrangePi_string = "sun8iw7";
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
