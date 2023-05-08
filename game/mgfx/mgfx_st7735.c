#include "mgfx_st7735.h"
#include "../tm4c123gh6pm.h"
#include "mgfx.h" /* Window size defines */

/* Refer to https://www.displayfuture.com/Display/datasheet/controller/ST7735.pdf */
/*
 * A lot of this stuff is black magic,
 * I would like to read all of the doc
 * for the LCD but there's not enough time
 * to do that and make a cool game
 */

/*
 * Pin connections
 *
 * PA2 - LCD SCK
 * PA3 - LCD TFT_CS
 * PA4 - LCD MISO
 * PA5 - LCD MOSI
 * PA6 - LCD D/C
 * PA7 - LCD RESET
 * PB0 - LCD CARD_CS
 */

/*
 * _write_command
 */
void mgfx__write_command(uint8_t c)
{
	while ((SSI0_SR_R & SSI_SR_BSY) == SSI_SR_BSY);
	TFT_CS = TFT_CS_LOW;
	DC = DC_COMMAND;
	SSI0_DR_R = c;
	while ((SSI0_SR_R & SSI_SR_BSY) == SSI_SR_BSY);
}

/*
 * _write_data
 */
void mgfx__write_data(uint8_t c)
{
	while ((SSI0_SR_R & SSI_SR_TNF) == 0);
	DC = DC_DATA;
	SSI0_DR_R = c;
}

/*
 * _deselect
 */
void mgfx__deselect(void)
{
	while ((SSI0_SR_R & SSI_SR_BSY) == SSI_SR_BSY);
	TFT_CS = TFT_CS_HIGH;
}

/*
 * _init
 *
 * References
 * https://users.ece.utexas.edu/~valvano/Volume1/E-Book/C6_MicrocontrollerPorts.htm
 */
static void Delay1ms(uint32_t n){uint32_t volatile time;
  while(n){
    time = 72724*2/91;  // 1msec, tuned at 80 MHz
    while(time){
      time--;
    }
    n--;
  }
}

static void mgfx__init_commands(void)
{
	/* TODO: Commands (Rcmd1 Rcmd2red Rcmd3) */
	mgfx__write_command(ST7735_SWRESET); /* Software reset */
	Delay1ms(150);
	
	mgfx__write_command(ST7735_SLPOUT); /* Sleep out */
	Delay1ms(255);

	mgfx__write_command(ST7735_FRMCTR1); /* Frame rate control */
	mgfx__write_data(0x01);
	mgfx__write_data(0x2c);
	mgfx__write_data(0x2d);
	
	mgfx__write_command(ST7735_FRMCTR2); /* Frame rate control */
	mgfx__write_data(0x01);
	mgfx__write_data(0x2c);
	mgfx__write_data(0x2d);
	
	mgfx__write_command(ST7735_FRMCTR3); /* Frame rate control */
	mgfx__write_data(0x01);
	mgfx__write_data(0x2c);
	mgfx__write_data(0x2d);
	mgfx__write_data(0x01);
	mgfx__write_data(0x2c);
	mgfx__write_data(0x2d);

	mgfx__write_command(ST7735_INVCTR); /* Inversion control */
	mgfx__write_data(0x7);
	
	mgfx__write_command(ST7735_PWCTR1); /* Power control */
	mgfx__write_data(0xa2);
	mgfx__write_data(0x02);
	mgfx__write_data(0x84);
	
	mgfx__write_command(ST7735_PWCTR2); /* Power control */
	mgfx__write_data(0xc5);
	
	mgfx__write_command(ST7735_PWCTR3); /* Power control */
	mgfx__write_data(0x0a);
	mgfx__write_data(0x00);
	
	mgfx__write_command(ST7735_PWCTR4); /* Power control */
	mgfx__write_data(0x8a);
	mgfx__write_data(0x2a);
	
	mgfx__write_command(ST7735_PWCTR5); /* Power control */
	mgfx__write_data(0x8a);
	mgfx__write_data(0xee);
	
	mgfx__write_command(ST7735_VMCTR1); /* ??? */
	mgfx__write_data(0x0e);

	mgfx__write_command(ST7735_INVOFF); /* Inversion off */
	
	mgfx__write_command(ST7735_MADCTL); /* Memory access control */
	mgfx__write_data(0xc0);
	//mgfx__write_data(0xc8); // testing
	
	mgfx__write_command(ST7735_COLMOD); /* Color mode */
	mgfx__write_data(0x5); /* 16-bit color */
	
	/* Idk why I need to do CASET and RASET here */
	mgfx__write_command(ST7735_CASET);
	mgfx__write_data(0);
	mgfx__write_data(0);
	mgfx__write_data(0);
	mgfx__write_data(WIN_XMAX);
	
	mgfx__write_command(ST7735_RASET);
	mgfx__write_data(0);
	mgfx__write_data(0);
	mgfx__write_data(0);
	mgfx__write_data(WIN_YMAX);
	
	mgfx__write_command(ST7735_GMCTRP1); /* ??? */
	mgfx__write_data(0x02);
	mgfx__write_data(0x1c);
	mgfx__write_data(0x07);
	mgfx__write_data(0x12);
	mgfx__write_data(0x37);
	mgfx__write_data(0x32);
	mgfx__write_data(0x29);
	mgfx__write_data(0x2d);
	mgfx__write_data(0x29);
	mgfx__write_data(0x25);
	mgfx__write_data(0x2b);
	mgfx__write_data(0x39);
	mgfx__write_data(0x00);
	mgfx__write_data(0x01);
	mgfx__write_data(0x03);
	mgfx__write_data(0x10);
	
	mgfx__write_command(ST7735_GMCTRN1); /* ??? */
	mgfx__write_data(0x03);
	mgfx__write_data(0x1d);
	mgfx__write_data(0x07);
	mgfx__write_data(0x06);
	mgfx__write_data(0x2e);
	mgfx__write_data(0x2c);
	mgfx__write_data(0x29);
	mgfx__write_data(0x2d);
	mgfx__write_data(0x2e);
	mgfx__write_data(0x2e);
	mgfx__write_data(0x37);
	mgfx__write_data(0x3f);
	mgfx__write_data(0x00);
	mgfx__write_data(0x00);
	mgfx__write_data(0x02);
	mgfx__write_data(0x10);
	
	mgfx__write_command(ST7735_NORON); /* Normal display on */
	Delay1ms(10);
	
	mgfx__write_command(ST7735_DISPON); /* Main screen on */
	Delay1ms(100);
	
}

void mgfx__init(void)
{
	SYSCTL_RCGCSSI_R |= 0x01; /* SSI0 */
	SYSCTL_RCGCGPIO_R |= 0x01; /* Port A */
	__asm ("NOP");
	__asm ("NOP");
	__asm ("NOP");
	__asm ("NOP");
	while (!(SYSCTL_PRGPIO_R & 0x1));
	GPIO_PORTA_DIR_R |= 0xc8;
	GPIO_PORTA_AFSEL_R &= ~0xc8;
	GPIO_PORTA_DEN_R |= 0xc8;
	
	/* Toggle RST low (LCD reset), toggle CS low (Select LCD) */
	GPIO_PORTA_PCTL_R = GPIO_PORTA_PCTL_R & 0x00FF0FFF;
	GPIO_PORTA_AMSEL_R &= ~0xc8;
	TFT_CS = TFT_CS_LOW;
	RESET = RESET_HIGH;
	Delay1ms(500); /* Idk what these delays are for or how reset works */
	RESET = RESET_LOW;
	Delay1ms(500);
	RESET = RESET_HIGH;
	Delay1ms(500);

	/* Init SSI0 */
	GPIO_PORTA_AFSEL_R |= 0x2c; /* Alternate functions */
	GPIO_PORTA_DEN_R |= 0x2c;
	/* SSI0 Clk, Fss, Tx */
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFF0F00FF) | 0x00202200;
	GPIO_PORTA_AMSEL_R &= ~0x2c;
	SSI0_CR1_R &= ~SSI_CR1_SSE; /* Disable SSI */
	SSI0_CR1_R &= ~SSI_CR1_MS; /* Master mode */
	/* System clock/PLL baud clock source */
	SSI0_CC_R = (SSI0_CC_R & ~SSI_CC_CS_M) | SSI_CC_CS_SYSPLL;
	SSI0_CPSR_R = (SSI0_CPSR_R & ~SSI_CPSR_CPSDVSR_M) + 10;
	SSI0_CR0_R &= ~(SSI_CR0_SCR_M | SSI_CR0_SPH | SSI_CR0_SPO);
	/* Freescale format */
	SSI0_CR0_R = (SSI0_CR0_R & ~SSI_CR0_FRF_M) | SSI_CR0_FRF_MOTO;
	/* 8 bit data */
	SSI0_CR0_R = (SSI0_CR0_R & ~SSI_CR0_DSS_M) | SSI_CR0_DSS_8;
	SSI0_CR1_R |= SSI_CR1_SSE;
	
	mgfx__init_commands();
}

void mgfx__SSI(void)
{
	/* Init SSI0 */
	GPIO_PORTA_AFSEL_R |= 0x2c; /* Alternate functions */
	GPIO_PORTA_DEN_R |= 0x2c;
	/* SSI0 Clk, Fss, Tx */
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFF0F00FF) | 0x00202200;
	GPIO_PORTA_AMSEL_R &= ~0x2c;
	SSI0_CR1_R &= ~SSI_CR1_SSE; /* Disable SSI */
	SSI0_CR1_R &= ~SSI_CR1_MS; /* Master mode */
	/* System clock/PLL baud clock source */
	SSI0_CC_R = (SSI0_CC_R & ~SSI_CC_CS_M) | SSI_CC_CS_SYSPLL;
	SSI0_CPSR_R = (SSI0_CPSR_R & ~SSI_CPSR_CPSDVSR_M) + 10;
	SSI0_CR0_R &= ~(SSI_CR0_SCR_M | SSI_CR0_SPH | SSI_CR0_SPO);
	/* Freescale format */
	SSI0_CR0_R = (SSI0_CR0_R & ~SSI_CR0_FRF_M) | SSI_CR0_FRF_MOTO;
	/* 8 bit data */
	SSI0_CR0_R = (SSI0_CR0_R & ~SSI_CR0_DSS_M) | SSI_CR0_DSS_8;
	SSI0_CR1_R |= SSI_CR1_SSE;
}