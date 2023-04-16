#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_heating_screen_security_button_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 3, 1);
    }
}

static void event_handler_cb_heating_screen_lighting_button_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 4, 1);
    }
}

static void event_handler_cb_heating_screen_temperature_arc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_VALUE_CHANGED) {
        flowPropagateValue(flowState, 8, 1);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        int32_t value = lv_arc_get_value(ta);
        if (tick_value_change_obj != ta) {
            assignIntegerProperty(flowState, 8, 2, value, "Failed to assign Value in Arc widget");
        }
    }
}

static void event_handler_cb_heating_screen_power_arc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_VALUE_CHANGED) {
        flowPropagateValue(flowState, 16, 1);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        int32_t value = lv_arc_get_value(ta);
        if (tick_value_change_obj != ta) {
            assignIntegerProperty(flowState, 16, 2, value, "Failed to assign Value in Arc widget");
        }
    }
}

static void event_handler_cb_heating_screen_save(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 20, 1);
    }
}

static void event_handler_cb_heating_screen__obj_label_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
}

static void event_handler_cb_security_screen_heating_button_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 2, 1);
    }
}

static void event_handler_cb_security_screen_lighting_button_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 4, 1);
    }
}

static void event_handler_cb_security_screen__obj_switch_19(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
        if (tick_value_change_obj != ta) {
            assignBooleanProperty(flowState, 23, 2, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_security_screen__obj_label_20(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
}

static void event_handler_cb_lighting_screen_heating_button_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 2, 1);
    }
}

static void event_handler_cb_lighting_screen_security_button_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 3, 1);
    }
}

static void event_handler_cb_lighting_screen__obj_slider_23(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_VALUE_CHANGED) {
        flowPropagateValue(flowState, 13, 1);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        int32_t value = lv_slider_get_value(ta);
        if (tick_value_change_obj != ta) {
            assignIntegerProperty(flowState, 13, 2, value, "Failed to assign Value in Slider widget");
        }
    }
}

static void event_handler_cb_lighting_screen_save_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 23, 1);
    }
}

static void event_handler_cb_lighting_screen__obj_label_33(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
}

static void event_handler_cb_header_user_box(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 1, 1);
    }
}

static void event_handler_cb_account_box_account_box_container(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 2, 1);
    }
}

static void event_handler_cb_account_box_user0_name(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 4, 1);
    }
}

static void event_handler_cb_account_box_user1_name(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 5, 1);
    }
}

static void event_handler_cb_account_box_user2_name(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 6, 1);
    }
}

static void event_handler_cb_zone_selector_btn_prev(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 1, 1);
    }
}

static void event_handler_cb_zone_selector__obj_label_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 0, 1);
    }
}

static void event_handler_cb_zone_selector_btn_next(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 3, 1);
    }
}

void create_screen_heating_screen() {
    void *flowState = getFlowState(0, 0);
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
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_header(obj, getFlowState(flowState, 0), 58);
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
                    lv_arc_set_range(obj, 15, 40);
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
                    objects._obj_label_0 = obj;
                    lv_obj_set_pos(obj, 97, 141);
                    lv_obj_set_size(obj, 127, 37);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &ui_font_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects._obj_label_1 = obj;
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
                    objects._obj_label_2 = obj;
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
                    lv_arc_set_range(obj, 0, 300);
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
                    objects._obj_label_3 = obj;
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
                    objects._obj_label_4 = obj;
                    lv_obj_set_pos(obj, 7, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_add_event_cb(obj, event_handler_cb_heating_screen__obj_label_4, LV_EVENT_ALL, flowState);
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
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_zone_selector(obj, getFlowState(flowState, 22), 91);
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
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_account_box(obj, getFlowState(flowState, 23), 37);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
    }
}

void tick_screen_heating_screen() {
    void *flowState = getFlowState(0, 0);
    tick_user_widget_header(getFlowState(flowState, 0), 58);
    {
        int32_t new_val = evalIntegerProperty(flowState, 8, 2, "Failed to evaluate Value in Arc widget");
        int32_t cur_val = lv_arc_get_value(objects.temperature_arc);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.temperature_arc;
            lv_arc_set_value(objects.temperature_arc, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_0);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_0;
            lv_label_set_text(objects._obj_label_0, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 10, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_1;
            lv_label_set_text(objects._obj_label_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_2;
            lv_label_set_text(objects._obj_label_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 16, 2, "Failed to evaluate Value in Arc widget");
        int32_t cur_val = lv_arc_get_value(objects.power_arc);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.power_arc;
            lv_arc_set_value(objects.power_arc, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 17, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_3;
            lv_label_set_text(objects._obj_label_3, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 20, 2, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.save, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.save;
            if (new_val) lv_obj_add_state(objects.save, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.save, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 21, 2, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects._obj_label_4, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_label_4;
            if (new_val) lv_obj_add_state(objects._obj_label_4, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects._obj_label_4, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    tick_user_widget_zone_selector(getFlowState(flowState, 22), 91);
    tick_user_widget_account_box(getFlowState(flowState, 23), 37);
}

void create_screen_security_screen() {
    void *flowState = getFlowState(0, 1);
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
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_header(obj, getFlowState(flowState, 0), 63);
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
            objects._obj_image_6 = obj;
            lv_obj_set_pos(obj, 353, 182);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_big_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects._obj_label_7 = obj;
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
            objects._obj_image_8 = obj;
            lv_obj_set_pos(obj, 729, 160);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects._obj_label_9 = obj;
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
            objects._obj_image_10 = obj;
            lv_obj_set_pos(obj, 729, 196);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects._obj_label_11 = obj;
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
            objects._obj_image_12 = obj;
            lv_obj_set_pos(obj, 729, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects._obj_label_13 = obj;
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
            objects._obj_image_14 = obj;
            lv_obj_set_pos(obj, 729, 268);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects._obj_label_15 = obj;
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
            objects._obj_image_16 = obj;
            lv_obj_set_pos(obj, 729, 304);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects._obj_label_17 = obj;
            lv_obj_set_pos(obj, 186, 304);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects._obj_label_18 = obj;
            lv_obj_set_pos(obj, 186, 338);
            lv_obj_set_size(obj, 382, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff939ebc), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects._obj_switch_19 = obj;
            lv_obj_set_pos(obj, 525, 403);
            lv_obj_set_size(obj, 236, 45);
            lv_obj_add_event_cb(obj, event_handler_cb_security_screen__obj_switch_19, LV_EVENT_ALL, flowState);
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
                    objects._obj_label_20 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 238, 46);
                    lv_label_set_text(obj, "");
                    lv_obj_add_event_cb(obj, event_handler_cb_security_screen__obj_label_20, LV_EVENT_ALL, flowState);
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
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_zone_selector(obj, getFlowState(flowState, 25), 95);
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
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_account_box(obj, getFlowState(flowState, 26), 43);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
    }
}

void tick_screen_security_screen() {
    void *flowState = getFlowState(0, 1);
    tick_user_widget_header(getFlowState(flowState, 0), 63);
    {
        bool new_val = evalBooleanProperty(flowState, 10, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_image_6, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_image_6;
            if (new_val) lv_obj_add_flag(objects._obj_image_6, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_image_6, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 11, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_7);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_7;
            lv_label_set_text(objects._obj_label_7, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 12, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_image_8, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_image_8;
            if (new_val) lv_obj_add_flag(objects._obj_image_8, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_image_8, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 13, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_9);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_9;
            lv_label_set_text(objects._obj_label_9, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 14, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_image_10, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_image_10;
            if (new_val) lv_obj_add_flag(objects._obj_image_10, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_image_10, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 15, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_11);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_11;
            lv_label_set_text(objects._obj_label_11, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 16, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_image_12, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_image_12;
            if (new_val) lv_obj_add_flag(objects._obj_image_12, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_image_12, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 17, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_13);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_13;
            lv_label_set_text(objects._obj_label_13, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 18, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_image_14, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_image_14;
            if (new_val) lv_obj_add_flag(objects._obj_image_14, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_image_14, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 19, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_15);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_15;
            lv_label_set_text(objects._obj_label_15, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 20, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_image_16, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_image_16;
            if (new_val) lv_obj_add_flag(objects._obj_image_16, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_image_16, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 21, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_17);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_17;
            lv_label_set_text(objects._obj_label_17, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 22, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_18);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_18;
            lv_label_set_text(objects._obj_label_18, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 23, 2, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects._obj_switch_19, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_switch_19;
            if (new_val) lv_obj_add_state(objects._obj_switch_19, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects._obj_switch_19, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 24, 2, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects._obj_label_20, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_label_20;
            if (new_val) lv_obj_add_state(objects._obj_label_20, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects._obj_label_20, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 24, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_20);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_20;
            lv_label_set_text(objects._obj_label_20, new_val);
            tick_value_change_obj = NULL;
        }
    }
    tick_user_widget_zone_selector(getFlowState(flowState, 25), 95);
    tick_user_widget_account_box(getFlowState(flowState, 26), 43);
}

void create_screen_lighting_screen() {
    void *flowState = getFlowState(0, 2);
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
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_header(obj, getFlowState(flowState, 0), 68);
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
            objects._obj_label_21 = obj;
            lv_obj_set_pos(obj, 312, 333);
            lv_obj_set_size(obj, 131, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bold_23, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects._obj_label_22 = obj;
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
            objects._obj_slider_23 = obj;
            lv_obj_set_pos(obj, 238, 297);
            lv_obj_set_size(obj, 263, 10);
            lv_obj_add_event_cb(obj, event_handler_cb_lighting_screen__obj_slider_23, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_img_src(obj, &img_slider_lighting, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects._obj_image_24 = obj;
            lv_obj_set_pos(obj, 729, 160);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects._obj_label_25 = obj;
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
            objects._obj_image_26 = obj;
            lv_obj_set_pos(obj, 729, 196);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects._obj_label_27 = obj;
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
            objects._obj_image_28 = obj;
            lv_obj_set_pos(obj, 729, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects._obj_label_29 = obj;
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
            objects._obj_image_30 = obj;
            lv_obj_set_pos(obj, 729, 268);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_checkmark);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects._obj_label_31 = obj;
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
            objects._obj_image_32 = obj;
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
                    objects._obj_label_33 = obj;
                    lv_obj_set_pos(obj, 7, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_add_event_cb(obj, event_handler_cb_lighting_screen__obj_label_33, LV_EVENT_ALL, flowState);
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
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_zone_selector(obj, getFlowState(flowState, 25), 99);
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
            lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, value, LV_PART_MAIN);
            lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, value, LV_PART_MAIN);
            create_user_widget_account_box(obj, getFlowState(flowState, 26), 49);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
    }
}

void tick_screen_lighting_screen() {
    void *flowState = getFlowState(0, 2);
    tick_user_widget_header(getFlowState(flowState, 0), 68);
    {
        const char *new_val = evalTextProperty(flowState, 11, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_21);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_21;
            lv_label_set_text(objects._obj_label_21, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_22);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_22;
            lv_label_set_text(objects._obj_label_22, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 13, 2, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects._obj_slider_23);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_slider_23;
            lv_slider_set_value(objects._obj_slider_23, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 14, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_image_24, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_image_24;
            if (new_val) lv_obj_add_flag(objects._obj_image_24, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_image_24, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 15, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_25);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_25;
            lv_label_set_text(objects._obj_label_25, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 16, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_image_26, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_image_26;
            if (new_val) lv_obj_add_flag(objects._obj_image_26, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_image_26, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 17, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_27);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_27;
            lv_label_set_text(objects._obj_label_27, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 18, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_image_28, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_image_28;
            if (new_val) lv_obj_add_flag(objects._obj_image_28, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_image_28, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 19, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_29);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_29;
            lv_label_set_text(objects._obj_label_29, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 20, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_image_30, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_image_30;
            if (new_val) lv_obj_add_flag(objects._obj_image_30, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_image_30, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 21, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects._obj_label_31);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects._obj_label_31;
            lv_label_set_text(objects._obj_label_31, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 22, 2, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects._obj_image_32, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_image_32;
            if (new_val) lv_obj_add_flag(objects._obj_image_32, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects._obj_image_32, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 23, 2, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.save_1, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.save_1;
            if (new_val) lv_obj_add_state(objects.save_1, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.save_1, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 24, 2, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects._obj_label_33, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects._obj_label_33;
            if (new_val) lv_obj_add_state(objects._obj_label_33, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects._obj_label_33, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    tick_user_widget_zone_selector(getFlowState(flowState, 25), 99);
    tick_user_widget_account_box(getFlowState(flowState, 26), 49);
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
                                lv_obj_set_pos(obj, 12, 6);
                                lv_obj_set_size(obj, 183, 39);
                                lv_label_set_text(obj, "ANA");
                                lv_obj_add_event_cb(obj, event_handler_cb_account_box_user0_name, LV_EVENT_ALL, flowState);
                                lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                lv_obj_set_style_text_font(obj, &ui_font_regular_21, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_text_color(obj, lv_color_hex(0xffe44d94), LV_PART_MAIN | LV_STATE_CHECKED);
                            }
                            {
                                // user1_name
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                                lv_obj_set_pos(obj, 12, 46);
                                lv_obj_set_size(obj, 183, 39);
                                lv_label_set_text(obj, "IVAN");
                                lv_obj_add_event_cb(obj, event_handler_cb_account_box_user1_name, LV_EVENT_ALL, flowState);
                                lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                lv_obj_set_style_text_font(obj, &ui_font_regular_21, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_text_color(obj, lv_color_hex(0xffe44d94), LV_PART_MAIN | LV_STATE_CHECKED);
                            }
                            {
                                // user2_name
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                                lv_obj_set_pos(obj, 12, 86);
                                lv_obj_set_size(obj, 183, 39);
                                lv_label_set_text(obj, "TOMA");
                                lv_obj_add_event_cb(obj, event_handler_cb_account_box_user2_name, LV_EVENT_ALL, flowState);
                                lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                lv_obj_set_style_text_font(obj, &ui_font_regular_21, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
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
                ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
                lv_obj_set_pos(obj, 98, 0);
                lv_obj_set_size(obj, 160, 60);
                lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                lv_label_set_text(obj, "");
                lv_obj_add_event_cb(obj, event_handler_cb_zone_selector__obj_label_5, LV_EVENT_ALL, flowState);
                lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                lv_obj_set_style_text_font(obj, &ui_font_bold_21, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_pad_top(obj, 19, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // btn_next
                lv_obj_t *obj = lv_btn_create(parent_obj);
                ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
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
            const char *new_val = evalTextProperty(flowState, 0, 2, "Failed to evaluate Text in Label widget");
            const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 0]);
            if (strcmp(new_val, cur_val) != 0) {
                tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 0];
                lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 0], new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
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
