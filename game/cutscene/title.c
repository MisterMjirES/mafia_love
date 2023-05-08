#include "title.h"
#include "../mgfx/mgfx.h"
#include "../mgfx/mgfxt.h"
#include "../output/output.h"
#include "../input/input.h"
#include "cutscene.h"
#include "../sound/sound.h"

uint8_t language;

void title_loop(void)
{
	struct input input;
	
	mgfx_draw_rect(0, 0, WIN_W, WIN_H, 0);
	mgfx_send();
	mgfx_draw_sd(0, 0, 0);
	mgfx_send();
		
	do {
		input = input_get();
	} while (!(input.buttons & (INPUT_LTRG | INPUT_RTRG)));
	if (input.buttons & INPUT_RTRG) {
		language = 1;
	}
	input_clear_button(INPUT_LTRG | INPUT_RTRG);
	cutscene_init(CUTSCENE_PROLOGUE);
}

extern void (*loop_fn)(void);
void title_init(void)
{
	loop_fn = title_loop;
	
	sound_play(0x05);
	
	output_green(0);
  output_yellow(0);
  output_red(0);
}