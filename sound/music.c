#include "music.h"
#include "dac.h"
#include "timer.h"
#include "edisk.h"
#include "tm4c123gh6pm.h"

#define SECTOR_SIZE 512

static uint8_t playing;

struct music {
	uint32_t sector_start;
	uint32_t length;
};

struct music music_current;
static volatile uint8_t music_flag;
#define MUSIC_RELOAD 0x01 /* Flag to signal reload */
#define MUSIC_READY  0x02 /* Flag to signal load finished */
#define MUSIC_START  0x04 /* Flag to signal reload music from the start */

const struct music music_table[] = {
	{    0, 3276800},
	{ 6400, 1872000},
	{10057, 1653760},
	{13287, 2544614},
	{18257, 3420588},
	{24938,  619203},
	{26148, 3168828},
	{32338,  874510}
};

/* For debug */
void PortF_Init(void){  unsigned long volatile delay;
  SYSCTL_RCGCGPIO_R |= 0x20; // activate port F
  delay = SYSCTL_RCGCGPIO_R;
  delay = SYSCTL_RCGCGPIO_R;
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTF_CR_R |= 0x1F;           // allow changes to PF4-0       
  GPIO_PORTF_DIR_R = 0x0E;     // make PF3-1 output (PF3-1 built-in LEDs),PF4,0 input
  GPIO_PORTF_PUR_R = 0x11;     // PF4,0 have pullup
  GPIO_PORTF_AFSEL_R = 0x00;   // disable alt funct on PF4-0
  GPIO_PORTF_DEN_R = 0x1F;     // enable digital I/O on PF4-0
  GPIO_PORTF_PCTL_R = 0x00000000;
  GPIO_PORTF_AMSEL_R = 0;      // disable analog functionality on PF
}

void music_init(void)
{
	dac1_init();
	timer1_init();
	PortF_Init();
}

#define BUFFER_SECTORS 1
#define BUFFER_LEN (SECTOR_SIZE * BUFFER_SECTORS)
#define BUFFER_MOD 0x1FF
uint8_t buffer_a[BUFFER_LEN];
uint8_t buffer_b[BUFFER_LEN];
uint32_t volatile index;
uint8_t volatile *buffer_p;

void music_play(uint8_t i)
{
	music_current = music_table[i];
	eDisk_Read(0, buffer_a, music_current.sector_start, BUFFER_SECTORS);
	eDisk_Read(0, buffer_b, music_current.sector_start + BUFFER_SECTORS , BUFFER_SECTORS);
	/*
	for (uint8_t i = 0; i < BUFFER_SECTORS; ++i) {
		eDisk_ReadBlock(buffer_a + SECTOR_SIZE * i, music_current.sector_start + i);
		eDisk_ReadBlock(buffer_b + SECTOR_SIZE * i, music_current.sector_start + BUFFER_SECTORS + i);
	}
	*/
	buffer_p = buffer_a;
	music_flag &= ~MUSIC_RELOAD;
	music_flag |=  MUSIC_READY;
	music_flag &= ~MUSIC_START;
	index = 0;
	//timer1_start(80000000/11025);
	timer1_start(80000000/12025); /* Magically sounds slightly better, idk what's happening */
	playing = 1;
}

void music_loop(void)
{
	if (!playing) return;
	uint8_t *read_buffer;
	if (buffer_p == buffer_a) read_buffer = buffer_b;
	else                      read_buffer = buffer_a;
	if (music_flag & MUSIC_RELOAD) {
		eDisk_Read(0, read_buffer, music_current.sector_start + index / BUFFER_LEN + 1, BUFFER_SECTORS);
		music_flag &= ~MUSIC_RELOAD;
		music_flag |=  MUSIC_READY;
	}
	if (music_flag & MUSIC_START) {
		eDisk_Read(0, read_buffer, music_current.sector_start, BUFFER_SECTORS);
		music_flag &= ~MUSIC_START;
		music_flag |=  MUSIC_READY;
	}
}

// flag is which flag to reload, reload or start
void swap_buffers(void)
{
	if (buffer_p == buffer_a) buffer_p = buffer_b;
	else                      buffer_p = buffer_a;
}

void music_stop(void)
{
	playing = 0;
	timer1_stop();
	dac1_out(0);
}

void Timer1A_Handler(void)
{
	TIMER1_ICR_R = TIMER_ICR_TATOCINT;
	if (index == music_current.length) {
		if (!(music_flag & MUSIC_READY)) return;
		swap_buffers();
		music_flag |= MUSIC_START;
		music_flag &= ~MUSIC_READY;
		index = 0;
	}
	if (!(index & BUFFER_MOD) && index) {
		if (!(music_flag & MUSIC_READY)) { GPIO_PORTF_DATA_R &= ~0x8; return;}
		GPIO_PORTF_DATA_R |= 0x8;
		swap_buffers();
		music_flag |= MUSIC_RELOAD;
		music_flag &= ~MUSIC_READY;
	}
	dac1_out(buffer_p[index & BUFFER_MOD]);
	++index;
}