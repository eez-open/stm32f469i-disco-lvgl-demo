#include <main.h>
#include "lvgl/lvgl.h"

#include "actions.h"
#include "vars.h"
#include "images.h"

void action_load_image(lv_event_t * e) {
	HAL_Delay(10);

	int32_t image_index = get_var_load_image_index();

	lv_color_t recolor;
	recolor.full = 0;

	_lv_img_cache_entry_t *entry = _lv_img_cache_open(images[image_index].img_dsc, recolor, 0);

	if (entry) {
		uint8_t *buf = lv_mem_buf_get(entry->dec_dsc.header.w * LV_IMG_PX_SIZE_ALPHA_BYTE);

		if (buf) {
			for (lv_coord_t y = 0; y < entry->dec_dsc.header.h; y++) {
				if (lv_img_decoder_read_line(&entry->dec_dsc, 0, y, entry->dec_dsc.header.w, buf) != LV_RES_OK) {
                    lv_img_decoder_close(&entry->dec_dsc);
					break;
				}
			}

			lv_mem_buf_release(buf);
		}
	}
}
