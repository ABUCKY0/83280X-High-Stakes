#include "main.h"
#include "pros/apix.h"
#include "./Helpers/helpers.h"
#include "../Constants/constants.h"
#include <sstream>
#if USE_UI == 1

lv_obj_t *auton_selector;
lv_style_t *box_red;
lv_style_t *box_green;
lv_style_t *box_yellow;
lv_style_t *box_blue;
lv_style_t *box_midnightblue;

static lv_obj_t *box_m1;
static lv_obj_t *box_m2;
static lv_obj_t *box_m3;
static lv_obj_t *box_m11;
static lv_obj_t *box_m12;
static lv_obj_t *box_m13;
static lv_obj_t *box_intake1;
static lv_obj_t *box_intake2;
static lv_obj_t *box_launcher;
static lv_obj_t *box_logo;
static lv_obj_t *box_battery;
static lv_obj_t *box_psi;
static lv_obj_t *box_autonsel;

static lv_obj_t *box_m1_label;
static lv_obj_t *box_m2_label;
static lv_obj_t *box_m3_label;
static lv_obj_t *box_m11_label;
static lv_obj_t *box_m12_label;
static lv_obj_t *box_m13_label;
static lv_obj_t *box_intake1_label;
static lv_obj_t *box_intake2_label;
static lv_obj_t *box_launcher_label;
static lv_obj_t *box_logo_label;
static lv_obj_t *box_battery_label;
static lv_obj_t *box_psi_label;
static lv_obj_t *box_autonsel_label;

static lv_obj_t *box_m1_val;
static lv_obj_t *box_m2_val;
static lv_obj_t *box_m3_val;
static lv_obj_t *box_m11_val;
static lv_obj_t *box_m12_val;
static lv_obj_t *box_m13_val;
static lv_obj_t *box_intake1_val;
static lv_obj_t *box_intake2_val;
static lv_obj_t *box_launcher_val;
static lv_obj_t *box_logo_val;
static lv_obj_t *box_battery_val;
static lv_obj_t *box_psi_val;

// Auton Selection Arrays
static const char *auton_options[] = {"BLU-C", "BLU-F", "RED-C", "RED-F"};
static const char *skills_options[] =  {"SKI-A", "SKI-B", "SKI-C", "SDRVR"};

string match_autons = "Blue Close\nBlue Far\nRed Close\nRed Far";
string skills_autons = "Auton A\nAuton B\nAuton C\nDriver";

pros::Mutex dataMutex; // Mutex to protect shared data

double motor1Temp = 0.0;
double motor2Temp = 0.0;
double motor3Temp = 0.0;
double motor11Temp = 0.0;
double motor12Temp = 0.0;
double motor13Temp = 0.0;
double motorIntakeTemp1 = 0.0;
double motorIntakeTemp2 = 0.0;
double motorLauncherTemp = 0.0;
double estpsi = 100.0;
double batteryCharge = 0.0;

// on press confirm
lv_res_t onMatchConfirmPress(lv_obj_t *btn)
{
	cout << "[UI] (INFO): Autonomous Selection Confirmed\n";
	cout << "[UI] (INFO): Switching to Game Screen\n";
	auton = lv_roller_get_selected(auton_selector);
	if (gameMode == 0)
	{
		cout << "[UI] (INFO): Setting Match Auton Value\n";
		lv_label_set_text(box_autonsel_label, auton_options[auton]);
	}
	else
	{
		cout << "[UI] (INFO): Setting Skills Auton Value\n";
		lv_label_set_text(box_autonsel_label, skills_options[auton]);
	}
	lv_scr_load(gamescr);
	return LV_RES_OK;
}

lv_res_t m_btn_action_skills(lv_obj_t *btn)
{
	// Get Roller
	cout << "[UI] (INFO): Skills Mode Switching\n";
	lv_roller_set_options(auton_selector, skills_autons.c_str());
	cout << "[UI] (INFO): Setting gameMode to 1\n";
	gameMode = 1;
	return LV_RES_OK;
}

lv_res_t m_btn_action_match(lv_obj_t *btn)
{
	// Get Roller
	cout << "[UI] (INFO): Match Mode Switching @ " << millis() << "\n";
	lv_roller_set_options(auton_selector, match_autons.c_str());
	cout << "[UI] (INFO): Setting gameMode to 0\n";
	gameMode = 0;
	return LV_RES_OK;
}

void init_marble_ui()
{
	cout << "[UI] (INFO): Initalizing matchscr\n";
	matchscr = lv_obj_create(NULL, NULL);

	/* ------------- Shared Styles ------------- */
	cout << "[UI] (INFO): [STYLE] [CREATION] style_bg\n";
	// Background
	static lv_style_t style_bg;
	lv_style_copy(&style_bg, &lv_style_plain);
	style_bg.body.main_color = LV_COLOR_MAKE(0x1f, 0x28, 0x2f); // 1f282f
	style_bg.body.grad_color = LV_COLOR_MAKE(0x1f, 0x28, 0x2f); // RGB for bright blue

	/* Create a style for the button */
	cout << "[UI] (INFO): [STYLE] [CREATION] style_btn\n";
	static lv_style_t style_btn;
	lv_style_copy(&style_btn, &lv_style_plain); // copy from the plain style
	style_btn.body.main_color = LV_COLOR_RED;	// set the main color to red
	style_btn.body.grad_color = LV_COLOR_RED;	// set the gradient color to red
	style_btn.body.radius = 8;					// set the corner radius
	style_btn.text.font = &blackopsone_18;		// set the font (replace with your font)
	style_btn.text.letter_space = .5;			// set the space between letters
	style_btn.text.color = LV_COLOR_WHITE;

	/* Button Selected */
	cout << "[UI] (INFO): [STYLE] [CREATION] style_btn_selected\n";
	static lv_style_t style_btn_selected;
	lv_style_copy(&style_btn_selected, &lv_style_plain);			 // copy from the plain style
	style_btn_selected.body.main_color = LV_COLOR_BLACK;			 // set the main color to red
	style_btn_selected.body.grad_color = LV_COLOR_BLACK;			 // set the gradient color to red
	style_btn_selected.body.radius = 8;								 // set the corner radius
	style_btn_selected.text.font = &blackopsone_18;					 // set the font (replace with your font)
	style_btn_selected.text.letter_space = .5;						 // set the space between letters
	style_btn_selected.text.color = LV_COLOR_MAKE(0x8b, 0x8a, 0x8b); // #8b8a8b

	// COnfirm Button Style
	cout << "[UI] (INFO): [STYLE] [CREATION] style_confirmtbn\n";
	static lv_style_t style_confirmbtn;
	lv_style_copy(&style_confirmbtn, &lv_style_plain);
	style_confirmbtn.body.main_color = LV_COLOR_RED; // set the main color to red
	style_confirmbtn.body.grad_color = LV_COLOR_RED; // set the gradient color to red
	style_confirmbtn.body.radius = 8;				 // set the corner radius
	style_confirmbtn.text.font = &blackopsone_20;	 // set the font (replace with your font)
	style_confirmbtn.text.letter_space = .5;		 // set the space between letters
	style_confirmbtn.text.color = LV_COLOR_WHITE;

	// confirm button selected
	cout << "[UI] (INFO): [STYLE] [CREATION] style_confirmbtn_selected\n";
	static lv_style_t style_confirmbtn_selected;
	lv_style_copy(&style_confirmbtn_selected, &lv_style_plain);
	style_confirmbtn_selected.body.main_color = LV_COLOR_BLACK;
	style_confirmbtn_selected.body.grad_color = LV_COLOR_BLACK;
	style_confirmbtn_selected.body.radius = 8;								// set the corner radius
	style_confirmbtn_selected.text.font = &blackopsone_20;					// set the font (replace with your font)
	style_confirmbtn_selected.text.letter_space = .5;						// set the space between letters
	style_confirmbtn_selected.text.color = LV_COLOR_MAKE(0x8b, 0x8a, 0x8b); // #8b8a8b

	// team name style
	cout << "[UI] (INFO): [STYLE] [CREATION] style_teamname\n";
	static lv_style_t style_teamname;
	lv_style_copy(&style_teamname, &lv_style_plain);
	style_teamname.text.font = &blackopsone_40;
	style_teamname.text.color = LV_COLOR_MAKE(0xD0, 0xA9, 0x33); // #D0A933

	// roller style
	cout << "[UI] (INFO): [STYLE] [CREATION] style_roller\n";
	static lv_style_t style_roller;
	lv_style_copy(&style_roller, &lv_style_plain);
	style_roller.text.font = &blackopsone_18;
	style_roller.body.main_color = LV_COLOR_MAKE(0x92, 0x92, 0x92); // #929292
	style_roller.body.grad_color = LV_COLOR_MAKE(0x92, 0x92, 0x92); // #929292
	style_roller.body.opa = LV_OPA_0;
	style_roller.text.color = LV_COLOR_WHITE;
	style_roller.body.empty = 1;
	style_roller.body.radius = 11;
	style_roller.body.padding.hor = 15;
	style_roller.body.padding.ver = 10;
	style_roller.text.line_space = 5;

	/* Create a style for the roller selected option */
	cout << "[UI] (INFO): [STYLE] [CREATION] roller_style_selected\n";
	static lv_style_t roller_style_selected;
	lv_style_copy(&roller_style_selected, &lv_style_plain);
	roller_style_selected.text.color = LV_COLOR_BLACK; // set the text color to red
	roller_style_selected.body.border.color = LV_COLOR_BLACK;
	roller_style_selected.body.grad_color = LV_COLOR_MAKE(0x92, 0x92, 0x92); // #929292
	roller_style_selected.body.main_color = LV_COLOR_MAKE(0x92, 0x92, 0x92); // #929292
	roller_style_selected.body.border.width = 3;
	roller_style_selected.body.radius = 11;
	style_roller.body.padding.hor = 15;
	style_roller.body.padding.ver = 10;
	style_roller.text.line_space = 5;

	// Roller Background Style
	cout << "[UI] (INFO): [STYLE] [CREATION] roller_bg_style\n";
	static lv_style_t roller_bg_style;
	lv_style_copy(&roller_bg_style, &lv_style_plain);
	roller_bg_style.body.opa = LV_OPA_70;
	roller_bg_style.body.main_color = LV_COLOR_BLACK;
	roller_bg_style.body.grad_color = LV_COLOR_BLACK;
	/* ----------- Begin Match Screen ---------- */

	cout << "[UI] (INFO): [SCREEN] [LOAD] matchscr\n";
	lv_scr_load(matchscr);

	// Image Background
	cout << "[UI] (INFO): [IMAGE] [CREATION] backgroundimage\n";
	lv_obj_t *backgroundimage = createImage(matchscr, 0, 0, 1, &bg);

	// Team Name
	cout << "[UI] (INFO): [LABEL] [CREATION] teamName\n";
	lv_obj_t *teamName = createLabel(matchscr, 38, 25, "83280W");
	lv_label_set_style(teamName, &style_teamname);
	// BG Boxes
	cout << "[UI] (INFO): [OBJ] [CREATION] rollerbg\n";
	lv_obj_t *rollerbg = createBaseObject(matchscr, 240, 21);
	lv_obj_set_size(rollerbg, 216, 197);
	lv_obj_set_style(rollerbg, &roller_bg_style);

	// Auton Selector
	// -- Screen Switch Buttons
	cout << "[UI] (INFO): [BUTTON] [CREATION] btn_match\n";
	lv_obj_t *btn_match = createBtn(matchscr, 248, 29, 90, 40, 2, "MATCH");
	lv_btn_set_style(btn_match, LV_BTN_STYLE_REL, &style_btn);
	lv_btn_set_style(btn_match, LV_BTN_STATE_PR, &style_btn_selected);
	cout << "[UI] (INFO): [BUTTON] [CREATION] btn_skills\n";
	lv_obj_t *btn_skills = createBtn(matchscr, 355, 29, 90, 40, 3, "SKILLS");
	lv_btn_set_style(btn_skills, LV_BTN_STYLE_REL, &style_btn);
	lv_btn_set_style(btn_skills, LV_BTN_STATE_PR, &style_btn_selected);
	// -- confirm button
	cout << "[UI] (INFO): [BUTTON] [CREATION] confirm_btn\n";
	lv_obj_t *confirm_btn = createBtn(matchscr, 248, 167.8, 197.7, 40.9, 4, "CONFIRM");
	lv_btn_set_style(confirm_btn, LV_BTN_STATE_REL, &style_confirmbtn);
	lv_btn_set_style(confirm_btn, LV_BTN_STATE_PR, &style_confirmbtn_selected);

	// roller
	cout << "[UI] (INFO): [ROLLER] [CREATION] auton_selector\n";
	auton_selector = createRoller(matchscr, match_autons.c_str(), 248, 92.6);
	lv_obj_set_free_num(auton_selector, 20);
	lv_roller_set_hor_fit(auton_selector, false);
	lv_obj_set_width(auton_selector, 198);
	lv_obj_set_height(auton_selector, 54);
	lv_roller_set_style(auton_selector, LV_ROLLER_STYLE_BG, &style_roller);
	lv_roller_set_style(auton_selector, LV_ROLLER_STYLE_SEL, &roller_style_selected);

	// Chick-Fil-A Chicken Sandwich
	cout << "[UI] (INFO): [IMAGE] [CREATION] chicken\n";
	lv_obj_t *chicken = createImage(matchscr, 40.5, 69.4, 5, &chicken_sandwich_nobg);

	// Apply Button Functions
	cout << "[UI] (INFO): [BUTTON] btn_skills [ACTIONSET] m_btn_action_skills\n";
	lv_btn_set_action(btn_skills, LV_BTN_ACTION_PR, m_btn_action_skills);
	cout << "[UI] (INFO): [BUTTON] btn_match [ACTIONSET] m_btn_action_match\n";
	lv_btn_set_action(btn_match, LV_BTN_ACTION_PR, m_btn_action_match);
	cout << "[UI] (INFO): [BUTTON] confirm_btn [ACTIONSET] onMatchConfirmPress\n";
	lv_btn_set_action(confirm_btn, LV_BTN_ACTION_PR, onMatchConfirmPress);
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
	lv_obj_t *game_backgroundimage = createImage(gamescr, 0, 0, 1, &bg);

	// Create a style for the box
	static lv_style_t style_box;
	lv_style_copy(&style_box, &lv_style_plain);
	style_box.body.main_color = LV_COLOR_MAKE(0xff, 0xf5, 0xf0);
	style_box.body.grad_color = LV_COLOR_WHITE;
	style_box.body.radius = 10; // Set the radius for rounded corners
	style_box.body.opa = LV_OPA_100;

	// Create a base object for the box
	lv_obj_t *box = lv_obj_create(gamescr, NULL);
	lv_obj_set_style(box, &style_box);

	// take mutex
	dataMutex.take(2000);

	// Set the Static Variable Box Styles
	// Red
	box_red = new lv_style_t;
	lv_style_copy(box_red, &style_box); 
	box_red->body.main_color = LV_COLOR_MAKE(0x77, 0x15, 0x16); // #771516
	box_red->body.grad_color = LV_COLOR_MAKE(0x77, 0x15, 0x16); // #771516
	// Green
	box_green = new lv_style_t;
	lv_style_copy(box_green, &style_box);
	box_green->body.main_color = LV_COLOR_MAKE(0x42, 0x86, 0x2e); // #42862e
	box_green->body.grad_color = LV_COLOR_MAKE(0x42, 0x86, 0x2e); // #42862e
	// Yellow
	box_yellow = new lv_style_t;
	lv_style_copy(box_yellow, &style_box);
	box_yellow->body.main_color = LV_COLOR_MAKE(0xab, 0x9b, 0x10); // #ab9b10
	box_yellow->body.grad_color = LV_COLOR_MAKE(0xab, 0x9b, 0x10); // #ab9b10
	// Blue #0097b2
	box_blue = new lv_style_t;
	lv_style_copy(box_blue, &style_box);
	box_blue->body.main_color = LV_COLOR_MAKE(0x00, 0x97, 0xb2); // #0097b2
	box_blue->body.grad_color = LV_COLOR_MAKE(0x00, 0x97, 0xb2); // #0097b2
	box_midnightblue = new lv_style_t;
	lv_style_copy(box_midnightblue, &style_box);
	//1f282f
	box_midnightblue->body.main_color = LV_COLOR_MAKE(0x1f, 0x28, 0x2f); // #1f282f
	box_midnightblue->body.grad_color = LV_COLOR_MAKE(0x1f, 0x28, 0x2f); // #1f282f


	static lv_style_t style_smalltext;
	lv_style_copy(&style_smalltext, &lv_style_plain);
	style_smalltext.text.font = &blackopsone_10;
	style_smalltext.text.color = LV_COLOR_WHITE;

	static lv_style_t style_largetext;
	lv_style_copy(&style_largetext, &lv_style_plain);
	style_largetext.text.font = &blackopsone_12;
	style_largetext.text.color = LV_COLOR_WHITE;

	static lv_style_t style_midtext;
	lv_style_copy(&style_midtext, &lv_style_plain);
	style_midtext.text.font = &blackopsone_20;
	style_midtext.text.color = LV_COLOR_WHITE;

	static lv_style_t style_buildtext;
	lv_style_copy(&style_buildtext, &lv_style_plain);
	style_buildtext.text.font = &blackopsone_12;
	style_buildtext.text.color = LV_COLOR_WHITE;


	// Set the size and position of the box
	lv_obj_set_size(box, 443, 211.4); // Replace with the size you want
	lv_obj_set_pos(box, 15.9, 17);	  // Replace with the position you want

	box_m1 = createBaseObject(gamescr, 72,72);
	box_m2 = lv_obj_create(gamescr, NULL);
	box_m3 = lv_obj_create(gamescr, NULL);
	box_m11 = lv_obj_create(gamescr, NULL);
	box_m12 = lv_obj_create(gamescr, NULL);
	box_m13 = lv_obj_create(gamescr, NULL);
	box_battery = lv_obj_create(gamescr, NULL);
	box_psi = lv_obj_create(gamescr, NULL);
	box_autonsel = lv_obj_create(gamescr, NULL);
	box_launcher = lv_obj_create(gamescr, NULL);
	box_intake1 = lv_obj_create(gamescr, NULL);
	box_intake2 = lv_obj_create(gamescr, NULL);
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
	box_launcher_label = lv_label_create(box_launcher, NULL);
	box_intake1_label = lv_label_create(box_intake1, NULL);
	box_intake2_label = lv_label_create(box_intake2, NULL);

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
	
	lv_label_set_style(box_launcher_label, &style_smalltext);
	lv_label_set_text(box_launcher_label, "Launcher\nTemp");
	lv_label_set_align(box_launcher_label, LV_LABEL_ALIGN_CENTER);
	
	lv_label_set_style(box_intake1_label, &style_smalltext);
	lv_label_set_text(box_intake1_label, "Intake 1\nTemp");
	lv_label_set_align(box_intake1_label, LV_LABEL_ALIGN_CENTER);

	lv_label_set_style(box_intake2_label, &style_smalltext);
	lv_label_set_text(box_intake2_label, "Intake 2\nTemp");
	lv_label_set_align(box_intake2_label, LV_LABEL_ALIGN_CENTER);


	lv_obj_set_style(box_m1, box_green);
	lv_obj_set_style(box_m2, box_green);
	lv_obj_set_style(box_m3, box_green);
	lv_obj_set_style(box_m11, box_green);
	lv_obj_set_style(box_m12, box_green);
	lv_obj_set_style(box_m13, box_green);
	lv_obj_set_style(box_battery, box_green);
	lv_obj_set_style(box_psi, box_green);
	lv_obj_set_style(box_autonsel, box_midnightblue);
	lv_obj_set_style(box_launcher, box_green);
	lv_obj_set_style(box_intake1, box_green);
	lv_obj_set_style(box_intake2, box_green);
	lv_obj_set_style(box_logo, box_midnightblue);

	//all motor boxes and logo are 72 by 72
	lv_obj_set_size(box_m1, 72, 72);
	lv_obj_set_size(box_m2, 72, 72);
	lv_obj_set_size(box_m3, 72, 72);
	lv_obj_set_size(box_m11, 72, 72);
	lv_obj_set_size(box_m12, 72, 72);
	lv_obj_set_size(box_m13, 72, 72);
	lv_obj_set_size(box_logo, 72, 72);
	lv_obj_set_size(box_launcher, 72, 72);
	lv_obj_set_size(box_intake1, 72, 72);
	lv_obj_set_size(box_intake2, 72, 72);

	//battery and psi are 161.5 by 42
	lv_obj_set_size(box_battery, 161.5, 42);
	lv_obj_set_size(box_psi, 161.5, 42);

	// auton seleector is 72 by 42
	lv_obj_set_size(box_autonsel, 72, 42);

	// Position the boxes
	lv_obj_set_pos(box_m1, 25.2, 24);
	lv_obj_set_pos(box_m2, 113.5, 24);
	lv_obj_set_pos(box_m3, 201.5, 24); 
	lv_obj_set_pos(box_m11, 24, 151);
	lv_obj_set_pos(box_m12, 113.5, 151);
	lv_obj_set_pos(box_m13, 201.5, 151);
	lv_obj_set_pos(box_battery, 25.2, 101.7);
	lv_obj_set_pos(box_psi, 289.5, 101.7);
	lv_obj_set_pos(box_autonsel, 201.5, 101.7);
	lv_obj_set_pos(box_launcher, 289.5, 150.7);
	lv_obj_set_pos(box_intake1, 289.5, 24);
	lv_obj_set_pos(box_intake2, 377.5, 24);
	lv_obj_set_pos(box_logo, 377.5, 149.7);

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
	lv_obj_align(box_launcher_label, box_launcher, LV_ALIGN_CENTER, 0, 15);
	lv_obj_align(box_intake1_label, box_intake1, LV_ALIGN_CENTER, 0, 15);
	lv_obj_align(box_intake2_label, box_intake2, LV_ALIGN_CENTER, 0, 15);


	// CREATE THE LARGE LABELS above the small labels above
	box_m1_val = lv_label_create(box_m1, NULL);
	box_m2_val = lv_label_create(box_m2, NULL);
	box_m3_val = lv_label_create(box_m3, NULL);
	box_m11_val = lv_label_create(box_m11, NULL);
	box_m12_val = lv_label_create(box_m12, NULL);
	box_m13_val = lv_label_create(box_m13, NULL);
	box_battery_val = lv_label_create(box_battery, NULL);
	box_psi_val = lv_label_create(box_psi, NULL);
	box_launcher_val = lv_label_create(box_launcher, NULL);
	box_intake1_val = lv_label_create(box_intake1, NULL);
	box_intake2_val = lv_label_create(box_intake2, NULL);

	// set the labels to midtext
	lv_label_set_style(box_m1_val, &style_midtext);
	lv_label_set_style(box_m2_val, &style_midtext);
	lv_label_set_style(box_m3_val, &style_midtext);
	lv_label_set_style(box_m11_val, &style_midtext);
	lv_label_set_style(box_m12_val, &style_midtext);
	lv_label_set_style(box_m13_val, &style_midtext);
	lv_label_set_style(box_battery_val, &style_midtext);
	lv_label_set_style(box_psi_val, &style_midtext);
	lv_label_set_style(box_launcher_val, &style_midtext);
	lv_label_set_style(box_intake1_val, &style_midtext);
	lv_label_set_style(box_intake2_val, &style_midtext);

	// set the text to the labels to -2
	lv_label_set_text(box_m1_val, "199%");
	lv_label_set_text(box_m2_val, "-99%");
	lv_label_set_text(box_m3_val, "-99%");
	lv_label_set_text(box_m11_val, "-99%");
	lv_label_set_text(box_m12_val, "-99%");
	lv_label_set_text(box_m13_val, "-99%");
	lv_label_set_text(box_battery_val, "100%");
	lv_label_set_text(box_psi_val, "100");
	lv_label_set_text(box_launcher_val, "-99%");
	lv_label_set_text(box_intake1_val, "-99%");
	lv_label_set_text(box_intake2_val, "-99%");

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
	lv_obj_align(box_launcher_val, box_launcher, LV_ALIGN_CENTER, 0, -15);
	lv_obj_align(box_intake1_val, box_intake1, LV_ALIGN_CENTER, 0, -15);
	lv_obj_align(box_intake2_val, box_intake2, LV_ALIGN_CENTER, 0, -15);

	// Chicken
	lv_obj_t* logo = createImage(gamescr, 382.1, 152.3, 8, &MiniChickenSandwich);

	std::ostringstream buildtagstr;
	// if contains MSYS, then it is windows
	// if contains linux, then it is linux
	// if contains darwin, then it is mac
	auto buildenv = "";
	// if (string(build_environment).find("MSYS") != std::string::npos) {
	// 	buildenv = "Built on Windows";
	// }
	// else if (string(build_environment).find("linux") != std::string::npos) {
	// 	buildenv = "Built on Linux";
	// }
	// else if (string(build_environment).find("darwin") != std::string::npos) { // Untested
	// 	buildenv = "Built on Mac";
	// }
	// else {
	// 	buildenv = "Unknown Build Environment";
	// }
	// buildtagstr << "Build: " << build_date << " -- v" << codebase_version << "@" << application_environment << "-" << build_number << "+" << std::string(git_commit).substr(0,6)  << "\n"<< buildenv << " - Git Branch: " << "(" << git_branch << "), Commit: " << string(git_commit).substr(0,8) << "...";
	buildtagstr << BUILD_ENVIRONMENT;
	lv_obj_t* buildtag = createLabel(matchscr, 0, 210, buildtagstr.str().c_str());
	lv_obj_set_style(buildtag, &style_buildtext);	


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
	// 	text = "83280W";
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
	lv_obj_set_pos(teamname, 240, 87.5);
	// custom style
	static lv_style_t style_teamname2;
	lv_style_copy(&style_teamname2, &style_teamname);
	style_teamname2.text.font = &blackopsone_50;
	// apply
	lv_obj_set_style(teamname, &style_teamname2);
	*/
}

void task_updvar(void* param)
{
	while (true)
	{
		pros::delay(250); // Delay to prevent overloading the CPU

		dataMutex.take(2000); // Try to take the mutex

		// Update the shared data
 // Update the shared data
        motor1Temp = pros::c::motor_get_temperature(MOTOR_PORT_LEFT_FRONT) * 1.8 + 32;
        if (motor1Temp == PROS_ERR_F) motor1Temp = -1;

        motor2Temp =pros::c::motor_get_temperature(MOTOR_PORT_LEFT_MIDDLE)*1.8+32;
        if (motor2Temp == PROS_ERR_F) motor2Temp = -1;

        motor3Temp = pros::c::motor_get_temperature(MOTOR_PORT_LEFT_BACK) * 1.8 + 32;
        if (motor3Temp == PROS_ERR_F) motor3Temp = -1;

        motor11Temp = pros::c::motor_get_temperature(MOTOR_PORT_RIGHT_FRONT) * 1.8 + 32;
        if (motor11Temp == PROS_ERR_F) motor11Temp = -1;

        motor12Temp = pros::c::motor_get_temperature(MOTOR_PORT_RIGHT_MIDDLE) * 1.8 + 32;
        if (motor12Temp == PROS_ERR_F) motor12Temp = -1;

        motor13Temp = pros::c::motor_get_temperature(MOTOR_PORT_RIGHT_BACK) * 1.8 + 32;
        if (motor13Temp == PROS_ERR_F) motor13Temp = -1;

        motorIntakeTemp1 = pros::c::motor_get_temperature(MOTOR_PORT_INTAKE) * 1.8 + 32;
        if (motorIntakeTemp1 == PROS_ERR_F) motorIntakeTemp1 = -1;

        motorIntakeTemp2 = pros::c::motor_get_temperature(MOTOR_PORT_INTAKE_2) * 1.8 + 32;
        if (motorIntakeTemp2 == PROS_ERR_F) motorIntakeTemp2 = -1;

        motorLauncherTemp = pros::c::motor_get_temperature(MOTOR_PORT_FLYWHEEL) * 1.8 + 32;
        if (motorLauncherTemp == PROS_ERR_F) motorLauncherTemp = -1;

        batteryCharge = pros::battery::get_capacity();
        if (batteryCharge == PROS_ERR) batteryCharge = -1;

		dataMutex.give(); // Release the mutex
	}
}

void task_updui(void *param)
{
	while (true)
	{
		pros::delay(100); // Delay to prevent overloading the CPU

		// Make sure the mutex is available
		dataMutex.take(2000); // Try to take the mutex

		// Make sure the Game Screen is loaded
		if (lv_scr_act() == gamescr)
		{
				// 7 is the offset for 4 digit numbers
				// 9 is the offset for 3 digit numbers
			
			if (motor1Temp != -1)
			{
				lv_label_set_text(box_m1_val, (std::to_string((int)motor1Temp) + "F").c_str());
			}
			else
			{
				lv_label_set_text(box_m1_val, "ERR");

			}
			if (motor2Temp != -1)
			{
				lv_label_set_text(box_m2_val, (std::to_string((int)motor2Temp) + "F").c_str());
			}
			else
			{
				lv_label_set_text(box_m2_val, "ERR");
			}
			if (motor3Temp != -1)
			{
				lv_label_set_text(box_m3_val, (std::to_string((int)motor3Temp) + "F").c_str());
			}
			else
			{
				lv_label_set_text(box_m3_val, "ERR");
			}
			if (motor11Temp != -1)
			{
				lv_label_set_text(box_m11_val, (std::to_string((int)motor11Temp) + "F").c_str());
			}
			else
			{
				lv_label_set_text(box_m11_val, "ERR");
			}
			if (motor12Temp != -1)
			{
				lv_label_set_text(box_m12_val, (std::to_string((int)motor12Temp) + "F").c_str());
			}
			else
			{
				lv_label_set_text(box_m12_val, "ERR");
			}
			if (motor13Temp != -1)
			{
				lv_label_set_text(box_m13_val, (std::to_string((int)motor13Temp) + "F").c_str());
			}
			else
			{
				lv_label_set_text(box_m13_val, "ERR");
			}
			if (motorIntakeTemp1 != -1)
			{
				lv_label_set_text(box_intake1_val, (std::to_string((int)motorIntakeTemp1) + "F").c_str());
			}
			else
			{
				lv_label_set_text(box_intake1_val, "ERR");
			}
			if (motorIntakeTemp2 != -1)
			{
				lv_label_set_text(box_intake2_val, (std::to_string((int)motorIntakeTemp2) + "F").c_str());
			}
			else
			{
				lv_label_set_text(box_intake2_val, "ERR");
			}
			if (motorLauncherTemp != -1)
			{
				lv_label_set_text(box_launcher_val, (std::to_string((int)motorLauncherTemp) + "F").c_str());
			}
			else
			{
				lv_label_set_text(box_launcher_val, "ERR");
			}
			if (batteryCharge != -1)
			{
				lv_label_set_text(box_battery_val, (std::to_string((int)batteryCharge) + "%").c_str());
			}
			else
			{
				lv_label_set_text(box_battery_val, "ERR");
			}
			if (estpsi != -1)
			{
				lv_label_set_text(box_psi_val, std::to_string((int)estpsi).c_str());
			}
			else
			{
				lv_label_set_text(box_psi_val, "ERR");
			}


			// Adjusting Placement for 3 or 4 digit Values
			// 7 is the offset for 4 digit numbers
			// 9 is the offset for 3 digit numbers
			
			if (motor1Temp >= 100)
			{
				lv_obj_align(box_m1_val, box_m1, LV_ALIGN_CENTER, 0, -15);
			}
			else {
				lv_obj_align(box_m1_val, box_m1, LV_ALIGN_CENTER, -1, -15);
			}
			if (motor2Temp >= 100)
			{
				lv_obj_align(box_m2_val, box_m2, LV_ALIGN_CENTER, 0, -15);
			}
			else {
				lv_obj_align(box_m2_val, box_m2, LV_ALIGN_CENTER, -1, -15);
			}
			if (motor3Temp >= 100)
			{
				lv_obj_align(box_m3_val, box_m3, LV_ALIGN_CENTER, 0, -15);
			}
			else {
				lv_obj_align(box_m3_val, box_m3, LV_ALIGN_CENTER, -1, -15);
			}
			if (motor11Temp >= 100)
			{
				lv_obj_align(box_m11_val, box_m11, LV_ALIGN_CENTER, 0, -15);
			}
			else {
				lv_obj_align(box_m11_val, box_m11, LV_ALIGN_CENTER, -1, -15);
			}
			if (motor12Temp >= 100)
			{
				lv_obj_align(box_m12_val, box_m12, LV_ALIGN_CENTER, 0, -15);
			}
			else {
				lv_obj_align(box_m12_val, box_m12, LV_ALIGN_CENTER, -1, -15);
			}
			if (motor13Temp >= 100)
			{
				lv_obj_align(box_m13_val, box_m13, LV_ALIGN_CENTER, 0, -15);
			}
			else {
				lv_obj_align(box_m13_val, box_m13, LV_ALIGN_CENTER, -1, -15);
			}
			if (motorLauncherTemp >= 100)
			{
				lv_obj_align(box_launcher_val, box_launcher, LV_ALIGN_CENTER, 0, -15);
			}
			else {
				lv_obj_align(box_launcher_val, box_launcher, LV_ALIGN_CENTER, -1, -15);
			}
			if (motorIntakeTemp1 >= 100)
			{
				lv_obj_align(box_intake1_val, box_intake1, LV_ALIGN_CENTER, 0, -15);
			}
			else {
				lv_obj_align(box_intake1_val, box_intake1, LV_ALIGN_CENTER, -1, -15);
			}
			if (motorIntakeTemp2 >= 100)
			{
				lv_obj_align(box_intake2_val, box_intake2, LV_ALIGN_CENTER, 0, -15);
			}
			else {
				lv_obj_align(box_intake2_val, box_intake2, LV_ALIGN_CENTER, -1, -15);
			}


			/* 
			 * LOGIC FOR BOX COLOR CHANGING
			 */

			// Motor 1
			if (motor1Temp < 90 && motor1Temp != -1)
			{
				lv_obj_set_style(box_m1, box_green);
			}
			else if (motor1Temp >= 90 && motor1Temp < 140)
			{
				lv_obj_set_style(box_m1, box_yellow);
			}
			else if (motor1Temp >= 140 || motor1Temp == -1)
			{
				lv_obj_set_style(box_m1, box_red);
			}

			// Motor 2
			if (motor2Temp < 90 && motor2Temp != -1)
			{
				lv_obj_set_style(box_m2, box_green);
			}
			else if (motor2Temp >= 90 && motor2Temp < 140)
			{
				lv_obj_set_style(box_m2, box_yellow);
			}
			else if (motor2Temp >= 140 || motor2Temp == -1)
			{
				lv_obj_set_style(box_m2, box_red);
			}

			// Motor 3
			if (motor3Temp < 90 && motor3Temp != -1)
			{
				lv_obj_set_style(box_m3, box_green);
			}
			else if (motor3Temp >= 90 && motor3Temp < 140)
			{
				lv_obj_set_style(box_m3, box_yellow);
			}
			else if (motor3Temp >= 140 || motor3Temp == -1)
			{
				lv_obj_set_style(box_m3, box_red);
			}

			// Motor 11
			if (motor11Temp < 90 && motor11Temp != -1)
			{
				lv_obj_set_style(box_m11, box_green);
			}
			else if (motor11Temp >= 90 && motor11Temp < 140)
			{
				lv_obj_set_style(box_m11, box_yellow);
			}
			else if (motor11Temp >= 140 || motor11Temp == -1)
			{
				lv_obj_set_style(box_m11, box_red);
			}

			// Motor 12
			if (motor12Temp < 90 && motor12Temp != -1)
			{
				lv_obj_set_style(box_m12, box_green);
			}
			else if (motor12Temp >= 90 && motor12Temp < 140)
			{
				lv_obj_set_style(box_m12, box_yellow);
			}
			else if (motor12Temp >= 140 || motor12Temp == -1)
			{
				lv_obj_set_style(box_m12, box_red);
			}

			// Motor 13
			if (motor13Temp < 90 && motor13Temp != -1)
			{
				lv_obj_set_style(box_m13, box_green);
			}
			else if (motor13Temp >= 90 && motor13Temp < 140)
			{
				lv_obj_set_style(box_m13, box_yellow);
			}
			else if (motor13Temp >= 140 || motor13Temp == -1)
			{
				lv_obj_set_style(box_m13, box_red);
			}

			// Battery
			if (batteryCharge >= 50)
			{
				lv_obj_set_style(box_battery, box_green);
			}
			else if (batteryCharge >= 25 && batteryCharge < 50)
			{
				lv_obj_set_style(box_battery, box_yellow);
			}
			else if (batteryCharge < 25)
			{
				lv_obj_set_style(box_battery, box_red);
			}

			// PSI
			if (estpsi >= 100)
			{
				lv_obj_set_style(box_psi, box_green);
			}
			else if (estpsi >= 45 && estpsi < 100)
			{
				lv_obj_set_style(box_psi, box_yellow);
			}
			else if (estpsi < 45)
			{
				lv_obj_set_style(box_psi, box_red);
			}

			// Launcher
			if (motorLauncherTemp < 90 && motorLauncherTemp != -1)
			{
				lv_obj_set_style(box_launcher, box_green);
			}
			else if (motorLauncherTemp >= 90 && motorLauncherTemp < 140)
			{
				lv_obj_set_style(box_launcher, box_yellow);
			}
			else if (motorLauncherTemp >= 140 || motorLauncherTemp == -1)
			{
				lv_obj_set_style(box_launcher, box_red);
			}

			// Intake 1
			if (motorIntakeTemp1 < 90 && motorIntakeTemp1 != -1)
			{
				lv_obj_set_style(box_intake1, box_green);
			}
			else if (motorIntakeTemp1 >= 100 && motorIntakeTemp1 < 140)
			{
				lv_obj_set_style(box_intake1, box_yellow);
			}
			else if (motorIntakeTemp1 >= 140 || motorIntakeTemp1 == -1)
			{
				lv_obj_set_style(box_intake1, box_red);
			}

			// Intake 2
			if (motorIntakeTemp2 < 90 && motorIntakeTemp2 != -1)
			{
				lv_obj_set_style(box_intake2, box_green);
			}
			else if (motorIntakeTemp2 >= 100 && motorIntakeTemp2 < 140)
			{
				lv_obj_set_style(box_intake2, box_yellow);
			}
			else if (motorIntakeTemp2 >= 140 || motorIntakeTemp2 == -1)
			{
				lv_obj_set_style(box_intake2, box_red);
			}
		}

		dataMutex.give(); // Release the mutex
	}
}

void create_tasks()
{
    pros::Task update_var_task(task_updvar, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "UpdateVarTask");
    pros::Task update_ui_task(task_updui, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "UpdateUITask");
}


#endif