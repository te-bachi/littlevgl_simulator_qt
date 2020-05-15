#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

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

void app_create(lv_obj_t *parent);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*APP_H*/
