#include "dac.h"
#include "tm4c123gh6pm.h"

/* Port B */
void dac2_init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x2;
	__asm("NOP");
	__asm("NOP");
	GPIO_PORTB_DIR_R |= 0x3F;
	GPIO_PORTB_DEN_R |= 0x3F;
	GPIO_PORTB_DR8R_R |= 0x3F;
}

/* Port E */
void dac1_init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x10;
	__asm("NOP");
	__asm("NOP");
	GPIO_PORTE_DIR_R |= 0x3F;
	GPIO_PORTE_DEN_R |= 0x3F;
	GPIO_PORTE_DR8R_R |= 0x3F;
}

void dac2_out(uint32_t data)
{
	GPIO_PORTB_DATA_R = ((GPIO_PORTB_DATA_R & ~0x3F) | data);
}

void dac1_out(uint32_t data)
{
	GPIO_PORTE_DATA_R = ((GPIO_PORTE_DATA_R & ~0x3F) | data);
}