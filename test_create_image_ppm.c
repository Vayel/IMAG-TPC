#include <stdlib.h>
#include <stdio.h>
#include "create_image.h"

int main() {
  //get_x
  uint32_t px = 75850;
  printf("%u", get_r(px)); // 1
  printf("%u", get_g(px)); // 40
  printf("%u", get_b(px)); // 74

  // create_image_ppm
  uint32_t bpic[36] = {255};
  create_image_ppm(bpic, 9, 4, "blue.ppm");

  uint32_t gpic[36] = {65280};
  create_image_ppm(gpic, 9, 4, "green.ppm");

  uint32_t rpic[36] = {16711680};
  create_image_ppm(rpic, 9, 4, "red.ppm");

  return EXIT_SUCCESS;
}
