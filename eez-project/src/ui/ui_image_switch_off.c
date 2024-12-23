#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif
#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_IMG_SWITCH_OFF
#define LV_ATTRIBUTE_IMG_IMG_SWITCH_OFF
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_IMG_SWITCH_OFF uint8_t img_switch_off_map[] = {
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 
    0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0xec, 0x00, 0x00, 0x00, 0x2d, 0x08, 0x06, 
    0x00, 0x00, 0x00, 0xad, 0x67, 0x87, 0x05, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 
    0x59, 0x73, 0x00, 0x00, 0x0b, 0x13, 0x00, 0x00, 0x0b, 0x13, 0x01, 0x00, 0x9a, 
    0x9c, 0x18, 0x00, 0x00, 0x00, 0x20, 0x63, 0x48, 0x52, 0x4d, 0x00, 0x00, 0x7a, 
    0x25, 0x00, 0x00, 0x80, 0x83, 0x00, 0x00, 0xf9, 0xff, 0x00, 0x00, 0x80, 0xe9, 
    0x00, 0x00, 0x75, 0x30, 0x00, 0x00, 0xea, 0x60, 0x00, 0x00, 0x3a, 0x98, 0x00, 
    0x00, 0x17, 0x6f, 0x92, 0x5f, 0xc5, 0x46, 0x00, 0x00, 0x04, 0x18, 0x49, 0x44, 
    0x41, 0x54, 0x78, 0xda, 0xec, 0xdd, 0x41, 0x68, 0x54, 0x57, 0x18, 0xc5, 0xf1, 
    0xff, 0x77, 0xdf, 0x4c, 0x24, 0x89, 0x42, 0x41, 0xc8, 0x4a, 0xb1, 0xb8, 0x30, 
    0x56, 0xad, 0x28, 0x48, 0x5c, 0xeb, 0xae, 0x6d, 0x1a, 0xa5, 0xd8, 0x20, 0x22, 
    0x42, 0x5d, 0x48, 0x32, 0x09, 0x52, 0x71, 0x6d, 0x87, 0xd1, 0x9d, 0x10, 0x1a, 
    0xc4, 0xc4, 0xe8, 0xc2, 0x6e, 0xaa, 0x54, 0x09, 0x45, 0xa3, 0xa9, 0x3b, 0xdd, 
    0x17, 0x41, 0xb1, 0x35, 0x1a, 0x41, 0xa9, 0xe8, 0x2a, 0x1b, 0x85, 0x98, 0xa8, 
    0x99, 0x79, 0xef, 0xeb, 0x62, 0x26, 0xa9, 0x55, 0xa3, 0x31, 0x1a, 0xf3, 0x46, 
    0xce, 0x6f, 0x33, 0x04, 0x06, 0x06, 0xce, 0xbc, 0xc3, 0x77, 0xdf, 0xf0, 0x72, 
    0xaf, 0xb9, 0x3b, 0xb3, 0x55, 0x28, 0x14, 0x42, 0x43, 0xc3, 0xba, 0xb5, 0x1e, 
    0x65, 0x36, 0x1b, 0xbe, 0x1e, 0x6c, 0x25, 0xb0, 0x14, 0x58, 0x04, 0xd4, 0x02, 
    0x31, 0x30, 0x56, 0x79, 0xad, 0x07, 0x6a, 0x00, 0x43, 0xe4, 0xd3, 0x91, 0x00, 
    0x13, 0xc0, 0xe3, 0xca, 0x75, 0xbe, 0xb8, 0x72, 0x9d, 0x3f, 0x03, 0x46, 0x81, 
    0x07, 0xe0, 0xb7, 0x1d, 0xbb, 0x66, 0x71, 0xe9, 0xf2, 0xc8, 0xc8, 0xf5, 0x1b, 
    0xf9, 0x7c, 0x3e, 0x99, 0xed, 0x87, 0xd9, 0x6c, 0x0a, 0x7b, 0xa4, 0x6f, 0xa0, 
    0x31, 0x6b, 0x61, 0x37, 0xc6, 0x0e, 0xb0, 0x25, 0xfa, 0xce, 0x44, 0x66, 0xca, 
    0x1f, 0xe2, 0x9c, 0x2e, 0x7a, 0x72, 0x72, 0x6f, 0x5b, 0xcb, 0xf0, 0x9c, 0x16, 
    0xf6, 0xe8, 0x89, 0x81, 0x55, 0x11, 0x51, 0x1e, 0xd8, 0x06, 0x04, 0x85, 0x2f, 
    0xf2, 0x5e, 0x93, 0xb9, 0x3f, 0x26, 0x2e, 0x74, 0xee, 0x69, 0x19, 0xfa, 0xa0, 
    0x85, 0xed, 0xea, 0xfa, 0xb5, 0xbe, 0x6e, 0xe1, 0x67, 0x3f, 0x61, 0xb6, 0x0f, 
    0xc8, 0x2a, 0x6b, 0x91, 0x0f, 0xa6, 0x88, 0xfb, 0xcf, 0xe3, 0x4f, 0x1e, 0x1f, 
    0xdc, 0xbf, 0x7f, 0xe7, 0xd8, 0x7b, 0x17, 0xb6, 0xb7, 0xf7, 0xe2, 0x6a, 0x32, 
    0x76, 0xd6, 0x60, 0x95, 0xb2, 0x15, 0x99, 0xa3, 0x85, 0x32, 0x0c, 0x51, 0xf2, 
    0xd6, 0x5c, 0xae, 0xf9, 0xe6, 0xac, 0x0b, 0xdb, 0x7b, 0x62, 0xf0, 0x6b, 0x83, 
    0xb3, 0x94, 0x7f, 0x30, 0x12, 0x91, 0xb9, 0x35, 0x96, 0x24, 0xfe, 0x7d, 0x47, 
    0x5b, 0xf3, 0xa5, 0xe9, 0xde, 0x30, 0xed, 0x7d, 0x68, 0xef, 0xf1, 0xc1, 0xed, 
    0x06, 0xe7, 0x54, 0x56, 0x91, 0x8f, 0xa6, 0x3e, 0x04, 0x3b, 0xdf, 0x7b, 0x7c, 
    0x70, 0xfb, 0x3b, 0x4d, 0xd8, 0x9e, 0xbe, 0x8b, 0x5f, 0x85, 0x60, 0xe7, 0x75, 
    0xbf, 0x2a, 0x32, 0x3f, 0xf7, 0xb5, 0x49, 0xe2, 0x5b, 0x5e, 0x37, 0x69, 0x5f, 
    0x29, 0xec, 0xb1, 0x63, 0xe7, 0xbe, 0x20, 0xca, 0xfe, 0x09, 0x2c, 0x54, 0x6e, 
    0x22, 0xf3, 0xe6, 0x09, 0x71, 0xb1, 0xa9, 0xbd, 0x7d, 0xeb, 0xad, 0x69, 0x97, 
    0xc4, 0xdd, 0xdd, 0xfd, 0xb5, 0x44, 0xd9, 0xb3, 0x2a, 0xab, 0xc8, 0xbc, 0x5b, 
    0x48, 0x94, 0x39, 0xd3, 0xdd, 0xdd, 0x5f, 0x3b, 0x6d, 0x61, 0x6b, 0xea, 0x6a, 
    0x0f, 0x00, 0x6b, 0x94, 0x95, 0x48, 0x1a, 0xd8, 0x97, 0x95, 0x4e, 0xbe, 0xba, 
    0x24, 0x3e, 0xd2, 0x37, 0xd0, 0x98, 0x0d, 0xd1, 0x0d, 0xca, 0x8f, 0x55, 0x89, 
    0x48, 0x3a, 0x4c, 0x14, 0x93, 0x78, 0xed, 0xe4, 0x53, 0x51, 0x53, 0x13, 0x36, 
    0x1b, 0xa2, 0x03, 0x2a, 0xab, 0x48, 0xea, 0xd4, 0x54, 0xba, 0xf9, 0xdf, 0x84, 
    0xed, 0xee, 0xfb, 0x7d, 0xf9, 0x82, 0xb0, 0x60, 0x18, 0xc8, 0x28, 0x1f, 0x91, 
    0xd4, 0x29, 0x3d, 0x4f, 0x9e, 0x37, 0xfe, 0xd8, 0xf6, 0xdd, 0xbd, 0x00, 0x50, 
    0x13, 0x16, 0xfc, 0xa0, 0xb2, 0x8a, 0xa4, 0x56, 0xa6, 0xd2, 0x51, 0x42, 0x08, 
    0xc1, 0x0c, 0x76, 0x2a, 0x13, 0x91, 0xf4, 0x32, 0xd8, 0x19, 0x42, 0x30, 0xeb, 
    0xe9, 0xb9, 0xb0, 0xda, 0x32, 0xf6, 0xb7, 0x22, 0x11, 0x49, 0x37, 0x2f, 0xf9, 
    0x9a, 0x60, 0x91, 0x6d, 0x52, 0x14, 0x22, 0x55, 0x30, 0x65, 0x23, 0xdb, 0x14, 
    0x1c, 0xdf, 0xa0, 0x28, 0x44, 0xaa, 0x60, 0xc2, 0xe2, 0x1b, 0x82, 0x99, 0xad, 
    0x50, 0x14, 0x22, 0x55, 0x30, 0x61, 0xcd, 0x56, 0x04, 0x60, 0x99, 0xa2, 0x10, 
    0xa9, 0x0a, 0xcb, 0x82, 0x97, 0x37, 0x4c, 0x13, 0x91, 0xd4, 0x2f, 0x89, 0x59, 
    0x14, 0x0c, 0xea, 0x14, 0x85, 0x48, 0x15, 0x2c, 0x89, 0xa1, 0x2e, 0x38, 0x8c, 
    0x2b, 0x0a, 0x91, 0xaa, 0x98, 0xb0, 0xe3, 0xc1, 0xca, 0x7b, 0xa7, 0x8a, 0x48, 
    0xfa, 0x27, 0xec, 0x68, 0x00, 0xee, 0x2b, 0x0a, 0x91, 0xaa, 0x70, 0x3f, 0xb8, 
    0xfb, 0x1d, 0xe5, 0x20, 0x52, 0x05, 0x4b, 0x62, 0xf7, 0x3b, 0xc1, 0xb0, 0xab, 
    0x8a, 0x42, 0xa4, 0x1a, 0x96, 0xc4, 0x76, 0x35, 0x78, 0xec, 0x57, 0x14, 0x85, 
    0x48, 0x15, 0x4c, 0xd8, 0xd8, 0xaf, 0x98, 0x99, 0x59, 0x4f, 0xdf, 0x85, 0x7b, 
    0xc0, 0xe7, 0x8a, 0x44, 0x24, 0xb5, 0xfe, 0xe9, 0x68, 0xfb, 0x76, 0x79, 0x48, 
    0x92, 0xc4, 0x71, 0x4e, 0x29, 0x0f, 0x91, 0x34, 0x8f, 0x57, 0x4e, 0x25, 0x49, 
    0xe2, 0x01, 0x20, 0x2e, 0x96, 0x7e, 0xa1, 0x7c, 0x54, 0x9e, 0x88, 0xa4, 0x4f, 
    0x5c, 0xe9, 0x68, 0x79, 0x4f, 0xa7, 0xce, 0xce, 0x2d, 0x77, 0xdd, 0x39, 0xa3, 
    0x5c, 0x44, 0x52, 0xe9, 0xb7, 0xce, 0xce, 0x2d, 0x77, 0xa7, 0x0a, 0x0b, 0x50, 
    0xf2, 0xf8, 0x20, 0xe5, 0x83, 0x69, 0x45, 0x24, 0x3d, 0x26, 0x8a, 0x49, 0x7c, 
    0x68, 0xf2, 0x8f, 0xa9, 0xc2, 0xee, 0x6d, 0x6b, 0x19, 0x76, 0xe8, 0x52, 0x3e, 
    0x22, 0x69, 0xba, 0x75, 0xa5, 0xeb, 0xc5, 0x83, 0x9f, 0xff, 0xb7, 0x91, 0xf8, 
    0xc4, 0xf8, 0xd3, 0x43, 0x80, 0xb6, 0x8b, 0x11, 0x49, 0x47, 0x5d, 0xff, 0xaa, 
    0x74, 0x72, 0x8a, 0xce, 0xd6, 0x11, 0x49, 0xa7, 0xb7, 0x9f, 0xad, 0x03, 0xd0, 
    0xde, 0xbe, 0xf5, 0x56, 0x92, 0x78, 0x2b, 0x50, 0x54, 0x66, 0x22, 0xf3, 0xa2, 
    0x98, 0x24, 0xde, 0xfa, 0x72, 0x59, 0x5f, 0x5b, 0x58, 0x80, 0x8e, 0xb6, 0xe6, 
    0x4b, 0xee, 0xec, 0x52, 0x69, 0x45, 0x3e, 0x7e, 0x59, 0xdd, 0xd9, 0x35, 0xdd, 
    0xa1, 0xce, 0x3a, 0x81, 0x5d, 0x24, 0x3d, 0x66, 0x7f, 0x02, 0x3b, 0x40, 0x6e, 
    0xcf, 0x37, 0x7f, 0x78, 0xc9, 0x37, 0x3a, 0x0c, 0x29, 0x4b, 0x91, 0xb9, 0xe3, 
    0x30, 0xe4, 0x25, 0xdf, 0xf8, 0xa6, 0xb2, 0xbe, 0xb5, 0xb0, 0x00, 0xb9, 0x5c, 
    0xf3, 0xcd, 0xa7, 0xa3, 0x8f, 0x9a, 0x70, 0x3f, 0xac, 0x25, 0xb2, 0xc8, 0x87, 
    0x5f, 0x02, 0xe3, 0x7e, 0xf8, 0xe9, 0xe8, 0xa3, 0xa6, 0x5c, 0xae, 0xf9, 0xe6, 
    0xdb, 0xde, 0xfc, 0xc6, 0x25, 0xf1, 0xcb, 0x8e, 0x9e, 0x18, 0x58, 0x15, 0x11, 
    0xe5, 0x81, 0x6d, 0x33, 0x29, 0xbb, 0x88, 0x4c, 0x2b, 0x01, 0xfa, 0x63, 0xe2, 
    0x42, 0xe7, 0x9e, 0x96, 0x19, 0xaf, 0x60, 0xdf, 0xa9, 0xb0, 0x93, 0x8e, 0xf4, 
    0x0d, 0x34, 0x66, 0x2d, 0xec, 0xc6, 0xd8, 0x01, 0xb6, 0x44, 0xd9, 0x8b, 0xcc, 
    0x78, 0xf1, 0xfb, 0x10, 0xe7, 0x74, 0xd1, 0x93, 0x93, 0x2f, 0x3e, 0x10, 0x31, 
    0xa7, 0x85, 0x9d, 0x54, 0x28, 0x14, 0x42, 0x43, 0xc3, 0xba, 0xb5, 0x1e, 0x65, 
    0x36, 0x1b, 0xbe, 0x1e, 0x6c, 0x25, 0xb0, 0x94, 0xf2, 0xd6, 0xa9, 0xb5, 0x94, 
    0xff, 0xa1, 0x60, 0xac, 0xf2, 0x5a, 0x4f, 0xf9, 0xfc, 0x59, 0xd3, 0x97, 0x26, 
    0x9f, 0xd8, 0xa4, 0x9c, 0x00, 0x1e, 0x57, 0xae, 0xf3, 0xc5, 0x95, 0xeb, 0xfc, 
    0x19, 0xe5, 0xfd, 0xd2, 0x1e, 0x80, 0xdf, 0x76, 0xec, 0x9a, 0xc5, 0xa5, 0xcb, 
    0x23, 0x23, 0xd7, 0x6f, 0xe4, 0xf3, 0xf9, 0x64, 0xb6, 0x1f, 0xf6, 0x2f, 0x00, 
    0x00, 0x00, 0xff, 0xff, 0x03, 0x00, 0x93, 0x09, 0x84, 0x6a, 0xb5, 0x51, 0x00, 
    0x87, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82, 
  
};

const lv_img_dsc_t img_switch_off = {
  .header.cf = LV_IMG_CF_RAW_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 236,
  .header.h = 45,
  .data_size = 1170,
  .data = img_switch_off_map,
};
