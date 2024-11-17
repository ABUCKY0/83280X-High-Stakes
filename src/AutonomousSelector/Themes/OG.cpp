#include "AutonomousSelector/Themes/OG.hpp"  // IWYU pragma: keep
#include "main.h"       // IWYU pragma: keep
#include "pros/apix.h"  // IWYU pragma: keep

namespace OGStyles {
lv_style_t style_bg;
lv_style_t style_btn;
lv_style_t style_btn_selected;
lv_style_t style_confirmbtn;
lv_style_t style_confirmbtn_selected;
lv_style_t style_teamname;
lv_style_t style_roller;
lv_style_t roller_style_selected;
lv_style_t roller_bg_style;
lv_style_t style_box;
lv_style_t style_smalltext;
lv_style_t style_largetext;
lv_style_t style_midtext;
lv_style_t style_buildtext;

lv_style_t box_blue;
lv_style_t box_green;
lv_style_t box_red;
lv_style_t box_yellow;
lv_style_t box_midnightblue;

lv_font_t font_small_text_labels;
lv_font_t font_large_text_labels;
lv_font_t font_mid_text_labels;
lv_font_t font_team_name_text;

lv_font_t font_btn_text;
lv_font_t font_confirmbtn_text;
lv_font_t font_roller_text;

lv_img_dsc_t bg_image;
lv_img_dsc_t big_image;
lv_img_dsc_t small_image;

void initStyles() {
  font_small_text_labels = blackopsone_10;
  font_large_text_labels = blackopsone_12;
  font_btn_text = blackopsone_18;
  font_confirmbtn_text = blackopsone_20;
  font_mid_text_labels = blackopsone_20;
  font_team_name_text = blackopsone_40;
  font_roller_text = blackopsone_18;

  lv_style_copy(&style_bg, &lv_style_plain);
  style_bg.body.main_color = LV_COLOR_MAKE(0x1f, 0x28, 0x2f);
  style_bg.body.grad_color = LV_COLOR_MAKE(0x1f, 0x28, 0x2f);

  lv_style_copy(&style_btn, &lv_style_plain);
  style_btn.body.main_color = LV_COLOR_RED;
  style_btn.body.grad_color = LV_COLOR_RED;
  style_btn.body.radius = 8;
  style_btn.text.font = &font_btn_text;
  style_btn.text.letter_space = .5;
  style_btn.text.color = LV_COLOR_WHITE;

  lv_style_copy(&style_btn_selected, &lv_style_plain);
  style_btn_selected.body.main_color = LV_COLOR_BLACK;
  style_btn_selected.body.grad_color = LV_COLOR_BLACK;
  style_btn_selected.body.radius = 8;
  style_btn_selected.text.font = &font_btn_text;
  style_btn_selected.text.letter_space = .5;
  style_btn_selected.text.color = LV_COLOR_WHITE;

  lv_style_copy(&style_confirmbtn, &lv_style_plain);
  style_confirmbtn.body.main_color = LV_COLOR_MAKE(0x42, 0x86, 0x4e);
  style_confirmbtn.body.grad_color = LV_COLOR_MAKE(0x42, 0x86, 0x4e);
  style_confirmbtn.body.radius = 8;
  style_confirmbtn.text.font = &font_confirmbtn_text;
  style_confirmbtn.text.letter_space = .5;
  style_confirmbtn.text.color = LV_COLOR_WHITE;

  lv_style_copy(&style_confirmbtn_selected, &lv_style_plain);
  style_confirmbtn_selected.body.main_color = LV_COLOR_BLACK;
  style_confirmbtn_selected.body.grad_color = LV_COLOR_BLACK;
  style_confirmbtn_selected.body.radius = 8;
  style_confirmbtn_selected.text.font = &font_confirmbtn_text;
  style_confirmbtn_selected.text.letter_space = .5;
  style_confirmbtn_selected.text.color = LV_COLOR_MAKE(0x8b, 0x8a, 0x8b);

  lv_style_copy(&style_teamname, &lv_style_plain);
  style_teamname.text.font = &font_team_name_text;
  style_teamname.text.color = LV_COLOR_MAKE(0xF5, 0x05, 0x04);

  lv_style_copy(&style_roller, &lv_style_plain);
  style_roller.text.font = &font_roller_text;
  style_roller.body.main_color = LV_COLOR_MAKE(0x92, 0x92, 0x92);
  style_roller.body.grad_color = LV_COLOR_MAKE(0x92, 0x92, 0x92);
  style_roller.body.opa = LV_OPA_0;
  style_roller.text.color = LV_COLOR_WHITE;
  style_roller.body.empty = 1;
  style_roller.body.radius = 11;
  style_roller.body.padding.hor = 15;
  style_roller.body.padding.ver = 10;
  style_roller.text.line_space = 5;

  lv_style_copy(&roller_style_selected, &lv_style_plain);
  roller_style_selected.text.color = LV_COLOR_BLACK;
  roller_style_selected.body.border.color = LV_COLOR_BLACK;
  roller_style_selected.body.grad_color = LV_COLOR_MAKE(0x92, 0x92, 0x92);
  roller_style_selected.body.main_color = LV_COLOR_MAKE(0x92, 0x92, 0x92);
  roller_style_selected.body.border.width = 3;
  roller_style_selected.body.radius = 11;

  lv_style_copy(&roller_bg_style, &lv_style_plain);
  roller_bg_style.body.opa = LV_OPA_70;
  roller_bg_style.body.main_color = LV_COLOR_BLACK;
  roller_bg_style.body.grad_color = LV_COLOR_BLACK;
  roller_bg_style.body.radius = 11;

  lv_style_copy(&style_box, &lv_style_plain);
  style_box.body.main_color = LV_COLOR_MAKE(0xff, 0xf5, 0xf0);
  style_box.body.grad_color = LV_COLOR_WHITE;
  style_box.body.radius = 10;  // Set the radius for rounded corners
  style_box.body.opa = LV_OPA_100;

  lv_style_copy(&style_smalltext, &lv_style_plain);
  style_smalltext.text.font = &font_small_text_labels;
  style_smalltext.text.color = LV_COLOR_WHITE;

  lv_style_copy(&style_largetext, &lv_style_plain);
  style_largetext.text.font = &font_large_text_labels;
  style_largetext.text.color = LV_COLOR_WHITE;

  lv_style_copy(&style_midtext, &lv_style_plain);
  style_midtext.text.font = &font_mid_text_labels;
  style_midtext.text.color = LV_COLOR_WHITE;

  lv_style_copy(&style_buildtext, &lv_style_plain);
  style_buildtext.text.font = &font_small_text_labels;
  style_buildtext.text.color = LV_COLOR_MAKE(0xFF, 0xFF, 0xFF);

  bg_image = OGBackground;
  big_image = lobo;
  small_image = mini_lobo;

  // Create a style for the box
  lv_style_copy(&box_red, &style_box);
  box_red.body.main_color = LV_COLOR_MAKE(0x77, 0x15, 0x16);  // #771516
  box_red.body.grad_color = LV_COLOR_MAKE(0x77, 0x15, 0x16);  // #771516

  lv_style_copy(&box_green, &style_box);
  box_green.body.main_color = LV_COLOR_MAKE(0x42, 0x86, 0x2e);  // #42862e
  box_green.body.grad_color = LV_COLOR_MAKE(0x42, 0x86, 0x2e);  // #42862e

  lv_style_copy(&box_yellow, &style_box);
  box_yellow.body.main_color = LV_COLOR_MAKE(0xab, 0x9b, 0x10);  // #ab9b10
  box_yellow.body.grad_color = LV_COLOR_MAKE(0xab, 0x9b, 0x10);  // #ab9b10

  lv_style_copy(&box_blue, &style_box);
  box_blue.body.main_color = LV_COLOR_MAKE(0x00, 0x97, 0xb2);  // #0097b2
  box_blue.body.grad_color = LV_COLOR_MAKE(0x00, 0x97, 0xb2);  // #0097b2

  lv_style_copy(&box_midnightblue, &style_box);
  box_midnightblue.body.main_color =
      LV_COLOR_MAKE(0x1f, 0x28, 0x2f);  // #1f282f
  box_midnightblue.body.grad_color =
      LV_COLOR_MAKE(0x1f, 0x28, 0x2f);  // #1f282f
}
}  // namespace MarbleStyles