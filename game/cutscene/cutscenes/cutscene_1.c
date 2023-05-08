#include "../../input/input.h"
#include "../../mgfx/mgfx.h"
#include "../../mgfx/mgfxt.h"
#include "../../level/level.h"
#include "../cutscene.h"
#include "../../sound/sound.h"

extern uint8_t language;

#define DTABLE_LEN 11
static struct dialogue dtable[] = {
	{2, 35, 0, 0, 90, 0x07, "Duolingo", {"You have proven your proficiency in another language, the language of love.", "Has probado tu competencia en otro idioma, el idioma del amor."}},
	{2, 35, 0, 0, 90, 0xEF, "Duolingo", {"One I don't comprehend, and I yield to you.", "Uno que no comprendo, y te cedo."}},
	{2, 35, 0, 0, 90, 0xEF, "Duolingo", {"Go further north and you will find Don's right-hand man.", "Ve mas al norte y encontraras a la mano derecha de Don."}},
	{2, 35, 0, 0, 90, 0xEF, "Duolingo", {"Take it as you might but you brought me love, once again!", "Tomalo como puedas, pero me trajiste amor, una vez mas."}},
	{1, 35, 0, 0, 90, 0xEF, "McQueenski", {"You heard the bird, let's go!", "Tu escuchaste el pajaro, !vamonos!"}},
	{1, 35, 0, 0, 90, 0xEF, "McQueenski", {"We have to get rid of the Don's right-hand man if we want a chance to stop his iron rule.", "Tenemos que deshacernos la mano derecha del Don si queremos tener la oportunidad de detener su gobierno de hierro."}},
	{3, 35, 0, 0, 90, 0xEF, "Yerraballer", {"Yerraballer: So you took down the bird? You seem like no pushover.", "?Asi que derribaste al pajaro? Parece que no eres facil de convencer"}},
	{3, 35, 0, 0, 90, 0xEF, "Yerraballer", {"However", "Sin embargo"}},
	{3, 35, 0, 0, 90, 0xEF, "Yerraballer", {"I am a professional basketball player.", "Soy un jugador de baloncesto profesional"}},
	{3, 35, 0, 0, 90, 0xEF, "Yerraballer", {"Twenty-seven time NBA champ.", "Veintisiete veces campeon de la NBA."}},
	{3, 35, 0, 0, 90, 0xEF, "Yerraballer", {"You won't be getting to the Don, the ball's always in my court.", "No llegaras al Don, la pelota siempre esta en mi corte."}}
};

#define INPUT_STALL \
	do { \
		input = input_get(); \
	} while (!(input.buttons & INPUT_LTRG)); \
	input_clear_button(INPUT_LTRG);
void cutscene_1_loop(void)
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
	sound_play(0x06);
	level_init(2, CUTSCENE_2);
}