#include <stddef.h>
#include <stdint.h>
#include "adafruit-st7735.h"
#include <adafruit-gfx.h>

#ifdef __cplusplus
extern "C" {
#endif

// typedef struct {
//     adafruit_gfx *gfx;
//     void *obj;
// } st7735;

void testlines(st7735 *st, uint16_t color);
void testdrawtext(st7735 *st, char *text, uint16_t color);
void testfastlines(st7735 *st, uint16_t color1, uint16_t color2);
void testdrawrects(st7735 *st, uint16_t color);
void testfillrects(st7735 *st, uint16_t color1, uint16_t color2);
void testfillcircles(st7735 *st, uint8_t radius, uint16_t color);
void testdrawcircles(st7735 *st, uint8_t radius, uint16_t color);
void testtriangles(st7735 *st);
void testroundrects(st7735 *st);
void tftPrintTest(st7735 *st);
void printData(st7735 *st, double battery);

#ifdef __cplusplus
}
#endif