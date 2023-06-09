#include "level.h"

const uint8_t circle[] = {
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const struct sprite circle_enemies[] = {
	{(10 << 8) + 0x80, (8 << 8) + 0x80, 1, 30, 0, 0, 0, 0},
	{(10 << 8) + 0x80, (10 << 8) + 0x80, 1, 30, 0, 0, 0, 0}
};

const uint8_t level_1[] = {
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1,
 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1,
 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1,
 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1,
 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1,
 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1,
 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1,
 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1,
 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1,
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const uint8_t level_2[] = {
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 1,
 1, 0, 3, 0, 0, 5, 0, 0, 0, 0, 5, 0, 3, 3, 0, 1,
 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 1,
 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 1,
 1, 0, 0, 0, 0, 5, 5, 0, 0, 5, 5, 0, 0, 0, 0, 1,
 1, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 1,
 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1,
 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1,
 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
 1, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1,
 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

const uint8_t boss[] = {
 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6,
 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6,
 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6,
 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6,
 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6,
 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6,
 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6,
 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6,
 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6,
 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6,
 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6,
 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6,
 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
};


const struct sprite level_1_enemies[] = {
	{(4 << 8) + 0x80, (1 << 8) + 0x80, 4, 10, 0, 0, 0, 0},
	{(7 << 8) + 0x80, (4 << 8) + 0x80, 4, 10, 0, 0, 0, 0},
	{(4 << 8) + 0x80, (7 << 8) + 0x80, 4, 10, 0, 0, 0, 0},
	{(2 << 8) + 0x80, (8 << 8) + 0x80, 4, 10, 0, 0, 0, 0},
	{(10 << 8) + 0x80, (9<< 8) + 0x80, 4, 10, 0, 0, 0, 0}
};

const struct sprite level_2_enemies[] = {
	{(1 << 8) + 0x80, (1 << 8) + 0x80, 8, 10, 0, 0, 0, 0},
	{(12 << 8) + 0x80, (1 << 8) + 0x80, 4, 10, 0, 0, 0, 0},
	{(10<< 8) + 0x80, (11 << 8) + 0x80, 8, 10, 0, 0, 0, 0},
	{(12 << 8) + 0x80, (13 << 8) + 0x80, 4, 10, 0, 0, 0, 0},
	{(14 << 8) + 0x80, (5 << 8) + 0x80, 8, 10, 0, 0, 0, 0},
	{(7 << 8) + 0x80, (13 << 8) + 0x80, 4, 10, 0, 0, 0, 0},
	{(11 << 8) + 0x80, (14 << 8) + 0x80, 4, 10, 0, 0, 0, 0},
	{(3 << 8) + 0x80, (11 << 8) + 0x80, 8, 10, 0, 0, 0, 0},
	{(2 << 8) + 0x80, (13 << 8) + 0x80, 4, 10, 0, 0, 0, 0},
	{(9 << 8) + 0x80, (3 << 8) + 0x80, 1, 30, 0, 0, 0, 0},
	{(8 << 8) + 0x00, (6 << 8) + 0x80, 11, 100, 0, 0, 0, 0}
};

const struct sprite boss_enemies[] = {
	{(10 << 8) + 0x80, (8 << 8) + 0x80, 6, 200, 0, 0, 0, 0},
};