/*
 * main.c
 *
 * Main function for the Sound
 */

#include "PLL.h"
#include "sfx.h"
#include "music.h"
#include "edisk.h"
#include "uart.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

static volatile int res;
void init(void)
{
	PLL_Init(Bus80MHz);
	res = eDisk_Init(0);  // initialize disk
	if (res) {
		__asm("NOP");
	}
	res = eDisk_Status(0);
	if (res) {
		__asm("NOP");
	}
	sfx_init();
	music_init();
	uart_init();
}
	
int main(void)
{
	DisableInterrupts();
	init();
	EnableInterrupts();
	
	//sfx_play(0);
	//music_play(0);
	
	/* Game loop */
	while (1) {
		music_loop();
	}
}

