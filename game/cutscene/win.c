#include "win.h"
#include "../mgfx/mgfx.h"
#include "../mgfx/mgfxt.h"
#include "../output/output.h"
#include "cutscene.h"
#include "../sound/sound.h"

void win_loop(void)
{	
	mgfx_draw_rect(0, 0, WIN_W, WIN_H, 0);
	mgfx_send();
	mgfx_draw_sd(0, 0, 9);
	mgfx_send();
		
	while(1);
}

extern void (*loop_fn)(void);
void win_init(void)
{
	loop_fn = win_loop;
	
	output_green(0);
  output_yellow(0);
  output_red(0);
	
	sound_play(0x03);
}