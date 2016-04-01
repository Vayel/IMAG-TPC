#include <stdlib.h>
#include <stdio.h>
#include "koch_fonctions.h"
#include "koch_ihm.h"
#include "create_image.h"

int main() {
  struct list *koch;
  uint32_t size = 311;
  uint32_t segment_length = 270;

  init_koch(&koch, size, segment_length);
  show_koch_list(koch);

  printf("\n");

  generer_koch(koch, 1);
  show_koch_list(koch);

  printf("\n");

  uint32_t *picture;
  init_picture(&picture, size, 255);
  render_image_bresenham(picture, koch, size, 0);
  create_image_ppm(picture, size, size, "test_fonctions.ppm");

  free_koch(koch);

  return EXIT_SUCCESS;
}
