#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations



// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_USERS = 0,
    FLOW_GLOBAL_VARIABLE_ZONES = 1,
    FLOW_GLOBAL_VARIABLE_SELECTED_USER = 2,
    FLOW_GLOBAL_VARIABLE_SELECTED_ZONE = 3
};

// Native global variables

extern int32_t get_var_load_image_index();
extern void set_var_load_image_index(int32_t value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/