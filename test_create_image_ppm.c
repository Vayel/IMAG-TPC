#include <stdlib.h>
#include <stdio.h>
#include "create_image.h"

void fill_pic(uint32_t *pic, uint64_t size, uint32_t color)
{
  for (uint64_t i = 0; i < size * size; i++) {
    pic[i] = color;
  }
}

void draw_diago(uint32_t *pic, uint64_t size, uint32_t color)
{
  for (uint64_t i = 0; i < size; i++) {
    pic[(1 + size) * i] = color;
  }
}

int main()
{
  //get_x
  uint32_t px = 75850;
  printf("r: %u\n", get_r(px)); // 1
  printf("g: %u\n", get_g(px)); // 40
  printf("b: %u\n", get_b(px)); // 74

  // create_image_ppm
  uint32_t bpic[300*300];
  fill_pic(bpic, 300, 255);
  create_image_ppm(bpic, 300, 300, "blue.ppm");

  uint32_t gpic[300*300];
  fill_pic(gpic, 300, 65280);
  create_image_ppm(gpic, 300, 300, "green.ppm");

  uint32_t rpic[300*300];
  fill_pic(rpic, 300, 16711680);
  create_image_ppm(rpic, 300, 300, "red.ppm");

  uint32_t dpic[300*300];
  fill_pic(dpic, 300, 16711680);
  draw_diago(dpic, 300, 255);
  create_image_ppm(dpic, 300, 300, "diago.ppm");

  return EXIT_SUCCESS;
}
