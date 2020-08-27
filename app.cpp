#include "app.h"
#include <stdio.h>
#include "task/CommunicationTask.h"
#include "Temperature.h"

using namespace dermair;

#ifdef __cplusplus
extern "C" {
#include "image/fotofinder_logo.h"
#include "image/fotofinder_logo_small.h"
}
#endif

CommunicationTask communicationTask;

void eventDebug(lv_event_t event)
{
    switch (event) {
        case LV_EVENT_PRESSED:              printf("LV_EVENT_PRESSED\n");               break;
        case LV_EVENT_PRESSING:             printf("LV_EVENT_PRESSING\n");              break;
        case LV_EVENT_PRESS_LOST:           printf("LV_EVENT_PRESS_LOST\n");            break;
        case LV_EVENT_SHORT_CLICKED:        printf("LV_EVENT_SHORT_CLICKED\n");         break;
        case LV_EVENT_LONG_PRESSED:         printf("LV_EVENT_LONG_PRESSED\n");          break;
        case LV_EVENT_LONG_PRESSED_REPEAT:  printf("LV_EVENT_LONG_PRESSED_REPEAT\n");   break;
        case LV_EVENT_CLICKED:              printf("LV_EVENT_CLICKED\n");               break;
        case LV_EVENT_RELEASED:             printf("LV_EVENT_RELEASED\n");              break;
        case LV_EVENT_DRAG_BEGIN:           printf("LV_EVENT_DRAG_BEGIN\n");            break;
        case LV_EVENT_DRAG_END:             printf("LV_EVENT_DRAG_END\n");              break;
        case LV_EVENT_DRAG_THROW_BEGIN:     printf("LV_EVENT_DRAG_THROW_BEGIN\n");      break;
        case LV_EVENT_KEY:                  printf("LV_EVENT_KEY\n");                   break;
        case LV_EVENT_FOCUSED:              printf("LV_EVENT_FOCUSED\n");               break;
        case LV_EVENT_DEFOCUSED:            printf("LV_EVENT_DEFOCUSED\n");             break;
        case LV_EVENT_VALUE_CHANGED:        printf("LV_EVENT_VALUE_CHANGED\n");         break;
        case LV_EVENT_INSERT:               printf("LV_EVENT_INSERT\n");                break;
        case LV_EVENT_REFRESH:              printf("LV_EVENT_REFRESH\n");               break;
        case LV_EVENT_APPLY:                printf("LV_EVENT_APPLY\n");                 break;
        case LV_EVENT_CANCEL:               printf("LV_EVENT_CANCEL\n");                break;
        case LV_EVENT_DELETE:               printf("LV_EVENT_DELETE\n");                break;
    }
}

static void temp_check_bounds();
static void button_splash_cb(lv_obj_t *button_plus, lv_event_t event);
static void button_plus_cb(lv_obj_t *button_plus, lv_event_t event);
static void button_minus_cb(lv_obj_t *button_minus, lv_event_t event);
static void button_one_cb(lv_obj_t *button_one, lv_event_t event);
static void button_ten_cb(lv_obj_t *button_ten, lv_event_t event);
static void button_set_cb(lv_obj_t *button_ten, lv_event_t event);
static void switch_power_cb(lv_obj_t *switch_power, lv_event_t event);

/* Styles */
static lv_style_t   style_label_button;
static lv_style_t   style_label_button_press;
static lv_style_t   style_label_button_toggle;
static lv_style_t   style_label;
static lv_style_t   style_label_subscript;
static lv_style_t   style_label_superscript;

/*--- SCREENS ---*/
static lv_obj_t    *screen_splash;
static lv_obj_t    *screen_app;

/*--- SPLASH ---*/
static lv_obj_t    *img_splash;
static lv_obj_t    *bar_splash;
static lv_obj_t    *button_splash;
static lv_obj_t    *label_button_splash;
static lv_obj_t    *label_splash;

/*--- IMAGE ---*/
static lv_obj_t    *img_main;

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

/* Set */
static lv_obj_t    *button_set;
static lv_obj_t    *label_set;

/*--- SWITCHES ---*/
static lv_obj_t    *switch_power;

/*--- LABELS ---*/

static lv_obj_t *label_current;
static lv_obj_t *label_temp_current;
static lv_obj_t *label_temp_current_grad;
static lv_obj_t *label_temp_current_celsius;

static lv_obj_t *label_target;
static lv_obj_t *label_temp_target;
static lv_obj_t *label_temp_target_grad;
static lv_obj_t *label_temp_target_celsius;
static lv_obj_t *label_power;


static const float TEMP_MIN = 0.0f;
static const float TEMP_MAX = 80.0f;

typedef enum {
    POWER_STATE_OFF,
    POWER_STATE_ON
} POWER_STATE;

static POWER_STATE powerStatus = POWER_STATE_OFF;

static float temp_target = 15.0f;
static float temp_step   = 1.0f;

#if USE_LV_LOG != 0
/* Serial debugging */
void app_log_print(lv_log_level_t level, const char * file, uint32_t line, const char * dsc)
{s
    Serial.printf("%s@%d->%s\r\n", file, line, dsc);
    delay(100);
}
#endif

lv_obj_t *
splash_screen_create()
{
    screen_splash = lv_obj_create(NULL, NULL);
    return screen_splash;
}

lv_obj_t *
app_screen_create()
{
    screen_app = lv_obj_create(NULL, NULL);
    return screen_app;
}

void
style_create()
{
    /*** Styles **************************************************************/
    lv_style_copy(&style_label_button, &lv_style_transp);
    style_label_button.text.color = lv_color_hex(0xffffff);
    style_label_button.text.sel_color = lv_color_hex(0x5596d8);
    style_label_button.text.font = &lv_font_roboto_28;
    style_label_button.text.letter_space = 0;
    style_label_button.text.line_space = 2;
    style_label_button.text.opa = 255;

    lv_style_copy(&style_label_button_press, &lv_style_btn_pr);
    style_label_button_press.body.main_color = lv_color_hex(0xff0000);
    style_label_button_press.body.grad_color = lv_color_hex(0x770000);

    lv_style_copy(&style_label_button_toggle, &lv_style_btn_tgl_pr);
    style_label_button_toggle.body.main_color = lv_color_hex(0xee0000);
    style_label_button_toggle.body.grad_color = lv_color_hex(0x660000);

    lv_style_copy(&style_label, &lv_style_transp);
    style_label.text.color = lv_color_hex(0x303030);
    style_label.text.sel_color = lv_color_hex(0x5596d8);
    style_label.text.font = &lv_font_roboto_28;
    style_label.text.letter_space = 0;
    style_label.text.line_space = 2;
    style_label.text.opa = 255;

    lv_style_copy(&style_label_subscript, &lv_style_transp);
    style_label_subscript.text.font = &lv_font_roboto_22;

    lv_style_copy(&style_label_superscript, &lv_style_transp);
    style_label_superscript.text.font = &lv_font_roboto_12;
}

void
splash_create(lv_obj_t *parent)
{
    img_splash = lv_img_create(parent, NULL);
    lv_img_set_src(img_splash, &fotofinder_logo);
    lv_obj_set_pos(img_splash, 14, 40);

    bar_splash = lv_bar_create(parent, NULL);
    lv_obj_set_pos(bar_splash, 90, 190);
    lv_obj_set_size(bar_splash, 300, 30);

    /* Button */
    button_splash = lv_btn_create(parent, NULL);
    lv_obj_set_pos(button_splash, 190, 255);
    lv_obj_set_size(button_splash, 100, 35);
    lv_btn_set_style(button_splash, LV_BTN_STYLE_REL, &lv_style_btn_rel);
    lv_obj_set_event_cb(button_splash, button_splash_cb);
    lv_obj_set_hidden(button_splash, true);

    /* Label (Button) */
    label_button_splash = lv_label_create(button_splash, NULL);
    lv_label_set_text(label_button_splash, "Start");
    lv_label_set_style(label_button_splash, LV_LABEL_STYLE_MAIN, &style_label_button);

    /* Label */
    label_splash = lv_label_create(parent, NULL);
    lv_label_set_text(label_splash, "");
    lv_obj_align(label_splash, button_splash, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_align(label_splash, LV_LABEL_ALIGN_CENTER);
    lv_label_set_style(label_splash, LV_LABEL_STYLE_MAIN, &style_label_subscript);
}

void
splash_show()
{
    lv_scr_load(screen_splash);
}

void
splash_bar_set_value(int16_t value, uint16_t time)
{
    lv_bar_set_anim_time(bar_splash, time);
    lv_bar_set_value(bar_splash, value, time == 0 ? LV_ANIM_OFF : LV_ANIM_ON);
}

void
splash_button_show()
{
    lv_obj_set_hidden(button_splash, false);
}

void
splash_button_hide()
{
    lv_obj_set_hidden(button_splash, true);
}

void
splash_label_set_text(const char* text)
{
    lv_label_set_text(label_splash, text);
    lv_obj_align(label_splash, button_splash, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_align(label_splash, LV_LABEL_ALIGN_CENTER);
}

void
app_create(lv_obj_t *parent)
{

    /*-- IMAGES -------------------------------------------------------------*/
    img_main = lv_img_create(parent, NULL);
    lv_img_set_src(img_main, &fotofinder_logo_small);
    lv_obj_set_pos(img_main, 89, 15);


    /*-- BUTTONS ------------------------------------------------------------*/

    /*** Plus ****************************************************************/
    /* Button */
    button_plus = lv_btn_create(parent, NULL);
    lv_obj_set_pos(button_plus, 250, 110);
    lv_obj_set_size(button_plus, 100, 40);
    lv_btn_set_style(button_plus, LV_BTN_STYLE_REL, &lv_style_btn_rel);
    lv_btn_set_style(button_plus, LV_BTN_STYLE_PR, &style_label_button_press);
    lv_obj_set_event_cb(button_plus, button_plus_cb);

    /* Label */
    label_plus = lv_label_create(button_plus, NULL);
    lv_label_set_text(label_plus, "+");
    lv_label_set_style(label_plus, LV_LABEL_STYLE_MAIN, &style_label_button);


    /*** Minus ***************************************************************/
    /* Button */
    button_minus = lv_btn_create(parent, NULL);
    lv_obj_set_pos(button_minus, 250, 160);
    lv_obj_set_size(button_minus, 100, 40);
    lv_btn_set_style(button_minus, LV_BTN_STYLE_REL, &lv_style_btn_rel);
    lv_btn_set_style(button_minus, LV_BTN_STYLE_PR, &style_label_button_press);
    lv_obj_set_event_cb(button_minus, button_minus_cb);

    /* Label */
    label_minus = lv_label_create(button_minus, NULL);
    lv_label_set_text(label_minus, "-");
    lv_label_set_style(label_minus, LV_LABEL_STYLE_MAIN, &style_label_button);

    /*** One *****************************************************************/
    /* Button */
    button_one = lv_btn_create(parent, NULL);
    lv_obj_set_pos(button_one, 360, 110);
    lv_obj_set_size(button_one, 100, 40);
    lv_btn_set_style(button_one, LV_BTN_STYLE_REL, &lv_style_btn_rel);
    lv_btn_set_style(button_one, LV_BTN_STYLE_PR, &style_label_button_press);
    lv_btn_set_style(button_one, LV_BTN_STYLE_TGL_REL, &style_label_button_toggle);
    lv_obj_set_event_cb(button_one, button_one_cb);
    lv_btn_set_toggle(button_one, true);
    lv_btn_set_state(button_one, LV_IMGBTN_STYLE_TGL_REL);

    /* Label */
    label_one = lv_label_create(button_one, NULL);
    lv_label_set_text(label_one, "1");
    lv_label_set_style(label_one, LV_LABEL_STYLE_MAIN, &style_label_button);

    /*** Ten *****************************************************************/
    /* Button */
    button_ten = lv_btn_create(parent, NULL);
    lv_obj_set_pos(button_ten, 360, 160);
    lv_obj_set_size(button_ten, 100, 40);
    lv_btn_set_style(button_ten, LV_BTN_STYLE_REL, &lv_style_btn_rel);
    lv_btn_set_style(button_ten, LV_BTN_STYLE_PR, &style_label_button_press);
    lv_btn_set_style(button_ten, LV_BTN_STYLE_TGL_REL, &style_label_button_toggle);
    lv_obj_set_event_cb(button_ten, button_ten_cb);
    lv_btn_set_toggle(button_ten, true);

    /* Label */
    label_ten = lv_label_create(button_ten, NULL);
    lv_label_set_text(label_ten, "10");
    lv_label_set_style(label_ten, LV_LABEL_STYLE_MAIN, &style_label_button);

    /*** Set *****************************************************************/
    /* Button */
    button_set = lv_btn_create(parent, NULL);
    lv_obj_set_pos(button_set, 250, 230);
    lv_obj_set_size(button_set, 210, 70);
    lv_btn_set_style(button_set, LV_BTN_STYLE_REL, &lv_style_btn_rel);
    lv_btn_set_style(button_set, LV_BTN_STYLE_PR, &style_label_button_press);
    lv_obj_set_event_cb(button_set, button_set_cb);

    /* Label */
    label_set = lv_label_create(button_set, NULL);
    lv_label_set_text(label_set, "Set");
    lv_label_set_style(label_set, LV_LABEL_STYLE_MAIN, &style_label_button);

    /*-- SWITCHES -----------------------------------------------------------*/
    /* Switch */
    switch_power = lv_sw_create(parent, NULL);
    lv_obj_set_pos(switch_power, 80+5, 230);
    lv_obj_set_size(switch_power, 70, 35);
    lv_sw_set_style(switch_power, LV_SW_STYLE_BG, &lv_style_pretty);
    lv_obj_set_event_cb(switch_power, switch_power_cb);

    /*-- LABELS -------------------------------------------------------------*/

    /* Current */
    label_current = lv_label_create(parent, NULL);
    lv_label_set_text(label_current, "Current");
    lv_label_set_align(label_current, LV_LABEL_ALIGN_LEFT);
    lv_label_set_long_mode(label_current, LV_LABEL_LONG_CROP);
    lv_obj_set_pos(label_current, 20, 110+5);
    lv_obj_set_size(label_current, 120, 40);
    lv_label_set_style(label_current, LV_LABEL_STYLE_MAIN, &style_label);

    label_temp_current = lv_label_create(parent, NULL);
    lv_label_set_text(label_temp_current, "-");
    lv_label_set_align(label_temp_current, LV_LABEL_ALIGN_RIGHT);
    lv_label_set_long_mode(label_temp_current, LV_LABEL_LONG_CROP);
    lv_obj_set_pos(label_temp_current, 130, 110+5);
    lv_obj_set_size(label_temp_current, 68, 40);
    lv_label_set_style(label_temp_current, LV_LABEL_STYLE_MAIN, &style_label);

    label_temp_current_grad = lv_label_create(parent, NULL);
    lv_label_set_text(label_temp_current_grad, "o");
    lv_obj_set_pos(label_temp_current_grad, 200, 110+5);
    lv_obj_set_size(label_temp_current_grad, 7, 14);
    lv_label_set_style(label_temp_current_grad, LV_LABEL_STYLE_MAIN, &style_label_superscript);

    label_temp_current_celsius = lv_label_create(parent, NULL);
    lv_label_set_text(label_temp_current_celsius, "C");
    lv_obj_set_pos(label_temp_current_celsius, 210, 110+5);
    lv_obj_set_size(label_temp_current_celsius, 20, 40);
    lv_label_set_style(label_temp_current_celsius, LV_LABEL_STYLE_MAIN, &style_label);


    /* Target */
    label_target = lv_label_create(parent, NULL);
    lv_label_set_text(label_target, "Target");
    lv_label_set_align(label_target, LV_LABEL_ALIGN_LEFT);
    lv_label_set_long_mode(label_target, LV_LABEL_LONG_CROP);
    lv_obj_set_pos(label_target, 20, 160+6);
    lv_obj_set_size(label_target, 120, 32);
    lv_label_set_style(label_target, LV_LABEL_STYLE_MAIN, &style_label);

    label_temp_target = lv_label_create(parent, NULL);
    lv_label_set_text(label_temp_target, "-");
    app_temp_target_set(temp_target);
    lv_label_set_long_mode(label_temp_target, LV_LABEL_LONG_CROP);
    lv_label_set_align(label_temp_target, LV_LABEL_ALIGN_RIGHT);
    lv_obj_set_pos(label_temp_target, 130, 160+6);
    lv_obj_set_size(label_temp_target, 68, 32);
    lv_label_set_style(label_temp_target, LV_LABEL_STYLE_MAIN, &style_label);

    label_temp_target_grad = lv_label_create(parent, NULL);
    lv_label_set_text(label_temp_target_grad, "o");
    lv_obj_set_pos(label_temp_target_grad, 200, 160+6);
    lv_obj_set_size(label_temp_target_grad, 7, 14);
    lv_label_set_style(label_temp_target_grad, LV_LABEL_STYLE_MAIN, &style_label_superscript);

    label_temp_target_celsius = lv_label_create(parent, NULL);
    lv_label_set_text(label_temp_target_celsius, "C");
    lv_obj_set_pos(label_temp_target_celsius, 210, 160+5);
    lv_obj_set_size(label_temp_target_celsius, 20, 40);
    lv_label_set_style(label_temp_target_celsius, LV_LABEL_STYLE_MAIN, &style_label);

    label_power = lv_label_create(parent, NULL);
    lv_label_set_text(label_power, "Power");
    lv_label_set_align(label_power, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_pos(label_power, 80, 271);
    lv_obj_set_size(label_power, 80, 32);
    lv_label_set_style(label_power, LV_LABEL_STYLE_MAIN, &style_label);
}

void
app_show()
{
    lv_scr_load(screen_app);
}

void
app_temp_current_set(float temp)
{
    lv_label_set_text_fmt(label_temp_current, "%5.1f", temp);
}

void
app_temp_target_set(float temp)
{
    lv_label_set_text_fmt(label_temp_target, "%5.1f", temp);
}

static void
temp_check_bounds()
{
    if (temp_target >= TEMP_MAX) {
        temp_target = TEMP_MAX;
        lv_btn_set_state(button_plus, LV_BTN_STATE_INA);
    } else {
        lv_btn_set_state(button_plus, LV_BTN_STATE_REL);
    }

    if (temp_target <= TEMP_MIN) {
        temp_target = TEMP_MIN;
        lv_btn_set_state(button_minus, LV_BTN_STATE_INA);
    } else {
        lv_btn_set_state(button_minus, LV_BTN_STATE_REL);
    }
}

static void
button_splash_cb(lv_obj_t *button_plus, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED) {
        app_show();
    }
}

static void
button_plus_cb(lv_obj_t *button_plus, lv_event_t event)
{
    if (lv_btn_get_state(button_plus) == LV_BTN_STATE_INA) {
        return;
    }

    switch (event) {
        case LV_EVENT_PRESSED:
        case LV_EVENT_LONG_PRESSED:
        case LV_EVENT_LONG_PRESSED_REPEAT:
            temp_target += temp_step;
            temp_check_bounds();
            app_temp_target_set(temp_target);
            break;

        default:
            break;
    }
}

static void
button_minus_cb(lv_obj_t *button_minus, lv_event_t event)
{
    if (lv_btn_get_state(button_minus) == LV_BTN_STATE_INA) {
        return;
    }

    switch (event) {
        case LV_EVENT_PRESSED:
        case LV_EVENT_LONG_PRESSED:
        case LV_EVENT_LONG_PRESSED_REPEAT:
            temp_target -= temp_step;
            temp_check_bounds();
            app_temp_target_set(temp_target);
            break;

        default:
            break;
    }
}

static void
button_one_cb(lv_obj_t *button_one, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED) {
        temp_step = 1.0f;
        lv_btn_set_state(button_one, LV_BTN_STYLE_PR);
        lv_btn_set_state(button_ten, LV_BTN_STYLE_REL);
    }
}

static void
button_ten_cb(lv_obj_t *button_ten, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED) {
        temp_step = 10.0f;
        lv_btn_set_state(button_ten, LV_BTN_STYLE_PR);
        lv_btn_set_state(button_one, LV_BTN_STYLE_REL);
    }
}

static void
button_set_cb(lv_obj_t *button_ten, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED) {
        Temperature t(Temperature::VALID, temp_target);
        communicationTask.setTargetTemperature(t);
    }
}

static void
switch_power_cb(lv_obj_t *switch_power, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED) {
        switch (powerStatus) {
            case POWER_STATE_OFF:
                communicationTask.setPowerStatus(true);
                powerStatus = POWER_STATE_ON;
                break;

            case POWER_STATE_ON:
                communicationTask.setPowerStatus(false);
                powerStatus = POWER_STATE_OFF;
                break;
        }
    }
}
