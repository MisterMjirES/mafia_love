/*
 * main.c
 *
 * Main function for the game. Initializes modules
 * and has the game loop.
 */

/*
 * System draws too much power and crashes
 * See https://www.ti.com/lit/an/spma059/spma059.pdf?ts=1680717742562&ref_url=https%253A%252F%252Fwww.ti.com%252Ftool%252FEK-TM4C123GXL
 * page 20
 */

#include "PLL.h"
#include "mgfx/mgfx.h"
#include "input/input.h"
#include "output/output.h"
#include "sound/sound.h"
#include "cutscene/title.h"
#include "timer.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

/* Loop function to call, its initialized to a dummy function for safety */
void (*loop_fn) (void);
void dummy_fn(void) {}
	
void init(void)
{
	PLL_Init(Bus80MHz);
	mgfx_init();
	input_init();
	output_init();
	sound_init();
	timer0_init();
	timer1_init();
	timer2_init();
	timer3_init();
	timer4_init();
}
	
#include "tm4c123gh6pm.h"
int main(void)
{
	DisableInterrupts();
	init();
	EnableInterrupts();
	
	loop_fn = dummy_fn;
	/* Initial state */
	title_init();
	
	/* Game loop */
	while (1) {
		loop_fn();
	}
}