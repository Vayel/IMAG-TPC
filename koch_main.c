/*
 * Fichier : koch_main.c
 * Description : Trace de fractales geometriques - flocon de koch - programme principal
 */

#include <stdlib.h> 
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
      for (uint32_t i = 0; i < params.nb_iterations + 1; i++) {
        // Iteration i
        init_picture(&picture, params.image_size, params.bg_color);
        generer_koch(koch, 1);
        render_image_bresenham(picture, koch, params.image_size, params.fg_color);
        create_image_ppm(picture, params.image_size, params.image_size, params.outfile); // TODO: fname
      }
    }

    free_koch(koch);

    return EXIT_SUCCESS;
}
