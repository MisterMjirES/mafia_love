#include "../../input/input.h"
#include "../../mgfx/mgfx.h"
#include "../../mgfx/mgfxt.h"
#include "../../level/level.h"
#include "../cutscene.h"
#include "../win.h"
#include "../../sound/sound.h"

extern uint8_t language;

#define DTABLE_LEN 11
static struct dialogue dtable[] = {
	{10,  0, 0, 0, 90, 0x00, "Don", {"I see, I was in the wrong. Who would have thought that you and a Russian car would end my rule?", "Ya veo, estaba equivocado. ?Quien hubiera pensado que tu y un coche ruso acabarian con mi gobierno?"}},
	{10,  0, 0, 0, 90, 0xEF, "Don", {"There is too much hate in the world, thank you for spreading love.", "Hay demasiado odio en el mundo, gracias por difundir el amor. Eres realmente asombroso."}},
	{10,  0, 0, 0, 90, 0xEF, "Don", {"You are truly amazing. I think it's time to turn over a new leaf.", "Creo que es hora de dar vuelta una nueva pagina."}},
	{ 3, 35, 0, 0, 90, 0xEF, "Yerraballer", {"What's up guys, I just got here.", "Que tal muchachos, acabo de llegar."}}, 
	{10,  0, 0, 0, 90, 0xEF, "Don", {"I'm going clean. No more of this mafia business.", "Yerraballer, Estoy saliendo limpio. No mas de este negocio de la mafia."}},
	{10,  0, 0, 0, 90, 0xEF, "Don", {"You know, there's a lab right next to us. I think I'm gonna go there and later become an embedded systems professor.", "Ya sabes, hay un laboratorio justo al lado de nosotros. Creo que ire alli y luego me convertire en profesor de sistemas integrados."}},
	{ 3, 35, 0, 0, 90, 0xEF, "Yerraballer", {"Dope, I think I'll do that too.", "Dope, creo que tambien lo hare."}},
	{ 3, 35, 0, 0, 90, 0xEF, "Yerraballer", {"I'm getting tired of b-ball anyways, I'm too good.", "Me estoy cansando del baloncesto de todos modos, soy demasiado bueno."}},
	{ 1, 35, 0, 0, 90, 0xEF, "McQueenski", {"Good job kiddo, you did it. You saved the world.", "Buen trabajo chico, lo hiciste. Tu salvaste el mundo."}},
	{ 1, 35, 0, 0, 90, 0xEF, "McQueenski", {"They say friendship is the greatest power, but I think love ain't too bad.", "Dicen que la amistad es el mayor poder, pero creo que el amor no es tan malo."}},
	{10,  0, 0, 0, 90, 0xEF, "Valvano", {"To The University of Texas at Austin!", "A la Universidad de Texas en Austin!"}}
};

#define INPUT_STALL \
	do { \
		input = input_get(); \
	} while (!(input.buttons & INPUT_LTRG)); \
	input_clear_button(INPUT_LTRG);
void cutscene_3_loop(void)
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
	win_init();
}