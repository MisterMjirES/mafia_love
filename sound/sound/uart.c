#include "uart.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "sfx.h"
#include "music.h"

void uart_init(void)
{
	SYSCTL_RCGCUART_R |= 0x2; /* UART1 */
	SYSCTL_RCGCGPIO_R |= 0x4; /* Port C */
	UART1_CTL_R &= ~0x1; /* Disable UART1 */
	UART1_IBRD_R = 2500;
	UART1_FBRD_R = 0;
	UART1_LCRH_R = 0x70;
	UART1_IM_R = 0x40;
	NVIC_PRI1_R = (NVIC_PRI1_R & 0xFF1FFFFF) | ( 2 << 21);
	NVIC_EN0_R |= 0x40;
	UART1_CTL_R |= 0x1;
	
	GPIO_PORTC_AFSEL_R |= 0x30;
	GPIO_PORTC_DEN_R |= 0x30;
	GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & 0xFF00FFFF) | 0x00220000;
	GPIO_PORTC_AMSEL_R &= ~0x30;
}

void UART1_Handler(void)
{
	uint8_t data;
	while (!(UART1_FR_R & 0x10)) {
		data = UART1_DR_R;
		if      (data == 0xFF) { music_stop(); }
		else if (data & 0x80)  { sfx_play(data & ~0x80); }
		else                   { music_play(data); }
	}
	UART1_ICR_R = 0x40;
}