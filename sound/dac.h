#ifndef DAC_H
#define DAC_H

#include <stdint.h>

void dac2_init(void);
void dac1_init(void);
void dac1_out(uint32_t data);
void dac2_out(uint32_t data);

#endif