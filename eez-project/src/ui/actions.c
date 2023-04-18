#include <main.h>
#include "lvgl/lvgl.h"

#include "actions.h"
#include "vars.h"
#include "images.h"

void action_load_image(lv_event_t * e) {
	HAL_Delay(10);

	int32_t image_index = get_var_load_image_index();

	lv_color_t recolor;
	recolor.ch.red = 0;
	recolor.ch.green = 0;
	recolor.ch.blue = 0;
	recolor.ch.alpha = 255;

	_lv_img_cache_open(images[image_index].img_dsc, recolor, 0);
}
