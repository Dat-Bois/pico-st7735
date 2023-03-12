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

#ifdef __cplusplus
}
#endif