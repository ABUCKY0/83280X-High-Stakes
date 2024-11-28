#ifndef HELLO_KITTY_STYLES_HPP
#define HELLO_KITTY_STYLES_HPP

#include "pros/apix.h"  // IWYU pragma: keep

namespace HelloKittyStyles {
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
extern lv_style_t box_blue;
extern lv_style_t box_green;
extern lv_style_t box_red;
extern lv_style_t box_yellow;
extern lv_style_t box_midnightblue;
extern lv_font_t font_small_text_labels;
extern lv_font_t font_large_text_labels;
extern lv_font_t font_mid_text_labels;
extern lv_font_t font_team_name_text;
extern lv_font_t font_btn_text;
extern lv_font_t font_confirmbtn_text;
extern lv_font_t font_roller_text;

extern lv_img_dsc_t big_image;
extern lv_img_dsc_t small_image;
extern lv_img_dsc_t bg_image;
extern lv_style_t box_color_temp_normal;
extern lv_style_t box_color_temp_warning;
extern lv_style_t box_color_temp_level1;
extern lv_style_t box_color_temp_level2;
extern lv_style_t box_color_temp_level3;
extern lv_style_t box_color_temp_level4;
extern lv_style_t box_color_temp_error;
void initStyles();
}  // namespace HelloKittyStyles

#endif  // HELLO_KITTY_STYLES_HPP