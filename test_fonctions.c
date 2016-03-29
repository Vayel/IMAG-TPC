#include <stdlib.h>
#include <stdio.h>
#include "koch_fonctions.h"
#include "koch_ihm.h"

int main() {
  struct list *koch;
  init_koch(&koch, 200, 150);
  show_koch_list(koch);

  return EXIT_SUCCESS;
}
