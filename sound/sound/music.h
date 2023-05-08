#ifndef MUSIC_H
#define MUSIC_H

#include <stdint.h>

void music_init(void);
void music_play(uint8_t i);
void music_loop(void);
void music_stop(void);

#endif