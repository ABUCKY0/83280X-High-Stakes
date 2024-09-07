
#include "pros/apix.h"

/***********************************************************************************
 * BlackOpsOne-Regular.ttf 6 px Font in U+0020 ( ) .. U+007e (~)  range with 4
 *bpp
 ***********************************************************************************/

/*Store the image of the letters (glyph)*/
static const uint8_t blackopsone_6_glyph_bitmap[] = {
    /*Unicode: U+0020 ( ) , Width: 2 */
    0x00, //..
    0x00, //..
    0x00, //..
    0x00, //..
    0x00, //..
    0x00, //..

    /*Unicode: U+0021 (!) , Width: 2 */
    0x00, //..
    0xa7, //%+
    0x97, //%+
    0x85, //%+
    0x75, //++
    0x00, //..

    /*Unicode: U+0022 (") , Width: 3 */
    0x00, 0x00, //...
    0x88, 0xd0, //%%@
    0x65, 0xa0, //++%
    0x00, 0x00, //...
    0x00, 0x00, //...
    0x00, 0x00, //...

    /*Unicode: U+0023 (#) , Width: 4 */
    0x00, 0x00, //....
    0x09, 0x71, //.%+.
    0x4e, 0xc7, //+@@+
    0x6e, 0xb6, //+@%+
    0x09, 0x90, //.%%.
    0x00, 0x00, //....

    /*Unicode: U+0024 ($) , Width: 4 */
    0x00, 0x00, //....
    0x3c, 0xb4, //.@%+
    0x6a, 0x00, //+%..
    0x2c, 0xc5, //.@@+
    0x1b, 0xb6, //.%%+
    0x00, 0x00, //....

    /*Unicode: U+0025 (%) , Width: 6 */
    0x00, 0x00, 0x00, //......
    0x7a, 0x69, 0x00, //+%+%..
    0x98, 0xb6, 0x00, //%%%+..
    0x58, 0xc7, 0x93, //+%@+%.
    0x00, 0x98, 0xa4, //..%%%+
    0x00, 0x30, 0x00, //......

    /*Unicode: U+0026 (&) , Width: 4 */
    0x00, 0x00, //....
    0x2c, 0xe3, //.@@.
    0x2e, 0x33, //.@..
    0x9a, 0xf9, //%%@%
    0x7c, 0xc6, //+@@+
    0x00, 0x00, //....

    /*Unicode: U+0027 (') , Width: 2 */
    0x00, //..
    0x86, //%+
    0x64, //++
    0x00, //..
    0x00, //..
    0x00, //..

    /*Unicode: U+0028 (() , Width: 3 */
    0x00, 0x00, //...
    0x3e, 0x00, //.@.
    0x6a, 0x00, //+%.
    0x6a, 0x00, //+%.
    0x6a, 0x00, //+%.
    0x2c, 0x00, //.@.

    /*Unicode: U+0029 ()) , Width: 2 */
    0x00, //..
    0x89, //%%
    0x3c, //.@
    0x3c, //.@
    0x3c, //.@
    0x87, //%+

    /*Unicode: U+002a (*) , Width: 3 */
    0x00, 0x00, //...
    0x1b, 0x30, //.%.
    0x4f, 0xa0, //+@%
    0x18, 0x60, //.%+
    0x00, 0x00, //...
    0x00, 0x00, //...

    /*Unicode: U+002b (+) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x08, 0x00, //.%..
    0x6e, 0xc0, //+@@.
    0x08, 0x00, //.%..
    0x00, 0x00, //....

    /*Unicode: U+002c (,) , Width: 2 */
    0x00, //..
    0x00, //..
    0x00, //..
    0x00, //..
    0x75, //++
    0x52, //+.

    /*Unicode: U+002d (-) , Width: 3 */
    0x00, 0x00, //...
    0x00, 0x00, //...
    0x00, 0x00, //...
    0x6b, 0x70, //+%+
    0x00, 0x00, //...
    0x00, 0x00, //...

    /*Unicode: U+002e (.) , Width: 2 */
    0x00, //..
    0x00, //..
    0x00, //..
    0x00, //..
    0x75, //++
    0x00, //..

    /*Unicode: U+002f (/) , Width: 2 */
    0x00, //..
    0x04, //.+
    0x08, //.%
    0x53, //+.
    0x90, //%.
    0x80, //%.

    /*Unicode: U+0030 (0) , Width: 4 */
    0x00, 0x00, //....
    0x7d, 0xc2, //+@@.
    0xb5, 0xa6, //%+%+
    0xb5, 0xa6, //%+%+
    0x7b, 0xe3, //+%@.
    0x00, 0x00, //....

    /*Unicode: U+0031 (1) , Width: 3 */
    0x00, 0x00, //...
    0x7f, 0x00, //+@.
    0x1f, 0x00, //.@.
    0x1f, 0x00, //.@.
    0x7c, 0x50, //+@+
    0x00, 0x00, //...

    /*Unicode: U+0032 (2) , Width: 4 */
    0x00, 0x00, //....
    0x7d, 0xb1, //+@%.
    0x31, 0xc4, //..@+
    0x6d, 0xc1, //+@@.
    0xbb, 0xb3, //%%%.
    0x00, 0x00, //....

    /*Unicode: U+0033 (3) , Width: 4 */
    0x00, 0x00, //....
    0x8d, 0xc2, //%@@.
    0x31, 0xa6, //..%+
    0x35, 0xd4, //.+@+
    0x8d, 0xc2, //%@@.
    0x00, 0x00, //....

    /*Unicode: U+0034 (4) , Width: 4 */
    0x00, 0x00, //....
    0x04, 0xe0, //.+@.
    0x1c, 0xe0, //.@@.
    0x99, 0xe0, //%%@.
    0xba, 0xf3, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0035 (5) , Width: 4 */
    0x00, 0x00, //....
    0xbc, 0xb2, //%@%.
    0xaa, 0xc1, //%%@.
    0x10, 0xb5, //..%+
    0x7d, 0xb2, //+@%.
    0x00, 0x00, //....

    /*Unicode: U+0036 (6) , Width: 4 */
    0x00, 0x00, //....
    0x7b, 0xe2, //+%@.
    0xb5, 0x00, //%+..
    0xbb, 0xc2, //%%@.
    0x7b, 0xd2, //+%@.
    0x00, 0x00, //....

    /*Unicode: U+0037 (7) , Width: 4 */
    0x00, 0x00, //....
    0xdc, 0xb0, //@@%.
    0x43, 0xb0, //+.%.
    0x09, 0x70, //.%+.
    0x0e, 0x20, //.@..
    0x00, 0x00, //....

    /*Unicode: U+0038 (8) , Width: 4 */
    0x00, 0x00, //....
    0x7b, 0xd4, //+%@+
    0xb5, 0x87, //%+%+
    0x9b, 0xe5, //%%@+
    0x7b, 0xd4, //+%@+
    0x00, 0x00, //....

    /*Unicode: U+0039 (9) , Width: 4 */
    0x00, 0x00, //....
    0x7b, 0xe2, //+%@.
    0xb5, 0xa6, //%+%+
    0x6c, 0xc6, //+@@+
    0x7b, 0xe3, //+%@.
    0x00, 0x00, //....

    /*Unicode: U+003a (:) , Width: 2 */
    0x00, //..
    0x00, //..
    0x75, //++
    0x00, //..
    0x75, //++
    0x00, //..

    /*Unicode: U+003b (;) , Width: 2 */
    0x00, //..
    0x00, //..
    0x75, //++
    0x00, //..
    0x75, //++
    0x52, //+.

    /*Unicode: U+003c (<) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x02, 0x60, //..+.
    0x5c, 0x60, //+@+.
    0x01, 0x60, //..+.
    0x00, 0x00, //....

    /*Unicode: U+003d (=) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x6b, 0xb0, //+%%.
    0x00, 0x00, //....
    0x6b, 0xb0, //+%%.
    0x00, 0x00, //....

    /*Unicode: U+003e (>) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x44, 0x00, //++..
    0x2a, 0xb0, //.%%.
    0x44, 0x00, //++..
    0x00, 0x00, //....

    /*Unicode: U+003f (?) , Width: 4 */
    0x00, 0x00, //....
    0x9d, 0xd1, //%@@.
    0x10, 0xd3, //..@.
    0x09, 0x70, //.%+.
    0x0b, 0x10, //.%..
    0x00, 0x00, //....

    /*Unicode: U+0040 (@) , Width: 4 */
    0x00, 0x00, //....
    0x4b, 0xd2, //+%@.
    0xa0, 0x29, //%..%
    0x83, 0x27, //%..+
    0x6b, 0xc1, //+%@.
    0x00, 0x00, //....

    /*Unicode: U+0041 (A) , Width: 4 */
    0x00, 0x00, //....
    0x0b, 0x70, //.%+.
    0x3c, 0xd0, //.@@.
    0x88, 0xf2, //%%@.
    0xd9, 0xe7, //@%@+
    0x00, 0x00, //....

    /*Unicode: U+0042 (B) , Width: 4 */
    0x00, 0x00, //....
    0xbb, 0xe3, //%%@.
    0xb5, 0xa6, //%+%+
    0xbb, 0xe4, //%%@+
    0xbb, 0xe3, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0043 (C) , Width: 4 */
    0x00, 0x00, //....
    0x8a, 0xd1, //%%@.
    0xc4, 0x62, //@++.
    0xc4, 0x31, //@+..
    0x8a, 0xd1, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0044 (D) , Width: 4 */
    0x00, 0x00, //....
    0xbb, 0xe3, //%%@.
    0xb5, 0xa6, //%+%+
    0xb5, 0xa6, //%+%+
    0xbb, 0xe3, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0045 (E) , Width: 4 */
    0x00, 0x00, //....
    0xbb, 0xf3, //%%@.
    0xb5, 0x10, //%+..
    0xbd, 0x60, //%@+.
    0xbb, 0xf3, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0046 (F) , Width: 4 */
    0x00, 0x00, //....
    0xbb, 0xf2, //%%@.
    0xb5, 0x30, //%+..
    0xbd, 0x40, //%@+.
    0xb5, 0x00, //%+..
    0x00, 0x00, //....

    /*Unicode: U+0047 (G) , Width: 4 */
    0x00, 0x00, //....
    0x7b, 0xe3, //+%@.
    0xb5, 0x10, //%+..
    0xb6, 0xc5, //%+@+
    0x7d, 0xb6, //+@%+
    0x00, 0x00, //....

    /*Unicode: U+0048 (H) , Width: 4 */
    0x00, 0x00, //....
    0xb5, 0xa6, //%+%+
    0xb5, 0xa6, //%+%+
    0xbb, 0xe6, //%%@+
    0xb5, 0xa6, //%+%+
    0x00, 0x00, //....

    /*Unicode: U+0049 (I) , Width: 2 */
    0x00, //..
    0xae, //%@
    0x6a, //+%
    0x6a, //+%
    0xae, //%@
    0x00, //..

    /*Unicode: U+004a (J) , Width: 4 */
    0x00, 0x00, //....
    0x5b, 0xf1, //+%@.
    0x00, 0xf1, //..@.
    0x72, 0xf1, //+.@.
    0xaa, 0xc0, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+004b (K) , Width: 4 */
    0x00, 0x00, //....
    0xb6, 0xe2, //%+@.
    0xbc, 0x90, //%@%.
    0xbc, 0xa0, //%@%.
    0xb6, 0xe4, //%+@+
    0x00, 0x00, //....

    /*Unicode: U+004c (L) , Width: 4 */
    0x00, 0x00, //....
    0xb5, 0x00, //%+..
    0xb5, 0x00, //%+..
    0xb5, 0x30, //%+..
    0xbb, 0xf0, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+004d (M) , Width: 5 */
    0x00, 0x00, 0x00, //.....
    0x8a, 0x1d, 0x30, //%%.@.
    0x9e, 0xad, 0x30, //%@%@.
    0xba, 0xdd, 0x30, //%%@@.
    0xb5, 0x3d, 0x30, //%+.@.
    0x00, 0x00, 0x00, //.....

    /*Unicode: U+004e (N) , Width: 4 */
    0x00, 0x00, //....
    0x9a, 0x86, //%%%+
    0x9e, 0xb6, //%@%+
    0xba, 0xd6, //%%@+
    0xb4, 0xe3, //%+@.
    0x00, 0x00, //....

    /*Unicode: U+004f (O) , Width: 4 */
    0x00, 0x00, //....
    0x8b, 0xe2, //%%@.
    0xc4, 0xb5, //@+%+
    0xc4, 0xb5, //@+%+
    0x8b, 0xe2, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0050 (P) , Width: 4 */
    0x00, 0x00, //....
    0xbb, 0xe2, //%%@.
    0xb5, 0xb5, //%+%+
    0xbb, 0xc2, //%%@.
    0xb5, 0x00, //%+..
    0x00, 0x00, //....

    /*Unicode: U+0051 (Q) , Width: 4 */
    0x00, 0x00, //....
    0x8b, 0xe2, //%%@.
    0xc4, 0xb5, //@+%+
    0xc4, 0xb5, //@+%+
    0x8d, 0xb2, //%@%.
    0x00, 0xa0, //..%.

    /*Unicode: U+0052 (R) , Width: 4 */
    0x00, 0x00, //....
    0xbb, 0xe3, //%%@.
    0xb5, 0xa6, //%+%+
    0xbb, 0xf2, //%%@.
    0xb5, 0xd4, //%+@+
    0x00, 0x00, //....

    /*Unicode: U+0053 (S) , Width: 4 */
    0x00, 0x00, //....
    0x8a, 0xd2, //%%@.
    0xc3, 0x00, //@...
    0x8e, 0xe3, //%@@.
    0x8c, 0xb2, //%@%.
    0x00, 0x00, //....

    /*Unicode: U+0054 (T) , Width: 3 */
    0x00, 0x00, //...
    0xab, 0xb0, //%%%
    0x0d, 0x10, //.@.
    0x0f, 0x10, //.@.
    0x0f, 0x10, //.@.
    0x00, 0x00, //...

    /*Unicode: U+0055 (U) , Width: 4 */
    0x00, 0x00, //....
    0xb5, 0xa6, //%+%+
    0xb5, 0xa6, //%+%+
    0xb5, 0xa6, //%+%+
    0x7b, 0xd2, //+%@.
    0x00, 0x00, //....

    /*Unicode: U+0056 (V) , Width: 4 */
    0x00, 0x00, //....
    0xe2, 0xc3, //@.@.
    0x98, 0xe0, //%%@.
    0x5c, 0x90, //+@%.
    0x0f, 0x20, //.@..
    0x00, 0x00, //....

    /*Unicode: U+0057 (W) , Width: 5 */
    0x00, 0x00, 0x00, //.....
    0xe3, 0xf5, 0xa0, //@.@+%
    0xbb, 0xdb, 0x60, //%%@%+
    0x7f, 0xcc, 0x10, //+@@@.
    0x3f, 0x6b, 0x00, //.@+%.
    0x00, 0x00, 0x00, //.....

    /*Unicode: U+0058 (X) , Width: 4 */
    0x00, 0x00, //....
    0xb8, 0xe1, //%%@.
    0x3e, 0x40, //.@+.
    0x3d, 0x80, //.@%.
    0xc8, 0xe1, //@%@.
    0x00, 0x00, //....

    /*Unicode: U+0059 (Y) , Width: 4 */
    0x00, 0x00, //....
    0xd4, 0xe0, //@+@.
    0x7c, 0x80, //+@%.
    0x1e, 0x10, //.@..
    0x0f, 0x10, //.@..
    0x00, 0x00, //....

    /*Unicode: U+005a (Z) , Width: 3 */
    0x00, 0x00, //...
    0xab, 0xe0, //%%@
    0x0b, 0x70, //.%+
    0x5c, 0x00, //+@.
    0xdb, 0xc0, //@%@
    0x00, 0x00, //...

    /*Unicode: U+005b ([) , Width: 3 */
    0x00, 0x00, //...
    0x5e, 0x00, //+@.
    0x5a, 0x00, //+%.
    0x5a, 0x00, //+%.
    0x5a, 0x00, //+%.
    0x4d, 0x00, //+@.

    /*Unicode: U+005c (\) , Width: 2 */
    0x00, //..
    0x40, //+.
    0x90, //%.
    0x62, //+.
    0x18, //.%
    0x09, //.%

    /*Unicode: U+005d (]) , Width: 2 */
    0x00, //..
    0x8b, //%%
    0x3b, //.%
    0x3b, //.%
    0x3b, //.%
    0x8a, //%%

    /*Unicode: U+005e (^) , Width: 3 */
    0x00, 0x00, //...
    0x00, 0x00, //...
    0x0b, 0x00, //.%.
    0x3b, 0x40, //.%+
    0x74, 0x80, //++%
    0x00, 0x00, //...

    /*Unicode: U+005f (_) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x88, 0x83, //%%%.

    /*Unicode: U+0060 (`) , Width: 2 */
    0x00, //..
    0x76, //++
    0x01, //..
    0x00, //..
    0x00, //..
    0x00, //..

    /*Unicode: U+0061 (a) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x5c, 0xc0, //+@@.
    0x8a, 0xf0, //%%@.
    0xa9, 0xf0, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0062 (b) , Width: 4 */
    0x00, 0x00, //....
    0xb5, 0x00, //%+..
    0xba, 0xc0, //%%@.
    0xb5, 0xf0, //%+@.
    0xbb, 0xc0, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0063 (c) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x8a, 0xc0, //%%@.
    0xc5, 0x30, //@+..
    0x8a, 0xc0, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0064 (d) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0xf1, //..@.
    0x9b, 0xf1, //%%@.
    0xc4, 0xf1, //@+@.
    0x8a, 0xf1, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0065 (e) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x8b, 0xc0, //%%@.
    0xcb, 0xd0, //@%@.
    0x8b, 0xa0, //%%%.
    0x00, 0x00, //....

    /*Unicode: U+0066 (f) , Width: 3 */
    0x00, 0x00, //...
    0x6d, 0x20, //+@.
    0xdb, 0x20, //@%.
    0xa6, 0x00, //%+.
    0xa6, 0x00, //%+.
    0x00, 0x00, //...

    /*Unicode: U+0067 (g) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x8a, 0xc0, //%%@.
    0xc5, 0xf0, //@+@.
    0x8a, 0xf0, //%%@.
    0x3c, 0xc0, //.@@.

    /*Unicode: U+0068 (h) , Width: 4 */
    0x00, 0x00, //....
    0xb5, 0x00, //%+..
    0xba, 0xc0, //%%@.
    0xb5, 0xf0, //%+@.
    0xb5, 0xf0, //%+@.
    0x00, 0x00, //....

    /*Unicode: U+0069 (i) , Width: 2 */
    0x00, //..
    0x84, //%+
    0xb5, //%+
    0xb5, //%+
    0xb5, //%+
    0x00, //..

    /*Unicode: U+006a (j) , Width: 2 */
    0x00, //..
    0x83, //%.
    0xb5, //%+
    0xb5, //%+
    0xb5, //%+
    0xe2, //@.

    /*Unicode: U+006b (k) , Width: 4 */
    0x00, 0x00, //....
    0xb5, 0x00, //%+..
    0xb9, 0xc0, //%%@.
    0xbc, 0x50, //%@+.
    0xb8, 0xe0, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+006c (l) , Width: 2 */
    0x00, //..
    0xb5, //%+
    0xb5, //%+
    0xb5, //%+
    0x8a, //%%
    0x00, //..

    /*Unicode: U+006d (m) , Width: 5 */
    0x00, 0x00, 0x00, //.....
    0x00, 0x00, 0x00, //.....
    0xba, 0xea, 0x80, //%%@%%
    0xb5, 0xf6, 0xb0, //%+@+%
    0xb5, 0xf6, 0xb0, //%+@+%
    0x00, 0x00, 0x00, //.....

    /*Unicode: U+006e (n) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0xba, 0xd0, //%%@.
    0xb5, 0xf0, //%+@.
    0xb5, 0xf0, //%+@.
    0x00, 0x00, //....

    /*Unicode: U+006f (o) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x8b, 0xd0, //%%@.
    0xc5, 0xf2, //@+@.
    0x8b, 0xd0, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0070 (p) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0xba, 0xc0, //%%@.
    0xb5, 0xf0, //%+@.
    0xbb, 0xc0, //%%@.
    0xb5, 0x00, //%+..

    /*Unicode: U+0071 (q) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x8a, 0xc0, //%%@.
    0xc5, 0xf0, //@+@.
    0x89, 0xf0, //%%@.
    0x00, 0xf0, //..@.

    /*Unicode: U+0072 (r) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0xba, 0xd0, //%%@.
    0xb5, 0x70, //%++.
    0xb5, 0x00, //%+..
    0x00, 0x00, //....

    /*Unicode: U+0073 (s) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x99, 0xa0, //%%%.
    0x7c, 0xb0, //+@%.
    0x88, 0xd0, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0074 (t) , Width: 3 */
    0x00, 0x00, //...
    0x54, 0x00, //++.
    0xdb, 0x10, //@%.
    0xa6, 0x00, //%+.
    0x7d, 0x10, //+@.
    0x00, 0x00, //...

    /*Unicode: U+0075 (u) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0xc5, 0xf0, //@+@.
    0xc5, 0xf0, //@+@.
    0x8a, 0xf0, //%%@.
    0x00, 0x00, //....

    /*Unicode: U+0076 (v) , Width: 3 */
    0x00, 0x00, //...
    0x00, 0x00, //...
    0xd6, 0xc0, //@+@
    0x8c, 0x70, //%@+
    0x3d, 0x10, //.@.
    0x00, 0x00, //...

    /*Unicode: U+0077 (w) , Width: 5 */
    0x00, 0x00, 0x00, //.....
    0x00, 0x00, 0x00, //.....
    0xd5, 0xe9, 0x60, //@+@%+
    0x9d, 0xdc, 0x10, //%@@@.
    0x4e, 0x89, 0x00, //+@%%.
    0x00, 0x00, 0x00, //.....

    /*Unicode: U+0078 (x) , Width: 3 */
    0x00, 0x00, //...
    0x00, 0x00, //...
    0xbb, 0x80, //%%%
    0x4e, 0x10, //+@.
    0xcb, 0x80, //@%%
    0x00, 0x00, //...

    /*Unicode: U+0079 (y) , Width: 3 */
    0x00, 0x00, //...
    0x00, 0x00, //...
    0xd5, 0xd0, //@+@
    0x7c, 0x80, //+@%
    0x1d, 0x30, //.@.
    0x2d, 0x00, //.@.

    /*Unicode: U+007a (z) , Width: 3 */
    0x00, 0x00, //...
    0x00, 0x00, //...
    0x8c, 0xa0, //%@%
    0x3e, 0x20, //.@.
    0xbb, 0x70, //%%+
    0x00, 0x00, //...

    /*Unicode: U+007b ({) , Width: 3 */
    0x00, 0x00, //...
    0x3e, 0x00, //.@.
    0x69, 0x00, //+%.
    0x97, 0x00, //%+.
    0x69, 0x00, //+%.
    0x2c, 0x00, //.@.

    /*Unicode: U+007c (|) , Width: 2 */
    0x00, //..
    0x62, //+.
    0x62, //+.
    0x62, //+.
    0x62, //+.
    0x62, //+.

    /*Unicode: U+007d (}) , Width: 3 */
    0x00, 0x00, //...
    0x89, 0x00, //%%.
    0x3d, 0x00, //.@.
    0x1e, 0x00, //.@.
    0x3d, 0x00, //.@.
    0x87, 0x00, //%+.

    /*Unicode: U+007e (~) , Width: 4 */
    0x00, 0x00, //....
    0x00, 0x00, //....
    0x4c, 0x22, //+@..
    0x35, 0xc0, //.+@.
    0x00, 0x00, //....
    0x00, 0x00, //....

};

/*Store the glyph descriptions*/
static const lv_font_glyph_dsc_t blackopsone_6_glyph_dsc[] = {
    {.w_px = 2, .glyph_index = 0},    /*Unicode: U+0020 ( )*/
    {.w_px = 2, .glyph_index = 6},    /*Unicode: U+0021 (!)*/
    {.w_px = 3, .glyph_index = 12},   /*Unicode: U+0022 (")*/
    {.w_px = 4, .glyph_index = 24},   /*Unicode: U+0023 (#)*/
    {.w_px = 4, .glyph_index = 36},   /*Unicode: U+0024 ($)*/
    {.w_px = 6, .glyph_index = 48},   /*Unicode: U+0025 (%)*/
    {.w_px = 4, .glyph_index = 66},   /*Unicode: U+0026 (&)*/
    {.w_px = 2, .glyph_index = 78},   /*Unicode: U+0027 (')*/
    {.w_px = 3, .glyph_index = 84},   /*Unicode: U+0028 (()*/
    {.w_px = 2, .glyph_index = 96},   /*Unicode: U+0029 ())*/
    {.w_px = 3, .glyph_index = 102},  /*Unicode: U+002a (*)*/
    {.w_px = 4, .glyph_index = 114},  /*Unicode: U+002b (+)*/
    {.w_px = 2, .glyph_index = 126},  /*Unicode: U+002c (,)*/
    {.w_px = 3, .glyph_index = 132},  /*Unicode: U+002d (-)*/
    {.w_px = 2, .glyph_index = 144},  /*Unicode: U+002e (.)*/
    {.w_px = 2, .glyph_index = 150},  /*Unicode: U+002f (/)*/
    {.w_px = 4, .glyph_index = 156},  /*Unicode: U+0030 (0)*/
    {.w_px = 3, .glyph_index = 168},  /*Unicode: U+0031 (1)*/
    {.w_px = 4, .glyph_index = 180},  /*Unicode: U+0032 (2)*/
    {.w_px = 4, .glyph_index = 192},  /*Unicode: U+0033 (3)*/
    {.w_px = 4, .glyph_index = 204},  /*Unicode: U+0034 (4)*/
    {.w_px = 4, .glyph_index = 216},  /*Unicode: U+0035 (5)*/
    {.w_px = 4, .glyph_index = 228},  /*Unicode: U+0036 (6)*/
    {.w_px = 4, .glyph_index = 240},  /*Unicode: U+0037 (7)*/
    {.w_px = 4, .glyph_index = 252},  /*Unicode: U+0038 (8)*/
    {.w_px = 4, .glyph_index = 264},  /*Unicode: U+0039 (9)*/
    {.w_px = 2, .glyph_index = 276},  /*Unicode: U+003a (:)*/
    {.w_px = 2, .glyph_index = 282},  /*Unicode: U+003b (;)*/
    {.w_px = 4, .glyph_index = 288},  /*Unicode: U+003c (<)*/
    {.w_px = 4, .glyph_index = 300},  /*Unicode: U+003d (=)*/
    {.w_px = 4, .glyph_index = 312},  /*Unicode: U+003e (>)*/
    {.w_px = 4, .glyph_index = 324},  /*Unicode: U+003f (?)*/
    {.w_px = 4, .glyph_index = 336},  /*Unicode: U+0040 (@)*/
    {.w_px = 4, .glyph_index = 348},  /*Unicode: U+0041 (A)*/
    {.w_px = 4, .glyph_index = 360},  /*Unicode: U+0042 (B)*/
    {.w_px = 4, .glyph_index = 372},  /*Unicode: U+0043 (C)*/
    {.w_px = 4, .glyph_index = 384},  /*Unicode: U+0044 (D)*/
    {.w_px = 4, .glyph_index = 396},  /*Unicode: U+0045 (E)*/
    {.w_px = 4, .glyph_index = 408},  /*Unicode: U+0046 (F)*/
    {.w_px = 4, .glyph_index = 420},  /*Unicode: U+0047 (G)*/
    {.w_px = 4, .glyph_index = 432},  /*Unicode: U+0048 (H)*/
    {.w_px = 2, .glyph_index = 444},  /*Unicode: U+0049 (I)*/
    {.w_px = 4, .glyph_index = 450},  /*Unicode: U+004a (J)*/
    {.w_px = 4, .glyph_index = 462},  /*Unicode: U+004b (K)*/
    {.w_px = 4, .glyph_index = 474},  /*Unicode: U+004c (L)*/
    {.w_px = 5, .glyph_index = 486},  /*Unicode: U+004d (M)*/
    {.w_px = 4, .glyph_index = 504},  /*Unicode: U+004e (N)*/
    {.w_px = 4, .glyph_index = 516},  /*Unicode: U+004f (O)*/
    {.w_px = 4, .glyph_index = 528},  /*Unicode: U+0050 (P)*/
    {.w_px = 4, .glyph_index = 540},  /*Unicode: U+0051 (Q)*/
    {.w_px = 4, .glyph_index = 552},  /*Unicode: U+0052 (R)*/
    {.w_px = 4, .glyph_index = 564},  /*Unicode: U+0053 (S)*/
    {.w_px = 3, .glyph_index = 576},  /*Unicode: U+0054 (T)*/
    {.w_px = 4, .glyph_index = 588},  /*Unicode: U+0055 (U)*/
    {.w_px = 4, .glyph_index = 600},  /*Unicode: U+0056 (V)*/
    {.w_px = 5, .glyph_index = 612},  /*Unicode: U+0057 (W)*/
    {.w_px = 4, .glyph_index = 630},  /*Unicode: U+0058 (X)*/
    {.w_px = 4, .glyph_index = 642},  /*Unicode: U+0059 (Y)*/
    {.w_px = 3, .glyph_index = 654},  /*Unicode: U+005a (Z)*/
    {.w_px = 3, .glyph_index = 666},  /*Unicode: U+005b ([)*/
    {.w_px = 2, .glyph_index = 678},  /*Unicode: U+005c (\)*/
    {.w_px = 2, .glyph_index = 684},  /*Unicode: U+005d (])*/
    {.w_px = 3, .glyph_index = 690},  /*Unicode: U+005e (^)*/
    {.w_px = 4, .glyph_index = 702},  /*Unicode: U+005f (_)*/
    {.w_px = 2, .glyph_index = 714},  /*Unicode: U+0060 (`)*/
    {.w_px = 4, .glyph_index = 720},  /*Unicode: U+0061 (a)*/
    {.w_px = 4, .glyph_index = 732},  /*Unicode: U+0062 (b)*/
    {.w_px = 4, .glyph_index = 744},  /*Unicode: U+0063 (c)*/
    {.w_px = 4, .glyph_index = 756},  /*Unicode: U+0064 (d)*/
    {.w_px = 4, .glyph_index = 768},  /*Unicode: U+0065 (e)*/
    {.w_px = 3, .glyph_index = 780},  /*Unicode: U+0066 (f)*/
    {.w_px = 4, .glyph_index = 792},  /*Unicode: U+0067 (g)*/
    {.w_px = 4, .glyph_index = 804},  /*Unicode: U+0068 (h)*/
    {.w_px = 2, .glyph_index = 816},  /*Unicode: U+0069 (i)*/
    {.w_px = 2, .glyph_index = 822},  /*Unicode: U+006a (j)*/
    {.w_px = 4, .glyph_index = 828},  /*Unicode: U+006b (k)*/
    {.w_px = 2, .glyph_index = 840},  /*Unicode: U+006c (l)*/
    {.w_px = 5, .glyph_index = 846},  /*Unicode: U+006d (m)*/
    {.w_px = 4, .glyph_index = 864},  /*Unicode: U+006e (n)*/
    {.w_px = 4, .glyph_index = 876},  /*Unicode: U+006f (o)*/
    {.w_px = 4, .glyph_index = 888},  /*Unicode: U+0070 (p)*/
    {.w_px = 4, .glyph_index = 900},  /*Unicode: U+0071 (q)*/
    {.w_px = 4, .glyph_index = 912},  /*Unicode: U+0072 (r)*/
    {.w_px = 4, .glyph_index = 924},  /*Unicode: U+0073 (s)*/
    {.w_px = 3, .glyph_index = 936},  /*Unicode: U+0074 (t)*/
    {.w_px = 4, .glyph_index = 948},  /*Unicode: U+0075 (u)*/
    {.w_px = 3, .glyph_index = 960},  /*Unicode: U+0076 (v)*/
    {.w_px = 5, .glyph_index = 972},  /*Unicode: U+0077 (w)*/
    {.w_px = 3, .glyph_index = 990},  /*Unicode: U+0078 (x)*/
    {.w_px = 3, .glyph_index = 1002}, /*Unicode: U+0079 (y)*/
    {.w_px = 3, .glyph_index = 1014}, /*Unicode: U+007a (z)*/
    {.w_px = 3, .glyph_index = 1026}, /*Unicode: U+007b ({)*/
    {.w_px = 2, .glyph_index = 1038}, /*Unicode: U+007c (|)*/
    {.w_px = 3, .glyph_index = 1044}, /*Unicode: U+007d (})*/
    {.w_px = 4, .glyph_index = 1056}, /*Unicode: U+007e (~)*/
};

lv_font_t blackopsone_6 = {
    .unicode_first = 32, /*First Unicode letter in this font*/
    .unicode_last = 126, /*Last Unicode letter in this font*/
    .h_px = 6,           /*Font height in pixels*/
    .glyph_bitmap = blackopsone_6_glyph_bitmap, /*Bitmap of glyphs*/
    .glyph_dsc = blackopsone_6_glyph_dsc,       /*Description of glyphs*/
    .glyph_cnt = 95,                            /*Number of glyphs in the font*/
    .unicode_list = NULL, /*Every character in the font from 'unicode_first' to
                             'unicode_last'*/
    .get_bitmap = lv_font_get_bitmap_continuous, /*Function pointer to get
                                                    glyph's bitmap*/
    .get_width =
        lv_font_get_width_continuous, /*Function pointer to get glyph's width*/
    .bpp = 4,                         /*Bit per pixel*/
    .monospace = 0,                   /*Fix width (0: if not used)*/
    .next_page = NULL,                /*Pointer to a font extension*/
};
