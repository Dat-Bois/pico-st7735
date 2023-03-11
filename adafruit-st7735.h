#pragma once

#include <stddef.h>
#include <stdint.h>
#include "colors.h"
#include "adafruit-gfx.h"


// https://nachtimwald.com/2017/08/18/wrapping-c-objects-in-c/

#ifdef __cplusplus
extern "C" {
#endif

//struct st7735;
//typedef struct st7735 st7735;

typedef struct {
    adafruit_gfx *gfx;
    void *obj;
} st7735;

st7735 *oled_create(int8_t cs, int8_t dc, int8_t mosi, int8_t sclk, int8_t rst);

void oled_initB(st7735 *st);
void oled_initR(st7735 *st, uint8_t options);
void oled_setRotation(st7735 *st, uint8_t m);

#ifdef __cplusplus
}
#endif