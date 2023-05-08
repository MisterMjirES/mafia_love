#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

void timer0_init (void);
void timer1_init (void);
void timer0_start(uint32_t reload);
void timer1_start(uint32_t reload);
void timer0_stop (void);
void timer1_stop (void);

#endif