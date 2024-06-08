#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *loading_screen;
    lv_obj_t *heating_screen;
    lv_obj_t *security_screen;
    lv_obj_t *lighting_screen;
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
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *obj15;
    lv_obj_t *obj16;
    lv_obj_t *obj17;
    lv_obj_t *obj18;
    lv_obj_t *obj19;
    lv_obj_t *obj2;
    lv_obj_t *obj20;
    lv_obj_t *obj21;
    lv_obj_t *obj22;
    lv_obj_t *obj23;
    lv_obj_t *obj24;
    lv_obj_t *obj25;
    lv_obj_t *obj26;
    lv_obj_t *obj27;
    lv_obj_t *obj28;
    lv_obj_t *obj29;
    lv_obj_t *obj3;
    lv_obj_t *obj30;
    lv_obj_t *obj31;
    lv_obj_t *obj32;
    lv_obj_t *obj33;
    lv_obj_t *obj34;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
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
    lv_obj_t *zone_selector_1__btn_next;
    lv_obj_t *zone_selector_1__btn_prev;
    lv_obj_t *zone_selector_1__obj6;
    lv_obj_t *zone_selector_2;
    lv_obj_t *zone_selector_2__btn_next;
    lv_obj_t *zone_selector_2__btn_prev;
    lv_obj_t *zone_selector_2__obj6;
    lv_obj_t *zone_selector_3;
    lv_obj_t *zone_selector_3__btn_next;
    lv_obj_t *zone_selector_3__btn_prev;
    lv_obj_t *zone_selector_3__obj6;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_LOADING_SCREEN = 1,
    SCREEN_ID_HEATING_SCREEN = 2,
    SCREEN_ID_SECURITY_SCREEN = 3,
    SCREEN_ID_LIGHTING_SCREEN = 4,
    SCREEN_ID_HEADER = 5,
    SCREEN_ID_ACCOUNT_BOX = 6,
    SCREEN_ID_ZONE_SELECTOR = 7,
};

void create_screen_loading_screen();
void tick_screen_loading_screen();

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