#ifndef _CREATE_IMAGE_H_
#define _CREATE_IMAGE_H_

#include <inttypes.h>

extern uint8_t get_r(uint32_t px);
extern uint8_t get_g(uint32_t px);
extern uint8_t get_b(uint32_t px);

extern void create_image_ppm(uint32_t *pic, int32_t size_x, int32_t size_y, char *filename);

#endif

