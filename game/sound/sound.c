#include "sound.h"
#include "../tm4c123gh6pm.h"

/*
 * init
 *
 * @desc
 *   Initialize sound (UART)
 */
void sound_init(void)
{
	SYSCTL_RCGCUART_R |= 0x2; /* UART1 */
	SYSCTL_RCGCGPIO_R |= 0x4; /* Port C */
	UART1_CTL_R &= ~0x1; /* Disable UART1 */
	UART1_IBRD_R = 2500;
	UART1_FBRD_R = 0;
	UART1_LCRH_R = 0x70;
	UART1_CTL_R |= 0x1;
	
	GPIO_PORTC_AFSEL_R |= 0x30;
	GPIO_PORTC_DEN_R |= 0x30;
	GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & 0xFF00FFFF) | 0x00220000;
	GPIO_PORTC_AMSEL_R &= ~0x30;
	
	/* For some reason the first thing sent over UART is 0, so send sound off */
	sound_play(0xFF);
}

/*
 * play
 *
 * @desc
 *   Play sfx or music
 */
void sound_play(uint8_t command)
{
	while (UART1_FR_R & 0x0020); /* Wait until TXFF is 0 */
	UART1_DR_R = command;
}
