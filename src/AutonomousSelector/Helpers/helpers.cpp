#include "AutonomousSelector/helpers.hpp"
#include "main.h" // IWYU pragma: keep

lv_obj_t *createBtn(lv_obj_t *parent, lv_coord_t x, lv_coord_t y,
                    lv_coord_t width, lv_coord_t height, int id,
                    const char *title) {
  cout << "[HELPER] (INFO): [CREATING] Button\n";
  lv_obj_t *btn = lv_btn_create(parent, NULL);
  lv_obj_set_pos(btn, x, y);
  lv_obj_set_size(btn, width, height);
  lv_obj_set_free_num(btn, id);

  lv_obj_t *label = lv_label_create(btn, NULL);
  lv_label_set_text(label, title);
  lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 5);

  return btn;
}

lv_style_t *createBtnStyle(lv_style_t *copy, lv_color_t rel, lv_color_t pr,
                           lv_color_t tglRel, lv_color_t tglPr,
                           lv_color_t tglBorder, lv_color_t textColor,
                           lv_obj_t *btn) {
  cout << "[HELPER] (INFO): [CREATING STYLE] Button Style\n";
  lv_style_t *btnStyle = (lv_style_t *)malloc(sizeof(lv_style_t) * 4);

  for (int i = 0; i < 4; i++)
    lv_style_copy(&btnStyle[i], copy);

  btnStyle[0].body.main_color = rel;
  btnStyle[0].body.grad_color = rel;
  btnStyle[0].text.color = textColor;

  btnStyle[1].body.main_color = pr;
  btnStyle[1].body.grad_color = pr;
  btnStyle[1].text.color = textColor;

  btnStyle[2].body.main_color = tglRel;
  btnStyle[2].body.grad_color = tglRel;
  btnStyle[2].body.border.width = 2;
  btnStyle[2].body.border.color = tglBorder;
  btnStyle[2].text.color = textColor;

  btnStyle[3].body.main_color = tglPr;
  btnStyle[3].body.grad_color = tglPr;
  btnStyle[3].body.border.width = 2;
  btnStyle[3].body.border.color = tglBorder;
  btnStyle[3].text.color = textColor;

  lv_btn_set_style(btn, LV_BTN_STYLE_REL, &btnStyle[0]);
  lv_btn_set_style(btn, LV_BTN_STYLE_PR, &btnStyle[1]);
  lv_btn_set_style(btn, LV_BTN_STYLE_TGL_REL, &btnStyle[2]);
  lv_btn_set_style(btn, LV_BTN_STYLE_TGL_PR, &btnStyle[3]);

  return btnStyle;
}

void setBtnStyle(lv_style_t *btnStyle, lv_obj_t *btn) {
  cout << "[HELPER] (INFO): [SETTING] Button Style\n";
  lv_btn_set_style(btn, LV_BTN_STYLE_REL, &btnStyle[0]);
  lv_btn_set_style(btn, LV_BTN_STYLE_PR, &btnStyle[1]);
  lv_btn_set_style(btn, LV_BTN_STYLE_TGL_REL, &btnStyle[2]);
  lv_btn_set_style(btn, LV_BTN_STYLE_TGL_PR, &btnStyle[3]);
}

lv_obj_t *
createImgBtn(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, int id,
             const void *imgSrc) // lv_coord_t width, lv_coord_t height,
{
  cout << "[HELPER] (INFO): [CREATING] Image Button\n";
  lv_obj_t *imgBtn = lv_imgbtn_create(parent, NULL);
  lv_obj_set_pos(imgBtn, x, y);
  // lv_obj_set_size(imgBtn, width, height);
  lv_obj_set_free_num(imgBtn, id);
  lv_imgbtn_set_src(imgBtn, LV_BTN_STATE_REL, imgSrc);

  return imgBtn;
}

lv_obj_t *createImage(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, int id,
                      const void *imgSrc) {
  cout << "[HELPER] (INFO): [CREATING] Image\n";
  // Create an image object
  lv_obj_t *img = lv_img_create(parent, NULL);

  // Set the source of the image
  lv_img_set_src(img, imgSrc);

  // Set the position of the image
  lv_obj_set_pos(img, x, y);

  // Set the unique ID for the image (optional)
  lv_obj_set_free_num(img, id);

  return img;
}

lv_obj_t *createImage(lv_obj_t *parent, lv_coord_t x, lv_coord_t y,
                      lv_coord_t wid, lv_coord_t hei, int id,
                      const void *imgSrc) {
  cout << "[HELPER] (INFO): [CREATING] Image\n";
  // Create an image object
  lv_obj_t *img = lv_img_create(parent, NULL);

  // Set the source of the image
  lv_img_set_src(img, imgSrc);

  // Set the position of the image
  lv_obj_align(img, NULL, LV_ALIGN_IN_TOP_LEFT, x, y);
  lv_obj_set_pos(img, x, y);

  // Set the size of the image
  lv_obj_set_size(img, wid, hei);
  lv_img_set_auto_size(img, true); // Enable auto size

  // Set the unique ID for the image (optional)
  lv_obj_set_free_num(img, id);

  return img;
}

lv_obj_t *createBaseObject(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Base Object\n";
  lv_obj_t *obj = lv_obj_create(parent, NULL);
  lv_obj_set_pos(obj, x, y);
  return obj;
}

lv_obj_t *createLabel(lv_obj_t *parent, int x, int y, const char *text) {
  cout << "[HELPER] (INFO): [CREATING] Label\n";
  lv_obj_t *label = lv_label_create(parent, NULL);
  lv_label_set_text(label, text);
  lv_obj_set_pos(label, x, y);
  return label;
}

lv_obj_t *createImage(lv_obj_t *parent, const char *imgSrc, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Image\n";
  lv_obj_t *img = lv_img_create(parent, NULL);
  lv_img_set_src(img, imgSrc);
  lv_obj_set_pos(img, x, y);
  return img;
}

lv_obj_t *createLine(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Line\n";
  lv_obj_t *line = lv_line_create(parent, NULL);
  lv_obj_set_pos(line, x, y);
  return line;
}

lv_obj_t *createArc(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Arc\n";
  lv_obj_t *arc = lv_arc_create(parent, NULL);
  lv_obj_set_pos(arc, x, y);
  return arc;
}

lv_obj_t *createContainer(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Container\n";
  lv_obj_t *cont = lv_cont_create(parent, NULL);
  lv_obj_set_pos(cont, x, y);
  return cont;
}

lv_obj_t *createPage(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Page\n";
  lv_obj_t *page = lv_page_create(parent, NULL);
  lv_obj_set_pos(page, x, y);
  return page;
}

lv_obj_t *createWindow(lv_obj_t *parent, const char *title, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Window\n";
  lv_obj_t *win = lv_win_create(parent, NULL);
  lv_win_set_title(win, title);
  lv_obj_set_pos(win, x, y);
  return win;
}

lv_obj_t *createTabview(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Tab View\n";
  lv_obj_t *tabview = lv_tabview_create(parent, NULL);
  lv_obj_set_pos(tabview, x, y);
  return tabview;
}

lv_obj_t *createBar(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Bar\n";
  lv_obj_t *bar = lv_bar_create(parent, NULL);
  lv_obj_set_pos(bar, x, y);
  return bar;
}

lv_obj_t *createLineMeter(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] LineMeter\n";
  lv_obj_t *lmeter = lv_lmeter_create(parent, NULL);
  lv_obj_set_pos(lmeter, x, y);
  return lmeter;
}

lv_obj_t *createGauge(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Gauge\n";
  lv_obj_t *gauge = lv_gauge_create(parent, NULL);
  lv_obj_set_pos(gauge, x, y);
  return gauge;
}

lv_obj_t *createChart(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Chart\n";
  lv_obj_t *chart = lv_chart_create(parent, NULL);
  lv_obj_set_pos(chart, x, y);
  return chart;
}

lv_obj_t *createLED(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] LED\n";
  lv_obj_t *led = lv_led_create(parent, NULL);
  lv_obj_set_pos(led, x, y);
  return led;
}

lv_obj_t *createPreloader(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] PreLoader\n";
  lv_obj_t *preload = lv_preload_create(parent, NULL);
  lv_obj_set_pos(preload, x, y);
  return preload;
}

lv_obj_t *createMessageBox(lv_obj_t *parent, const char *text, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] MessageBox\n";
  lv_obj_t *mbox = lv_mbox_create(parent, NULL);
  lv_mbox_set_text(mbox, text);
  lv_obj_set_pos(mbox, x, y);
  return mbox;
}

lv_obj_t *createTextArea(lv_obj_t *parent, const char *text, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Text Area\n";
  lv_obj_t *ta = lv_ta_create(parent, NULL);
  lv_ta_set_text(ta, text);
  lv_obj_set_pos(ta, x, y);
  return ta;
}

lv_obj_t *createCalendar(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Calendar\n";
  lv_obj_t *calendar = lv_calendar_create(parent, NULL);
  lv_obj_set_pos(calendar, x, y);
  return calendar;
}

lv_obj_t *createButton(lv_obj_t *parent, const char *text, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Button\n";
  lv_obj_t *btn = lv_btn_create(parent, NULL);
  lv_obj_t *label = lv_label_create(btn, NULL);
  lv_label_set_text(label, text);
  lv_obj_set_pos(btn, x, y);
  return btn;
}

lv_obj_t *createImageButton(lv_obj_t *parent, const void *imgSrc, int x,
                            int y) {
  cout << "[HELPER] (INFO): [CREATING] Image Button\n";
  lv_obj_t *imgbtn = lv_imgbtn_create(parent, NULL);
  lv_imgbtn_set_src(imgbtn, LV_BTN_STATE_REL, imgSrc);
  lv_obj_set_pos(imgbtn, x, y);
  return imgbtn;
}

lv_obj_t *createButtonMatrix(lv_obj_t *parent, const char **map, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Button Matrix\n";
  lv_obj_t *btnm = lv_btnm_create(parent, NULL);
  lv_btnm_set_map(btnm, map);
  lv_obj_set_pos(btnm, x, y);
  return btnm;
}

lv_obj_t *createKeyboard(lv_obj_t *parent, lv_obj_t *ta) {
  cout << "[HELPER] (INFO): [CREATING] Keyboard\n";
  lv_obj_t *kb = lv_kb_create(parent, NULL);
  lv_kb_set_ta(kb, ta);
  return kb;
}

lv_obj_t *createList(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] List\n";
  lv_obj_t *list = lv_list_create(parent, NULL);
  lv_obj_set_pos(list, x, y);
  return list;
}

lv_obj_t *createDropDownList(lv_obj_t *parent, const char *options, int x,
                             int y) {
  cout << "[HELPER] (INFO): [CREATING] Drop Down List\n";
  lv_obj_t *ddlist = lv_ddlist_create(parent, NULL);
  lv_ddlist_set_options(ddlist, options);
  lv_obj_set_pos(ddlist, x, y);
  return ddlist;
}

lv_obj_t *createRoller(lv_obj_t *parent, const char *options, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Roller\n";
  lv_obj_t *roller = lv_roller_create(parent, NULL);
  lv_roller_set_options(roller, options);
  lv_obj_set_pos(roller, x, y);
  return roller;
}

lv_obj_t *createCheckBox(lv_obj_t *parent, const char *text, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] CheckBox\n";
  lv_obj_t *cb = lv_cb_create(parent, NULL);
  lv_cb_set_text(cb, text);
  lv_obj_set_pos(cb, x, y);
  return cb;
}

lv_obj_t *createSwitch(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Switch\n";
  lv_obj_t *sw = lv_sw_create(parent, NULL);
  lv_obj_set_pos(sw, x, y);
  return sw;
}

lv_obj_t *createSlider(lv_obj_t *parent, int x, int y) {
  cout << "[HELPER] (INFO): [CREATING] Slider\n";
  lv_obj_t *slider = lv_slider_create(parent, NULL);
  lv_obj_set_pos(slider, x, y);
  return slider;
}

lv_obj_t *createButtonMatrix(lv_obj_t *parent, int x, int y, const char **map) {
  cout << "[HELPER] (INFO): [CREATING] Button Matrix\n";
  lv_obj_t *btnm = lv_btnm_create(parent, NULL);
  lv_btnm_set_map(btnm, map);
  lv_obj_set_pos(btnm, x, y);
  return btnm;
}

lv_obj_t *get_child_by_index(lv_obj_t *parent, uint16_t index) {
  cout << "[HELPER] (INFO): called get_child_by_index\n";
  lv_obj_t *child = lv_obj_get_child_back(parent, NULL);
  for (uint16_t i = 0; i < index && child != NULL; i++) {
    child = lv_obj_get_child_back(parent, child);
  }
  return child;
}

int readCounterFromMemory() {
  cout << "[HELPER] (INFO): reading counter\n";
  return 0;
  // read the counter from memory
  // open sd card
  FILE *file = fopen("/usd/counter.txt", "r");
  // check if the file exists
  if (file == NULL) {
    // file does not exist make it
    file = fopen("/usd/counter.txt", "w");
    // write 0 to the file
    fprintf(file, "0");
    // close the file
    fclose(file);
    // return 0
    return 0;
  }
  // read the counter
  int counter;
  fscanf(file, "%d", &counter);
  // increment the counter
  counter = counter + 1;

  // write the counter to the file
  file = fopen("/usd/counter.txt", "w");
  fprintf(file, "%d", counter);
  // close the file
  fclose(file);
  return counter;
}
