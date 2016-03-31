#include <stdlib.h>
#include <stdio.h>
#include "koch_fonctions.h"
#include "koch_ihm.h"

int main() {
  struct list *koch;
  uint32_t size = 200;

  init_koch(&koch, size, 150);
  show_koch_list(koch);

  printf("\n");

  generer_koch(koch, 1);
  show_koch_list(koch);

  printf("\n");

  uint32_t *picture;
  init_picture(&picture, size, 255);
  render_image_bresenham(picture, koch, size, 0);

  free_koch(koch);

  return EXIT_SUCCESS;
}
