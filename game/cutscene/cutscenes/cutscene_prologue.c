#include "../../input/input.h"
#include "../../mgfx/mgfx.h"
#include "../../mgfx/mgfxt.h"
#include "../../level/level.h"
#include "../cutscene.h"
#include "../../sound/sound.h"

extern uint8_t language;

#define DTABLE_LEN 8
static struct dialogue dtable[] = {
	{1, 35, 0, 0, 90, 0x02, "McQueenski", {"McQueenski: Kachowski!", "McQueenski: "}},
	{1, 35, 0, 0, 90, 0xEF, "McQueenski", {"My name is Lightning McQueenski, I've heard you're the best of the best.", "Mi nombre es Lightning McQueenski, he oido que eres el mejor de los mejores."}},
	{1, 35, 0, 0, 90, 0xEF, "McQueenski", {"There are only a few of us fighting to bring love to the world that Don Valvano has brought upon us.", "Somos pocos los que luchamos por traer amor al mundo que don Valvano nos ha quitado."}},
	{1, 35, 0, 0, 90, 0xEF, "McQueenski", {"We need you to defeat his henchmen and put a stop to his reign.", "Necesitamos derrotar a sus secuaces y poner fin a su reinado."}},
	{1, 35, 0, 0, 90, 0xEF, "McQueenski", {"Let's go set up base and get some intel. Hop on!", "Vamos a configurar la base y obtener algo de informacion. !Subir!"}},
	{2, 35, 0, 0, 90, 0xEF, "Duolingo", {"Phew phew phew you think you could pass!", "Phew phew phew piensas que puedes pasar!"}},
	{1, 35, 0, 0, 90, 0xEF, "McQueenski", {"That's one of his most trusted henchmen!", "!Ese es uno de sus secuaces mas confiables!"}},
	{2, 35, 0, 0, 90, 0xEF, "Duolingo", {"MEN! Get rid of these ratas! You know how it goes. Spanish, or vanish.", "HOMBRES! Deshazte de estas rats! You know how it goes. Spanish, or vanish."}}
};

#define INPUT_STALL \
	do { \
		input = input_get(); \
	} while (!(input.buttons & INPUT_LTRG)); \
	input_clear_button(INPUT_LTRG);
void cutscene_prologue_loop(void)
{
  struct input input;
	
	for (uint8_t i = 0; i < DTABLE_LEN; ++i) {
		mgfx_draw_rect(0, 0, WIN_W, WIN_H, 0);
		mgfx_send();
		mgfxt_draw(0, 90, WIN_H, dtable[i].text[language], 2);
		mgfx_draw_sd(dtable[i].ix, dtable[i].iy, dtable[i].img);
		mgfx_send();
		if (dtable[i].sound != 0xEF) sound_play(dtable[i].sound);
		INPUT_STALL;
	}
	sound_play(0x04);
	/* Should be 1 */
	level_init(1, CUTSCENE_1);
}