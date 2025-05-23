#include <sstream>

// Styles
#include "AutonomousSelector/Themes/Christmas.hpp"
#include "AutonomousSelector/Themes/HelloKitty.hpp"
#include "AutonomousSelector/Themes/Marble.hpp"
#include "AutonomousSelector/Themes/Nick.hpp"
#include "AutonomousSelector/Themes/OG.hpp"

// Regular Includes
#include "AutonomousSelector/helpers.hpp"
#include "Constants.hpp"
#include "main.h"
#include "pros/apix.h"  // IWYU pragma: keep
#include "pros/distance.h"

#if USE_UI == 1

lv_obj_t* auton_selector;
lv_style_t* box_red;
lv_style_t* box_green;
lv_style_t* box_yellow;
lv_style_t* box_blue;
lv_style_t* box_midnightblue;

static lv_obj_t* box_m1;
static lv_obj_t* box_m2;
static lv_obj_t* box_m3;
static lv_obj_t* box_m11;
static lv_obj_t* box_m12;
static lv_obj_t* box_m13;
static lv_obj_t* box_intake;
static lv_obj_t* box_distance;
static lv_obj_t* box_intake2;
static lv_obj_t* box_logo;
static lv_obj_t* box_battery;
static lv_obj_t* box_psi;
static lv_obj_t* box_autonsel;

static lv_obj_t* box_m1_label;
static lv_obj_t* box_m2_label;
static lv_obj_t* box_m3_label;
static lv_obj_t* box_m11_label;
static lv_obj_t* box_m12_label;
static lv_obj_t* box_m13_label;
static lv_obj_t* box_intake_label;
static lv_obj_t* box_distance_label;
static lv_obj_t* box_intake2_label;
static lv_obj_t* box_logo_label;
static lv_obj_t* box_battery_label;
static lv_obj_t* box_psi_label;
static lv_obj_t* box_autonsel_label;

static lv_obj_t* box_m1_val;
static lv_obj_t* box_m2_val;
static lv_obj_t* box_m3_val;
static lv_obj_t* box_m11_val;
static lv_obj_t* box_m12_val;
static lv_obj_t* box_m13_val;
static lv_obj_t* box_intake_val;
static lv_obj_t* box_distance_val;
static lv_obj_t* box_intake2_val;
static lv_obj_t* box_logo_val;
static lv_obj_t* box_battery_val;
static lv_obj_t* box_psi_val;

/*4 (100% of max current): 70c
3 (75% of max current): 65c
2 (50% of max current): 60c
1 (25% of max current): 55c*/

#define MOTOR_WARNING_TEMP 45
#define MOTOR_OVERTEMP_LEVEL1 55
#define MOTOR_OVERTEMP_LEVEL2 60
#define MOTOR_OVERTEMP_LEVEL3 65
#define MOTOR_OVERTEMP_LEVEL4 70
#define MOTOR_OVER_TEMP_MAX MOTOR_OVERTEMP_LEVEL4

// Auton Selection Arrays
static const char* auton_options[] = {"BLU-L", "BLU-R", "RED-L", "RED-R"};
static const char* skills_options[] = {"SKI-A", "SKI-B", "SKI-C", "SDRVR"};

string match_autons = "Blue Left\nBlue Right\nRed Left\nRed Right";
string skills_autons = "Auton A\nAuton B\nAuton C\nDriver";

pros::Mutex dataMutex;  // Mutex to protect shared data

double drivetrain_left_a_temp = 0.0;
double drivetrain_left_b_temp = 0.0;
double drivetrain_left_c_temp = 0.0;
double drivetrain_right_a_temp = 0.0;
double drivetrain_right_b_temp = 0.0;
double drivetrain_right_c_temp = 0.0;
double intake_temp = 0.0;
double intake2_temp = 0.0;
char distance_status = 0;  // 0 = No Connection, 1 = Primary, 2 = Backup

double estpsi = 100.0;
double batteryCharge = 0.0;

// Styles
static lv_style_t style_bg;
static lv_style_t style_btn;
static lv_style_t style_btn_selected;
static lv_style_t style_confirmbtn;
static lv_style_t style_confirmbtn_selected;
static lv_style_t style_teamname;
static lv_style_t style_roller;
static lv_style_t roller_style_selected;
static lv_style_t roller_bg_style;
static lv_style_t style_box;
static lv_style_t style_smalltext;
static lv_style_t style_largetext;
static lv_style_t style_midtext;
static lv_style_t style_buildtext;
static lv_style_t style_blue;
static lv_style_t style_green;
static lv_style_t style_red;
static lv_style_t style_yellow;
static lv_style_t style_midnightblue;
static lv_style_t box_color_temp_error;
static lv_style_t box_color_temp_normal;
static lv_style_t box_color_temp_warning;
static lv_style_t box_color_temp_level1;
static lv_style_t box_color_temp_level2;
static lv_style_t box_color_temp_level3;
static lv_style_t box_color_temp_level4;

// Images
static lv_img_dsc_t bg_image;
static lv_img_dsc_t big_image;
static lv_img_dsc_t small_image;

// // Screen
static lv_obj_t* matchscr;
static lv_obj_t* gamescr;
static lv_obj_t* switchscr;

// Everything on the screen
static lv_obj_t* btn_match;
static lv_obj_t* btn_skills;
static lv_obj_t* confirm_btn;
static lv_obj_t* teamName;
static lv_obj_t* rollerbg;
static lv_obj_t* buildtag;
static lv_obj_t* box;

// images
static lv_obj_t* backgroundimage;
static lv_obj_t* chicken;
static lv_obj_t* game_backgroundimage;
static lv_obj_t* logo;

static lv_obj_t* currentScreen;
// on press confirm
lv_res_t onMatchConfirmPress(lv_obj_t* btn) {
  cout << "[UI] (INFO): Autonomous Selection Confirmed\n";
  cout << "[UI] (INFO): Switching to Game Screen\n";
  auton = lv_roller_get_selected(auton_selector);
  if (gameMode == 0) {
    cout << "[UI] (INFO): Setting Match Auton Value\n";
    lv_label_set_text(box_autonsel_label, auton_options[auton]);
  } else {
    cout << "[UI] (INFO): Setting Skills Auton Value\n";
    lv_label_set_text(box_autonsel_label, skills_options[auton]);
  }
  lv_scr_load(gamescr);
  currentScreen = gamescr;
  return LV_RES_OK;
}

lv_res_t m_btn_open_selector_screen_again(lv_obj_t* btn) {
  cout << "[UI] (INFO): Opening Selector Screen Again\n";
  lv_scr_load(matchscr);
  currentScreen = matchscr;
  return LV_RES_OK;
}

lv_res_t m_btn_action_skills(lv_obj_t* btn) {
  // Get Roller
  cout << "[UI] (INFO): Skills Mode Switching\n";
  lv_roller_set_options(auton_selector, skills_autons.c_str());
  cout << "[UI] (INFO): Setting gameMode to 1\n";
  gameMode = 1;
  return LV_RES_OK;
}

lv_res_t m_btn_action_match(lv_obj_t* btn) {
  // Get Roller
  cout << "[UI] (INFO): Match Mode Switching @ " << millis() << "\n";
  lv_roller_set_options(auton_selector, match_autons.c_str());
  cout << "[UI] (INFO): Setting gameMode to 0\n";
  gameMode = 0;
  return LV_RES_OK;
}
enum class Theme { HELLOKITTY, MARBLE, NICK, OG, CHRISTMAS, THANKSGIVING };

void switchTheme(Theme theme) {
  switch (theme) {
    case Theme::HELLOKITTY:
      std::cout
          << "[UI] (INFO): Switching to Hello Kitty Theme (SWITCHTHEME)\n";
      style_bg = HelloKittyStyles::style_bg;
      style_btn = HelloKittyStyles::style_btn;
      style_btn_selected = HelloKittyStyles::style_btn_selected;
      style_confirmbtn = HelloKittyStyles::style_confirmbtn;
      style_confirmbtn_selected = HelloKittyStyles::style_confirmbtn_selected;
      style_teamname = HelloKittyStyles::style_teamname;
      style_roller = HelloKittyStyles::style_roller;
      roller_style_selected = HelloKittyStyles::roller_style_selected;
      roller_bg_style = HelloKittyStyles::roller_bg_style;
      style_box = HelloKittyStyles::style_box;
      style_smalltext = HelloKittyStyles::style_smalltext;
      style_largetext = HelloKittyStyles::style_largetext;
      style_midtext = HelloKittyStyles::style_midtext;
      style_buildtext = HelloKittyStyles::style_buildtext;
      box_blue = &HelloKittyStyles::box_blue;
      box_green = &HelloKittyStyles::box_green;
      box_red = &HelloKittyStyles::box_red;
      box_yellow = &HelloKittyStyles::box_yellow;
      box_midnightblue = &HelloKittyStyles::box_midnightblue;
      style_midnightblue = HelloKittyStyles::box_midnightblue;
      bg_image = HelloKittyStyles::bg_image;
      big_image = HelloKittyStyles::big_image;
      small_image = HelloKittyStyles::small_image;
      box_color_temp_normal = HelloKittyStyles::box_color_temp_normal;
      box_color_temp_warning = HelloKittyStyles::box_color_temp_warning;
      box_color_temp_level1 = HelloKittyStyles::box_color_temp_level1;
      box_color_temp_level2 = HelloKittyStyles::box_color_temp_level2;
      box_color_temp_level3 = HelloKittyStyles::box_color_temp_level3;
      box_color_temp_level4 = HelloKittyStyles::box_color_temp_level4;
      box_color_temp_error = HelloKittyStyles::box_color_temp_error;
      break;
    case Theme::MARBLE:
      std::cout << "[UI] (INFO): Switching to Marble Theme (SWITCHTHEME)\n";
      style_bg = MarbleStyles::style_bg;
      style_btn = MarbleStyles::style_btn;
      style_btn_selected = MarbleStyles::style_btn_selected;
      style_confirmbtn = MarbleStyles::style_confirmbtn;
      style_confirmbtn_selected = MarbleStyles::style_confirmbtn_selected;
      style_teamname = MarbleStyles::style_teamname;
      style_roller = MarbleStyles::style_roller;
      roller_style_selected = MarbleStyles::roller_style_selected;
      roller_bg_style = MarbleStyles::roller_bg_style;
      style_box = MarbleStyles::style_box;
      style_smalltext = MarbleStyles::style_smalltext;
      style_largetext = MarbleStyles::style_largetext;
      style_midtext = MarbleStyles::style_midtext;
      style_buildtext = MarbleStyles::style_buildtext;
      box_blue = &MarbleStyles::box_blue;
      box_green = &MarbleStyles::box_green;
      box_red = &MarbleStyles::box_red;
      box_yellow = &MarbleStyles::box_yellow;
      box_midnightblue = &MarbleStyles::box_midnightblue;
      style_midnightblue = MarbleStyles::box_midnightblue;
      bg_image = MarbleStyles::bg_image;
      big_image = MarbleStyles::big_image;
      small_image = MarbleStyles::small_image;
      box_color_temp_normal = MarbleStyles::box_color_temp_normal;
      box_color_temp_warning = MarbleStyles::box_color_temp_warning;
      box_color_temp_level1 = MarbleStyles::box_color_temp_level1;
      box_color_temp_level2 = MarbleStyles::box_color_temp_level2;
      box_color_temp_level3 = MarbleStyles::box_color_temp_level3;
      box_color_temp_level4 = MarbleStyles::box_color_temp_level4;
      box_color_temp_error = MarbleStyles::box_color_temp_error;

      break;
    case Theme::OG:
      std::cout << "[UI] (INFO): Switching to OG Theme (SWITCHTHEME)\n";
      style_bg = OGStyles::style_bg;
      style_btn = OGStyles::style_btn;
      style_btn_selected = OGStyles::style_btn_selected;
      style_confirmbtn = OGStyles::style_confirmbtn;
      style_confirmbtn_selected = OGStyles::style_confirmbtn_selected;
      style_teamname = OGStyles::style_teamname;
      style_roller = OGStyles::style_roller;
      roller_style_selected = OGStyles::roller_style_selected;
      roller_bg_style = OGStyles::roller_bg_style;
      style_box = OGStyles::style_box;
      style_smalltext = OGStyles::style_smalltext;
      style_largetext = OGStyles::style_largetext;
      style_midtext = OGStyles::style_midtext;
      style_buildtext = OGStyles::style_buildtext;
      box_blue = &OGStyles::box_blue;
      box_green = &OGStyles::box_green;
      box_red = &OGStyles::box_red;
      box_yellow = &OGStyles::box_yellow;
      box_midnightblue = &OGStyles::box_midnightblue;
      style_midnightblue = OGStyles::box_midnightblue;
      bg_image = OGStyles::bg_image;
      big_image = OGStyles::big_image;
      small_image = OGStyles::small_image;
      box_color_temp_normal = OGStyles::box_color_temp_normal;
      box_color_temp_warning = OGStyles::box_color_temp_warning;
      box_color_temp_level1 = OGStyles::box_color_temp_level1;
      box_color_temp_level2 = OGStyles::box_color_temp_level2;
      box_color_temp_level3 = OGStyles::box_color_temp_level3;
      box_color_temp_level4 = OGStyles::box_color_temp_level4;
      box_color_temp_error = OGStyles::box_color_temp_error;
      break;
    case Theme::CHRISTMAS:
      std::cout << "[UI] (INFO): Switching to Christmas Theme (SWITCHTHEME)\n";
      style_bg = ChristmasStyles::style_bg;
      style_btn = ChristmasStyles::style_btn;
      style_btn_selected = ChristmasStyles::style_btn_selected;
      style_confirmbtn = ChristmasStyles::style_confirmbtn;
      style_confirmbtn_selected = ChristmasStyles::style_confirmbtn_selected;
      style_teamname = ChristmasStyles::style_teamname;
      style_roller = ChristmasStyles::style_roller;
      roller_style_selected = ChristmasStyles::roller_style_selected;
      roller_bg_style = ChristmasStyles::roller_bg_style;
      style_box = ChristmasStyles::style_box;
      style_smalltext = ChristmasStyles::style_smalltext;
      style_largetext = ChristmasStyles::style_largetext;
      style_midtext = ChristmasStyles::style_midtext;
      style_buildtext = ChristmasStyles::style_buildtext;
      box_blue = &ChristmasStyles::box_blue;
      box_green = &ChristmasStyles::box_green;
      box_red = &ChristmasStyles::box_red;
      box_yellow = &ChristmasStyles::box_yellow;
      box_midnightblue = &ChristmasStyles::box_midnightblue;
      style_midnightblue = ChristmasStyles::box_midnightblue;
      bg_image = ChristmasStyles::bg_image;
      big_image = ChristmasStyles::big_image;
      small_image = ChristmasStyles::small_image;
      box_color_temp_normal = ChristmasStyles::box_color_temp_normal;
      box_color_temp_warning = ChristmasStyles::box_color_temp_warning;
      box_color_temp_level1 = ChristmasStyles::box_color_temp_level1;
      box_color_temp_level2 = ChristmasStyles::box_color_temp_level2;
      box_color_temp_level3 = ChristmasStyles::box_color_temp_level3;
      box_color_temp_level4 = ChristmasStyles::box_color_temp_level4;
      box_color_temp_error = ChristmasStyles::box_color_temp_error;
      break;
    case Theme::NICK:
      std::cout << "[UI] (INFO): Switching to Nick's Theme (SWITCHTHEME)\n";
      style_bg = NickStyles::style_bg;
      style_btn = NickStyles::style_btn;
      style_btn_selected = NickStyles::style_btn_selected;
      style_confirmbtn = NickStyles::style_confirmbtn;
      style_confirmbtn_selected = NickStyles::style_confirmbtn_selected;
      style_teamname = NickStyles::style_teamname;
      style_roller = NickStyles::style_roller;
      roller_style_selected = NickStyles::roller_style_selected;
      roller_bg_style = NickStyles::roller_bg_style;
      style_box = NickStyles::style_box;
      style_smalltext = NickStyles::style_smalltext;
      style_largetext = NickStyles::style_largetext;
      style_midtext = NickStyles::style_midtext;
      style_buildtext = NickStyles::style_buildtext;
      box_blue = &NickStyles::box_blue;
      box_green = &NickStyles::box_green;
      box_red = &NickStyles::box_red;
      box_yellow = &NickStyles::box_yellow;
      box_midnightblue = &NickStyles::box_midnightblue;
      style_midnightblue = NickStyles::box_midnightblue;
      bg_image = NickStyles::bg_image;
      big_image = NickStyles::big_image;
      small_image = NickStyles::small_image;
      box_color_temp_normal = NickStyles::box_color_temp_normal;
      box_color_temp_warning = NickStyles::box_color_temp_warning;
      box_color_temp_level1 = NickStyles::box_color_temp_level1;
      box_color_temp_level2 = NickStyles::box_color_temp_level2;
      box_color_temp_level3 = NickStyles::box_color_temp_level3;
      box_color_temp_level4 = NickStyles::box_color_temp_level4;
      box_color_temp_error = NickStyles::box_color_temp_error;

      break;
    default:
      //switchTheme(Theme::MARBLE);
      return;
  }
  std::cout << "[UI] (INFO): Theme Switched\n";

  // // Update the UI elements with the new styles
  // lv_obj_set_style(matchscr, &style_bg);
  // lv_label_set_style(teamName, &style_teamname);
  // lv_obj_set_style(rollerbg, &roller_bg_style);
  // lv_btn_set_style(btn_match, LV_BTN_STYLE_REL, &style_btn);
  // lv_btn_set_style(btn_match, LV_BTN_STATE_PR, &style_btn_selected);
  // lv_btn_set_style(btn_skills, LV_BTN_STYLE_REL, &style_btn);
  // lv_btn_set_style(btn_skills, LV_BTN_STATE_PR, &style_btn_selected);
  // lv_btn_set_style(confirm_btn, LV_BTN_STATE_REL, &style_confirmbtn);
  // lv_btn_set_style(confirm_btn, LV_BTN_STATE_PR, &style_confirmbtn_selected);
  // lv_roller_set_style(auton_selector, LV_ROLLER_STYLE_BG, &style_roller);
  // lv_roller_set_style(auton_selector, LV_ROLLER_STYLE_SEL,
  //                     &roller_style_selected);
  // lv_obj_set_style(box, &style_box);
  // lv_label_set_style(box_m1_label, &style_smalltext);
  // lv_label_set_style(box_m2_label, &style_smalltext);
  // lv_label_set_style(box_m3_label, &style_smalltext);
  // lv_label_set_style(box_m11_label, &style_smalltext);
  // lv_label_set_style(box_m12_label, &style_smalltext);
  // lv_label_set_style(box_m13_label, &style_smalltext);
  // lv_label_set_style(box_battery_label, &style_largetext);
  // lv_label_set_style(box_psi_label, &style_largetext);
  // lv_label_set_style(box_autonsel_label, &style_midtext);
  // lv_label_set_style(box_intake2_label, &style_smalltext);
  // lv_label_set_style(box_intake_label, &style_smalltext);
  // lv_label_set_style(box_distance_label, &style_smalltext);
  // lv_label_set_style(box_m1_val, &style_midtext);
  // lv_label_set_style(box_m2_val, &style_midtext);
  // lv_label_set_style(box_m3_val, &style_midtext);
  // lv_label_set_style(box_m11_val, &style_midtext);
  // lv_label_set_style(box_m12_val, &style_midtext);
  // lv_label_set_style(box_m13_val, &style_midtext);
  // lv_label_set_style(box_battery_val, &style_midtext);
  // lv_label_set_style(box_psi_val, &style_midtext);
  // lv_label_set_style(box_intake2_val, &style_midtext);
  // lv_label_set_style(box_intake_val, &style_midtext);
  // lv_label_set_style(box_distance_val, &style_midtext);
  // lv_obj_set_style(box_m1, box_green);
  // lv_obj_set_style(box_m2, box_green);
  // lv_obj_set_style(box_m3, box_green);
  // lv_obj_set_style(box_m11, box_green);
  // lv_obj_set_style(box_m12, box_green);
  // lv_obj_set_style(box_m13, box_green);
  // lv_obj_set_style(box_battery, box_green);
  // lv_obj_set_style(box_psi, box_green);
  // lv_obj_set_style(box_autonsel, box_midnightblue);
  // lv_obj_set_style(box_intake2, box_green);
  // lv_obj_set_style(box_intake, box_green);
  // lv_obj_set_style(box_distance, box_green);
  // lv_obj_set_style(box_logo, box_midnightblue);
  // lv_obj_set_style(buildtag, &style_buildtext);

  lv_scr_load(currentScreen);
}

lv_res_t m_btn_set_theme_hellokitty(lv_obj_t* btn) {
  cout << "[UI] (INFO): Switching to Hello Kitty Theme\n";
  switchTheme(Theme::HELLOKITTY);
  return LV_RES_OK;
}

lv_res_t m_btn_set_theme_marble(lv_obj_t* btn) {
  cout << "[UI] (INFO): Switching to Marble Theme\n";
  switchTheme(Theme::MARBLE);
  return LV_RES_OK;
}

lv_res_t m_btn_set_theme_nick(lv_obj_t* btn) {
  cout << "[UI] (INFO): Switching to Nick's Theme\n";
  switchTheme(Theme::NICK);
  return LV_RES_OK;
}

lv_res_t m_btn_set_theme_og(lv_obj_t* btn) {
  cout << "[UI] (INFO): Switching to OG Theme\n";
  switchTheme(Theme::OG);
  return LV_RES_OK;
}

lv_res_t m_btn_set_theme_christmas(lv_obj_t* btn) {
  cout << "[UI] (INFO): Switching to Christmas Theme\n";
  switchTheme(Theme::CHRISTMAS);
  return LV_RES_OK;
}

lv_res_t m_btn_set_theme_thanksgiving(lv_obj_t* btn) {
  cout << "[UI] (INFO): Switching to Thanksgiving Theme\n";
  switchTheme(Theme::THANKSGIVING);
  return LV_RES_OK;
}

lv_res_t m_btn_open_theme_switcher(lv_obj_t* btn) {
  lv_scr_load(switchscr);
  return LV_RES_OK;
}

void init_marble_ui() {

  HelloKittyStyles::initStyles();
  MarbleStyles::initStyles();
  OGStyles::initStyles();
  ChristmasStyles::initStyles();
  NickStyles::initStyles();
  cout << "[UI] (INFO): Initalizing matchscr\n";
  matchscr = lv_obj_create(NULL, NULL);
  currentScreen = matchscr;

  /* ------------- Shared Styles ------------- */
  switchTheme(Theme::MARBLE);

  /* ----------- Begin Match Screen ---------- */

  cout << "[UI] (INFO): [SCREEN] [LOAD] matchscr\n";
  lv_scr_load(matchscr);

  // Image Background
  cout << "[UI] (INFO): [IMAGE] [CREATION] backgroundimage\n";
  backgroundimage = createImage(matchscr, 0, 0, 1, &bg_image);

  // Team Name
  cout << "[UI] (INFO): [LABEL] [CREATION] teamName\n";
  teamName = createLabel(matchscr, 38, 25, "83280X");
  lv_label_set_style(teamName, &style_teamname);
  // BG Boxes
  cout << "[UI] (INFO): [OBJ] [CREATION] rollerbg\n";
  rollerbg = createBaseObject(matchscr, 240, 21);
  lv_obj_set_size(rollerbg, 216, 197);
  lv_obj_set_style(rollerbg, &roller_bg_style);

  // Auton Selector
  // -- Screen Switch Buttons
  cout << "[UI] (INFO): [BUTTON] [CREATION] btn_match\n";
  btn_match = createBtn(matchscr, 248, 29, 90, 40, 2, "MATCH");
  lv_btn_set_style(btn_match, LV_BTN_STYLE_REL, &style_btn);
  lv_btn_set_style(btn_match, LV_BTN_STATE_PR, &style_btn_selected);
  cout << "[UI] (INFO): [BUTTON] [CREATION] btn_skills\n";

  btn_skills = createBtn(matchscr, 355, 29, 90, 40, 3, "SKILLS");
  lv_btn_set_style(btn_skills, LV_BTN_STYLE_REL, &style_btn);
  lv_btn_set_style(btn_skills, LV_BTN_STATE_PR, &style_btn_selected);
  // -- confirm button
  cout << "[UI] (INFO): [BUTTON] [CREATION] confirm_btn\n";
  confirm_btn = createBtn(matchscr, 248, 167, 197, 40, 4, "CONFIRM");
  lv_btn_set_style(confirm_btn, LV_BTN_STATE_REL, &style_confirmbtn);
  lv_btn_set_style(confirm_btn, LV_BTN_STATE_PR, &style_confirmbtn_selected);

  // roller
  cout << "[UI] (INFO): [ROLLER] [CREATION] auton_selector\n";
  auton_selector = createRoller(matchscr, match_autons.c_str(), 248, 74);
  lv_obj_set_free_num(auton_selector, 20);
  lv_roller_set_hor_fit(auton_selector, false);
  lv_obj_set_width(auton_selector, 202);
  lv_obj_set_height(auton_selector, 84);
  lv_roller_set_style(auton_selector, LV_ROLLER_STYLE_BG, &style_roller);
  lv_roller_set_style(auton_selector, LV_ROLLER_STYLE_SEL,
                      &roller_style_selected);

  // Chick-Fil-A Chicken Sandwich
  cout << "[UI] (INFO): [IMAGE] [CREATION] large image\n";
  chicken = createImage(matchscr, 40, 69, 5, &big_image);

  // Apply Button Functions
  cout << "[UI] (INFO): [BUTTON] btn_skills [ACTIONSET] m_btn_action_skills\n";
  lv_btn_set_action(btn_skills, LV_BTN_ACTION_CLICK, m_btn_action_skills);
  cout << "[UI] (INFO): [BUTTON] btn_match [ACTIONSET] m_btn_action_match\n";
  lv_btn_set_action(btn_match, LV_BTN_ACTION_CLICK, m_btn_action_match);
  cout << "[UI] (INFO): [BUTTON] confirm_btn [ACTIONSET] onMatchConfirmPress\n";
  lv_btn_set_action(confirm_btn, LV_BTN_ACTION_CLICK, onMatchConfirmPress);
  /* ---------- End Selections Screen ---------- */
  /* ----------- Begin Game Scr ----------- */
  /*
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  // get the time in milliseconds
  int64_t now = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
  */

  int src = readCounterFromMemory();
  srand(src);
  // random
  int useChicken = rand() % 10 + 1;

  gamescr = lv_obj_create(NULL, NULL);
  cout << "[UI] (INFO): [IMAGE] [CREATION] Game Screen Background\n";
  game_backgroundimage = createImage(gamescr, 0, 0, 1, &bg_image);

  // Create a base object for the box
  box = lv_obj_create(gamescr, NULL);
  lv_obj_set_style(box, &style_box);

  // take mutex
  dataMutex.take(2000);

  // Set the Static Variable Box Styles
  // Red

  // static lv_style_t style_buildtext;
  // lv_style_copy(&style_buildtext, &lv_style_plain);
  // style_buildtext.text.font = &blackopsone_12;
  // style_buildtext.text.color = LV_COLOR_WHITE;

  // Set the size and position of the box
  lv_obj_set_size(box, 443, 211);  // Replace with the size you want
  lv_obj_set_pos(box, 15, 17);     // Replace with the position you want

  box_m1 = createBaseObject(gamescr, 72, 72);
  box_m2 = lv_obj_create(gamescr, NULL);
  box_m3 = lv_obj_create(gamescr, NULL);
  box_m11 = lv_obj_create(gamescr, NULL);
  box_m12 = lv_obj_create(gamescr, NULL);
  box_m13 = lv_obj_create(gamescr, NULL);
  box_battery = lv_obj_create(gamescr, NULL);
  box_psi = lv_obj_create(gamescr, NULL);
  box_autonsel = lv_btn_create(gamescr, NULL);
  box_intake2 = lv_obj_create(gamescr, NULL);
  box_intake = lv_obj_create(gamescr, NULL);
  box_distance = lv_obj_create(gamescr, NULL);
  box_logo = lv_obj_create(gamescr, NULL);

  box_m1_label = lv_label_create(box_m1, NULL);
  box_m2_label = lv_label_create(box_m2, NULL);
  box_m3_label = lv_label_create(box_m3, NULL);
  box_m11_label = lv_label_create(box_m11, NULL);
  box_m12_label = lv_label_create(box_m12, NULL);
  box_m13_label = lv_label_create(box_m13, NULL);
  box_battery_label = lv_label_create(box_battery, NULL);
  box_psi_label = lv_label_create(box_psi, NULL);
  box_autonsel_label = lv_label_create(box_autonsel, NULL);
  box_intake2_label = lv_label_create(box_intake2, NULL);
  box_intake_label = lv_label_create(box_intake, NULL);
  box_distance_label = lv_label_create(box_distance, NULL);

  // set the labels to small text
  lv_label_set_style(box_m1_label, &style_smalltext);
  lv_label_set_text(box_m1_label, "LDTM 1\nTemp");
  lv_label_set_align(box_m1_label, LV_LABEL_ALIGN_CENTER);

  lv_label_set_style(box_m2_label, &style_smalltext);
  lv_label_set_text(box_m2_label, "LDTM 2\nTemp");
  lv_label_set_align(box_m2_label, LV_LABEL_ALIGN_CENTER);

  lv_label_set_style(box_m3_label, &style_smalltext);
  lv_label_set_text(box_m3_label, "LDTM 3\nTemp");
  lv_label_set_align(box_m3_label, LV_LABEL_ALIGN_CENTER);

  lv_label_set_style(box_m11_label, &style_smalltext);
  lv_label_set_text(box_m11_label, "RDTM 1\nTemp");
  lv_label_set_align(box_m11_label, LV_LABEL_ALIGN_CENTER);

  lv_label_set_style(box_m12_label, &style_smalltext);
  lv_label_set_text(box_m12_label, "RDTM 2\nTemp");
  lv_label_set_align(box_m12_label, LV_LABEL_ALIGN_CENTER);

  lv_label_set_style(box_m13_label, &style_smalltext);
  lv_label_set_text(box_m13_label, "RDTM 3\nTemp");
  lv_label_set_align(box_m13_label, LV_LABEL_ALIGN_CENTER);

  lv_label_set_style(box_battery_label, &style_largetext);
  lv_label_set_text(box_battery_label, "Battery\nCharge");
  lv_label_set_align(box_battery_label, LV_LABEL_ALIGN_CENTER);

  lv_label_set_style(box_psi_label, &style_largetext);
  lv_label_set_text(box_psi_label, "PSI\nEstimated");
  lv_label_set_align(box_psi_label, LV_LABEL_ALIGN_CENTER);

  lv_label_set_style(box_autonsel_label, &style_midtext);
  lv_label_set_text(box_autonsel_label, "DEF-A");
  lv_label_set_align(box_autonsel_label, LV_LABEL_ALIGN_CENTER);
  // make clickthrough
  lv_obj_set_click(box_autonsel_label, false);

  lv_label_set_style(box_intake2_label, &style_smalltext);
  lv_label_set_text(box_intake2_label, "Intake2\nTemp");
  lv_label_set_align(box_intake2_label, LV_LABEL_ALIGN_CENTER);

  lv_label_set_style(box_intake_label, &style_smalltext);
  lv_label_set_text(box_intake_label, "Intake\nTemp");
  lv_label_set_align(box_intake_label, LV_LABEL_ALIGN_CENTER);

  lv_label_set_style(box_distance_label, &style_smalltext);
  lv_label_set_text(box_distance_label, "distance\nStatus");
  lv_label_set_align(box_distance_label, LV_LABEL_ALIGN_CENTER);

  lv_obj_set_style(box_m1, box_green);
  lv_obj_set_style(box_m2, box_green);
  lv_obj_set_style(box_m3, box_green);
  lv_obj_set_style(box_m11, box_green);
  lv_obj_set_style(box_m12, box_green);
  lv_obj_set_style(box_m13, box_green);
  lv_obj_set_style(box_battery, box_green);
  lv_obj_set_style(box_psi, box_green);
  //lv_obj_set_style(box_autonsel, box_midnightblue);
  lv_obj_set_style(box_intake2, box_green);
  lv_obj_set_style(box_intake, box_green);
  lv_obj_set_style(box_distance, box_green);
  lv_obj_set_style(box_logo, box_midnightblue);

  // all motor boxes and logo are 72 by 72
  lv_obj_set_size(box_m1, 72, 72);
  lv_obj_set_size(box_m2, 72, 72);
  lv_obj_set_size(box_m3, 72, 72);
  lv_obj_set_size(box_m11, 72, 72);
  lv_obj_set_size(box_m12, 72, 72);
  lv_obj_set_size(box_m13, 72, 72);
  lv_obj_set_size(box_logo, 72, 72);
  lv_obj_set_size(box_intake2, 72, 72);
  lv_obj_set_size(box_intake, 72, 72);
  lv_obj_set_size(box_distance, 72, 72);

  // battery and psi are 161 by 42
  lv_obj_set_size(box_battery, 161, 42);
  lv_obj_set_size(box_psi, 161, 42);

  // auton seleector is 72 by 42
  lv_obj_set_size(box_autonsel, 72, 42);

  // Position the boxes
  lv_obj_set_pos(box_m1, 25, 24);
  lv_obj_set_pos(box_m2, 113, 24);
  lv_obj_set_pos(box_m3, 201, 24);
  lv_obj_set_pos(box_m11, 24, 151);
  lv_obj_set_pos(box_m12, 113, 151);
  lv_obj_set_pos(box_m13, 201, 151);
  lv_obj_set_pos(box_battery, 25, 101);
  lv_obj_set_pos(box_psi, 289, 101);
  lv_obj_set_pos(box_autonsel, 201, 101);
  lv_obj_set_pos(box_intake2, 289, 150);
  lv_obj_set_pos(box_intake, 289, 24);
  lv_obj_set_pos(box_distance, 377, 24);
  lv_obj_set_pos(box_logo, 377, 149);

  // Position the labels in the boxes to below center
  lv_obj_align(box_m1_label, box_m1, LV_ALIGN_CENTER, 0, 15);
  lv_obj_align(box_m2_label, box_m2, LV_ALIGN_CENTER, 0, 15);
  lv_obj_align(box_m3_label, box_m3, LV_ALIGN_CENTER, 0, 15);
  lv_obj_align(box_m11_label, box_m11, LV_ALIGN_CENTER, 0, 15);
  lv_obj_align(box_m12_label, box_m12, LV_ALIGN_CENTER, 0, 15);
  lv_obj_align(box_m13_label, box_m13, LV_ALIGN_CENTER, 0, 15);
  lv_obj_align(box_battery_label, box_battery, LV_ALIGN_CENTER, 40, 0);
  lv_obj_align(box_psi_label, box_psi, LV_ALIGN_CENTER, 35, 0);
  lv_obj_align(box_autonsel_label, box_autonsel, LV_ALIGN_CENTER, 0, 0);
  lv_obj_align(box_intake2_label, box_intake2, LV_ALIGN_CENTER, 0, 15);
  lv_obj_align(box_intake_label, box_intake, LV_ALIGN_CENTER, 0, 15);
  lv_obj_align(box_distance_label, box_distance, LV_ALIGN_CENTER, 0, 15);

  // CREATE THE LARGE LABELS above the small labels above
  box_m1_val = lv_label_create(box_m1, NULL);
  box_m2_val = lv_label_create(box_m2, NULL);
  box_m3_val = lv_label_create(box_m3, NULL);
  box_m11_val = lv_label_create(box_m11, NULL);
  box_m12_val = lv_label_create(box_m12, NULL);
  box_m13_val = lv_label_create(box_m13, NULL);
  box_battery_val = lv_label_create(box_battery, NULL);
  box_psi_val = lv_label_create(box_psi, NULL);
  box_intake2_val = lv_label_create(box_intake2, NULL);
  box_intake_val = lv_label_create(box_intake, NULL);
  box_distance_val = lv_label_create(box_distance, NULL);

  // set the labels to midtext
  lv_label_set_style(box_m1_val, &style_midtext);
  lv_label_set_style(box_m2_val, &style_midtext);
  lv_label_set_style(box_m3_val, &style_midtext);
  lv_label_set_style(box_m11_val, &style_midtext);
  lv_label_set_style(box_m12_val, &style_midtext);
  lv_label_set_style(box_m13_val, &style_midtext);
  lv_label_set_style(box_battery_val, &style_midtext);
  lv_label_set_style(box_psi_val, &style_midtext);
  lv_label_set_style(box_intake2_val, &style_midtext);
  lv_label_set_style(box_intake_val, &style_midtext);
  lv_label_set_style(box_distance_val, &style_midtext);

  // set the text to the labels to -2
  lv_label_set_text(box_m1_val, "199%");
  lv_label_set_text(box_m2_val, "-99%");
  lv_label_set_text(box_m3_val, "-99%");
  lv_label_set_text(box_m11_val, "-99%");
  lv_label_set_text(box_m12_val, "-99%");
  lv_label_set_text(box_m13_val, "-99%");
  lv_label_set_text(box_battery_val, "100%");
  lv_label_set_text(box_psi_val, "100");
  lv_label_set_text(box_intake2_val, "-99%");
  lv_label_set_text(box_intake_val, "-99%");
  lv_label_set_text(box_distance_val, "-99%");

  // Position the labels in the boxes to above center

  // 7 is the offset for 4 digit numbers
  // 9 is the offset for 3 digit numbers

  lv_obj_align(box_m1_val, box_m1, LV_ALIGN_CENTER, 7, -15);
  lv_obj_align(box_m2_val, box_m2, LV_ALIGN_CENTER, 10, -15);
  lv_obj_align(box_m3_val, box_m3, LV_ALIGN_CENTER, 0, -15);
  lv_obj_align(box_m11_val, box_m11, LV_ALIGN_CENTER, 0, -15);
  lv_obj_align(box_m12_val, box_m12, LV_ALIGN_CENTER, 0, -15);
  lv_obj_align(box_m13_val, box_m13, LV_ALIGN_CENTER, 0, -15);
  lv_obj_align(box_battery_val, box_battery, LV_ALIGN_CENTER, -30, 0);
  lv_obj_align(box_psi_val, box_psi, LV_ALIGN_CENTER, -45, 0);
  lv_obj_align(box_intake2_val, box_intake2, LV_ALIGN_CENTER, 0, -15);
  lv_obj_align(box_intake_val, box_intake, LV_ALIGN_CENTER, 0, -15);
  lv_obj_align(box_distance_val, box_distance, LV_ALIGN_CENTER, 0, -15);

  // Icon
  //logo = createImage(gamescr, 382, 157, 8, &small_image);
  logo = createImageButton(gamescr, &small_image, 384, 157);
  lv_imgbtn_set_src(logo, LV_BTN_STATE_REL, &small_image);
  lv_imgbtn_set_src(logo, LV_BTN_STATE_PR, &small_image);
  lv_btn_set_style(logo, LV_BTN_STYLE_REL, &style_btn);
  lv_btn_set_style(logo, LV_BTN_STATE_PR, &style_btn_selected);
  lv_btn_set_action(logo, LV_BTN_ACTION_CLICK, m_btn_open_theme_switcher);

  std::ostringstream buildtagstr;
  // if contains MSYS, then it is windows
  // if contains linux, then it is linux
  // if contains darwin, then it is mac
  auto buildenv = "";
  if (string(BUILD_ENVIRONMENT).find("MSYS") != std::string::npos) {
    buildenv = "Built on Windows";
  } else if (string(BUILD_ENVIRONMENT).find("zorinos") != std::string::npos) {
    buildenv = "Built on Linux";
  } else if (string(BUILD_ENVIRONMENT).find("darwin") != std::string::npos) {
    // Untested 	buildenv = "Built on Mac";
  } else {
    buildenv = "Unknown Build Environment";
  }
  buildtagstr << "Build: " << BUILD_DATE << " -- v" << CODEBASE_VERSION << "@"
              << APPLICATION_ENVIRONMENT << "-" << BUILD_NUMBER << "+"
              << std::string(GIT_COMMIT).substr(0, 6) << "\n"
              << buildenv << " - Git Branch: " << "(" << GIT_BRANCH << ")"
              << " - " << ROBOT_NAME << COMPETITION_NAME;
  // buildtagstr << BUILD_ENVIRONMENT;
  buildtag = createLabel(matchscr, 0, 220, buildtagstr.str().c_str());
  lv_obj_set_style(buildtag, &style_buildtext);

  //lv_obj_t* stockingsOverlay = createImage(gamescr, 0, 0, 1, &ChristmasStockings);
  // return mutex
  dataMutex.give();
  // lv_scr_load(gamescr);
  //  set id
  // lv_obj_set_free_num(gamescr, 1337);

  // lv_obj_t *logo;
  // char *text;
  // if (useChicken == 2)
  // {
  // 	logo = createImage(gamescr, 24, 24, 8, &chicken_sandwich);
  // 	text = "Chicken";
  // }
  // else
  // {
  // 	logo = createImage(gamescr, 24, 24, 8, &Robotics_Logo_Huge);
  // 	text = "83280X";
  // }

  /*
  // custom image style
  static lv_style_t style_img;
  lv_style_copy(&style_img, &lv_style_plain);
  style_img.image.color = LV_COLOR_MAKE(0xff, 0x00, 0x00); // #ff0000
  lv_obj_set_style(logo, &style_img);
  // teamname
  lv_obj_t *teamname = lv_label_create(gamescr, NULL);
  lv_label_set_text(teamname, text);
  lv_obj_set_pos(teamname, 240, 87);
  // custom style
  static lv_style_t style_teamname2;
  lv_style_copy(&style_teamname2, &style_teamname);
  style_teamname2.text.font = &blackopsone_50;
  // apply
  lv_obj_set_style(teamname, &style_teamname2);
  */

  lv_style_t style_newmidnightblue;
  lv_style_copy(&style_newmidnightblue, &style_box);
  style_newmidnightblue.body.main_color =
      LV_COLOR_MAKE(0x1f, 0x28, 0x2f);  // #1f282f
  style_newmidnightblue.body.grad_color =
      LV_COLOR_MAKE(0x1f, 0x28, 0x2f);  // #1f282f
  style_newmidnightblue.body.opa = LV_OPA_100;

  lv_btn_set_action(box_autonsel, LV_BTN_ACTION_CLICK,
                    m_btn_open_selector_screen_again);
  lv_btn_set_style(box_autonsel, LV_BTN_STYLE_REL, &style_midnightblue);
  lv_btn_set_style(box_autonsel, LV_BTN_STATE_PR, &style_midnightblue);
  lv_obj_set_style(box_autonsel, &style_midnightblue);

  // ----------------- Switch Theme Screen -----------------
  switchscr = lv_obj_create(NULL, NULL);

  lv_obj_set_style(switchscr, &style_bg);
  lv_obj_t* switchscr_logo = createImage(switchscr, 0, 0, 1, &bg_image);
  lv_obj_t* teamNumberTwo = createLabel(switchscr, 152, 8, "83280X");
  lv_label_set_style(teamNumberTwo, &style_teamname);

  // Background Box
  lv_obj_t* switchscr_box = lv_obj_create(switchscr, NULL);
  lv_obj_set_size(switchscr_box, 273, 172);
  lv_obj_set_pos(switchscr_box, 103, 57);
  lv_obj_set_style(switchscr_box, &roller_bg_style);

  // Theme Text (Top right of box)
  // lv_obj_t* switchscr_theme_text = createLabel(switchscr, 50, 60, "Theme");
  // lv_label_set_style(switchscr_theme_text, &style_midtext);

  // Theme Switch Buttons
  // lv_obj_t* switchscr_btn_hellokitty = createBtn(switchscr, 72, 92, 72, 72, 5, "Hello Kitty");
  // lv_btn_set_style(switchscr_btn_hellokitty, LV_BTN_STYLE_REL, &style_btn);
  // lv_btn_set_style(switchscr_btn_hellokitty, LV_BTN_STATE_PR, &style_btn_selected);
  // lv_btn_set_action(switchscr_btn_hellokitty, LV_BTN_ACTION_PR, m_btn_set_theme_hellokitty);

  // lv_obj_t* switchscr_btn_marble =
  //     createBtn(switchscr, 159, 90, 72, 72, 6, "Marble");
  // lv_btn_set_style(switchscr_btn_marble, LV_BTN_STYLE_REL, &style_btn);
  // lv_btn_set_style(switchscr_btn_marble, LV_BTN_STATE_PR, &style_btn_selected);
  // lv_btn_set_action(switchscr_btn_marble, LV_BTN_ACTION_PR, m_btn_set_theme_marble);

  // lv_obj_t* switchscr_btn_darkknight =
  //     createBtn(switchscr, 247, 90, 72, 72, 7, "Dark Knight");
  // lv_btn_set_style(switchscr_btn_darkknight, LV_BTN_STYLE_REL, &style_btn);
  // lv_btn_set_style(switchscr_btn_darkknight, LV_BTN_STATE_PR, &style_btn_selected);
  // lv_btn_set_action(switchscr_btn_darkknight, LV_BTN_ACTION_PR, m_btn_set_theme_batman);

  // lv_obj_t* switchscr_btn_og =
  //     createBtn(switchscr, 336, 90, 72, 72, 8, "OG");
  // lv_btn_set_style(switchscr_btn_og, LV_BTN_STYLE_REL, &style_btn);
  // lv_btn_set_style(switchscr_btn_og, LV_BTN_STATE_PR, &style_btn_selected);
  // lv_btn_set_action(switchscr_btn_og, LV_BTN_ACTION_PR, m_btn_set_theme_og);

  lv_obj_t* switchscr_btn_hellokitty =
      createImgBtn(switchscr, 115, 66, 5, &helloKittyButton);
  lv_imgbtn_set_src(switchscr_btn_hellokitty, LV_BTN_STATE_PR,
                    &helloKittyButton);
  lv_btn_set_action(switchscr_btn_hellokitty, LV_BTN_ACTION_CLICK,
                    m_btn_set_theme_hellokitty);

  lv_obj_t* switchscr_btn_marble =
      createImgBtn(switchscr, 293, 66, 6, &redMarbleButton);
  lv_imgbtn_set_src(switchscr_btn_marble, LV_BTN_STATE_PR, &redMarbleButton);
  lv_btn_set_action(switchscr_btn_marble, LV_BTN_ACTION_CLICK,
                    m_btn_set_theme_marble);

  lv_obj_t* switchscr_btn_nick =
      createImgBtn(switchscr, 204, 66, 7, &nicksthemeicon);
  lv_imgbtn_set_src(switchscr_btn_nick, LV_BTN_STATE_PR, &nicksthemeicon);
  lv_btn_set_action(switchscr_btn_nick, LV_BTN_ACTION_CLICK,
                    m_btn_set_theme_nick);

  lv_obj_t* switchscr_btn_og = createImgBtn(switchscr, 293, 148, 8, &ogButton);
  lv_imgbtn_set_src(switchscr_btn_og, LV_BTN_STATE_PR, &ogButton);
  lv_btn_set_action(switchscr_btn_og, LV_BTN_ACTION_CLICK, m_btn_set_theme_og);

  lv_obj_t* switchscr_btn_christmas =
      createImgBtn(switchscr, 115, 148, 9, &ChristmasButton);
  lv_imgbtn_set_src(switchscr_btn_christmas, LV_BTN_STATE_PR, &ChristmasButton);
  lv_btn_set_action(switchscr_btn_christmas, LV_BTN_ACTION_CLICK,
                    m_btn_set_theme_christmas);

  // lv_obj_t* switchscr_btn_thanksgiving = createImgBtn(switchscr, 204, 148, 10, &ThanksgivingButton);
  // lv_imgbtn_set_src(switchscr_btn_thanksgiving, LV_BTN_STATE_PR, &ThanksgivingButton);
  // lv_btn_set_action(switchscr_btn_thanksgiving, LV_BTN_ACTION_CLICK, m_btn_set_theme_thanksgiving);

  //lv_scr_load(switchscr);
  // pros::delay(2500);
  // switchTheme(Theme::MARBLE);
}

void task_updvar(void* param) {
  while (true) {
    pros::delay(250);  // Delay to prevent overloading the CPU

    dataMutex.take(2000);  // Try to take the mutex

    // Update the shared data
    // Update the shared data
    drivetrain_left_a_temp = pros::c::motor_get_temperature(MOTOR_PORT_LEFT_A);
    if (drivetrain_left_a_temp == PROS_ERR_F)
      drivetrain_left_a_temp = -1;

    drivetrain_left_b_temp = pros::c::motor_get_temperature(MOTOR_PORT_LEFT_B);
    if (drivetrain_left_b_temp == PROS_ERR_F)
      drivetrain_left_b_temp = -1;

    drivetrain_left_c_temp = pros::c::motor_get_temperature(MOTOR_PORT_LEFT_C);
    if (drivetrain_left_c_temp == PROS_ERR_F)
      drivetrain_left_c_temp = -1;

    drivetrain_right_a_temp =
        pros::c::motor_get_temperature(MOTOR_PORT_RIGHT_A);
    if (drivetrain_right_a_temp == PROS_ERR_F)
      drivetrain_right_a_temp = -1;

    drivetrain_right_b_temp =
        pros::c::motor_get_temperature(MOTOR_PORT_RIGHT_B);
    if (drivetrain_right_b_temp == PROS_ERR_F)
      drivetrain_right_b_temp = -1;

    drivetrain_right_c_temp =
        pros::c::motor_get_temperature(MOTOR_PORT_RIGHT_C);
    if (drivetrain_right_c_temp == PROS_ERR_F)
      drivetrain_right_c_temp = -1;

    intake_temp = pros::c::motor_get_temperature(MOTOR_PORT_INTAKE);
    if (intake_temp == PROS_ERR_F)
      intake_temp = -1;

    intake2_temp = pros::c::motor_get_temperature(MOTOR_PORT_INTAKE2);
    if (intake2_temp == PROS_ERR_F)
      intake2_temp = -1;

    // if (pros::c::link_connected(GEN_PORT_distance_PRIMARY)) {
    //   distance_status = 0;
    // } else if (pros::c::link_connected(GEN_PORT_distance_BACKUP)) {
    //   distance_status = 1;
    // } else {
    //   distance_status = -1;
    // }

    if (distance_status == PROS_ERR_F)
      distance_status = -1;

    batteryCharge = pros::battery::get_capacity();
    if (batteryCharge == PROS_ERR)
      batteryCharge = -1;

    dataMutex.give();  // Release the mutex
  }
}

void task_updui(void* param) {
  while (true) {
    pros::delay(100);  // Delay to prevent overloading the CPU

    // Make sure the mutex is available
    dataMutex.take(2000);  // Try to take the mutex
    // Make sure the Game Screen is loaded
    if (lv_scr_act() == gamescr) {
      // 7 is the offset for 4 digit numbers
      // 9 is the offset for 3 digit numbers

      if (drivetrain_left_a_temp != -1) {
        lv_label_set_text(
            box_m1_val,
            (std::to_string((int)drivetrain_left_a_temp) + "C").c_str());
      } else {
        lv_label_set_text(box_m1_val, "ERR");
      }
      if (drivetrain_left_b_temp != -1) {
        lv_label_set_text(
            box_m2_val,
            (std::to_string((int)drivetrain_left_b_temp) + "C").c_str());
      } else {
        lv_label_set_text(box_m2_val, "ERR");
      }
      if (drivetrain_left_c_temp != -1) {
        lv_label_set_text(
            box_m3_val,
            (std::to_string((int)drivetrain_left_c_temp) + "C").c_str());
      } else {
        lv_label_set_text(box_m3_val, "ERR");
      }
      if (drivetrain_right_a_temp != -1) {
        lv_label_set_text(
            box_m11_val,
            (std::to_string((int)drivetrain_right_a_temp) + "C").c_str());
      } else {
        lv_label_set_text(box_m11_val, "ERR");
      }
      if (drivetrain_right_b_temp != -1) {
        lv_label_set_text(
            box_m12_val,
            (std::to_string((int)drivetrain_right_b_temp) + "C").c_str());
      } else {
        lv_label_set_text(box_m12_val, "ERR");
      }
      if (drivetrain_right_c_temp != -1) {
        lv_label_set_text(
            box_m13_val,
            (std::to_string((int)drivetrain_right_c_temp) + "C").c_str());
      } else {
        lv_label_set_text(box_m13_val, "ERR");
      }
      if (intake_temp != -1) {
        lv_label_set_text(box_intake_val,
                          (std::to_string((int)intake_temp) + "C").c_str());
      } else {
        lv_label_set_text(box_intake_val, "ERR");
      }
      // if (distance_status != -1) {
      //   lv_label_set_text(box_distance_val,
      //                     (std::to_string((int)distance_status) + "C").c_str());
      // } else {
      //   lv_label_set_text(box_distance_val, "ERR");
      // }
      if (pros::c::distance_get(SENSOR_PORT_MOGO_DISTANCE) != PROS_ERR) {
        lv_label_set_text(box_distance_val, to_string(pros::c::distance_get(SENSOR_PORT_MOGO_DISTANCE)).c_str());
      }
      else {
        lv_label_set_text(box_distance_val, "ERR");
      }
      if (intake2_temp != -1) {
        lv_label_set_text(box_intake2_val,
                          (std::to_string((int)intake2_temp) + "C").c_str());
      } else {
        lv_label_set_text(box_intake2_val, "ERR");
      }

      if (batteryCharge != -1) {
        lv_label_set_text(box_battery_val,
                          (std::to_string((int)batteryCharge) + "%").c_str());
      } else {
        lv_label_set_text(box_battery_val, "ERR");
      }
      if (estpsi != -1) {
        lv_label_set_text(box_psi_val, std::to_string((int)estpsi).c_str());
      } else {
        lv_label_set_text(box_psi_val, "ERR");
      }

      // Adjusting Placement for 3 or 4 digit Values
      // 7 is the offset for 4 digit numbers
      // 9 is the offset for 3 digit numbers

      if (drivetrain_left_a_temp >= 100) {
        lv_obj_align(box_m1_val, box_m1, LV_ALIGN_CENTER, 0, -15);
      } else {
        lv_obj_align(box_m1_val, box_m1, LV_ALIGN_CENTER, -1, -15);
      }
      if (drivetrain_left_b_temp >= 100) {
        lv_obj_align(box_m2_val, box_m2, LV_ALIGN_CENTER, 0, -15);
      } else {
        lv_obj_align(box_m2_val, box_m2, LV_ALIGN_CENTER, -1, -15);
      }
      if (drivetrain_left_c_temp >= 100) {
        lv_obj_align(box_m3_val, box_m3, LV_ALIGN_CENTER, 0, -15);
      } else {
        lv_obj_align(box_m3_val, box_m3, LV_ALIGN_CENTER, -1, -15);
      }
      if (drivetrain_right_a_temp >= 100) {
        lv_obj_align(box_m11_val, box_m11, LV_ALIGN_CENTER, 0, -15);
      } else {
        lv_obj_align(box_m11_val, box_m11, LV_ALIGN_CENTER, -1, -15);
      }
      if (drivetrain_right_b_temp >= 100) {
        lv_obj_align(box_m12_val, box_m12, LV_ALIGN_CENTER, 0, -15);
      } else {
        lv_obj_align(box_m12_val, box_m12, LV_ALIGN_CENTER, -1, -15);
      }
      if (drivetrain_right_c_temp >= 100) {
        lv_obj_align(box_m13_val, box_m13, LV_ALIGN_CENTER, 0, -15);
      } else {
        lv_obj_align(box_m13_val, box_m13, LV_ALIGN_CENTER, -1, -15);
      }
      // if (ActivedistanceConnection >= 100) {
      //   lv_obj_align(box_intake2_val, box_intake2, LV_ALIGN_CENTER, 0, -15);
      // } else {
      //   lv_obj_align(box_intake2_val, box_intake2, LV_ALIGN_CENTER, -1, -15);
      // }
      if (intake_temp >= 100) {
        lv_obj_align(box_intake_val, box_intake, LV_ALIGN_CENTER, 0, -15);
      } else {
        lv_obj_align(box_intake_val, box_intake, LV_ALIGN_CENTER, -1, -15);
      }
      if (intake2_temp >= 100) {
        lv_obj_align(box_intake2_val, box_intake2, LV_ALIGN_CENTER, 0, -15);
      } else {
        lv_obj_align(box_intake2_val, box_intake2, LV_ALIGN_CENTER, -1, -15);
      }

      /*
       * LOGIC FOR BOX COLOR CHANGING
       */

      // Left Drive Temperature
      if (drivetrain_left_a_temp < MOTOR_WARNING_TEMP &&
          drivetrain_left_a_temp > 0) {
        lv_obj_set_style(box_m1, &box_color_temp_normal);
      } else if (drivetrain_left_a_temp < MOTOR_OVERTEMP_LEVEL1) {
        lv_obj_set_style(box_m1, &box_color_temp_warning);
      } else if (drivetrain_left_a_temp < MOTOR_OVERTEMP_LEVEL2) {
        lv_obj_set_style(box_m1, &box_color_temp_level1);
      } else if (drivetrain_left_a_temp < MOTOR_OVERTEMP_LEVEL3) {
        lv_obj_set_style(box_m1, &box_color_temp_level2);
      } else if (drivetrain_left_a_temp < MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_m1, &box_color_temp_level3);
      } else if (drivetrain_left_a_temp >= MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_m1, &box_color_temp_level4);
      } else {
        lv_obj_set_style(box_m1, &box_color_temp_error);
      }

      if (drivetrain_left_b_temp < MOTOR_WARNING_TEMP &&
          drivetrain_left_b_temp > 0) {
        lv_obj_set_style(box_m2, &box_color_temp_normal);
      } else if (drivetrain_left_b_temp < MOTOR_OVERTEMP_LEVEL1) {
        lv_obj_set_style(box_m2, &box_color_temp_warning);
      } else if (drivetrain_left_b_temp < MOTOR_OVERTEMP_LEVEL2) {
        lv_obj_set_style(box_m2, &box_color_temp_level1);
      } else if (drivetrain_left_b_temp < MOTOR_OVERTEMP_LEVEL3) {
        lv_obj_set_style(box_m2, &box_color_temp_level2);
      } else if (drivetrain_left_b_temp < MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_m2, &box_color_temp_level3);
      } else if (drivetrain_left_b_temp >= MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_m2, &box_color_temp_level4);
      } else {
        lv_obj_set_style(box_m2, &box_color_temp_error);
      }

      if (drivetrain_left_c_temp < MOTOR_WARNING_TEMP &&
          drivetrain_left_c_temp > 0) {
        lv_obj_set_style(box_m3, &box_color_temp_normal);
      } else if (drivetrain_left_c_temp < MOTOR_OVERTEMP_LEVEL1) {
        lv_obj_set_style(box_m3, &box_color_temp_warning);
      } else if (drivetrain_left_c_temp < MOTOR_OVERTEMP_LEVEL2) {
        lv_obj_set_style(box_m3, &box_color_temp_level1);
      } else if (drivetrain_left_c_temp < MOTOR_OVERTEMP_LEVEL3) {
        lv_obj_set_style(box_m3, &box_color_temp_level2);
      } else if (drivetrain_left_c_temp < MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_m3, &box_color_temp_level3);
      } else if (drivetrain_left_c_temp >= MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_m3, &box_color_temp_level4);
      } else {
        lv_obj_set_style(box_m3, &box_color_temp_error);
      }

      // Right Drive Temperature
      if (drivetrain_right_a_temp < MOTOR_WARNING_TEMP &&
          drivetrain_right_a_temp > 0) {
        lv_obj_set_style(box_m11, &box_color_temp_normal);
      } else if (drivetrain_right_a_temp < MOTOR_OVERTEMP_LEVEL1) {
        lv_obj_set_style(box_m11, &box_color_temp_warning);
      } else if (drivetrain_right_a_temp < MOTOR_OVERTEMP_LEVEL2) {
        lv_obj_set_style(box_m11, &box_color_temp_level1);
      } else if (drivetrain_right_a_temp < MOTOR_OVERTEMP_LEVEL3) {
        lv_obj_set_style(box_m11, &box_color_temp_level2);
      } else if (drivetrain_right_a_temp < MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_m11, &box_color_temp_level3);
      } else if (drivetrain_right_a_temp >= MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_m11, &box_color_temp_level4);
      } else {
        lv_obj_set_style(box_m11, &box_color_temp_error);
      }

      if (drivetrain_right_b_temp < MOTOR_WARNING_TEMP &&
          drivetrain_right_b_temp > 0) {
        lv_obj_set_style(box_m12, &box_color_temp_normal);
      } else if (drivetrain_right_b_temp < MOTOR_OVERTEMP_LEVEL1) {
        lv_obj_set_style(box_m12, &box_color_temp_warning);
      } else if (drivetrain_right_b_temp < MOTOR_OVERTEMP_LEVEL2) {
        lv_obj_set_style(box_m12, &box_color_temp_level1);
      } else if (drivetrain_right_b_temp < MOTOR_OVERTEMP_LEVEL3) {
        lv_obj_set_style(box_m12, &box_color_temp_level2);
      } else if (drivetrain_right_b_temp < MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_m12, &box_color_temp_level3);
      } else if (drivetrain_right_b_temp >= MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_m12, &box_color_temp_level4);
      } else {
        lv_obj_set_style(box_m12, &box_color_temp_error);
      }

      if (drivetrain_right_c_temp < MOTOR_WARNING_TEMP &&
          drivetrain_right_c_temp > 0) {
        lv_obj_set_style(box_m13, &box_color_temp_normal);
      } else if (drivetrain_right_c_temp < MOTOR_OVERTEMP_LEVEL1) {
        lv_obj_set_style(box_m13, &box_color_temp_warning);
      } else if (drivetrain_right_c_temp < MOTOR_OVERTEMP_LEVEL2) {
        lv_obj_set_style(box_m13, &box_color_temp_level1);
      } else if (drivetrain_right_c_temp < MOTOR_OVERTEMP_LEVEL3) {
        lv_obj_set_style(box_m13, &box_color_temp_level2);
      } else if (drivetrain_right_c_temp < MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_m13, &box_color_temp_level3);
      } else if (drivetrain_right_c_temp >= MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_m13, &box_color_temp_level4);
      } else {
        lv_obj_set_style(box_m13, &box_color_temp_error);
      }

      // Intake Temperature
      if (intake_temp < MOTOR_WARNING_TEMP && intake_temp > 0) {
        lv_obj_set_style(box_intake, &box_color_temp_normal);
      } else if (intake_temp < MOTOR_OVERTEMP_LEVEL1) {
        lv_obj_set_style(box_intake, &box_color_temp_warning);
      } else if (intake_temp < MOTOR_OVERTEMP_LEVEL2) {
        lv_obj_set_style(box_intake, &box_color_temp_level1);
      } else if (intake_temp < MOTOR_OVERTEMP_LEVEL3) {
        lv_obj_set_style(box_intake, &box_color_temp_level2);
      } else if (intake_temp < MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_intake, &box_color_temp_level3);
      } else if (intake_temp >= MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_intake, &box_color_temp_level4);
      } else {
        lv_obj_set_style(box_intake, &box_color_temp_error);
      }

      // Intake2 Temperature
      if (intake2_temp < MOTOR_WARNING_TEMP && intake2_temp > 0) {
        lv_obj_set_style(box_intake2, &box_color_temp_normal);
      } else if (intake2_temp < MOTOR_OVERTEMP_LEVEL1) {
        lv_obj_set_style(box_intake2, &box_color_temp_warning);
      } else if (intake2_temp < MOTOR_OVERTEMP_LEVEL2) {
        lv_obj_set_style(box_intake2, &box_color_temp_level1);
      } else if (intake2_temp < MOTOR_OVERTEMP_LEVEL3) {
        lv_obj_set_style(box_intake2, &box_color_temp_level2);
      } else if (intake2_temp < MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_intake2, &box_color_temp_level3);
      } else if (intake2_temp >= MOTOR_OVERTEMP_LEVEL4) {
        lv_obj_set_style(box_intake2, &box_color_temp_level4);
      } else {
        lv_obj_set_style(box_intake2, &box_color_temp_error);
      }

      // distance Status
      if (pros::c::distance_get(SENSOR_PORT_MOGO_DISTANCE) > 15 &&
          pros::c::distance_get(SENSOR_PORT_MOGO_DISTANCE) < 30) {
        lv_obj_set_style(box_distance, box_green);
      } else if (pros::c::distance_get(SENSOR_PORT_MOGO_DISTANCE) < 15 &&
                 pros::c::distance_get(SENSOR_PORT_MOGO_DISTANCE) > 0) {
        lv_obj_set_style(box_distance, box_blue);
      } else {
        lv_obj_set_style(box_distance, box_red);
      }

      // Battery Charge
      if (batteryCharge > 50) {
        lv_obj_set_style(box_battery, box_green);
      } else if (batteryCharge > 25) {
        lv_obj_set_style(box_battery, box_yellow);
      } else {
        lv_obj_set_style(box_battery, box_red);
      }

      // PSI
      if (estpsi > 75) {
        lv_obj_set_style(box_psi, box_green);
      } else if (estpsi > 50) {
        lv_obj_set_style(box_psi, box_yellow);
      } else {
        lv_obj_set_style(box_psi, box_red);
      }
    }

    dataMutex.give();  // Release the mutex
  }
}

void create_tasks() {
  pros::Task update_var_task(task_updvar, nullptr, TASK_PRIORITY_DEFAULT,
                             TASK_STACK_DEPTH_DEFAULT, "UpdateVarTask");
  pros::Task update_ui_task(task_updui, nullptr, TASK_PRIORITY_DEFAULT,
                            TASK_STACK_DEPTH_DEFAULT, "UpdateUITask");
}

void mogoActuation() {
  estpsi -= 2;
}

void sweeperActuation() {
  estpsi -= 2;
}

#endif