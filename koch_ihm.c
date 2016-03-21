/*
 * Fichier : koch_ihm.c
 * Description : Saisie et initialisation des parametres - flocon de koch
 */

#include "koch_fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void init_parameters(struct parameters *parameters, int argc, char *argv[])
{
  if (argc < 6)
  {
    // TODO
  } else
  {
    parameters->segment_length = atoi(argv[1]);
    parameters->nb_iterations = atoi(argv[2]);
    parameters->fg_color = strtol(argv[3], NULL, 16);
    parameters->bg_color = strtol(argv[4], NULL, 16);
    parameters->outfile = argv[5];
    parameters->all_images = argc >= 7 && !strcmp(argv[6], "all");
  }

  parameters->image_size = 0; // TODO
}

void show_koch_list(struct list *koch)
{
  while (koch != NULL) {
    printf("(%u, %u) ", koch->x, koch->y);
    koch = koch->next;
  }
}

void show_parameters(const struct parameters *parameters)
{
  printf("Segment length: %u\n", parameters->segment_length);
  printf("Image size: %u\n", parameters->image_size);
  printf("Nb iterations: %u\n", parameters->nb_iterations);
  printf("Foreground color: 0x%x\n", parameters->fg_color);
  printf("Background color: 0x%x\n", parameters->bg_color);
  printf("All images: %d\n", parameters->all_images);
  printf("Outfile: %s", parameters->outfile);
}
