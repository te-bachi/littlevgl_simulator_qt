#include "app.h"

static void button_plus_cb(lv_obj_t *button_plus, lv_event_t event);
static void button_minus_cb(lv_obj_t *button_minus, lv_event_t event);
static void button_one_cb(lv_obj_t *button_one, lv_event_t event);
static void button_ten_cb(lv_obj_t *button_ten, lv_event_t event);
static void switch_power_cb(lv_obj_t *switch_power, lv_event_t event);

/* Styles */
static lv_style_t   style_label_button;
static lv_style_t   style_label;
static lv_style_t   style_label_superscript;

/*--- BUTTONS ---*/
/* Plus */
static lv_obj_t    *button_plus;
static lv_obj_t    *label_plus;

/* Minus */
static lv_obj_t    *button_minus;
static lv_obj_t    *label_minus;

/* One */
static lv_obj_t    *button_one;
static lv_obj_t    *label_one;

/* Ten */
static lv_obj_t    *button_ten;
static lv_obj_t    *label_ten;

/*--- SWITCHES ---*/
static lv_obj_t    *switch_power;

/*--- LABELS ---*/

static lv_obj_t *label_temp_current;
static lv_obj_t *label_temp_current_grad;
static lv_obj_t *label_temp_current_celsius;
static lv_obj_t *label_temp_target;
static lv_obj_t *label_temp_target_grad;
static lv_obj_t *label_temp_target_celsius;
static lv_obj_t *label_power;

static int temp_target;


void app_create(lv_obj_t *parent)
{
    temp_target = 0;

    /*** Styles **************************************************************/
    lv_style_copy(&style_label_button, &lv_style_transp);
    style_label_button.text.color = lv_color_hex(0xffffff);
    style_label_button.text.sel_color = lv_color_hex(0x5596d8);
    style_label_button.text.font = &lv_font_roboto_28;
    style_label_button.text.letter_space = 0;
    style_label_button.text.line_space = 2;
    style_label_button.text.opa = 255;

    lv_style_copy(&style_label, &lv_style_transp);
    style_label.text.color = lv_color_hex(0x303030);
    style_label.text.sel_color = lv_color_hex(0x5596d8);
    style_label.text.font = &lv_font_roboto_28;
    style_label.text.letter_space = 0;
    style_label.text.line_space = 2;
    style_label.text.opa = 255;

    lv_style_copy(&style_label_superscript, &lv_style_transp);
    style_label_superscript.text.font = &lv_font_roboto_12;

    /*-- BUTTONS ------------------------------------------------------------*/

    /*** Plus ****************************************************************/
    /* Button */
    button_plus = lv_btn_create(parent, NULL);
    lv_obj_set_pos(button_plus, 20, 30);
    lv_obj_set_size(button_plus, 100, 35);
    lv_btn_set_style(button_plus, LV_BTN_STYLE_REL, &lv_style_btn_rel);
    lv_obj_set_event_cb(button_plus, button_plus_cb);

    /* Label */
    label_plus = lv_label_create(button_plus, NULL);
    lv_label_set_text(label_plus, "+");
    lv_label_set_style(label_plus, LV_LABEL_STYLE_MAIN, &style_label_button);


    /*** Minus ***************************************************************/
    /* Button */
    button_minus = lv_btn_create(parent, NULL);
    lv_obj_set_pos(button_minus, 20, 80);
    lv_obj_set_size(button_minus, 100, 35);
    lv_btn_set_style(button_minus, LV_BTN_STYLE_REL, &lv_style_btn_rel);
    lv_obj_set_event_cb(button_minus, button_minus_cb);

    /* Label */
    label_minus = lv_label_create(button_minus, NULL);
    lv_label_set_text(label_minus, "-");
    lv_label_set_style(label_minus, LV_LABEL_STYLE_MAIN, &style_label_button);

    /*** One *****************************************************************/
    /* Button */
    button_one = lv_btn_create(parent, NULL);
    lv_obj_set_pos(button_one, 320, 30);
    lv_obj_set_size(button_one, 100, 35);
    lv_btn_set_style(button_one, LV_BTN_STYLE_REL, &lv_style_btn_rel);
    lv_obj_set_event_cb(button_one, button_one_cb);

    /* Label */
    label_one = lv_label_create(button_one, NULL);
    lv_label_set_text(label_one, "1");
    lv_label_set_style(label_one, LV_LABEL_STYLE_MAIN, &style_label_button);

    /*** Ten *****************************************************************/
    /* Button */
    button_ten = lv_btn_create(parent, NULL);
    lv_obj_set_pos(button_ten, 320, 80);
    lv_obj_set_size(button_ten, 100, 35);
    lv_btn_set_style(button_ten, LV_BTN_STYLE_REL, &lv_style_btn_rel);
    lv_obj_set_event_cb(button_ten, button_ten_cb);

    /* Label */
    label_ten = lv_label_create(button_ten, NULL);
    lv_label_set_text(label_ten, "10");
    lv_label_set_style(label_ten, LV_LABEL_STYLE_MAIN, &style_label_button);

    /*-- SWITCHES -----------------------------------------------------------*/
    /* Switch */
    switch_power = lv_sw_create(parent, NULL);
    lv_obj_set_pos(switch_power, 198, 222);
    lv_obj_set_size(switch_power, 70, 35);
    lv_sw_set_style(switch_power, LV_SW_STYLE_BG, &lv_style_pretty);
    lv_obj_set_event_cb(switch_power, switch_power_cb);

    /*-- LABELS -------------------------------------------------------------*/

    label_temp_current = lv_label_create(parent, NULL);
    lv_label_set_text(label_temp_current, "2");
    lv_label_set_align(label_temp_current, LV_LABEL_ALIGN_RIGHT);
    lv_label_set_long_mode(label_temp_current, LV_LABEL_LONG_CROP);
    lv_obj_set_pos(label_temp_current, 190, 30);
    lv_obj_set_size(label_temp_current, 48, 32);
    lv_label_set_style(label_temp_current, LV_LABEL_STYLE_MAIN, &style_label);


    label_temp_current_grad = lv_label_create(parent, NULL);
    lv_label_set_text(label_temp_current_grad, "o");
    lv_obj_set_pos(label_temp_current_grad, 240, 30);
    lv_obj_set_size(label_temp_current_grad, 7, 14);
    lv_label_set_style(label_temp_current_grad, LV_LABEL_STYLE_MAIN, &style_label_superscript);


    label_temp_target = lv_label_create(parent, NULL);
    lv_label_set_text(label_temp_target, "100");
    lv_label_set_long_mode(label_temp_target, LV_LABEL_LONG_CROP);
    lv_label_set_align(label_temp_target, LV_LABEL_ALIGN_RIGHT);
    lv_obj_set_pos(label_temp_target, 190, 80);
    lv_obj_set_size(label_temp_target, 48, 32);
    lv_label_set_style(label_temp_target, LV_LABEL_STYLE_MAIN, &style_label);


    label_temp_target_grad = lv_label_create(parent, NULL);
    lv_label_set_text(label_temp_target_grad, "o");
    lv_obj_set_pos(label_temp_target_grad, 240, 80);
    lv_obj_set_size(label_temp_target_grad, 7, 14);
    lv_label_set_style(label_temp_target_grad, LV_LABEL_STYLE_MAIN, &style_label_superscript);


    label_power = lv_label_create(parent, NULL);
    lv_label_set_text(label_power, "Power");
    lv_label_set_align(label_power, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_pos(label_power, 193, 263);
    lv_obj_set_size(label_power, 80, 32);
    lv_label_set_style(label_power, LV_LABEL_STYLE_MAIN, &style_label);

}

static void
button_plus_cb(lv_obj_t *button_plus, lv_event_t event)
{
    switch(event) {
        case LV_EVENT_PRESSED:
        case LV_EVENT_LONG_PRESSED:
        case LV_EVENT_LONG_PRESSED_REPEAT:
            temp_target += 1;
            lv_label_set_text_fmt(label_temp_current, "%d", temp_target);
            break;

        default:
            break;
    }
}

static void
button_minus_cb(lv_obj_t *button_minus, lv_event_t event)
{

}

static void
button_one_cb(lv_obj_t *button_one, lv_event_t event)
{

}

static void
button_ten_cb(lv_obj_t *button_ten, lv_event_t event)
{

}

#include <stdio.h>

static void
switch_power_cb(lv_obj_t *switch_power, lv_event_t event)
{

    switch(event) {
        case LV_EVENT_PRESSED:
        case LV_EVENT_LONG_PRESSED:
        case LV_EVENT_LONG_PRESSED_REPEAT:
            temp_target -= 1;
            lv_label_set_text_fmt(label_temp_current, "%d", temp_target);
            break;

        case LV_EVENT_APPLY:
            printf("apply");
            break;

        case LV_EVENT_CANCEL:
            printf("cancel");
            break;

        default:
            break;
    }
}
