#include <stdlib.h>
#include <stdio.h>
#include "koch_fonctions.h"
#include "koch_ihm.h"

int main(int argc, char **argv) {
  // Init params

  struct parameters p;
  init_parameters(&p, argc, argv);
  show_parameters(&p);
  printf("\n\n");

  // Show list

  struct list p3 = {3, 3, NULL};
  struct list p2 = {2, 2, &p3};
  struct list p1 = {1, 1, &p2};

  show_koch_list(&p1);
  printf("\n\n");

  // Show params

  struct parameters params = {
    10,
    20,
    4,
    0x000000,
    0xFFFFFF,
    true,
    "test.ppm"
  };

  show_parameters(&params);
  printf("\n\n");

  return EXIT_SUCCESS;
}
