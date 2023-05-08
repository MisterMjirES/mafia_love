#include "mgfx.h"
#include "mgfx_st7735.h"
#include "edisk.h"

/* Color palette (Color indices lookup) [0 is transparent/don't draw] */
static const uint16_t mgfx_palette[256] = {
	/* Basic colors */
	0x0000, 0x0000, 0xffff, 0xf800, 0x07e0, 0x001f, 0xffff, 0xffff,
	/* Palette */
	0x4167, 0x59a8, 0x7a29, 0xa2ca, 0xbbcb, 0xed0c, 0xf674, 0xb6a7,
	0x7546, 0x3bc8, 0x3aca, 0x3165, 0x5a8a, 0x7b8e, 0xa491, 0xce37,
	0xdfbe, 0x8f5e, 0x2e7b, 0x3bd5, 0x3a2f, 0x3989, 0x520c, 0x8a31,
	0xcb12, 0xfd76, 0xf5a3, 0xf3e3, 0xe245, 0xa9c7, 0x8392, 0x4aad,
	/* Darker palette */
	0x20a3, 0x28c4, 0x3904, 0x5165, 0x59e5, 0x7286, 0x7b2a, 0x5b43,
	0x3aa3, 0x19e4, 0x1965, 0x18a2, 0x2945, 0x39c7, 0x5248, 0x630b,
	0x6bcf, 0x43af, 0x132d, 0x19ea, 0x1907, 0x18c4, 0x2906, 0x4127,
	0x6189, 0x7aab, 0x7ac1, 0x79e1, 0x7122, 0x50e3, 0x41c9, 0x2146, 
};

/* The color index buffer */
#define CIB_LEN (WIN_W * WIN_H)
volatile uint8_t mgfx_cib[CIB_LEN];

/*
 * mgfx_init
 *
 * @desc
 *   Initializes everything needed for
 *   graphics to run
 */
void mgfx_init(void)
{
	eDisk_Init(0);
	mgfx__init();
}

/*
 * mgfx_send
 *
 * @desc
 *   Sends the framebuffer to the
 *   screen
 */
void mgfx_send(void)
{
	mgfx__write_command(ST7735_CASET);
	mgfx__write_data(0);
	mgfx__write_data(0);
	mgfx__write_data(0);
	mgfx__write_data(WIN_XMAX);
	
	mgfx__write_command(ST7735_RASET);
	mgfx__write_data(0);
	mgfx__write_data(0);
	mgfx__write_data(0);
	mgfx__write_data(WIN_YMAX);
	
	mgfx__write_command(ST7735_RAMWR);
	
	for (uint32_t i = 0; i < CIB_LEN; ++i) {
		mgfx__write_data((uint8_t) (mgfx_palette[mgfx_cib[i]] >> 8));
		mgfx__write_data((uint8_t) mgfx_palette[mgfx_cib[i]]);
	}
	
	mgfx__deselect();
}

/*
 * draw_pixel
 *
 * @desc
 *   Draws a single pixel
 *   (no transparency)
 * @param x
 *   x coordinate of the pixel (0 - WIN_XMAX)
 * @param y
 *   y coordinate of the pixel (0 - WIN_YMAX)
 * @param color_index
 *   Index of the color on the palette
 */
void mgfx_draw_pixel(uint8_t x, uint8_t y, uint8_t color_index)
{
	mgfx_cib[y * WIN_W + x] = color_index;
}

/*
 * draw_rect
 *
 * @desc
 *   Draws a filled in rectangle of a single color
 *   (no transparency)
 * @param x
 *   x coordinate of the top left (0 - WIN_XMAX)
 * @param y
 *   y coordinate of the top left (0 - WIN_YMAX)
 * @param w
 *   Width of the rectangle
 * @param h
 *   Height of the rectangle
 * @param color_index
 *   Index of the color on the palette
 */
void mgfx_draw_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color_index)
{
	if (x + (w - 1) > WIN_XMAX) w = WIN_XMAX - x + 1;
	if (y + (h - 1) > WIN_YMAX) h = WIN_YMAX - y + 1;
	
	for (uint8_t row = 0; row < h; ++row) {
		for (uint8_t col = 0; col < w; ++col) {
			mgfx_cib[(y + row) * WIN_W + (x + col)] = color_index;
		}
	}
}

/*
 * draw_array
 *
 * @desc
 *   Draws an array
 * @param x
 *   x coordinate of the top left (0 - WIN_XMAX)
 * @param y
 *   y coordinate of the top left (0 - WIN_YMAX)
 * @param w
 *   Width of the array (columns)
 * @param h
 *   Height of the array (rows)
 * @param array
 *   Array of color indices
 */
void mgfx_draw_array(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const uint8_t *array)
{
	uint32_t i = 0;
	for (uint8_t iy = y; iy < y + h; ++iy) {
		if (iy > WIN_YMAX) break;
		for (uint8_t ix = x; ix < x + w; ++ix) {
			if (ix > WIN_XMAX) {
				i += w;
				i -= WIN_W - x;
				break;
			}
			uint8_t color_index;
			color_index = array[i++];
			if (color_index) mgfx_cib[iy * WIN_W + ix] = color_index;
		}
	}
}

/*
 * draw_array
 *
 * @desc
 *   Draws an image from the SD card
 *   The x and y coordinates will get rotated
*    by the function
 * @param x
 *   x coordinate of the top left (0 - WIN_XMAX)
 * @param y
 *   y coordinate of the top left (0 - WIN_YMAX)
 * @param w
 *   Width of the array (columns)
 * @param h
 *   Height of the array (rows)
 * @param array
 *   Array of color indices
 */
struct img {
	uint32_t sector_start;
	uint8_t w;
	uint8_t h;
};
const struct img img_table[] = {
	{  0, 160, 128}, /*  0 Title */
	{ 40,  90,  90}, /*  1 McQueenski */
	{ 56,  90,  90}, /*  2 Duolingo */
	{ 72,  90,  90}, /*  3 Yerraballer */
	{ 88,  90,  90}, /*  4 Don */
	{104,  90,  90}, /*  5 Don sans */
	{120, 160, 128}, /*  6 Pause */
	{160, 160, 128}, /*  7 Lose 1 */
	{200, 160, 128}, /*  8 Lose 2 */
	{240, 160, 128}, /*  9 Win */
	{280, 160,  90}  /* 10 Valvano */
};
static uint8_t buffer[512];
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void mgfx_draw_sd(int16_t x, int16_t y, uint32_t i)
{
	int16_t sy = WIN_YMAX - x;
	x = y;
	y = sy;
	uint16_t w = img_table[i].w;
	
	DisableInterrupts();
	
	eDisk_SSI();

	for (uint32_t idx = 0, remaining = w * img_table[i].h; remaining > 0; --remaining, ++idx) {
		if ((idx & 0x1FF) == 0) {
			eDisk_ReadBlock(buffer, img_table[i].sector_start + (idx >> 9));
		}
		mgfx_cib[y * WIN_W + x] = buffer[idx & 0x1FF];
		--y;
		if (y < sy - w + 1) {
			y = sy;
			++x;
		}
	}
	
	mgfx__SSI();
	
	EnableInterrupts();
}