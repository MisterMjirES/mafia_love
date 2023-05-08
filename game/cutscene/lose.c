#include "lose.h"
#include "../mgfx/mgfx.h"
#include "../mgfx/mgfxt.h"
#include "../output/output.h"
#include "../input/input.h"
#include "../level/level.h"
#include "../sound/sound.h"

static uint8_t l;
static uint8_t c;

static uint32_t tick;

void lose_loop(void)
{
	struct input input;
	
	mgfx_draw_rect(0, 0, WIN_W, WIN_H, 0);
	mgfx_send();
	mgfx_draw_sd(0, 0, 7);
	mgfxt_draw(0, 96, 160, "You lost, you got ratio'ed, but love always prevails. Shoot to try again", 2);
	mgfx_send();
	
	do {
		input = input_get();
	} while (!(input.buttons & INPUT_LTRG));
	input_clear_button(INPUT_LTRG);
	if (l == 3) sound_play(0x01);
	if (l == 2) sound_play(0x06);
	else sound_play(0x04);
	level_init(l, c);
}

extern void (*loop_fn)(void);
void lose_init(uint8_t level, uint8_t cutscene)
{
	loop_fn = lose_loop;
	
	l = level;
	c = cutscene;
	
	sound_play(0x00);
	
	output_green(0);
  output_yellow(0);
  output_red(0);
}