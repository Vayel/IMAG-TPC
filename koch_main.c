/*
 * Fichier : koch_main.c
 * Description : Trace de fractales geometriques - flocon de koch - programme principal
 */

#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include "koch_fonctions.h"
#include "koch_ihm.h"
#include "create_image.h"

int main(int argc, char **argv)
{
    struct parameters params;
    uint32_t *picture;
    struct list *koch;

    init_parameters(&params, argc, argv);
    init_koch(&koch, params.image_size, params.segment_length);
    
    if (!params.all_images) {
      init_picture(&picture, params.image_size, params.bg_color);
      generer_koch(koch, params.nb_iterations);
      render_image_bresenham(picture, koch, params.image_size, params.fg_color);
      create_image_ppm(picture, params.image_size, params.image_size, params.outfile);
    } else {
      // Iteration 0
      char fname[strlen(params.outfile)];
      sprintf(fname, "%d_", 0);
      strcat(fname, params.outfile);

      init_picture(&picture, params.image_size, params.bg_color);
      render_image_bresenham(picture, koch, params.image_size, params.fg_color);
      create_image_ppm(picture, params.image_size, params.image_size, fname);

      for (uint32_t i = 0; i < params.nb_iterations; i++) {
        // Iteration i+1
        char fname[strlen(params.outfile)];
        sprintf(fname, "%d_", (int) i+1);
        strcat(fname, params.outfile);

        init_picture(&picture, params.image_size, params.bg_color);
        generer_koch(koch, 1);
        render_image_bresenham(picture, koch, params.image_size, params.fg_color);
        create_image_ppm(picture, params.image_size, params.image_size, fname);
      }
    }

    free_koch(koch);

    return EXIT_SUCCESS;
}
