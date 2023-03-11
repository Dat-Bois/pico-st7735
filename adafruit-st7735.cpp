//--------

#include "adafruit-st7735.h"
#include "Adafruit_ST7735.h"


static inline Adafruit_ST7735 *get_obj(st7735 *st) { return (static_cast<Adafruit_ST7735 *>(st->obj)); }

static st7735 *create(Adafruit_ST7735 *lib) {
    st7735 *st = (st7735 *)malloc(sizeof(st7735));
    st->gfx = adafruit_gfx_create(lib);
    st->obj = lib;
    return st;
}

st7735 *oled_create(int8_t cs, int8_t dc, int8_t mosi, int8_t sclk, int8_t rst) {
    Adafruit_ST7735 *lib = new Adafruit_ST7735(cs, dc, mosi, sclk, rst);
    return create(lib);
}

void oled_initB(st7735 *st) {
    get_obj(st)->initB();
}
void oled_initR(st7735 *st, uint8_t options) {
    get_obj(st)->initR(options);
}
void oled_setRotation(st7735 *st, uint8_t m) {
    get_obj(st)->setRotation(m);
}