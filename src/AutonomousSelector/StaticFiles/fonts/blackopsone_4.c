
#include "pros/apix.h"

/***********************************************************************************
 * BlackOpsOne-Regular.ttf 4 px Font in U+0020 ( ) .. U+007e (~)  range with 4 bpp
***********************************************************************************/

/*Store the image of the letters (glyph)*/
static const uint8_t blackopsone_4_glyph_bitmap[] = 
{
  /*Unicode: U+0020 ( ) , Width: 2 */
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+0021 (!) , Width: 1 */
  0x00,  //. 
  0xa0,  //% 
  0xc0,  //@ 
  0x00,  //. 


  /*Unicode: U+0022 (") , Width: 2 */
  0x00,  //.. 
  0x88,  //%% 
  0x11,  //.. 
  0x00,  //.. 


  /*Unicode: U+0023 (#) , Width: 3 */
  0x00, 0x00,  //... 
  0x79, 0x10,  //+%. 
  0x89, 0x00,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0024 ($) , Width: 3 */
  0x05, 0x00,  //.+. 
  0x6e, 0x30,  //+@. 
  0x5b, 0x10,  //+%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0025 (%) , Width: 4 */
  0x02, 0x30,  //.... 
  0x59, 0x81,  //+%%. 
  0x05, 0xb3,  //.+%. 
  0x02, 0x00,  //.... 


  /*Unicode: U+0026 (&) , Width: 3 */
  0x00, 0x00,  //... 
  0x79, 0x00,  //+%. 
  0x9e, 0x10,  //%@. 
  0x00, 0x00,  //... 


  /*Unicode: U+0027 (') , Width: 1 */
  0x00,  //. 
  0x80,  //% 
  0x10,  //. 
  0x00,  //. 


  /*Unicode: U+0028 (() , Width: 2 */
  0x81,  //%. 
  0xa0,  //%. 
  0x61,  //+. 
  0x00,  //.. 


  /*Unicode: U+0029 ()) , Width: 2 */
  0x90,  //%. 
  0x81,  //%. 
  0x70,  //+. 
  0x00,  //.. 


  /*Unicode: U+002a (*) , Width: 2 */
  0x77,  //++ 
  0x56,  //++ 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+002b (+) , Width: 2 */
  0x00,  //.. 
  0x67,  //++ 
  0x13,  //.. 
  0x00,  //.. 


  /*Unicode: U+002c (,) , Width: 1 */
  0x00,  //. 
  0x00,  //. 
  0x50,  //+ 
  0x30,  //. 


  /*Unicode: U+002d (-) , Width: 2 */
  0x00,  //.. 
  0x53,  //+. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+002e (.) , Width: 1 */
  0x00,  //. 
  0x00,  //. 
  0x50,  //+ 
  0x00,  //. 


  /*Unicode: U+002f (/) , Width: 2 */
  0x50,  //+. 
  0x50,  //+. 
  0x50,  //+. 
  0x00,  //.. 


  /*Unicode: U+0030 (0) , Width: 3 */
  0x00, 0x00,  //... 
  0xaa, 0x00,  //%%. 
  0x9b, 0x00,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0031 (1) , Width: 2 */
  0x00,  //.. 
  0x92,  //%. 
  0x95,  //%+ 
  0x00,  //.. 


  /*Unicode: U+0032 (2) , Width: 2 */
  0x00,  //.. 
  0xc9,  //@% 
  0xb6,  //%+ 
  0x00,  //.. 


  /*Unicode: U+0033 (3) , Width: 3 */
  0x00, 0x00,  //... 
  0x6c, 0x00,  //+@. 
  0x9a, 0x00,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0034 (4) , Width: 2 */
  0x00,  //.. 
  0x4a,  //+% 
  0x9b,  //%% 
  0x00,  //.. 


  /*Unicode: U+0035 (5) , Width: 2 */
  0x00,  //.. 
  0xaf,  //%@ 
  0x7a,  //+% 
  0x00,  //.. 


  /*Unicode: U+0036 (6) , Width: 3 */
  0x00, 0x00,  //... 
  0xbe, 0x00,  //%@. 
  0xaa, 0x00,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0037 (7) , Width: 2 */
  0x00,  //.. 
  0xae,  //%@ 
  0x55,  //++ 
  0x00,  //.. 


  /*Unicode: U+0038 (8) , Width: 3 */
  0x00, 0x00,  //... 
  0xad, 0x00,  //%@. 
  0xaa, 0x00,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0039 (9) , Width: 3 */
  0x00, 0x00,  //... 
  0x7d, 0x00,  //+@. 
  0x6a, 0x00,  //+%. 
  0x00, 0x00,  //... 


  /*Unicode: U+003a (:) , Width: 1 */
  0x00,  //. 
  0x50,  //+ 
  0x50,  //+ 
  0x00,  //. 


  /*Unicode: U+003b (;) , Width: 1 */
  0x00,  //. 
  0x50,  //+ 
  0x50,  //+ 
  0x30,  //. 


  /*Unicode: U+003c (<) , Width: 2 */
  0x00,  //.. 
  0x24,  //.+ 
  0x34,  //.+ 
  0x00,  //.. 


  /*Unicode: U+003d (=) , Width: 2 */
  0x00,  //.. 
  0x55,  //++ 
  0x55,  //++ 
  0x00,  //.. 


  /*Unicode: U+003e (>) , Width: 2 */
  0x00,  //.. 
  0x42,  //+. 
  0x44,  //++ 
  0x00,  //.. 


  /*Unicode: U+003f (?) , Width: 2 */
  0x00,  //.. 
  0x89,  //%% 
  0x32,  //.. 
  0x00,  //.. 


  /*Unicode: U+0040 (@) , Width: 3 */
  0x00, 0x00,  //... 
  0x6a, 0x20,  //+%. 
  0x76, 0x00,  //++. 
  0x00, 0x00,  //... 


  /*Unicode: U+0041 (A) , Width: 3 */
  0x00, 0x00,  //... 
  0x58, 0x00,  //+%. 
  0xac, 0x00,  //%@. 
  0x00, 0x00,  //... 


  /*Unicode: U+0042 (B) , Width: 3 */
  0x00, 0x00,  //... 
  0xbe, 0x00,  //%@. 
  0xab, 0x00,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0043 (C) , Width: 2 */
  0x00,  //.. 
  0x9b,  //%% 
  0x99,  //%% 
  0x00,  //.. 


  /*Unicode: U+0044 (D) , Width: 3 */
  0x00, 0x00,  //... 
  0xab, 0x00,  //%%. 
  0xab, 0x00,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0045 (E) , Width: 2 */
  0x00,  //.. 
  0xca,  //@% 
  0xa9,  //%% 
  0x00,  //.. 


  /*Unicode: U+0046 (F) , Width: 2 */
  0x00,  //.. 
  0xc9,  //@% 
  0xa0,  //%. 
  0x00,  //.. 


  /*Unicode: U+0047 (G) , Width: 3 */
  0x00, 0x00,  //... 
  0x9f, 0x00,  //%@. 
  0xab, 0x00,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0048 (H) , Width: 3 */
  0x00, 0x00,  //... 
  0xac, 0x00,  //%@. 
  0xa9, 0x00,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0049 (I) , Width: 2 */
  0x00,  //.. 
  0xc1,  //@. 
  0xc1,  //@. 
  0x00,  //.. 


  /*Unicode: U+004a (J) , Width: 2 */
  0x00,  //.. 
  0x5c,  //+@ 
  0xb9,  //%% 
  0x00,  //.. 


  /*Unicode: U+004b (K) , Width: 2 */
  0x00,  //.. 
  0xa9,  //%% 
  0xba,  //%% 
  0x00,  //.. 


  /*Unicode: U+004c (L) , Width: 2 */
  0x00,  //.. 
  0xa0,  //%. 
  0xa9,  //%% 
  0x00,  //.. 


  /*Unicode: U+004d (M) , Width: 3 */
  0x00, 0x00,  //... 
  0xb7, 0x80,  //%+% 
  0xa9, 0x80,  //%%% 
  0x00, 0x00,  //... 


  /*Unicode: U+004e (N) , Width: 3 */
  0x00, 0x00,  //... 
  0xbb, 0x00,  //%%. 
  0x9c, 0x00,  //%@. 
  0x00, 0x00,  //... 


  /*Unicode: U+004f (O) , Width: 2 */
  0x00,  //.. 
  0xaa,  //%% 
  0xaa,  //%% 
  0x00,  //.. 


  /*Unicode: U+0050 (P) , Width: 3 */
  0x00, 0x00,  //... 
  0xab, 0x00,  //%%. 
  0xa8, 0x00,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0051 (Q) , Width: 2 */
  0x00,  //.. 
  0xaa,  //%% 
  0xaa,  //%% 
  0x04,  //.+ 


  /*Unicode: U+0052 (R) , Width: 3 */
  0x00, 0x00,  //... 
  0xab, 0x00,  //%%. 
  0xab, 0x00,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0053 (S) , Width: 2 */
  0x00,  //.. 
  0x8f,  //%@ 
  0x7a,  //+% 
  0x00,  //.. 


  /*Unicode: U+0054 (T) , Width: 2 */
  0x00,  //.. 
  0xd9,  //@% 
  0x63,  //+. 
  0x00,  //.. 


  /*Unicode: U+0055 (U) , Width: 3 */
  0x00, 0x00,  //... 
  0xa9, 0x00,  //%%. 
  0xaa, 0x00,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0056 (V) , Width: 2 */
  0x00,  //.. 
  0xa9,  //%% 
  0x76,  //++ 
  0x00,  //.. 


  /*Unicode: U+0057 (W) , Width: 3 */
  0x00, 0x00,  //... 
  0xac, 0x80,  //%@% 
  0x9b, 0x50,  //%%+ 
  0x00, 0x00,  //... 


  /*Unicode: U+0058 (X) , Width: 2 */
  0x00,  //.. 
  0x98,  //%% 
  0x89,  //%% 
  0x00,  //.. 


  /*Unicode: U+0059 (Y) , Width: 2 */
  0x00,  //.. 
  0x98,  //%% 
  0x64,  //++ 
  0x00,  //.. 


  /*Unicode: U+005a (Z) , Width: 2 */
  0x00,  //.. 
  0x99,  //%% 
  0xb7,  //%+ 
  0x00,  //.. 


  /*Unicode: U+005b ([) , Width: 2 */
  0x91,  //%. 
  0x90,  //%. 
  0x71,  //+. 
  0x00,  //.. 


  /*Unicode: U+005c (\) , Width: 2 */
  0x50,  //+. 
  0x50,  //+. 
  0x41,  //+. 
  0x00,  //.. 


  /*Unicode: U+005d (]) , Width: 2 */
  0xa0,  //%. 
  0x80,  //%. 
  0x80,  //%. 
  0x00,  //.. 


  /*Unicode: U+005e (^) , Width: 2 */
  0x00,  //.. 
  0x43,  //+. 
  0x66,  //++ 
  0x00,  //.. 


  /*Unicode: U+005f (_) , Width: 3 */
  0x00, 0x00,  //... 
  0x00, 0x00,  //... 
  0x00, 0x00,  //... 
  0x55, 0x00,  //++. 


  /*Unicode: U+0060 (`) , Width: 2 */
  0x20,  //.. 
  0x20,  //.. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+0061 (a) , Width: 2 */
  0x00,  //.. 
  0x5a,  //+% 
  0x8a,  //%% 
  0x00,  //.. 


  /*Unicode: U+0062 (b) , Width: 2 */
  0xa0,  //%. 
  0xaa,  //%% 
  0xaa,  //%% 
  0x00,  //.. 


  /*Unicode: U+0063 (c) , Width: 2 */
  0x00,  //.. 
  0x97,  //%+ 
  0x97,  //%+ 
  0x00,  //.. 


  /*Unicode: U+0064 (d) , Width: 2 */
  0x0a,  //.% 
  0xaa,  //%% 
  0xaa,  //%% 
  0x00,  //.. 


  /*Unicode: U+0065 (e) , Width: 2 */
  0x00,  //.. 
  0x99,  //%% 
  0x9b,  //%% 
  0x00,  //.. 


  /*Unicode: U+0066 (f) , Width: 2 */
  0xa2,  //%. 
  0xb2,  //%. 
  0xa0,  //%. 
  0x00,  //.. 


  /*Unicode: U+0067 (g) , Width: 2 */
  0x00,  //.. 
  0x9a,  //%% 
  0xaa,  //%% 
  0x39,  //.% 


  /*Unicode: U+0068 (h) , Width: 2 */
  0xa0,  //%. 
  0xaa,  //%% 
  0xaa,  //%% 
  0x00,  //.. 


  /*Unicode: U+0069 (i) , Width: 1 */
  0x50,  //+ 
  0xa0,  //% 
  0xa0,  //% 
  0x00,  //. 


  /*Unicode: U+006a (j) , Width: 1 */
  0x50,  //+ 
  0xa0,  //% 
  0xa0,  //% 
  0x90,  //% 


  /*Unicode: U+006b (k) , Width: 2 */
  0xa0,  //%. 
  0xa8,  //%% 
  0xb9,  //%% 
  0x00,  //.. 


  /*Unicode: U+006c (l) , Width: 2 */
  0xa0,  //%. 
  0xa0,  //%. 
  0xa0,  //%. 
  0x00,  //.. 


  /*Unicode: U+006d (m) , Width: 3 */
  0x00, 0x00,  //... 
  0xab, 0xa0,  //%%% 
  0xaa, 0xa0,  //%%% 
  0x00, 0x00,  //... 


  /*Unicode: U+006e (n) , Width: 2 */
  0x00,  //.. 
  0xaa,  //%% 
  0xaa,  //%% 
  0x00,  //.. 


  /*Unicode: U+006f (o) , Width: 2 */
  0x00,  //.. 
  0xaa,  //%% 
  0xaa,  //%% 
  0x00,  //.. 


  /*Unicode: U+0070 (p) , Width: 2 */
  0x00,  //.. 
  0xaa,  //%% 
  0xaa,  //%% 
  0xa0,  //%. 


  /*Unicode: U+0071 (q) , Width: 2 */
  0x00,  //.. 
  0x9a,  //%% 
  0xaa,  //%% 
  0x09,  //.% 


  /*Unicode: U+0072 (r) , Width: 2 */
  0x00,  //.. 
  0xaa,  //%% 
  0xa0,  //%. 
  0x00,  //.. 


  /*Unicode: U+0073 (s) , Width: 2 */
  0x00,  //.. 
  0x8d,  //%@ 
  0x69,  //+% 
  0x00,  //.. 


  /*Unicode: U+0074 (t) , Width: 2 */
  0x30,  //.. 
  0xb2,  //%. 
  0xa2,  //%. 
  0x00,  //.. 


  /*Unicode: U+0075 (u) , Width: 2 */
  0x00,  //.. 
  0xaa,  //%% 
  0xaa,  //%% 
  0x00,  //.. 


  /*Unicode: U+0076 (v) , Width: 2 */
  0x00,  //.. 
  0xa8,  //%% 
  0x83,  //%. 
  0x00,  //.. 


  /*Unicode: U+0077 (w) , Width: 3 */
  0x00, 0x00,  //... 
  0xab, 0x80,  //%%% 
  0x9b, 0x20,  //%%. 
  0x00, 0x00,  //... 


  /*Unicode: U+0078 (x) , Width: 2 */
  0x00,  //.. 
  0xa5,  //%+ 
  0xa6,  //%+ 
  0x00,  //.. 


  /*Unicode: U+0079 (y) , Width: 2 */
  0x00,  //.. 
  0x99,  //%% 
  0x66,  //++ 
  0x72,  //+. 


  /*Unicode: U+007a (z) , Width: 2 */
  0x00,  //.. 
  0x87,  //%+ 
  0xb5,  //%+ 
  0x00,  //.. 


  /*Unicode: U+007b ({) , Width: 2 */
  0x81,  //%. 
  0x90,  //%. 
  0x61,  //+. 
  0x00,  //.. 


  /*Unicode: U+007c (|) , Width: 1 */
  0x50,  //+ 
  0x50,  //+ 
  0x50,  //+ 
  0x00,  //. 


  /*Unicode: U+007d (}) , Width: 2 */
  0x90,  //%. 
  0x72,  //+. 
  0x70,  //+. 
  0x00,  //.. 


  /*Unicode: U+007e (~) , Width: 2 */
  0x00,  //.. 
  0x00,  //.. 
  0x15,  //.+ 
  0x00,  //.. 


};


/*Store the glyph descriptions*/
static const lv_font_glyph_dsc_t blackopsone_4_glyph_dsc[] = 
{
  {.w_px = 2,	.glyph_index = 0},	/*Unicode: U+0020 ( )*/
  {.w_px = 1,	.glyph_index = 4},	/*Unicode: U+0021 (!)*/
  {.w_px = 2,	.glyph_index = 8},	/*Unicode: U+0022 (")*/
  {.w_px = 3,	.glyph_index = 12},	/*Unicode: U+0023 (#)*/
  {.w_px = 3,	.glyph_index = 20},	/*Unicode: U+0024 ($)*/
  {.w_px = 4,	.glyph_index = 28},	/*Unicode: U+0025 (%)*/
  {.w_px = 3,	.glyph_index = 36},	/*Unicode: U+0026 (&)*/
  {.w_px = 1,	.glyph_index = 44},	/*Unicode: U+0027 (')*/
  {.w_px = 2,	.glyph_index = 48},	/*Unicode: U+0028 (()*/
  {.w_px = 2,	.glyph_index = 52},	/*Unicode: U+0029 ())*/
  {.w_px = 2,	.glyph_index = 56},	/*Unicode: U+002a (*)*/
  {.w_px = 2,	.glyph_index = 60},	/*Unicode: U+002b (+)*/
  {.w_px = 1,	.glyph_index = 64},	/*Unicode: U+002c (,)*/
  {.w_px = 2,	.glyph_index = 68},	/*Unicode: U+002d (-)*/
  {.w_px = 1,	.glyph_index = 72},	/*Unicode: U+002e (.)*/
  {.w_px = 2,	.glyph_index = 76},	/*Unicode: U+002f (/)*/
  {.w_px = 3,	.glyph_index = 80},	/*Unicode: U+0030 (0)*/
  {.w_px = 2,	.glyph_index = 88},	/*Unicode: U+0031 (1)*/
  {.w_px = 2,	.glyph_index = 92},	/*Unicode: U+0032 (2)*/
  {.w_px = 3,	.glyph_index = 96},	/*Unicode: U+0033 (3)*/
  {.w_px = 2,	.glyph_index = 104},	/*Unicode: U+0034 (4)*/
  {.w_px = 2,	.glyph_index = 108},	/*Unicode: U+0035 (5)*/
  {.w_px = 3,	.glyph_index = 112},	/*Unicode: U+0036 (6)*/
  {.w_px = 2,	.glyph_index = 120},	/*Unicode: U+0037 (7)*/
  {.w_px = 3,	.glyph_index = 124},	/*Unicode: U+0038 (8)*/
  {.w_px = 3,	.glyph_index = 132},	/*Unicode: U+0039 (9)*/
  {.w_px = 1,	.glyph_index = 140},	/*Unicode: U+003a (:)*/
  {.w_px = 1,	.glyph_index = 144},	/*Unicode: U+003b (;)*/
  {.w_px = 2,	.glyph_index = 148},	/*Unicode: U+003c (<)*/
  {.w_px = 2,	.glyph_index = 152},	/*Unicode: U+003d (=)*/
  {.w_px = 2,	.glyph_index = 156},	/*Unicode: U+003e (>)*/
  {.w_px = 2,	.glyph_index = 160},	/*Unicode: U+003f (?)*/
  {.w_px = 3,	.glyph_index = 164},	/*Unicode: U+0040 (@)*/
  {.w_px = 3,	.glyph_index = 172},	/*Unicode: U+0041 (A)*/
  {.w_px = 3,	.glyph_index = 180},	/*Unicode: U+0042 (B)*/
  {.w_px = 2,	.glyph_index = 188},	/*Unicode: U+0043 (C)*/
  {.w_px = 3,	.glyph_index = 192},	/*Unicode: U+0044 (D)*/
  {.w_px = 2,	.glyph_index = 200},	/*Unicode: U+0045 (E)*/
  {.w_px = 2,	.glyph_index = 204},	/*Unicode: U+0046 (F)*/
  {.w_px = 3,	.glyph_index = 208},	/*Unicode: U+0047 (G)*/
  {.w_px = 3,	.glyph_index = 216},	/*Unicode: U+0048 (H)*/
  {.w_px = 2,	.glyph_index = 224},	/*Unicode: U+0049 (I)*/
  {.w_px = 2,	.glyph_index = 228},	/*Unicode: U+004a (J)*/
  {.w_px = 2,	.glyph_index = 232},	/*Unicode: U+004b (K)*/
  {.w_px = 2,	.glyph_index = 236},	/*Unicode: U+004c (L)*/
  {.w_px = 3,	.glyph_index = 240},	/*Unicode: U+004d (M)*/
  {.w_px = 3,	.glyph_index = 248},	/*Unicode: U+004e (N)*/
  {.w_px = 2,	.glyph_index = 256},	/*Unicode: U+004f (O)*/
  {.w_px = 3,	.glyph_index = 260},	/*Unicode: U+0050 (P)*/
  {.w_px = 2,	.glyph_index = 268},	/*Unicode: U+0051 (Q)*/
  {.w_px = 3,	.glyph_index = 272},	/*Unicode: U+0052 (R)*/
  {.w_px = 2,	.glyph_index = 280},	/*Unicode: U+0053 (S)*/
  {.w_px = 2,	.glyph_index = 284},	/*Unicode: U+0054 (T)*/
  {.w_px = 3,	.glyph_index = 288},	/*Unicode: U+0055 (U)*/
  {.w_px = 2,	.glyph_index = 296},	/*Unicode: U+0056 (V)*/
  {.w_px = 3,	.glyph_index = 300},	/*Unicode: U+0057 (W)*/
  {.w_px = 2,	.glyph_index = 308},	/*Unicode: U+0058 (X)*/
  {.w_px = 2,	.glyph_index = 312},	/*Unicode: U+0059 (Y)*/
  {.w_px = 2,	.glyph_index = 316},	/*Unicode: U+005a (Z)*/
  {.w_px = 2,	.glyph_index = 320},	/*Unicode: U+005b ([)*/
  {.w_px = 2,	.glyph_index = 324},	/*Unicode: U+005c (\)*/
  {.w_px = 2,	.glyph_index = 328},	/*Unicode: U+005d (])*/
  {.w_px = 2,	.glyph_index = 332},	/*Unicode: U+005e (^)*/
  {.w_px = 3,	.glyph_index = 336},	/*Unicode: U+005f (_)*/
  {.w_px = 2,	.glyph_index = 344},	/*Unicode: U+0060 (`)*/
  {.w_px = 2,	.glyph_index = 348},	/*Unicode: U+0061 (a)*/
  {.w_px = 2,	.glyph_index = 352},	/*Unicode: U+0062 (b)*/
  {.w_px = 2,	.glyph_index = 356},	/*Unicode: U+0063 (c)*/
  {.w_px = 2,	.glyph_index = 360},	/*Unicode: U+0064 (d)*/
  {.w_px = 2,	.glyph_index = 364},	/*Unicode: U+0065 (e)*/
  {.w_px = 2,	.glyph_index = 368},	/*Unicode: U+0066 (f)*/
  {.w_px = 2,	.glyph_index = 372},	/*Unicode: U+0067 (g)*/
  {.w_px = 2,	.glyph_index = 376},	/*Unicode: U+0068 (h)*/
  {.w_px = 1,	.glyph_index = 380},	/*Unicode: U+0069 (i)*/
  {.w_px = 1,	.glyph_index = 384},	/*Unicode: U+006a (j)*/
  {.w_px = 2,	.glyph_index = 388},	/*Unicode: U+006b (k)*/
  {.w_px = 2,	.glyph_index = 392},	/*Unicode: U+006c (l)*/
  {.w_px = 3,	.glyph_index = 396},	/*Unicode: U+006d (m)*/
  {.w_px = 2,	.glyph_index = 404},	/*Unicode: U+006e (n)*/
  {.w_px = 2,	.glyph_index = 408},	/*Unicode: U+006f (o)*/
  {.w_px = 2,	.glyph_index = 412},	/*Unicode: U+0070 (p)*/
  {.w_px = 2,	.glyph_index = 416},	/*Unicode: U+0071 (q)*/
  {.w_px = 2,	.glyph_index = 420},	/*Unicode: U+0072 (r)*/
  {.w_px = 2,	.glyph_index = 424},	/*Unicode: U+0073 (s)*/
  {.w_px = 2,	.glyph_index = 428},	/*Unicode: U+0074 (t)*/
  {.w_px = 2,	.glyph_index = 432},	/*Unicode: U+0075 (u)*/
  {.w_px = 2,	.glyph_index = 436},	/*Unicode: U+0076 (v)*/
  {.w_px = 3,	.glyph_index = 440},	/*Unicode: U+0077 (w)*/
  {.w_px = 2,	.glyph_index = 448},	/*Unicode: U+0078 (x)*/
  {.w_px = 2,	.glyph_index = 452},	/*Unicode: U+0079 (y)*/
  {.w_px = 2,	.glyph_index = 456},	/*Unicode: U+007a (z)*/
  {.w_px = 2,	.glyph_index = 460},	/*Unicode: U+007b ({)*/
  {.w_px = 1,	.glyph_index = 464},	/*Unicode: U+007c (|)*/
  {.w_px = 2,	.glyph_index = 468},	/*Unicode: U+007d (})*/
  {.w_px = 2,	.glyph_index = 472},	/*Unicode: U+007e (~)*/
};

lv_font_t blackopsone_4 = 
{
    .unicode_first = 32,	/*First Unicode letter in this font*/
    .unicode_last = 126,	/*Last Unicode letter in this font*/
    .h_px = 4,				/*Font height in pixels*/
    .glyph_bitmap = blackopsone_4_glyph_bitmap,	/*Bitmap of glyphs*/
    .glyph_dsc = blackopsone_4_glyph_dsc,		/*Description of glyphs*/
    .glyph_cnt = 95,			/*Number of glyphs in the font*/
    .unicode_list = NULL,	/*Every character in the font from 'unicode_first' to 'unicode_last'*/
    .get_bitmap = lv_font_get_bitmap_continuous,	/*Function pointer to get glyph's bitmap*/
    .get_width = lv_font_get_width_continuous,	/*Function pointer to get glyph's width*/
    .bpp = 4,				/*Bit per pixel*/
    .monospace = 0,				/*Fix width (0: if not used)*/
    .next_page = NULL,		/*Pointer to a font extension*/
};
