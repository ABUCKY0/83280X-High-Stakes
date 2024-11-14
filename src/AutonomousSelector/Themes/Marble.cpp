#include "AutonomousSelector/Themes/Marble.hpp" // IWYU pragma: keep
#include "main.h" // IWYU pragma: keep
#include "pros/apix.h" // IWYU pragma: keep
namespace MarbleStyles {
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

lv_img_dsc_t bg_image;

void initStyles() {
  lv_style_copy(&style_bg, &lv_style_plain);
  style_bg.body.main_color = LV_COLOR_MAKE(0x1f, 0x28, 0x2f);
  style_bg.body.grad_color = LV_COLOR_MAKE(0x1f, 0x28, 0x2f);

  lv_style_copy(&style_btn, &lv_style_plain);
  style_btn.body.main_color = LV_COLOR_RED;
  style_btn.body.grad_color = LV_COLOR_RED;
  style_btn.body.radius = 8;
  style_btn.text.font = &blackopsone_18;
  style_btn.text.letter_space = .5;
  style_btn.text.color = LV_COLOR_WHITE;

  lv_style_copy(&style_btn_selected, &lv_style_plain);
  style_btn_selected.body.main_color = LV_COLOR_BLACK;
  style_btn_selected.body.grad_color = LV_COLOR_BLACK;
  style_btn_selected.body.radius = 8;
  style_btn_selected.text.letter_space = .5;
  style_btn_selected.text.font = &blackopsone_18;

  lv_style_copy(&style_confirmbtn, &lv_style_plain);
  style_confirmbtn.body.main_color = LV_COLOR_BLACK;
  style_confirmbtn.body.grad_color = LV_COLOR_BLACK;
  style_confirmbtn.body.radius = 8;
  style_confirmbtn.text.font = &blackopsone_20;
  style_confirmbtn.text.letter_space = .5;
  style_confirmbtn.text.color = LV_COLOR_MAKE(0x8b, 0x8a, 0x8b);

  lv_style_copy(&style_confirmbtn_selected, &lv_style_plain);
  style_confirmbtn_selected.body.main_color = LV_COLOR_BLACK;
  style_confirmbtn_selected.body.grad_color = LV_COLOR_BLACK;
  style_confirmbtn_selected.body.radius = 8;
  style_confirmbtn_selected.text.font = &blackopsone_20;
  style_confirmbtn_selected.text.letter_space = .5;
  style_confirmbtn_selected.text.color = LV_COLOR_MAKE(0x8b, 0x8a, 0x8b);

  lv_style_copy(&style_teamname, &lv_style_plain);
  style_teamname.text.font = &blackopsone_40;
  style_teamname.text.color = LV_COLOR_MAKE(0xD0, 0xA9, 0x33);

  lv_style_copy(&style_roller, &lv_style_plain);
  style_roller.text.font = &blackopsone_18;
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

  lv_style_copy(&style_box, &lv_style_plain);
  style_box.body.main_color = LV_COLOR_MAKE(0xff, 0xf5, 0xf0);
  style_box.body.grad_color = LV_COLOR_WHITE;
  style_box.body.radius = 10;

  lv_style_copy(&style_smalltext, &lv_style_plain);
  style_smalltext.text.font = &blackopsone_10;
  style_smalltext.text.color = LV_COLOR_WHITE;

  lv_style_copy(&style_largetext, &lv_style_plain);
  style_largetext.text.font = &blackopsone_12;
  style_largetext.text.color = LV_COLOR_WHITE;

  lv_style_copy(&style_midtext, &lv_style_plain);
  style_midtext.text.font = &blackopsone_20;
  style_midtext.text.color = LV_COLOR_WHITE;

  lv_style_copy(&style_buildtext, &lv_style_plain);
  style_buildtext.text.font = &blackopsone_12;
  style_buildtext.text.color = LV_COLOR_WHITE;

  bg_image = marblebg;
}
}  // namespace Marble