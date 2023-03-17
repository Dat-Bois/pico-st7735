#include "functions-st7735.h"
#include "stdio.h"
#include "pico/stdlib.h"

void testlines(st7735 *st, uint16_t color) {
  gfx_fillScreen(st->gfx, ST77XX_BLACK);
  for (int16_t x=0; x < gfx_width(st->gfx); x+=6) {
    gfx_drawLine(st->gfx, 0, 0, x, gfx_height(st->gfx)-1, color);
  }
  for (int16_t y=0; y < gfx_height(st->gfx); y+=6) {
    gfx_drawLine(st->gfx, 0, 0, gfx_width(st->gfx)-1, y, color);
  }

  gfx_fillScreen(st->gfx, ST77XX_BLACK);
  for (int16_t x=0; x < gfx_width(st->gfx); x+=6) {
    gfx_drawLine(st->gfx, gfx_width(st->gfx)-1, 0, x, gfx_height(st->gfx)-1, color);
  }
  for (int16_t y=0; y < gfx_height(st->gfx); y+=6) {
    gfx_drawLine(st->gfx, gfx_width(st->gfx)-1, 0, 0, y, color);
  }

  gfx_fillScreen(st->gfx, ST77XX_BLACK);
  for (int16_t x=0; x < gfx_width(st->gfx); x+=6) {
    gfx_drawLine(st->gfx, 0, gfx_height(st->gfx)-1, x, 0, color);
  }
  for (int16_t y=0; y < gfx_height(st->gfx); y+=6) {
    gfx_drawLine(st->gfx, 0, gfx_height(st->gfx)-1, gfx_width(st->gfx)-1, y, color);
  }

  gfx_fillScreen(st->gfx, ST77XX_BLACK);
  for (int16_t x=0; x < gfx_width(st->gfx); x+=6) {
    gfx_drawLine(st->gfx, gfx_width(st->gfx)-1, gfx_height(st->gfx)-1, x, 0, color);
  }
  for (int16_t y=0; y < gfx_height(st->gfx); y+=6) {
    gfx_drawLine(st->gfx, gfx_width(st->gfx)-1, gfx_height(st->gfx)-1, 0, y, color);
  }
}

void testdrawtext(st7735 *st, char *text, uint16_t color) {
  gfx_setCursor(st->gfx, 0, 0);
  gfx_setTextColor(st->gfx, color);
  gfx_setTextWrap(st->gfx, true);
  gfx_print(st->gfx, text);
}

void testfastlines(st7735 *st, uint16_t color1, uint16_t color2) {
  gfx_fillScreen(st->gfx, ST77XX_BLACK);
  for (int16_t y=0; y < gfx_height(st->gfx); y+=5) {
    gfx_drawFastHLine(st->gfx, 0, y, gfx_width(st->gfx), color1);
  }
  for (int16_t x=0; x < gfx_width(st->gfx); x+=5) {
    gfx_drawFastVLine(st->gfx, x, 0, gfx_height(st->gfx), color2);
  }
}

void testdrawrects(st7735 *st, uint16_t color) {
  gfx_fillScreen(st->gfx, ST77XX_BLACK);
  for (int16_t x=0; x < gfx_width(st->gfx); x+=6) {
    gfx_drawRect(st->gfx, gfx_width(st->gfx)/2 -x/2, gfx_height(st->gfx)/2 -x/2 , x, x, color);
  }
}

void testfillrects(st7735 *st, uint16_t color1, uint16_t color2) {
  gfx_fillScreen(st->gfx, ST77XX_BLACK);
  for (int16_t x=gfx_width(st->gfx)-1; x > 6; x-=6) {
    gfx_fillRect(st->gfx, gfx_width(st->gfx)/2 -x/2, gfx_height(st->gfx)/2 -x/2 , x, x, color1);
    gfx_drawRect(st->gfx, gfx_width(st->gfx)/2 -x/2, gfx_height(st->gfx)/2 -x/2 , x, x, color2);
  }
}

void testfillcircles(st7735 *st, uint8_t radius, uint16_t color) {
  for (int16_t x=radius; x < gfx_width(st->gfx); x+=radius*2) {
    for (int16_t y=radius; y < gfx_height(st->gfx); y+=radius*2) {
      gfx_fillCircle(st->gfx, x, y, radius, color);
    }
  }
}

void testdrawcircles(st7735 *st, uint8_t radius, uint16_t color) {
  for (int16_t x=0; x < gfx_width(st->gfx)+radius; x+=radius*2) {
    for (int16_t y=0; y < gfx_height(st->gfx)+radius; y+=radius*2) {
      gfx_drawCircle(st->gfx, x, y, radius, color);
    }
  }
}

void testtriangles(st7735 *st) {
  gfx_fillScreen(st->gfx, ST77XX_BLACK);
  uint16_t color = 0xF800;
  int t;
  int w = gfx_width(st->gfx)/2;
  int x = gfx_height(st->gfx)-1;
  int y = 0;
  int z = gfx_width(st->gfx);
  for(t = 0 ; t <= 15; t++) {
    gfx_drawTriangle(st->gfx, w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
  }
}

void testroundrects(st7735 *st) {
  gfx_fillScreen(st->gfx, ST77XX_BLACK);
  uint16_t color = 100;
  int i;
  int t;
  for(t = 0 ; t <= 4; t+=1) {
    int x = 0;
    int y = 0;
    int w = gfx_width(st->gfx)-2;
    int h = gfx_height(st->gfx)-2;
    for(i = 0 ; i <= 16; i+=1) {
      gfx_drawRoundRect(st->gfx, x, y, w, h, 5, color);
      x+=2;
      y+=3;
      w-=4;
      h-=6;
      color+=1100;
    }
    color+=100;
  }
}

void tftPrintTest(st7735 *st) {
  gfx_setTextWrap(st->gfx, false);
  gfx_fillScreen(st->gfx, ST77XX_BLACK);
  gfx_setCursor(st->gfx, 0, 30);
  gfx_setTextColor(st->gfx, ST77XX_RED);
  gfx_setTextSize(st->gfx, 1);
  gfx_println(st->gfx, "Hello World!");
  gfx_setTextColor(st->gfx, ST77XX_YELLOW);
  gfx_setTextSize(st->gfx, 2);
  gfx_println(st->gfx, "Hello World!");
  gfx_setTextColor(st->gfx, ST77XX_GREEN);
  gfx_setTextSize(st->gfx, 3);
  gfx_println(st->gfx, "Hello World!");
  gfx_setTextColor(st->gfx, ST77XX_BLUE);
  gfx_setTextSize(st->gfx, 4);
  gfx_print_l(st->gfx, 1234.567);
  sleep_ms(1500);
  gfx_setCursor(st->gfx, 0, 0);
  gfx_fillScreen(st->gfx, ST77XX_BLACK);
  gfx_setTextColor(st->gfx, ST77XX_WHITE);
  gfx_setTextSize(st->gfx, 0);
  gfx_println(st->gfx, "Hello World!");
  gfx_setTextSize(st->gfx, 1);
  gfx_setTextColor(st->gfx, ST77XX_GREEN);
  gfx_print_d_digits(st->gfx, 3.1415926, 6);
  gfx_println(st->gfx, " Want pi?");
  gfx_println(st->gfx, " ");
  // gfx_setTextColor(st->gfx, ST77XX_WHITE);
  // gfx_println(st->gfx, "Program has been");
  // gfx_println(st->gfx, "running for: ");
  // gfx_setTextColor(st->gfx, ST77XX_MAGENTA);
  // gfx_print(st->gfx, millis() / 1000);
  // gfx_setTextColor(st->gfx, ST77XX_WHITE);
  // gfx_print(st->gfx, " seconds.");
}

// void mediabuttons() {
//   // play
//   gfx_fillScreen(ST77XX_BLACK);
//   gfx_fillRoundRect(25, 10, 78, 60, 8, ST77XX_WHITE);
//   gfx_fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_RED);
//   delay(500);
//   // pause
//   gfx_fillRoundRect(25, 90, 78, 60, 8, ST77XX_WHITE);
//   gfx_fillRoundRect(39, 98, 20, 45, 5, ST77XX_GREEN);
//   gfx_fillRoundRect(69, 98, 20, 45, 5, ST77XX_GREEN);
//   delay(500);
//   // play color
//   gfx_fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_BLUE);
//   delay(50);
//   // pause color
//   gfx_fillRoundRect(39, 98, 20, 45, 5, ST77XX_RED);
//   gfx_fillRoundRect(69, 98, 20, 45, 5, ST77XX_RED);
//   // play color
//   gfx_fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_GREEN);
// }