#include "cutscene.h"
#include "../mgfx/mgfx.h"
#include "../mgfx/mgfxt.h"
#include "../input/input.h"
#include "../level/level.h"
#include "../sound/sound.h"

void cutscene_prologue_loop(void);
void cutscene_1_loop(void);
void cutscene_2_loop(void);
void cutscene_3_loop(void);

void (*cutscene_table[])(void) = {
	cutscene_prologue_loop,
	cutscene_1_loop,
	cutscene_2_loop,
	cutscene_3_loop
};

void cutscene_loop(void)
{
	/* Unused function */
	struct input input;
	
	mgfx_draw_rect(0, 0, WIN_W, WIN_H, 0);
	mgfx_send();
	mgfxt_draw(54, WIN_XMAX - 16, WIN_H - 2, "Kachow ;)", 3);
	mgfx_draw_sd(32, 0, 0);
	mgfx_send();
		
	while (!input_paused());
	input_clear_pause();
}

/*
 * cutscene_init
 *
 * @desc
 *   Switches the state to cutscene,
 *   and initializes the cutscene
 */
extern void (*loop_fn)(void);
void cutscene_init(uint8_t cutscene)
{
	loop_fn = cutscene_table[cutscene];
	
	sound_play(0x05);
}