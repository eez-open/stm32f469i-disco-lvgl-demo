#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *heating_screen;
    lv_obj_t *security_screen;
    lv_obj_t *lighting_screen;
    lv_obj_t *_obj_image_10;
    lv_obj_t *_obj_image_12;
    lv_obj_t *_obj_image_14;
    lv_obj_t *_obj_image_16;
    lv_obj_t *_obj_image_24;
    lv_obj_t *_obj_image_26;
    lv_obj_t *_obj_image_28;
    lv_obj_t *_obj_image_30;
    lv_obj_t *_obj_image_32;
    lv_obj_t *_obj_image_6;
    lv_obj_t *_obj_image_8;
    lv_obj_t *_obj_label_0;
    lv_obj_t *_obj_label_1;
    lv_obj_t *_obj_label_11;
    lv_obj_t *_obj_label_13;
    lv_obj_t *_obj_label_15;
    lv_obj_t *_obj_label_17;
    lv_obj_t *_obj_label_18;
    lv_obj_t *_obj_label_2;
    lv_obj_t *_obj_label_20;
    lv_obj_t *_obj_label_21;
    lv_obj_t *_obj_label_22;
    lv_obj_t *_obj_label_25;
    lv_obj_t *_obj_label_27;
    lv_obj_t *_obj_label_29;
    lv_obj_t *_obj_label_3;
    lv_obj_t *_obj_label_31;
    lv_obj_t *_obj_label_33;
    lv_obj_t *_obj_label_4;
    lv_obj_t *_obj_label_7;
    lv_obj_t *_obj_label_9;
    lv_obj_t *_obj_slider_23;
    lv_obj_t *_obj_switch_19;
    lv_obj_t *account_box_1;
    lv_obj_t *account_box_1__account_box_container;
    lv_obj_t *account_box_1__account_box_image;
    lv_obj_t *account_box_1__user0_name;
    lv_obj_t *account_box_1__user1_name;
    lv_obj_t *account_box_1__user2_name;
    lv_obj_t *account_box_2;
    lv_obj_t *account_box_2__account_box_container;
    lv_obj_t *account_box_2__account_box_image;
    lv_obj_t *account_box_2__user0_name;
    lv_obj_t *account_box_2__user1_name;
    lv_obj_t *account_box_2__user2_name;
    lv_obj_t *account_box_3;
    lv_obj_t *account_box_3__account_box_container;
    lv_obj_t *account_box_3__account_box_image;
    lv_obj_t *account_box_3__user0_name;
    lv_obj_t *account_box_3__user1_name;
    lv_obj_t *account_box_3__user2_name;
    lv_obj_t *background;
    lv_obj_t *background_1;
    lv_obj_t *background_2;
    lv_obj_t *header_1;
    lv_obj_t *header_1__arrow_account;
    lv_obj_t *header_1__face;
    lv_obj_t *header_1__menu;
    lv_obj_t *header_1__user_box;
    lv_obj_t *header_2;
    lv_obj_t *header_2__arrow_account;
    lv_obj_t *header_2__face;
    lv_obj_t *header_2__menu;
    lv_obj_t *header_2__user_box;
    lv_obj_t *header_3;
    lv_obj_t *header_3__arrow_account;
    lv_obj_t *header_3__face;
    lv_obj_t *header_3__menu;
    lv_obj_t *header_3__user_box;
    lv_obj_t *heating_button_1;
    lv_obj_t *heating_button_2;
    lv_obj_t *heating_button_3;
    lv_obj_t *heating_power_panel;
    lv_obj_t *heating_temperature_panel;
    lv_obj_t *lighting_button_1;
    lv_obj_t *lighting_button_2;
    lv_obj_t *lighting_button_3;
    lv_obj_t *power_arc;
    lv_obj_t *power_background;
    lv_obj_t *save;
    lv_obj_t *save_1;
    lv_obj_t *security_button_1;
    lv_obj_t *security_button_2;
    lv_obj_t *security_button_3;
    lv_obj_t *temperature_arc;
    lv_obj_t *temperature_background;
    lv_obj_t *watch;
    lv_obj_t *zone_selector_1;
    lv_obj_t *zone_selector_1___obj_label_5;
    lv_obj_t *zone_selector_1__btn_next;
    lv_obj_t *zone_selector_1__btn_prev;
    lv_obj_t *zone_selector_2;
    lv_obj_t *zone_selector_2___obj_label_5;
    lv_obj_t *zone_selector_2__btn_next;
    lv_obj_t *zone_selector_2__btn_prev;
    lv_obj_t *zone_selector_3;
    lv_obj_t *zone_selector_3___obj_label_5;
    lv_obj_t *zone_selector_3__btn_next;
    lv_obj_t *zone_selector_3__btn_prev;
} objects_t;

extern objects_t objects;

void create_screen_heating_screen();
void tick_screen_heating_screen();

void create_screen_security_screen();
void tick_screen_security_screen();

void create_screen_lighting_screen();
void tick_screen_lighting_screen();

void create_user_widget_header(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_header(void *flowState, int startWidgetIndex);

void create_user_widget_account_box(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_account_box(void *flowState, int startWidgetIndex);

void create_user_widget_zone_selector(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_zone_selector(void *flowState, int startWidgetIndex);

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/