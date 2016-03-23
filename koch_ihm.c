/*
 * Fichier : koch_ihm.c
 * Description : Saisie et initialisation des parametres - flocon de koch
 */

#include "koch_fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_OUTFILE_LEN 50
#define MIN_ARGS_NUM 6

void init_parameters(struct parameters *parameters, int argc, char *argv[])
{
  if (argc < MIN_ARGS_NUM)
  {
    int all;
    char outfile[MAX_OUTFILE_LEN];

    printf("Please input parameters."); 
    printf("\nSegment length: ");
    scanf("%u", &(parameters->segment_length));
    printf("Number of iterations: ");
    scanf("%u", &(parameters->nb_iterations));
    printf("Foreground color (hex): ");
    scanf("%x", &(parameters->fg_color));
    printf("Background color (hex): ");
    scanf("%x", &(parameters->bg_color));
    printf("Outfile path: ");
    scanf("%49s", outfile);
    printf("All images (0/1): ");
    scanf("%u", &all);
    parameters->all_images = (bool) all;
  
    parameters->outfile = outfile;
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
