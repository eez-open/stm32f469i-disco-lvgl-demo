#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_loading_screen_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 6, 3, value, "Failed to assign Value in Slider widget");
            }
        }
    }
}

static void event_handler_cb_heating_screen_security_button_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 10, 0);
    }
}

static void event_handler_cb_heating_screen_lighting_button_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 11, 0);
    }
}

static void event_handler_cb_heating_screen_temperature_arc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_VALUE_CHANGED) {
        flowPropagateValue(flowState, 15, 0);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 15, 3, value, "Failed to assign Value in Arc widget");
            }
        }
    }
}

static void event_handler_cb_heating_screen_power_arc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_VALUE_CHANGED) {
        flowPropagateValue(flowState, 23, 0);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 23, 3, value, "Failed to assign Value in Arc widget");
            }
        }
    }
}

static void event_handler_cb_heating_screen_save(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 27, 0);
    }
}

static void event_handler_cb_heating_screen_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
}

static void event_handler_cb_security_screen_heating_button_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 7, 0);
    }
}

static void event_handler_cb_security_screen_lighting_button_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 9, 0);
    }
}

static void event_handler_cb_security_screen_obj20(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 24, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_security_screen_obj21(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
}

static void event_handler_cb_lighting_screen_heating_button_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 9, 0);
    }
}

static void event_handler_cb_lighting_screen_security_button_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 10, 0);
    }
}

static void event_handler_cb_lighting_screen_obj24(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_VALUE_CHANGED) {
        flowPropagateValue(flowState, 16, 0);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 16, 3, value, "Failed to assign Value in Slider widget");
            }
        }
    }
}

static void event_handler_cb_lighting_screen_save_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 26, 0);
    }
}

static void event_handler_cb_lighting_screen_obj34(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
}

static void event_handler_cb_header_user_box(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 1, 0);
    }
}

static void event_handler_cb_account_box_account_box_container(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 2, 0);
    }
}

static void event_handler_cb_account_box_user0_name(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 4, 0);
    }
}

static void event_handler_cb_account_box_user1_name(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 5, 0);
    }
}

static void event_handler_cb_account_box_user2_name(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 6, 0);
    }
}

static void event_handler_cb_zone_selector_btn_prev(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 1, 0);
    }
}

static void event_handler_cb_zone_selector_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 0, 0);
    }
}

static void event_handler_cb_zone_selector_btn_next(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 3, 0);
    }
}

void create_screen_loading_screen() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.loading_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 185, 235);
            lv_obj_set_size(obj, 430, 10);
            lv_obj_add_event_cb(obj, event_handler_cb_loading_screen_obj0, LV_EVENT_ALL, flowState);
            lv_obj_set_style_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcacaca), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcacaca), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_loading_screen() {
    void *flowState = getFlowState(0, 0);
    {
        int32_t new_val = evalIntegerProperty(flowState, 6, 3, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.obj0);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj0;
            lv_slider_set_value(objects.obj0, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_heating_screen() {
    void *flowState = getFlowState(0, 1);
    lv_obj_t *obj = lv_obj_create(0);
    objects.heating_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // background
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.background = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_background_1);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_img_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // header_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.header_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 75);
            lv_style_value_t value;
            value.num = 0;
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_TOP, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_RIGHT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_BOTTOM, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_header(obj, getFlowState(flowState, 8), 26);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            // heating_button_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.heating_button_1 = obj;
            lv_obj_set_pos(obj, 31, 90);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_add_state(obj, LV_STATE_CHECKED);
            lv_obj_set_style_bg_img_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_src(obj, &img_heating_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // security_button_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.security_button_1 = obj;
            lv_obj_set_pos(obj, 31, 217);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_event_cb(obj, event_handler_cb_heating_screen_security_button_1, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_img_src(obj, &img_security_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_src(obj, &img_security_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_security_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // lighting_button_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.lighting_button_1 = obj;
            lv_obj_set_pos(obj, 31, 343);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_event_cb(obj, event_handler_cb_heating_screen_lighting_button_1, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_img_src(obj, &img_lighting_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_src(obj, &img_lighting_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_lighting_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // heating_temperature_panel
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.heating_temperature_panel = obj;
            lv_obj_set_pos(obj, 164, 90);
            lv_obj_set_size(obj, 303, 298);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
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
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                }
                {
                    // temperature_arc
                    lv_obj_t *obj = lv_arc_create(parent_obj);
                    objects.temperature_arc = obj;
                    lv_obj_set_pos(obj, 71, 69);
                    lv_obj_set_size(obj, 180, 180);
                    lv_arc_set_bg_start_angle(obj, 135);
                    lv_arc_set_bg_end_angle(obj, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_heating_screen_temperature_arc, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_arc_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_img_src(obj, &img_slider_indicator, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 8, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_slider_knob, LV_PART_KNOB | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 97, 141);
                    lv_obj_set_size(obj, 127, 37);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &ui_font_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 153, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &ui_font_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // watch
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.watch = obj;
                    lv_obj_set_pos(obj, 103, 260);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_watch);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj3 = obj;
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
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
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
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                }
                {
                    // power_arc
                    lv_obj_t *obj = lv_arc_create(parent_obj);
                    objects.power_arc = obj;
                    lv_obj_set_pos(obj, 61, 69);
                    lv_obj_set_size(obj, 180, 180);
                    lv_arc_set_bg_start_angle(obj, 135);
                    lv_arc_set_bg_end_angle(obj, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_heating_screen_power_arc, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_arc_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_img_src(obj, &img_slider_indicator, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 8, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_slider_knob, LV_PART_KNOB | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj4 = obj;
                    lv_obj_set_pos(obj, 88, 141);
                    lv_obj_set_size(obj, 127, 37);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &ui_font_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 141, 184);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "kW");
                    lv_obj_set_style_text_font(obj, &ui_font_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
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
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_img_src(obj, &img_saved, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_src(obj, &img_save, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 32, LV_PART_MAIN | LV_STATE_DISABLED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj5 = obj;
                    lv_obj_set_pos(obj, 7, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_add_event_cb(obj, event_handler_cb_heating_screen_obj5, LV_EVENT_ALL, flowState);
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
            lv_style_value_t value;
            value.num = 0;
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_TOP, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_RIGHT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_BOTTOM, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_zone_selector(obj, getFlowState(flowState, 29), 93);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            // account_box_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.account_box_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 480);
            lv_style_value_t value;
            value.num = 0;
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_TOP, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_RIGHT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_BOTTOM, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_account_box(obj, getFlowState(flowState, 30), 5);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
    }
}

void tick_screen_heating_screen() {
    void *flowState = getFlowState(0, 1);
    tick_user_widget_header(getFlowState(flowState, 8), 26);
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
        const char *cur_val = lv_label_get_text(objects.obj1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj1;
            lv_label_set_text(objects.obj1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 17, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj2;
            lv_label_set_text(objects.obj2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 19, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj3;
            lv_label_set_text(objects.obj3, new_val);
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
        const char *cur_val = lv_label_get_text(objects.obj4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj4;
            lv_label_set_text(objects.obj4, new_val);
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
        bool cur_val = lv_obj_has_state(objects.obj5, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj5;
            if (new_val) lv_obj_add_state(objects.obj5, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj5, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    tick_user_widget_zone_selector(getFlowState(flowState, 29), 93);
    tick_user_widget_account_box(getFlowState(flowState, 30), 5);
}

void create_screen_security_screen() {
    void *flowState = getFlowState(0, 2);
    lv_obj_t *obj = lv_obj_create(0);
    objects.security_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // background_1
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.background_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_background_2);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_img_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // header_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.header_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 75);
            lv_style_value_t value;
            value.num = 0;
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_TOP, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_RIGHT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_BOTTOM, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_header(obj, getFlowState(flowState, 6), 31);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            // heating_button_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.heating_button_2 = obj;
            lv_obj_set_pos(obj, 31, 90);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_event_cb(obj, event_handler_cb_security_screen_heating_button_2, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_img_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_src(obj, &img_heating_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // security_button_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.security_button_2 = obj;
            lv_obj_set_pos(obj, 31, 217);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_add_state(obj, LV_STATE_CHECKED);
            lv_obj_set_style_bg_img_src(obj, &img_security_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_src(obj, &img_security_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_security_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // lighting_button_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.lighting_button_2 = obj;
            lv_obj_set_pos(obj, 31, 343);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_event_cb(obj, event_handler_cb_security_screen_lighting_button_2, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_img_src(obj, &img_lighting_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_src(obj, &img_lighting_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_lighting_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 186, 115);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Security");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bold_23, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 353, 182);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_big_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj8 = obj;
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
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 729, 160);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj10 = obj;
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
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 729, 196);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj12 = obj;
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
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 729, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj14 = obj;
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
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 729, 268);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj16 = obj;
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
            objects.obj17 = obj;
            lv_obj_set_pos(obj, 729, 304);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 186, 304);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 186, 338);
            lv_obj_set_size(obj, 382, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff939ebc), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, 525, 403);
            lv_obj_set_size(obj, 236, 45);
            lv_obj_add_event_cb(obj, event_handler_cb_security_screen_obj20, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_switch_off, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_switch_on, LV_PART_INDICATOR | LV_STATE_CHECKED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj21 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 238, 46);
                    lv_label_set_text(obj, "");
                    lv_obj_add_event_cb(obj, event_handler_cb_security_screen_obj21, LV_EVENT_ALL, flowState);
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
            lv_style_value_t value;
            value.num = 0;
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_TOP, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_RIGHT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_BOTTOM, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_zone_selector(obj, getFlowState(flowState, 26), 97);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            // account_box_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.account_box_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 480);
            lv_style_value_t value;
            value.num = 0;
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_TOP, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_RIGHT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_BOTTOM, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_account_box(obj, getFlowState(flowState, 27), 11);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
    }
}

void tick_screen_security_screen() {
    void *flowState = getFlowState(0, 2);
    tick_user_widget_header(getFlowState(flowState, 6), 31);
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj7, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj7;
            if (new_val) lv_obj_add_flag(objects.obj7, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj7, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj8);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj8;
            lv_label_set_text(objects.obj8, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 13, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj9, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj9;
            if (new_val) lv_obj_add_flag(objects.obj9, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj9, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 14, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj10);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj10;
            lv_label_set_text(objects.obj10, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 15, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj11, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj11;
            if (new_val) lv_obj_add_flag(objects.obj11, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj11, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 16, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj12);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj12;
            lv_label_set_text(objects.obj12, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 17, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj13, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj13;
            if (new_val) lv_obj_add_flag(objects.obj13, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj13, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 18, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj14);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj14;
            lv_label_set_text(objects.obj14, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 19, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj15, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj15;
            if (new_val) lv_obj_add_flag(objects.obj15, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj15, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 20, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj16);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj16;
            lv_label_set_text(objects.obj16, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 21, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj17, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj17;
            if (new_val) lv_obj_add_flag(objects.obj17, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj17, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 22, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj18);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj18;
            lv_label_set_text(objects.obj18, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 23, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj19);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj19;
            lv_label_set_text(objects.obj19, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 24, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj20, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj20;
            if (new_val) lv_obj_add_state(objects.obj20, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj20, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 25, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj21, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj21;
            if (new_val) lv_obj_add_state(objects.obj21, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj21, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 25, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj21);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj21;
            lv_label_set_text(objects.obj21, new_val);
            tick_value_change_obj = NULL;
        }
    }
    tick_user_widget_zone_selector(getFlowState(flowState, 26), 97);
    tick_user_widget_account_box(getFlowState(flowState, 27), 11);
}

void create_screen_lighting_screen() {
    void *flowState = getFlowState(0, 3);
    lv_obj_t *obj = lv_obj_create(0);
    objects.lighting_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // background_2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.background_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_background_3);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_img_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // header_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.header_3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 75);
            lv_style_value_t value;
            value.num = 0;
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_TOP, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_RIGHT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_BOTTOM, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_header(obj, getFlowState(flowState, 8), 36);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            // heating_button_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.heating_button_3 = obj;
            lv_obj_set_pos(obj, 31, 90);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_event_cb(obj, event_handler_cb_lighting_screen_heating_button_3, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_img_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_src(obj, &img_heating_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_heating_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // security_button_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.security_button_3 = obj;
            lv_obj_set_pos(obj, 31, 217);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_event_cb(obj, event_handler_cb_lighting_screen_security_button_3, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_img_src(obj, &img_security_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_src(obj, &img_security_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_security_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // lighting_button_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.lighting_button_3 = obj;
            lv_obj_set_pos(obj, 31, 343);
            lv_obj_set_size(obj, 111, 114);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_CHECKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_add_state(obj, LV_STATE_CHECKED);
            lv_obj_set_style_bg_img_src(obj, &img_lighting_button_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_src(obj, &img_lighting_button, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_lighting_button_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
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
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj22 = obj;
            lv_obj_set_pos(obj, 312, 333);
            lv_obj_set_size(obj, 131, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bold_23, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj23 = obj;
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
            objects.obj24 = obj;
            lv_obj_set_pos(obj, 238, 297);
            lv_obj_set_size(obj, 263, 10);
            lv_obj_add_event_cb(obj, event_handler_cb_lighting_screen_obj24, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_slider_lighting, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj25 = obj;
            lv_obj_set_pos(obj, 729, 160);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj26 = obj;
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
            objects.obj27 = obj;
            lv_obj_set_pos(obj, 729, 196);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj28 = obj;
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
            objects.obj29 = obj;
            lv_obj_set_pos(obj, 729, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj30 = obj;
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
            objects.obj31 = obj;
            lv_obj_set_pos(obj, 729, 268);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj32 = obj;
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
            objects.obj33 = obj;
            lv_obj_set_pos(obj, 729, 304);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            // save_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.save_1 = obj;
            lv_obj_set_pos(obj, 528, 397);
            lv_obj_set_size(obj, 241, 58);
            lv_obj_add_event_cb(obj, event_handler_cb_lighting_screen_save_1, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_img_src(obj, &img_saved, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_img_src(obj, &img_save, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_opa(obj, 32, LV_PART_MAIN | LV_STATE_DISABLED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj34 = obj;
                    lv_obj_set_pos(obj, 7, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_add_event_cb(obj, event_handler_cb_lighting_screen_obj34, LV_EVENT_ALL, flowState);
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
            lv_style_value_t value;
            value.num = 0;
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_TOP, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_RIGHT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_BOTTOM, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_zone_selector(obj, getFlowState(flowState, 28), 101);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            // account_box_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.account_box_3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 480);
            lv_style_value_t value;
            value.num = 0;
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_TOP, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_RIGHT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_BOTTOM, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_account_box(obj, getFlowState(flowState, 29), 17);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
    }
}

void tick_screen_lighting_screen() {
    void *flowState = getFlowState(0, 3);
    tick_user_widget_header(getFlowState(flowState, 8), 36);
    {
        const char *new_val = evalTextProperty(flowState, 14, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj22);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj22;
            lv_label_set_text(objects.obj22, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 15, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj23);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj23;
            lv_label_set_text(objects.obj23, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 16, 3, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.obj24);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj24;
            lv_slider_set_value(objects.obj24, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 17, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj25, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj25;
            if (new_val) lv_obj_add_flag(objects.obj25, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj25, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 18, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj26);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj26;
            lv_label_set_text(objects.obj26, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 19, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj27, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj27;
            if (new_val) lv_obj_add_flag(objects.obj27, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj27, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 20, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj28);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj28;
            lv_label_set_text(objects.obj28, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 21, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj29, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj29;
            if (new_val) lv_obj_add_flag(objects.obj29, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj29, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 22, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj30);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj30;
            lv_label_set_text(objects.obj30, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 23, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj31, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj31;
            if (new_val) lv_obj_add_flag(objects.obj31, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj31, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 24, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj32);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj32;
            lv_label_set_text(objects.obj32, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 25, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj33, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj33;
            if (new_val) lv_obj_add_flag(objects.obj33, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj33, LV_OBJ_FLAG_HIDDEN);
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
        bool cur_val = lv_obj_has_state(objects.obj34, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj34;
            if (new_val) lv_obj_add_state(objects.obj34, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj34, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    tick_user_widget_zone_selector(getFlowState(flowState, 28), 101);
    tick_user_widget_account_box(getFlowState(flowState, 29), 17);
}

void create_user_widget_header(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // user_box
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
            lv_obj_set_pos(obj, 1, 0);
            lv_obj_set_size(obj, 221, 75);
            lv_obj_add_event_cb(obj, event_handler_cb_header_user_box, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
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
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_transform_pivot_x(obj, 27, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_transform_pivot_y(obj, 27, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 87, 18);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "My home");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_regular_21, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 87, 42);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "3 MEMBERS");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // arrow_account
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
                    lv_obj_set_pos(obj, 171, 44);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_arrow_account);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CHECKABLE);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_img_src(obj, &img_arrow_account_hoover, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_img_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                }
            }
        }
        {
            // menu
            lv_obj_t *obj = lv_img_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
            lv_obj_set_pos(obj, 519, 26);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_header_menu);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
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
            anim_state.obj_face_scale_init_value = lv_obj_get_style_prop(((lv_obj_t **)&objects)[startWidgetIndex + 1], LV_PART_MAIN, LV_STYLE_TRANSFORM_ZOOM).num;
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
                lv_obj_set_local_style_prop(obj, LV_STYLE_TRANSFORM_ZOOM, value, LV_PART_MAIN);
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
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
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
                        ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                        lv_obj_set_pos(obj, 132, 64);
                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        lv_img_set_src(obj, &img_account_box);
                        lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        {
                            lv_obj_t *parent_obj = obj;
                            {
                                // user0_name
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
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
                                ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
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
                                ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
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
                ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                lv_obj_set_pos(obj, 38, 0);
                lv_obj_set_size(obj, 60, 60);
                lv_obj_add_event_cb(obj, event_handler_cb_zone_selector_btn_prev, LV_EVENT_ALL, flowState);
                lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_img_src(obj, &img_arrow_prev, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_img_src(obj, &img_arrow_prev_hoover, LV_PART_MAIN | LV_STATE_PRESSED);
            }
            {
                lv_obj_t *obj = lv_label_create(parent_obj);
                ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                lv_obj_set_pos(obj, 98, 0);
                lv_obj_set_size(obj, 160, 60);
                lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                lv_label_set_text(obj, "");
                lv_obj_add_event_cb(obj, event_handler_cb_zone_selector_obj6, LV_EVENT_ALL, flowState);
                lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_pad_top(obj, 19, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // btn_next
                lv_obj_t *obj = lv_btn_create(parent_obj);
                ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
                lv_obj_set_pos(obj, 258, 0);
                lv_obj_set_size(obj, 60, 60);
                lv_obj_add_event_cb(obj, event_handler_cb_zone_selector_btn_next, LV_EVENT_ALL, flowState);
                lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_img_src(obj, &img_arrow_next, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_img_src(obj, &img_arrow_next_hover, LV_PART_MAIN | LV_STATE_PRESSED);
            }
        }
    }
    
    void tick_user_widget_zone_selector(void *flowState, int startWidgetIndex) {
        {
            const char *new_val = evalTextProperty(flowState, 0, 3, "Failed to evaluate Text in Label widget");
            const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 2]);
            if (strcmp(new_val, cur_val) != 0) {
                tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 2];
                lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 2], new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_loading_screen();
    create_screen_heating_screen();
    create_screen_security_screen();
    create_screen_lighting_screen();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_loading_screen,
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
