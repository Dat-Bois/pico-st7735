#include "functions-st7735.h"

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

// void testfastlines(uint16_t color1, uint16_t color2) {
//   gfx_fillScreen(ST77XX_BLACK);
//   for (int16_t y=0; y < gfx_height(); y+=5) {
//     gfx_drawFastHLine(0, y, gfx_width(), color1);
//   }
//   for (int16_t x=0; x < gfx_width(); x+=5) {
//     gfx_drawFastVLine(x, 0, gfx_height(), color2);
//   }
// }

// void testdrawrects(uint16_t color) {
//   gfx_fillScreen(ST77XX_BLACK);
//   for (int16_t x=0; x < gfx_width(); x+=6) {
//     gfx_drawRect(gfx_width()/2 -x/2, gfx_height()/2 -x/2 , x, x, color);
//   }
// }

// void testfillrects(uint16_t color1, uint16_t color2) {
//   gfx_fillScreen(ST77XX_BLACK);
//   for (int16_t x=gfx_width()-1; x > 6; x-=6) {
//     gfx_fillRect(gfx_width()/2 -x/2, gfx_height()/2 -x/2 , x, x, color1);
//     gfx_drawRect(gfx_width()/2 -x/2, gfx_height()/2 -x/2 , x, x, color2);
//   }
// }

// void testfillcircles(uint8_t radius, uint16_t color) {
//   for (int16_t x=radius; x < gfx_width(); x+=radius*2) {
//     for (int16_t y=radius; y < gfx_height(); y+=radius*2) {
//       gfx_fillCircle(x, y, radius, color);
//     }
//   }
// }

// void testdrawcircles(uint8_t radius, uint16_t color) {
//   for (int16_t x=0; x < gfx_width()+radius; x+=radius*2) {
//     for (int16_t y=0; y < gfx_height()+radius; y+=radius*2) {
//       gfx_drawCircle(x, y, radius, color);
//     }
//   }
// }

// void testtriangles() {
//   gfx_fillScreen(ST77XX_BLACK);
//   uint16_t color = 0xF800;
//   int t;
//   int w = gfx_width()/2;
//   int x = gfx_height()-1;
//   int y = 0;
//   int z = gfx_width();
//   for(t = 0 ; t <= 15; t++) {
//     gfx_drawTriangle(w, y, y, x, z, x, color);
//     x-=4;
//     y+=4;
//     z-=4;
//     color+=100;
//   }
// }

// void testroundrects() {
//   gfx_fillScreen(ST77XX_BLACK);
//   uint16_t color = 100;
//   int i;
//   int t;
//   for(t = 0 ; t <= 4; t+=1) {
//     int x = 0;
//     int y = 0;
//     int w = gfx_width()-2;
//     int h = gfx_height()-2;
//     for(i = 0 ; i <= 16; i+=1) {
//       gfx_drawRoundRect(x, y, w, h, 5, color);
//       x+=2;
//       y+=3;
//       w-=4;
//       h-=6;
//       color+=1100;
//     }
//     color+=100;
//   }
// }

// void tftPrintTest() {
//   gfx_setTextWrap(false);
//   gfx_fillScreen(ST77XX_BLACK);
//   gfx_setCursor(0, 30);
//   gfx_setTextColor(ST77XX_RED);
//   gfx_setTextSize(1);
//   gfx_println("Hello World!");
//   gfx_setTextColor(ST77XX_YELLOW);
//   gfx_setTextSize(2);
//   gfx_println("Hello World!");
//   gfx_setTextColor(ST77XX_GREEN);
//   gfx_setTextSize(3);
//   gfx_println("Hello World!");
//   gfx_setTextColor(ST77XX_BLUE);
//   gfx_setTextSize(4);
//   gfx_print(1234.567);
//   delay(1500);
//   gfx_setCursor(0, 0);
//   gfx_fillScreen(ST77XX_BLACK);
//   gfx_setTextColor(ST77XX_WHITE);
//   gfx_setTextSize(0);
//   gfx_println("Hello World!");
//   gfx_setTextSize(1);
//   gfx_setTextColor(ST77XX_GREEN);
//   gfx_print(p, 6);
//   gfx_println(" Want pi?");
//   gfx_println(" ");
//   gfx_print(8675309, HEX); // print 8,675,309 out in HEX!
//   gfx_println(" Print HEX!");
//   gfx_println(" ");
//   gfx_setTextColor(ST77XX_WHITE);
//   gfx_println("Sketch has been");
//   gfx_println("running for: ");
//   gfx_setTextColor(ST77XX_MAGENTA);
//   gfx_print(millis() / 1000);
//   gfx_setTextColor(ST77XX_WHITE);
//   gfx_print(" seconds.");
// }

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