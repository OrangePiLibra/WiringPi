/*
 * OrangePi GPIO Demo 
 *   General gpio input or output
 *
 * Copyright (c) 2017 Buddy.Zhang <buddy.zhang@aliyun.com>
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
 */  
#include <stdio.h>

#include <wiringPi.h>

#define PA1                          1
#define GPIO_DEMO_INPUT_MODE         1
#define GPIO_DEMO_OUTPUT_MODE        0
#define GPIO_2G_IOT_GROUP_C          0
#define GPIO_2G_IOT_GENERAL_GROUP    1

static void OrangePi_2G_IOT_Demo(void);
static void OrangePi_2G_IOT_GPIOC_Demo(void);

/*
 * Main entry
 */
int main(int argc, char *argv[])
{
#if GPIO_2G_IOT_GROUP_C
	/* OrangePi 2G-IOT GPIO C group */
	OrangePi_2G_IOT_GPIOC_Demo();
#endif

#if GPIO_2G_IOT_GENERAL_GROUP
	/* OrangePi 2G-IOT General GPIO */
	OrangePi_2G_IOT_Demo();
#endif

	return 0;
}

/* 
 * General gpio input or output on OrangePi 2G-IOT
 */
static void OrangePi_2G_IOT_Demo(void)
{
	/* 
	 * More information about pin definition 
	 * see README.md, section OrangePi 2G-IOT
	 */
	wiringPiSetup();

#if GPIO_DEMO_OUTPUT_MODE
	/* Set Output mode */
	pinMode(PA1, OUTPUT);

	for (;;) {
		digitalWrite(PA1, HIGH); 
		delay(500);
		digitalWrite(PA1, LOW);
		delay(500);
	}
#elif GPIO_DEMO_INPUT_MODE
	unsigned int vol;

	/* Set Input mode */
	pinMode(PA1, INPUT);

	for (;;) {
		vol = digitalRead(PA1);
		delay(500);
		printf("Current voltage: %#x\n", vol);	
	}
#endif
}

/*
 * GPIO C group usemanual.
 *   On hardware, the location of modem between CPU and reigster of GPIOC.
 *   So, CPU must send message to modem before controling GPIOC. and we don't 
 *   use GPIOC as general GPIO. Now, GPIOC only support OUTPUT.
 *   
 *   The first number of GPIOC (GPIO_C_0) is 64, and bank is of GPIOC group is 32.
 *   So, the last number of GPIOC (GPIO_C_31) is 95.
 */
static void OrangePi_2G_IOT_GPIOC_Demo(void)
{
	/*
	 * The range of GPIOC is 64 to 93.
	 * So, we can get index of GPIOC:
	 *   GPIO_C_x: index = 64 + x
	 * Demo: GPIO_C_27
	 *             index = 64 + 27 = 91
	 */
#define GPIO_C_27     91

	wiringPiSetup();

	/* Set gpio as output */
	pinMode(GPIO_C_27, OUTPUT);

	for (;;) {
		digitalWrite(GPIO_C_27, HIGH);
		delay(500);
		digitalWrite(GPIO_C_27, LOW);
		delay(500);
	}
}
