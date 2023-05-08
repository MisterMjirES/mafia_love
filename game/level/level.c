#include "level.h"
#include "../mgfx/mgfx.h"
#include "../mgfx/mgfxt.h"
#include "../raycast/raycast.h"
#include "level_inputs.h"
#include "../input/input.h"
#include "../cutscene/cutscene.h"
#include "levels.h"
#include "../output/output.h"
#include "../sound/sound.h"
#include "bullet.h"
#include "../timer.h"
#include "../tm4c123gh6pm.h"

#define PLAYER_HP 100
#define MAX_TIME  120000
#define TIMER_RELOAD 80000

const struct level world_table[] = {
	{circle,  16, circle_enemies,   1, ( 8 << 8) + 0x80, ( 8 << 8) + 0x80, 0},
	{level_1, 16, level_1_enemies,  5, ( 3 << 8) + 0x80, ( 8 << 8) + 0x80, 0},
	{level_2, 16, level_2_enemies, 11, (14 << 8) + 0x80, (14 << 8) + 0x80, 32768},
	{boss,    16, boss_enemies,     1, ( 6 << 8) + 0x80, ( 8 << 8) + 0x80, 0},
};

/* Level state info */
uint8_t       current_world;
uint16_t      x;
uint16_t      y;
uint16_t      phi;
uint16_t      hp;
uint32_t      time;
uint8_t       next_cutscene;
/* External code uses sentinel, level module uses counts */
struct sprite enemies[MAX_ENEMIES + 1];
uint8_t       enemy_count;
struct sprite player_bullets[MAX_PLAYER_BULLETS + 1];
uint8_t       player_bullet_count;
struct sprite enemy_bullets[MAX_ENEMY_BULLETS + 1];
uint8_t       enemy_bullet_count;
/* Output stuff */
uint16_t output_ammo;
uint16_t output_ammo_step;
uint16_t output_hp;
uint16_t output_hp_step;
uint16_t output_ehp;
uint16_t output_ehp_step;
static uint16_t ehp_total;


#define GREEN 17
#define YELLOW 34
#define RED 36
#define DRAW_HP_OFFSET 16
static void draw_hp(void)
{
	uint8_t color;
	
	mgfx_draw_rect(0, 0, 11, WIN_H, 19);
	mgfxt_draw(2 + DRAW_HP_OFFSET, 2, 160, "HP", 2);
	
	color = GREEN;
	if (hp < 50) color = YELLOW;
	if (hp < 25) color = RED;
	
	mgfx_draw_rect(2, WIN_YMAX - 2 - 16 - DRAW_HP_OFFSET - hp, 7, hp, color);
}

/*
 * level_draw
 *
 * @desc
 *   Draws the level
 */
#include "big_level.h"
void level_draw(uint16_t x, uint16_t y, uint16_t phi)
{
	mgfx_draw_rect(0,          0, WIN_W >> 1, WIN_H, 26);
	mgfx_draw_rect(WIN_W >> 1, 0, WIN_W >> 1, WIN_H, 17);
	
	rc_draw(x, y, phi, world_table[current_world].map, world_table[current_world].map_w,
		enemies, player_bullets, enemy_bullets);
	
	draw_hp();
	
	mgfx_send();	
}

/*
 * level_loop
 *
 * @desc
 *   Level loop
 */
void level_loop(void)
{
	struct input input;
	
	/* Pause */
	if (input_paused()) {
		mgfx_draw_rect(0, 0, WIN_W, WIN_H, 0);
		mgfx_send();
		mgfx_draw_sd(0, 0, 6);
		mgfx_send();
		while (input_paused()) {
			input = input_get();
			if (input.buttons & INPUT_LTRG) {
				cutscene_init(next_cutscene);
				break;
			}
		}
	}
	
	/* Move player */
	level_inputs(&input, &x, &y, &phi, world_table[current_world].map, world_table[current_world].map_w);
	
	update_bullets(&input);
		
	level_draw(x, y, phi);
}

/*
 * level_init
 *
 * @desc
 *   Switches the state to level,
 *   and initializes the level
 */
static void level_init_player(void)
{
	x = world_table[current_world].spawn_x;
	y = world_table[current_world].spawn_y;
	phi = world_table[current_world].spawn_phi;
	hp = PLAYER_HP;
}

static void level_init_sprites(void)
{
	enemy_count = 0;
	
	ehp_total = 0;
	for (uint8_t i = 0; i < world_table[current_world].enemy_count; ++i) {
		enemies[i].id = world_table[current_world].enemies[i].id;
		enemies[i].x = world_table[current_world].enemies[i].x;
		enemies[i].y = world_table[current_world].enemies[i].y;
		enemies[i].hp = world_table[current_world].enemies[i].hp;
		enemies[i].data = 1;
		++enemy_count;
		ehp_total += enemies[i].hp;
	}
	
	enemies[world_table[current_world].enemy_count].id = 0;
	
	player_bullets[0].id = 0;
	player_bullet_count = 0;
	enemy_bullets[0].id = 0;
	enemy_bullet_count = 0;
}

static void level_init_outputs(void)
{
	output_green((output_hp = 2499));
  output_yellow((output_ammo = 2499));
  output_red((output_ehp = 2499));
	
	output_ammo_step = 2500 / MAX_PLAYER_BULLETS;
	output_hp_step = 2500 / PLAYER_HP;
	output_ehp_step = (2500 * 10 / ehp_total) / 10;
}

extern void (*loop_fn)(void);
void level_init(uint8_t level, uint8_t nc)
{
	/* Figure out what world it is */
	current_world = level;
	level_init_player();
	level_init_sprites();
	level_init_outputs();
	next_cutscene = nc;
	/* Set loop fn */
	loop_fn = level_loop;
	
	time = MAX_TIME;
	timer0_start(TIMER_RELOAD);	
}

void Timer0A_Handler(void)
{
	TIMER0_ICR_R = TIMER_ICR_TATOCINT;
	if (time) {
		--time;
	}
	else {
		timer0_stop();
	}
}