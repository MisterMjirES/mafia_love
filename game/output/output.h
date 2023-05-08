#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdint.h>

void output_init  (void);
void output_green (uint32_t cmp);
void output_yellow(uint32_t cmp);
void output_red   (uint32_t cmp);

#endif