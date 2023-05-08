#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

void timer0_init (void);
void timer1_init (void);
void timer2_init (void);
void timer3_init (void);
void timer4_init (void);
void timer0_start(uint32_t reload);
void timer1_start(uint32_t reload);
void timer2_start(uint32_t reload);
void timer3_start(uint32_t reload);
void timer4_start(uint32_t reload);
void timer0_stop (void);
void timer1_stop (void);
void timer2_stop (void);
void timer3_stop (void);
void timer4_stop (void);

#endif