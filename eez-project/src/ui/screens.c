#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_heating_screen_security_button_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_heating_screen_lighting_button_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_heating_screen_temperature_arc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 15, 3, value, "Failed to assign Value in Arc widget");
            }
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_heating_screen_power_arc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 23, 3, value, "Failed to assign Value in Arc widget");
            }
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 23, 0, e);
    }
}

static void event_handler_cb_heating_screen_save(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 27, 0, e);
    }
}

static void event_handler_cb_heating_screen_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_security_screen_heating_button_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_security_screen_lighting_button_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_security_screen_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 24, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_security_screen_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_lighting_screen_heating_button_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_lighting_screen_security_button_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_lighting_screen_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 16, 3, value, "Failed to assign Value in Slider widget");
            }
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 16, 0, e);
    }
}

static void event_handler_cb_lighting_screen_save_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 26, 0, e);
    }
}

static void event_handler_cb_lighting_screen_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_header_user_box(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 1, 0, e);
    }
}

static void event_handler_cb_account_box_account_box_container(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_account_box_user0_name(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_account_box_user1_name(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_account_box_user2_name(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_zone_selector_btn_prev(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 1, 0, e);
    }
}

static void event_handler_cb_zone_selector_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
}

static void event_handler_cb_zone_selector_btn_next(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

void create_screen_heating_screen() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.heating_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // background
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.background = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_background_1);
            lv_img_set_pivot(obj, 0, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_bg_image_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // header_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.header_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 75);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_header(obj, getFlowState(flowState, 8), 4);
        }
        {
            // heating_button_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.heating_button_1 = obj;
            lv_obj_set_pos(obj, 31, 90);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN|LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER);
            lv_obj_add_state(obj, LV_STATE_CHECKED);
            lv_obj_set_style_bg_image_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_heating_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // security_button_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.security_button_1 = obj;
            lv_obj_set_pos(obj, 31, 217);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_event_cb(obj, event_handler_cb_heating_screen_security_button_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_image_src(obj, &img_security_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_security_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_security_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // lighting_button_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.lighting_button_1 = obj;
            lv_obj_set_pos(obj, 31, 343);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_event_cb(obj, event_handler_cb_heating_screen_lighting_button_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_image_src(obj, &img_lighting_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_lighting_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_lighting_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // heating_temperature_panel
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.heating_temperature_panel = obj;
            lv_obj_set_pos(obj, 164, 90);
            lv_obj_set_size(obj, 303, 298);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj5 = obj;
                    lv_obj_set_pos(obj, 103, 25);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Temperature");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_bold_23, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // temperature_background
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.temperature_background = obj;
                    lv_obj_set_pos(obj, 72, 69);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_temperature_background);
                    lv_img_set_pivot(obj, 0, 0);
                }
                {
                    // temperature_arc
                    lv_obj_t *obj = lv_arc_create(parent_obj);
                    objects.temperature_arc = obj;
                    lv_obj_set_pos(obj, 71, 69);
                    lv_obj_set_size(obj, 180, 180);
                    lv_arc_set_range(obj, 15, 40);
                    lv_arc_set_bg_start_angle(obj, 135);
                    lv_arc_set_bg_end_angle(obj, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_heating_screen_temperature_arc, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_arc_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_image_src(obj, &img_slider_indicator, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 8, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_image_src(obj, &img_slider_knob, LV_PART_KNOB | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj6 = obj;
                    lv_obj_set_pos(obj, 97, 141);
                    lv_obj_set_size(obj, 127, 37);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &ui_font_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff333333), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj7 = obj;
                    lv_obj_set_pos(obj, 153, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &ui_font_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff333333), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // watch
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.watch = obj;
                    lv_obj_set_pos(obj, 103, 260);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_watch);
                    lv_img_set_pivot(obj, 0, 0);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj8 = obj;
                    lv_obj_set_pos(obj, 134, 262);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_bold_17, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // heating_power_panel
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.heating_power_panel = obj;
            lv_obj_set_pos(obj, 467, 90);
            lv_obj_set_size(obj, 303, 298);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj9 = obj;
                    lv_obj_set_pos(obj, 119, 25);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Power");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_bold_23, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // power_background
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.power_background = obj;
                    lv_obj_set_pos(obj, 63, 69);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_power_background);
                    lv_img_set_pivot(obj, 0, 0);
                }
                {
                    // power_arc
                    lv_obj_t *obj = lv_arc_create(parent_obj);
                    objects.power_arc = obj;
                    lv_obj_set_pos(obj, 61, 69);
                    lv_obj_set_size(obj, 180, 180);
                    lv_arc_set_range(obj, 0, 300);
                    lv_arc_set_bg_start_angle(obj, 135);
                    lv_arc_set_bg_end_angle(obj, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_heating_screen_power_arc, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_arc_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_image_src(obj, &img_slider_indicator, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 8, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_image_src(obj, &img_slider_knob, LV_PART_KNOB | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj10 = obj;
                    lv_obj_set_pos(obj, 88, 141);
                    lv_obj_set_size(obj, 127, 37);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &ui_font_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff333333), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj11 = obj;
                    lv_obj_set_pos(obj, 141, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "kW");
                    lv_obj_set_style_text_font(obj, &ui_font_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff333333), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj12 = obj;
                    lv_obj_set_pos(obj, 93, 262);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Saving 187 EUR");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_bold_17, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // save
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.save = obj;
            lv_obj_set_pos(obj, 530, 396);
            lv_obj_set_size(obj, 241, 58);
            lv_obj_add_event_cb(obj, event_handler_cb_heating_screen_save, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_image_src(obj, &img_saved, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_save, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_opa(obj, 32, LV_PART_MAIN | LV_STATE_DISABLED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj0 = obj;
                    lv_obj_set_pos(obj, 7, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_add_event_cb(obj, event_handler_cb_heating_screen_obj0, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 64, LV_PART_MAIN | LV_STATE_DISABLED);
                }
            }
        }
        {
            // zone_selector_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.zone_selector_1 = obj;
            lv_obj_set_pos(obj, 165, 396);
            lv_obj_set_size(obj, 356, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_zone_selector(obj, getFlowState(flowState, 29), 11);
        }
        {
            // account_box_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.account_box_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_account_box(obj, getFlowState(flowState, 30), 15);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void tick_screen_heating_screen() {
    void *flowState = getFlowState(0, 0);
    tick_user_widget_header(getFlowState(flowState, 8), 4);
    {
        int32_t new_val = evalIntegerProperty(flowState, 15, 3, "Failed to evaluate Value in Arc widget");
        int32_t cur_val = lv_arc_get_value(objects.temperature_arc);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.temperature_arc;
            lv_arc_set_value(objects.temperature_arc, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 16, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj6);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj6;
            lv_label_set_text(objects.obj6, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 17, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj7);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj7;
            lv_label_set_text(objects.obj7, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 19, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj8);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj8;
            lv_label_set_text(objects.obj8, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 23, 3, "Failed to evaluate Value in Arc widget");
        int32_t cur_val = lv_arc_get_value(objects.power_arc);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.power_arc;
            lv_arc_set_value(objects.power_arc, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 24, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj10);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj10;
            lv_label_set_text(objects.obj10, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 27, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.save, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.save;
            if (new_val) lv_obj_add_state(objects.save, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.save, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 28, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj0, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj0;
            if (new_val) lv_obj_add_state(objects.obj0, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj0, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    tick_user_widget_zone_selector(getFlowState(flowState, 29), 11);
    tick_user_widget_account_box(getFlowState(flowState, 30), 15);
}

void create_screen_security_screen() {
    void *flowState = getFlowState(0, 1);
    lv_obj_t *obj = lv_obj_create(0);
    objects.security_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // background_1
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.background_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_background_2);
            lv_img_set_pivot(obj, 0, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_bg_image_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // header_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.header_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 75);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_header(obj, getFlowState(flowState, 6), 21);
        }
        {
            // heating_button_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.heating_button_2 = obj;
            lv_obj_set_pos(obj, 31, 90);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_event_cb(obj, event_handler_cb_security_screen_heating_button_2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_image_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_heating_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // security_button_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.security_button_2 = obj;
            lv_obj_set_pos(obj, 31, 217);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN|LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER);
            lv_obj_add_state(obj, LV_STATE_CHECKED);
            lv_obj_set_style_bg_image_src(obj, &img_security_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_security_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_security_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // lighting_button_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.lighting_button_2 = obj;
            lv_obj_set_pos(obj, 31, 343);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_event_cb(obj, event_handler_cb_security_screen_lighting_button_2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_image_src(obj, &img_lighting_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_lighting_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_lighting_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 186, 115);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Security");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bold_23, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj21 = obj;
            lv_obj_set_pos(obj, 353, 182);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_big_checkmark);
            lv_img_set_pivot(obj, 0, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 584, 160);
            lv_obj_set_size(obj, 167, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj22 = obj;
            lv_obj_set_pos(obj, 729, 160);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_img_set_pivot(obj, 0, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 584, 196);
            lv_obj_set_size(obj, 167, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj23 = obj;
            lv_obj_set_pos(obj, 729, 196);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_img_set_pivot(obj, 0, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 584, 232);
            lv_obj_set_size(obj, 167, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj24 = obj;
            lv_obj_set_pos(obj, 729, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_img_set_pivot(obj, 0, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj17 = obj;
            lv_obj_set_pos(obj, 584, 268);
            lv_obj_set_size(obj, 167, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj25 = obj;
            lv_obj_set_pos(obj, 729, 268);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_img_set_pivot(obj, 0, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 584, 304);
            lv_obj_set_size(obj, 167, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj26 = obj;
            lv_obj_set_pos(obj, 729, 304);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_img_set_pivot(obj, 0, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 186, 304);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, 186, 338);
            lv_obj_set_size(obj, 382, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff939ebc), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 525, 403);
            lv_obj_set_size(obj, 236, 45);
            lv_obj_add_event_cb(obj, event_handler_cb_security_screen_obj1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_image_src(obj, &img_switch_off, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_switch_on, LV_PART_INDICATOR | LV_STATE_CHECKED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 238, 46);
                    lv_label_set_text(obj, "");
                    lv_obj_add_event_cb(obj, event_handler_cb_security_screen_obj2, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DISABLED);
                }
            }
        }
        {
            // zone_selector_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.zone_selector_2 = obj;
            lv_obj_set_pos(obj, 165, 396);
            lv_obj_set_size(obj, 356, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_zone_selector(obj, getFlowState(flowState, 26), 28);
        }
        {
            // account_box_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.account_box_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_account_box(obj, getFlowState(flowState, 27), 32);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void tick_screen_security_screen() {
    void *flowState = getFlowState(0, 1);
    tick_user_widget_header(getFlowState(flowState, 6), 21);
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj21, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj21;
            if (new_val) lv_obj_add_flag(objects.obj21, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj21, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj14);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj14;
            lv_label_set_text(objects.obj14, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 13, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj22, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj22;
            if (new_val) lv_obj_add_flag(objects.obj22, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj22, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 14, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj15);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj15;
            lv_label_set_text(objects.obj15, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 15, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj23, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj23;
            if (new_val) lv_obj_add_flag(objects.obj23, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj23, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 16, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj16);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj16;
            lv_label_set_text(objects.obj16, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 17, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj24, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj24;
            if (new_val) lv_obj_add_flag(objects.obj24, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj24, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 18, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj17);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj17;
            lv_label_set_text(objects.obj17, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 19, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj25, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj25;
            if (new_val) lv_obj_add_flag(objects.obj25, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj25, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 20, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj18);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj18;
            lv_label_set_text(objects.obj18, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 21, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj26, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj26;
            if (new_val) lv_obj_add_flag(objects.obj26, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj26, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 22, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj19);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj19;
            lv_label_set_text(objects.obj19, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 23, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj20);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj20;
            lv_label_set_text(objects.obj20, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 24, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj1, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj1;
            if (new_val) lv_obj_add_state(objects.obj1, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj1, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 25, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj2, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj2;
            if (new_val) lv_obj_add_state(objects.obj2, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj2, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 25, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj2;
            lv_label_set_text(objects.obj2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    tick_user_widget_zone_selector(getFlowState(flowState, 26), 28);
    tick_user_widget_account_box(getFlowState(flowState, 27), 32);
}

void create_screen_lighting_screen() {
    void *flowState = getFlowState(0, 2);
    lv_obj_t *obj = lv_obj_create(0);
    objects.lighting_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // background_2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.background_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_background_3);
            lv_img_set_pivot(obj, 0, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_bg_image_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // header_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.header_3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 75);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_header(obj, getFlowState(flowState, 8), 38);
        }
        {
            // heating_button_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.heating_button_3 = obj;
            lv_obj_set_pos(obj, 31, 90);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_event_cb(obj, event_handler_cb_lighting_screen_heating_button_3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_image_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_heating_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // security_button_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.security_button_3 = obj;
            lv_obj_set_pos(obj, 31, 217);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_event_cb(obj, event_handler_cb_lighting_screen_security_button_3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_image_src(obj, &img_security_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_security_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_security_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // lighting_button_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.lighting_button_3 = obj;
            lv_obj_set_pos(obj, 31, 343);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN|LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER);
            lv_obj_add_state(obj, LV_STATE_CHECKED);
            lv_obj_set_style_bg_image_src(obj, &img_lighting_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_lighting_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_lighting_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj27 = obj;
            lv_obj_set_pos(obj, 186, 115);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Lighting");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bold_23, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 186, 123);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_light_bulb);
            lv_img_set_pivot(obj, 0, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj28 = obj;
            lv_obj_set_pos(obj, 312, 333);
            lv_obj_set_size(obj, 131, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bold_23, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj29 = obj;
            lv_obj_set_pos(obj, 584, 160);
            lv_obj_set_size(obj, 167, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 238, 297);
            lv_obj_set_size(obj, 263, 10);
            lv_obj_add_event_cb(obj, event_handler_cb_lighting_screen_obj3, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_set_style_bg_image_src(obj, &img_slider_lighting, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj34 = obj;
            lv_obj_set_pos(obj, 729, 160);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_img_set_pivot(obj, 0, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj30 = obj;
            lv_obj_set_pos(obj, 584, 196);
            lv_obj_set_size(obj, 167, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj35 = obj;
            lv_obj_set_pos(obj, 729, 196);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_img_set_pivot(obj, 0, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj31 = obj;
            lv_obj_set_pos(obj, 584, 232);
            lv_obj_set_size(obj, 167, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj36 = obj;
            lv_obj_set_pos(obj, 729, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_img_set_pivot(obj, 0, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj32 = obj;
            lv_obj_set_pos(obj, 584, 268);
            lv_obj_set_size(obj, 167, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj37 = obj;
            lv_obj_set_pos(obj, 729, 268);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_img_set_pivot(obj, 0, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj33 = obj;
            lv_obj_set_pos(obj, 584, 304);
            lv_obj_set_size(obj, 167, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj38 = obj;
            lv_obj_set_pos(obj, 729, 304);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_img_set_pivot(obj, 0, 0);
        }
        {
            // save_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.save_1 = obj;
            lv_obj_set_pos(obj, 528, 397);
            lv_obj_set_size(obj, 241, 58);
            lv_obj_add_event_cb(obj, event_handler_cb_lighting_screen_save_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_image_src(obj, &img_saved, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_save, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_opa(obj, 32, LV_PART_MAIN | LV_STATE_DISABLED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj4 = obj;
                    lv_obj_set_pos(obj, 7, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_add_event_cb(obj, event_handler_cb_lighting_screen_obj4, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 64, LV_PART_MAIN | LV_STATE_DISABLED);
                }
            }
        }
        {
            // zone_selector_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.zone_selector_3 = obj;
            lv_obj_set_pos(obj, 165, 396);
            lv_obj_set_size(obj, 356, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_zone_selector(obj, getFlowState(flowState, 28), 45);
        }
        {
            // account_box_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.account_box_3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_account_box(obj, getFlowState(flowState, 29), 49);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void tick_screen_lighting_screen() {
    void *flowState = getFlowState(0, 2);
    tick_user_widget_header(getFlowState(flowState, 8), 38);
    {
        const char *new_val = evalTextProperty(flowState, 14, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj28);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj28;
            lv_label_set_text(objects.obj28, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 15, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj29);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj29;
            lv_label_set_text(objects.obj29, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 16, 3, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.obj3);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj3;
            lv_slider_set_value(objects.obj3, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 17, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj34, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj34;
            if (new_val) lv_obj_add_flag(objects.obj34, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj34, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 18, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj30);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj30;
            lv_label_set_text(objects.obj30, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 19, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj35, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj35;
            if (new_val) lv_obj_add_flag(objects.obj35, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj35, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 20, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj31);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj31;
            lv_label_set_text(objects.obj31, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 21, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj36, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj36;
            if (new_val) lv_obj_add_flag(objects.obj36, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj36, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 22, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj32);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj32;
            lv_label_set_text(objects.obj32, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 23, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj37, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj37;
            if (new_val) lv_obj_add_flag(objects.obj37, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj37, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 24, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj33);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj33;
            lv_label_set_text(objects.obj33, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 25, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj38, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj38;
            if (new_val) lv_obj_add_flag(objects.obj38, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj38, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 26, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.save_1, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.save_1;
            if (new_val) lv_obj_add_state(objects.save_1, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.save_1, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 27, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj4, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj4;
            if (new_val) lv_obj_add_state(objects.obj4, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj4, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    tick_user_widget_zone_selector(getFlowState(flowState, 28), 45);
    tick_user_widget_account_box(getFlowState(flowState, 29), 49);
}

void create_user_widget_header(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // user_box
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 1, 0);
            lv_obj_set_size(obj, 221, 75);
            lv_obj_add_event_cb(obj, event_handler_cb_header_user_box, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // face
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                    lv_obj_set_pos(obj, 21, 9);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_face_0);
                    lv_img_set_pivot(obj, 0, 0);
                    lv_obj_set_style_transform_pivot_x(obj, 27, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_transform_pivot_y(obj, 27, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                    lv_obj_set_pos(obj, 87, 18);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "My home");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_regular_21, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                    lv_obj_set_pos(obj, 87, 42);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "3 MEMBERS");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // arrow_account
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                    lv_obj_set_pos(obj, 171, 44);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_arrow_account);
                    lv_img_set_pivot(obj, 0, 0);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN|LV_OBJ_FLAG_CHECKABLE);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER);
                    lv_obj_set_style_bg_image_src(obj, &img_arrow_account_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_image_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                }
            }
        }
        {
            // menu
            lv_obj_t *obj = lv_img_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 5] = obj;
            lv_obj_set_pos(obj, 519, 26);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_header_menu);
            lv_img_set_pivot(obj, 0, 0);
        }
    }
}

void tick_user_widget_header(void *flowState, int startWidgetIndex) {
    {
        float timeline_position = getTimelinePosition(flowState);
        
        static struct {
            float last_timeline_position;
            int32_t obj_face_scale_init_value;
        } anim_state = { -1 };
        
        if (anim_state.last_timeline_position == -1) {
            anim_state.last_timeline_position = 0;
            anim_state.obj_face_scale_init_value = lv_obj_get_style_prop(((lv_obj_t **)&objects)[startWidgetIndex + 1], LV_PART_MAIN, LV_STYLE_TRANSFORM_SCALE_X).num;
        }
        
        if (timeline_position != anim_state.last_timeline_position) {
            anim_state.last_timeline_position = timeline_position;
            
            {
                lv_obj_t *obj = ((lv_obj_t **)&objects)[startWidgetIndex + 1];
                
                float scale_value = anim_state.obj_face_scale_init_value;
                
                while (1) {
                    // keyframe #1
                    if (timeline_position < 0) {
                        break;
                    }
                    if (timeline_position >= 0 && timeline_position < 0.5) {
                        float t = (timeline_position - 0) / 0.5;
                        // scale
                        scale_value += eez_linear(t) * (64 - scale_value);
                        break;
                    }
                    scale_value = 64;
                    
                    // keyframe #2
                    if (timeline_position >= 0.5 && timeline_position < 1) {
                        float t = (timeline_position - 0.5) / 0.5;
                        // scale
                        scale_value += eez_linear(t) * (256 - scale_value);
                        break;
                    }
                    scale_value = 256;
                    
                    break;
                }
                
                lv_style_value_t value;
                
                value.num = (int32_t)roundf(scale_value);
                lv_obj_set_local_style_prop(obj, LV_STYLE_TRANSFORM_SCALE_X, value, LV_PART_MAIN);
                lv_obj_set_local_style_prop(obj, LV_STYLE_TRANSFORM_SCALE_Y, value, LV_PART_MAIN);
            }
        }
    }
}

void create_user_widget_account_box(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // account_box_container
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 480);
            lv_obj_add_event_cb(obj, event_handler_cb_account_box_account_box_container, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // account_box_image
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                    lv_obj_set_pos(obj, 132, 64);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_account_box);
                    lv_img_set_pivot(obj, 0, 0);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user0_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                            lv_obj_set_pos(obj, 16, 8);
                            lv_obj_set_size(obj, 262, 54);
                            lv_label_set_text(obj, "ANA");
                            lv_obj_add_event_cb(obj, event_handler_cb_account_box_user0_name, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_text_font(obj, &ui_font_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe44d94), LV_PART_MAIN | LV_STATE_CHECKED);
                        }
                        {
                            // user1_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                            lv_obj_set_pos(obj, 16, 66);
                            lv_obj_set_size(obj, 262, 54);
                            lv_label_set_text(obj, "IVAN");
                            lv_obj_add_event_cb(obj, event_handler_cb_account_box_user1_name, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_text_font(obj, &ui_font_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe44d94), LV_PART_MAIN | LV_STATE_CHECKED);
                        }
                        {
                            // user2_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                            lv_obj_set_pos(obj, 16, 123);
                            lv_obj_set_size(obj, 262, 54);
                            lv_label_set_text(obj, "TOMA");
                            lv_obj_add_event_cb(obj, event_handler_cb_account_box_user2_name, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_text_font(obj, &ui_font_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe44d94), LV_PART_MAIN | LV_STATE_CHECKED);
                        }
                    }
                }
            }
        }
    }
}

void tick_user_widget_account_box(void *flowState, int startWidgetIndex) {
}

void create_user_widget_zone_selector(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // btn_prev
            lv_obj_t *obj = lv_btn_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 38, 0);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_zone_selector_btn_prev, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_arrow_prev, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_arrow_prev_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
            lv_obj_set_pos(obj, 98, 0);
            lv_obj_set_size(obj, 160, 60);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
            lv_obj_add_event_cb(obj, event_handler_cb_zone_selector_obj2, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 19, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // btn_next
            lv_obj_t *obj = lv_btn_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
            lv_obj_set_pos(obj, 258, 0);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_zone_selector_btn_next, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_arrow_next, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_arrow_next_hover, LV_PART_MAIN | LV_STATE_PRESSED);
        }
    }
}

void tick_user_widget_zone_selector(void *flowState, int startWidgetIndex) {
    {
        const char *new_val = evalTextProperty(flowState, 0, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 1]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 1];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 1], new_val);
            tick_value_change_obj = NULL;
        }
    }
}


static const char *screen_names[] = { "heating_screen", "security_screen", "lighting_screen" };
static const char *object_names[] = { "heating_screen", "security_screen", "lighting_screen", "header_1", "header_1__user_box", "header_1__face", "header_1__obj0", "header_1__obj1", "header_1__arrow_account", "header_1__menu", "zone_selector_1", "zone_selector_1__btn_prev", "zone_selector_1__obj2", "zone_selector_1__btn_next", "account_box_1", "account_box_1__account_box_container", "account_box_1__user0_name", "account_box_1__user1_name", "account_box_1__user2_name", "account_box_1__account_box_image", "header_2", "header_2__user_box", "header_2__face", "header_2__obj0", "header_2__obj1", "header_2__arrow_account", "header_2__menu", "zone_selector_2", "zone_selector_2__btn_prev", "zone_selector_2__obj2", "zone_selector_2__btn_next", "account_box_2", "account_box_2__account_box_container", "account_box_2__user0_name", "account_box_2__user1_name", "account_box_2__user2_name", "account_box_2__account_box_image", "header_3", "header_3__user_box", "header_3__face", "header_3__obj0", "header_3__obj1", "header_3__arrow_account", "header_3__menu", "zone_selector_3", "zone_selector_3__btn_prev", "zone_selector_3__obj2", "zone_selector_3__btn_next", "account_box_3", "account_box_3__account_box_container", "account_box_3__user0_name", "account_box_3__user1_name", "account_box_3__user2_name", "account_box_3__account_box_image", "security_button_1", "lighting_button_1", "temperature_arc", "power_arc", "save", "obj0", "heating_button_2", "lighting_button_2", "obj1", "obj2", "heating_button_3", "security_button_3", "obj3", "save_1", "obj4", "background", "heating_button_1", "heating_temperature_panel", "obj5", "temperature_background", "obj6", "obj7", "watch", "obj8", "heating_power_panel", "obj9", "power_background", "obj10", "obj11", "obj12", "background_1", "security_button_2", "obj13", "obj14", "obj15", "obj16", "obj17", "obj18", "obj19", "obj20", "obj21", "obj22", "obj23", "obj24", "obj25", "obj26", "background_2", "lighting_button_3", "obj27", "obj28", "obj29", "obj30", "obj31", "obj32", "obj33", "obj34", "obj35", "obj36", "obj37", "obj38" };

void create_screens() {
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_heating_screen();
    create_screen_security_screen();
    create_screen_lighting_screen();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_heating_screen,
    tick_screen_security_screen,
    tick_screen_lighting_screen,
    0,
    0,
    0,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
