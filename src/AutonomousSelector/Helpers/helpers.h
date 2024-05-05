#ifndef HELPERS_H
#define HELPERS_H

#include "main.h"
#include "pros/apix.h"
#include <chrono>

/**
 * Create a button with a label.
 * @param parent Parent object, usually a screen.
 * @param x X position of the button.
 * @param y Y position of the button.
 * @param width Width of the button.
 * @param height Height of the button.
 * @param id Unique identifier for the button.
 * @param title Text to display on the button.
 * @return Pointer to the created button object.
 */
lv_obj_t *createBtn(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, int id, const char *title);

/**
 * Create a style for a button.
 * @param copy Style to copy from.
 * @param rel Color for the button in normal state.
 * @param pr Color for the button when pressed.
 * @param tglRel Color for the button when toggled in normal state.
 * @param tglPr Color for the button when toggled and pressed.
 * @param tglBorder Border color for the button when toggled.
 * @param textColor Color for the text on the button.
 * @param btn Button to apply the style to.
 * @return Pointer to the created style.
 */
lv_style_t *createBtnStyle(lv_style_t *copy, lv_color_t rel, lv_color_t pr, lv_color_t tglRel, lv_color_t tglPr, lv_color_t tglBorder, lv_color_t textColor, lv_obj_t *btn);

/**
 * Set a style for a button.
 * @param btnStyle Style to apply.
 * @param btn Button to apply the style to.
 */
void setBtnStyle(lv_style_t *btnStyle, lv_obj_t *btn);

/**
 * Create an image button.
 * @param parent Parent object, usually a screen.
 * @param x X position of the image button.
 * @param y Y position of the image button.
 * @param id Unique identifier for the image button.
 * @param imgSrc Source of the image to display on the button.
 * @return Pointer to the created image button object.
 */
lv_obj_t *createImgBtn(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, int id, const void *imgSrc);

/**
 * Create an image.
 * @param parent Parent object, usually a screen.
 * @param x X position of the image.
 * @param y Y position of the image.
 * @param id Unique identifier for the image.
 * @param imgSrc Source of the image to display.
 * @return Pointer to the created image object.
 */
lv_obj_t *createImage(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, int id, const void *imgSrc);

/**
 * Create an image with specified size.
 * @param parent Parent object, usually a screen.
 * @param x X position of the image.
 * @param y Y position of the image.
 * @param wid Width of the image.
 * @param hei Height of the image.
 * @param id Unique identifier for the image.
 * @param imgSrc Source of the image to display.
 * @return Pointer to the created image object.
 */
lv_obj_t *createImage(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t wid, lv_coord_t hei, int id, const void *imgSrc);

/**
 * Create a base object.
 * @param parent Parent object, usually a screen.
 * @param x X position of the object.
 * @param y Y position of the object.
 * @return Pointer to the created object.
 */
lv_obj_t* createBaseObject(lv_obj_t *parent, int x, int y);

/**
 * Create a label.
 * @param parent Parent object, usually a screen.
 * @param x X position of the label.
 * @param y Y position of the label.
 * @param text Text to display on the label.
 * @return Pointer to the created label object.
 */
lv_obj_t* createLabel(lv_obj_t *parent, int x, int y, const char *text);

/**
 * Create an image.
 * @param parent Parent object, usually a screen.
 * @param imgSrc Source of the image to display.
 * @param x X position of the image.
 * @param y Y position of the image.
 * @return Pointer to the created image object.
 */
lv_obj_t *createImage(lv_obj_t *parent, const char *imgSrc, int x, int y);

/**
 * Create a line.
 * @param parent Parent object, usually a screen.
 * @param x X position of the line.
 * @param y Y position of the line.
 * @return Pointer to the created line object.
 */
lv_obj_t *createLine(lv_obj_t *parent, int x, int y);

/**
 * Create an arc.
 * @param parent Parent object, usually a screen.
 * @param x X position of the arc.
 * @param y Y position of the arc.
 * @return Pointer to the created arc object.
 */
lv_obj_t *createArc(lv_obj_t *parent, int x, int y);

/**
 * Create a container.
 * @param parent Parent object, usually a screen.
 * @param x X position of the container.
 * @param y Y position of the container.
 * @return Pointer to the created container object.
 */
lv_obj_t *createContainer(lv_obj_t *parent, int x, int y);

/**
 * Create a page.
 * @param parent Parent object, usually a screen.
 * @param x X position of the page.
 * @param y Y position of the page.
 * @return Pointer to the created page object.
 */
lv_obj_t *createPage(lv_obj_t *parent, int x, int y);

/**
 * Create a window.
 * @param parent Parent object, usually a screen.
 * @param title Title of the window.
 * @param x X position of the window.
 * @param y Y position of the window.
 * @return Pointer to the created window object.
 */
lv_obj_t *createWindow(lv_obj_t *parent, const char *title, int x, int y);

/**
 * Create a tabview.
 * @param parent Parent object, usually a screen.
 * @param x X position of the tabview.
 * @param y Y position of the tabview.
 * @return Pointer to the created tabview object.
 */
lv_obj_t *createTabview(lv_obj_t *parent, int x, int y);

/**
 * Create a bar.
 * @param parent Parent object, usually a screen.
 * @param x X position of the bar.
 * @param y Y position of the bar.
 * @return Pointer to the created bar object.
 */
lv_obj_t *createBar(lv_obj_t *parent, int x, int y);

/**
 * Create a line meter.
 * @param parent Parent object, usually a screen.
 * @param x X position of the line meter.
 * @param y Y position of the line meter.
 * @return Pointer to the created line meter object.
 */
lv_obj_t *createLineMeter(lv_obj_t *parent, int x, int y);

/**
 * Create a gauge.
 * @param parent Parent object, usually a screen.
 * @param x X position of the gauge.
 * @param y Y position of the gauge.
 * @return Pointer to the created gauge object.
 */
lv_obj_t *createGauge(lv_obj_t *parent, int x, int y);

/**
 * Create a chart.
 * @param parent Parent object, usually a screen.
 * @param x X position of the chart.
 * @param y Y position of the chart.
 * @return Pointer to the created chart object.
 */
lv_obj_t *createChart(lv_obj_t *parent, int x, int y);

/**
 * Create a LED.
 * @param parent Parent object, usually a screen.
 * @param x X position of the LED.
 * @param y Y position of the LED.
 * @return Pointer to the created LED object.
 */
lv_obj_t *createLED(lv_obj_t *parent, int x, int y);

/**
 * Create a preloader.
 * @param parent Parent object, usually a screen.
 * @param x X position of the preloader.
 * @param y Y position of the preloader.
 * @return Pointer to the created preloader object.
 */
lv_obj_t *createPreloader(lv_obj_t *parent, int x, int y);

/**
 * Create a message box.
 * @param parent Parent object, usually a screen.
 * @param text Text to display in the message box.
 * @param x X position of the message box.
 * @param y Y position of the message box.
 * @return Pointer to the created message box object.
 */
lv_obj_t *createMessageBox(lv_obj_t *parent, const char *text, int x, int y);

/**
 * Create a text area.
 * @param parent Parent object, usually a screen.
 * @param text Text to display in the text area.
 * @param x X position of the text area.
 * @param y Y position of the text area.
 * @return Pointer to the created text area object.
 */
lv_obj_t *createTextArea(lv_obj_t *parent, const char *text, int x, int y);

/**
 * Create a calendar.
 * @param parent Parent object, usually a screen.
 * @param x X position of the calendar.
 * @param y Y position of the calendar.
 * @return Pointer to the created calendar object.
 */
lv_obj_t *createCalendar(lv_obj_t *parent, int x, int y);

/**
 * Create a button with a label.
 * @param parent Parent object, usually a screen.
 * @param text Text to display on the button.
 * @param x X position of the button.
 * @param y Y position of the button.
 * @return Pointer to the created button object.
 */
lv_obj_t *createButton(lv_obj_t *parent, const char *text, int x, int y);

/**
 * Create an image button.
 * @param parent Parent object, usually a screen.
 * @param imgSrc Source of the image to display on the button.
 * @param x X position of the image button.
 * @param y Y position of the image button.
 * @return Pointer to the created image button object.
 */
lv_obj_t *createImageButton(lv_obj_t *parent, const void *imgSrc, int x, int y);

/**
 * Create a button matrix.
 * @param parent Parent object, usually a screen.
 * @param map Array of strings to display on the buttons.
 * @param x X position of the button matrix.
 * @param y Y position of the button matrix.
 * @return Pointer to the created button matrix object.
 */
lv_obj_t *createButtonMatrix(lv_obj_t *parent, const char **map, int x, int y);

/**
 * Create a keyboard.
 * @param parent Parent object, usually a screen.
 * @param ta Text area to associate with the keyboard.
 * @return Pointer to the created keyboard object.
 */
lv_obj_t *createKeyboard(lv_obj_t *parent, lv_obj_t *ta);

/**
 * Create a list.
 * @param parent Parent object, usually a screen.
 * @param x X position of the list.
 * @param y Y position of the list.
 * @return Pointer to the created list object.
 */
lv_obj_t *createList(lv_obj_t *parent, int x, int y);

/**
 * Create a drop-down list.
 * @param parent Parent object, usually a screen.
 * @param options Options to display in the drop-down list.
 * @param x X position of the drop-down list.
 * @param y Y position of the drop-down list.
 * @return Pointer to the created drop-down list object.
 */
lv_obj_t *createDropDownList(lv_obj_t *parent, const char *options, int x, int y);

/**
 * Create a roller.
 * @param parent Parent object, usually a screen.
 * @param options Options to display in the roller.
 * @param x X position of the roller.
 * @param y Y position of the roller.
 * @return Pointer to the created roller object.
 */
lv_obj_t *createRoller(lv_obj_t *parent, const char *options, int x, int y);

/**
 * Create a checkbox.
 * @param parent Parent object, usually a screen.
 * @param text Text to display next to the checkbox.
 * @param x X position of the checkbox.
 * @param y Y position of the checkbox.
 * @return Pointer to the created checkbox object.
 */
lv_obj_t *createCheckBox(lv_obj_t *parent, const char *text, int x, int y);

/**
 * Create a switch.
 * @param parent Parent object, usually a screen.
 * @param x X position of the switch.
 * @param y Y position of the switch.
 * @return Pointer to the created switch object.
 */
lv_obj_t *createSwitch(lv_obj_t *parent, int x, int y);

/**
 * Create a slider.
 * @param parent Parent object, usually a screen.
 * @param x X position of the slider.
 * @param y Y position of the slider.
 * @return Pointer to the created slider object.
 */
lv_obj_t *createSlider(lv_obj_t *parent, int x, int y);

/**
 * Create a button matrix.
 * @param parent Parent object, usually a screen.
 * @param x X position of the button matrix.
 * @param y Y position of the button matrix.
 * @param map Array of strings to display on the buttons.
 * @return Pointer to the created button matrix object.
 */
lv_obj_t *createButtonMatrix(lv_obj_t *parent, int x, int y, const char **map);

/**
 * Get a child object by its index.
 * @param parent Parent object.
 * @param index Index of the child object.
 * @return Pointer to the child object.
 */
lv_obj_t *get_child_by_index(lv_obj_t *parent, uint16_t index);

/**
 * Read a counter from memory.
 * @return The counter value.
 */
int readCounterFromMemory();

#endif /* HELPERS_H */