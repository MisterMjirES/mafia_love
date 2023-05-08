#include "output.h"
#include "../tm4c123gh6pm.h"

/*
 * References
 * https://microcontrollerslab.com/pwm-tm4c123-example-codes-tiva-c-launchpad/
 */

/*
 * Pin connections
 *
 * PB4 (M0PWM2) - LED 1 (Green)
 * PB5 (M0PWM3) - LED 2 (Yellow)
 * PB6 (M0PWM0) - LED 3 (Red)
 */

/* This is 5 Hz? idk tbh */
#define LOAD_VALUE 2500

/*
 * init
 *
 * @desc
 *   Initializes everything for output
 */
void output_init(void)
{
	/* Comments may be wrong */
	SYSCTL_RCGCPWM_R |=0x01; /* PWM0 */
  SYSCTL_RCGCGPIO_R|=0x02; /* Port B */
  while ((SYSCTL_PRGPIO_R&0x02) == 0) {};           
  GPIO_PORTB_AFSEL_R |= 0x70; /* Enable alt funct on PB4,PB5,PB6 */
  GPIO_PORTB_PCTL_R &= ~0x0FFF0000; /* Configure PB4,PB5,PB6 as PWM0 */
  GPIO_PORTB_PCTL_R |= 0x04440000;              
  GPIO_PORTB_AMSEL_R &= ~0x70; /* Disable analog functionality on PB4,PB5,PB6 */
  GPIO_PORTB_DEN_R |= 0x70; /* Enable digital I/O on PB4,PB5,PB6 */
	/* Use PWM divider, configure for /16 divider to C */
  SYSCTL_RCC_R = 0x00100000 | (SYSCTL_RCC_R & (~0x000C0000));
	/* Reload, up-counting mode */
	PWM0_0_CTL_R = 0x2;
  PWM0_1_CTL_R = 0x2;
	PWM0_0_GENA_R = (2 << 0) | (3 << 6); /* Low on LOAD, high on CMPA (Gen 0 CMP A) */
  PWM0_1_GENA_R = (2 << 0) | (3 << 6); /* Low on LOAD, high on CMPA down (Gen 1 CMP A) */
	PWM0_1_GENB_R = (2 << 0) | (3 << 10); /* Low on LOAD, high on CMPB down (Gen 1 CMP B) */
	/* Set load value */
	PWM0_0_LOAD_R = LOAD_VALUE;
  PWM0_1_LOAD_R = LOAD_VALUE;
	/* Initialize cmp to 0 (off) */
	PWM0_0_CMPA_R = 0;
	PWM0_1_CMPA_R = 0;
	PWM0_1_CMPB_R = 0;
	/* Start/enable */
	PWM0_0_CTL_R |= 0x00000001; /* Start PWM0 */
  PWM0_1_CTL_R |= 0x00000001; /* Start PWM0 */
  PWM0_ENABLE_R |= (PWM_ENABLE_PWM0EN); /* Enable PB6/M0PWM0 */
	PWM0_ENABLE_R |= (PWM_ENABLE_PWM2EN); /* Enable PB4/M0PWM2 */
	PWM0_ENABLE_R |= (PWM_ENABLE_PWM3EN); /* Enable PB5/M0PWM3 */
}

/*
 * LED functions
 *
 * @desc
 *   Basically set the brightness of the LED
 *   Changes the compare value
 * @param cmp
 *   Compare value, 0 to turn off
 */
#define X_LIST X(green, 1, A ,2) X(yellow, 1, B,3) X(red, 0, A,0)
#define X(color, num, gen, WM) \
	void output_##color(uint32_t cmp) \
	{ \
		PWM0_##num##_CMP##gen##_R = cmp; \
	}
X_LIST
#undef X
#undef X_LIST