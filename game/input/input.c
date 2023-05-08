#include "input.h"
#include "../tm4c123gh6pm.h"
#include "../timer.h"

/*
 * References
 * http://users.ece.utexas.edu/~valvano/Volume1/IntroToEmbSys/Ch8_ADC.htm
 * https://microcontrollerslab.com/adc-tm4c123g-tiva-c-launchpad-measure-analog-voltage-signal/
 * https://www.ti.com/lit/ds/spms376e/spms376e.pdf?ts=1679198595328&ref_url=https%253A%252F%252Fwww.ti.com%252Ftool%252FEK-TM4C123GXL
 * (pg ~ 860)
 */

/*
 * Pin connections
 *
 * PE0 (Ain3) - JS1 X
 * PE1 (Ain2) - JS1 Y
 * PE2 (Ain1) - JS2 X
 * PE3 (Ain0) - JS2 Y
 * PE4        - LTRG
 * PE5        - RTRG
 * PB1        - Pause
 */
static struct input live_inputs;
static uint8_t      paused;
static uint32_t     time_left;
static uint32_t     time_right;
static uint32_t     time_pause;

/*
 * pause_init
 *
 * @desc
 *   Helper for init
 *   Initializes everything needed for pause
 */
void pause_init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x2;
	__asm("NOP");
	__asm("NOP");
	__asm("NOP");
	__asm("NOP");
	GPIO_PORTB_DIR_R &= ~0x2;
	GPIO_PORTB_DEN_R |= 0x2;
	/* Interrupt */
	GPIO_PORTB_IS_R &= ~0x1; /* Edge sensitive */
	GPIO_PORTB_IBE_R &= ~0x1; /* Single edge */
	GPIO_PORTB_IEV_R |= 0x1; /* Rising edge */
	GPIO_PORTB_ICR_R |= 0x1; /* Clear interrupt flags */
	GPIO_PORTB_IM_R |= 0x2; /* Enable interrupts on PB1 */
	NVIC_PRI0_R = (NVIC_PRI0_R & ~0x000000E0) | 0x20; /* Priority is 1 */
	NVIC_EN0_R |= 0x2; /* Enable Port B Interrupt */
}

/*
 * trigger_init
 *
 * @desc
 *   Helper for init
 *   Initializes triggers (the left and right buttons)
 */
void trigger_init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x10;
	__asm("NOP");
	__asm("NOP");
	GPIO_PORTE_DIR_R &= ~0x30;
	GPIO_PORTE_DEN_R |= 0x30;
	/* Interrupt */
	GPIO_PORTE_IS_R &= ~0x30; /* Edge sensitive */
	GPIO_PORTE_IBE_R &= ~0x30; /* Single edge */
	GPIO_PORTE_IEV_R |= 0x30; /* Rising edge */
	GPIO_PORTE_ICR_R |= 0x30; /* Clear interrupt flags */
	GPIO_PORTE_IM_R |= 0x30; /* Enable interrupts on PA2-5 */
	NVIC_PRI0_R = (NVIC_PRI0_R & ~0x000000E0) | 0x20; /* Priority is 1 */
	NVIC_EN0_R |= 0x10; /* Enable Port E Interrupt */
}

/*
 * joystick_init
 *
 * @desc
 *   Helper for init
 *   Initializes joysticks
 */
void joystick_init(void)
{
	SYSCTL_RCGCADC_R |= 0x1; /* ADC0 */
	SYSCTL_RCGCGPIO_R |= 0x10;
	__asm("NOP");
	__asm("NOP");
	__asm("NOP");
	__asm("NOP");
	GPIO_PORTE_DIR_R &= ~0xF;
	GPIO_PORTE_AFSEL_R |= 0xF;
	GPIO_PORTE_DEN_R &=  ~0xF;
	
	GPIO_PORTE_PCTL_R = GPIO_PORTE_PCTL_R&0xFFFF0000;
	GPIO_PORTE_AMSEL_R |= 0xF;
	ADC0_PC_R = (ADC0_PC_R & ~0xF) | 0x1; /* 125k samples / sec */
	ADC0_SSPRI_R = 0x0123; /* Priority (irrelevant because only using 1 sequencer) */
	ADC0_ACTSS_R &= ~0x4; /* Disable sequencer 2 */
	ADC0_EMUX_R &= ~0xF00; /* Start sequencer 2 (software) */
	ADC0_SSMUX2_R = 0x0123; /* Set Channels for PE0-E3*/
	ADC0_SSCTL2_R = 0x6000; /* takes one sample , set flag */
	ADC0_IM_R &= ~0x4; /* Disable sequencer 2 interrupts */
	ADC0_ACTSS_R |= 0x4; /* Enable sequencer 2 */
}

/*
 * init
 *
 * @desc
 *   Initializes everything needed for inputs
 */
void input_init(void)
{
	live_inputs.x1 = 0;
	live_inputs.y1 = 0;
	live_inputs.x2 = 0;
	live_inputs.y2 = 0;
	live_inputs.buttons = 0;
	live_inputs.pause = 0;

	pause_init();
	trigger_init();
	joystick_init();
}

/*
 * update_joysticks
 *
 * @desc
 *   Sample joysticks and store it in live inputs
 */
void input_update_joysticks(void)
{
	/* Get joystick inputs */
	ADC0_PSSI_R = 0x4; /* Initiate SS2 */
	while (!(ADC0_RIS_R & 0x4)); /* Wait for conversion */
	/* Read the results */
	live_inputs.x1 = ADC0_SSFIFO2_R & 0xFFF;
	live_inputs.y1 = ADC0_SSFIFO2_R & 0xFFF;
	live_inputs.x2 = ADC0_SSFIFO2_R & 0xFFF;
	live_inputs.y2 = ADC0_SSFIFO2_R & 0xFFF;
	ADC0_ISC_R = 0x4; /* Acknowledge completion */
}

/*
 * update_buttons
 *
 * @desc
 *   Doesn't do anything rn
 */
void input_update_buttons(void)
{
	/* Doesn't do anything, interrupts set this */
}

/*
 * get
 *
 * @desc
 *   Performs ADC sampling and returns all inputs
 */
struct input input_get(void)
{
	input_update_joysticks();
	input_update_buttons();
	return live_inputs;
}

void input_clear_pause(void)
{
	live_inputs.pause = 0;
}

uint8_t input_paused(void)
{
	return live_inputs.pause;
}

void input_clear_button(uint8_t flag)
{
	live_inputs.buttons &= ~flag;
}

/* INTERRUPTS */
/* Triggers */
#define TIMEOUT 10000
#define RELOAD 1000
void GPIOPortE_Handler(void)
{
	if(GPIO_PORTE_RIS_R & 0x10){ // PE4
		GPIO_PORTE_ICR_R |= 0x10;
		if (!time_left) {
			live_inputs.buttons |= INPUT_LTRG;
			time_left = TIMEOUT;
			timer1_start(RELOAD);
		}
	}
	if(GPIO_PORTE_RIS_R & 0x20){ // PE5
		GPIO_PORTE_ICR_R |= 0x20;
		if (!time_right) {
			live_inputs.buttons |= INPUT_RTRG;
			time_right = TIMEOUT;
			timer2_start(RELOAD);
		}
	}
}
/* Paused */
void GPIOPortB_Handler(void)
{
		GPIO_PORTB_ICR_R |= 0x2;
		if (!time_pause) {
			live_inputs.pause ^= 1;
			time_pause = TIMEOUT;
			timer4_start(RELOAD);
		}
}

/* Timers */
void Timer1A_Handler(void)
{
	TIMER1_ICR_R = TIMER_ICR_TATOCINT;
	if (time_left) --time_left;
	else timer1_stop();
}

void Timer2A_Handler(void)
{
	TIMER2_ICR_R = TIMER_ICR_TATOCINT;
	if (time_right) --time_right;
	else timer2_stop();
}

void Timer4A_Handler(void)
{
	TIMER4_ICR_R = TIMER_ICR_TATOCINT;
	if (time_pause) --time_pause;
	else timer4_stop();
}