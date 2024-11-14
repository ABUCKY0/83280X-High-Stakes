#ifndef MARBLE_STYLES_HPP
#define MARBLE_STYLES_HPP

#include "pros/apix.h"  // IWYU pragma: keep

namespace MarbleStyles {
extern lv_style_t style_bg;
extern lv_style_t style_btn;
extern lv_style_t style_btn_selected;
extern lv_style_t style_confirmbtn;
extern lv_style_t style_confirmbtn_selected;
extern lv_style_t style_teamname;
extern lv_style_t style_roller;
extern lv_style_t roller_style_selected;
extern lv_style_t roller_bg_style;
extern lv_style_t style_box;
extern lv_style_t style_smalltext;
extern lv_style_t style_largetext;
extern lv_style_t style_midtext;
extern lv_style_t style_buildtext;

extern lv_img_dsc_t bg_image;

void initStyles();
}  // namespace MarbleStyles

#endif  // MARBLE_STYLES_HPP