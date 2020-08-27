#ifndef __APP_H_
#define __APP_H_

/**********************
 *      INCLUDES
 **********************/

#include "lvgl/lvgl.h"

/**********************
 *       WIDGETS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t *splash_screen_create();
lv_obj_t *app_screen_create();

void style_create();

void splash_create(lv_obj_t *parent);
void splash_bar_set_value(int16_t value, uint16_t time);
void splash_button_show();
void splash_button_hide();
void splash_label_set_text(const char* text);

void app_create(lv_obj_t *parent);
void app_temp_current_set(float temp);
void app_temp_target_set(float temp);

#endif
