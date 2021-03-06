/*
 * Fichier : create_image.c
 * Description : Creation d'un fichier ppm a partir d'une image sous la forme
 *               d'un tableau uint32_t *
 */
#include "create_image.h"
#include <stdio.h>

/* Un pixel est un uint32_t, code de la maniere suivante (le premier octet n'a pas d'importance) :
 * xxxxxxxxRRRRRRRRVVVVVVVVBBBBBBBB
 */

// Retourne la composante rouge d'un pixel
uint8_t get_r(uint32_t px)
{
    return px >> 16;
}

// Retourne la composante verte d'un pixel
uint8_t get_g(uint32_t px)
{
    return px >> 8;
}

// Retourne la composante bleu d'un pixel
uint8_t get_b(uint32_t px)
{
    return px;
}

void create_image_ppm(uint32_t *pic, int32_t size_x, int32_t size_y, char *filename)
{
    FILE *f;
    f = fopen(filename, "w");

    // En-tete, en ASCII
    fprintf(f, "P6\n");
    fprintf(f, "%d", size_x);
    fprintf(f, " ");
    fprintf(f, "%d", size_y);
    fprintf(f, "\n255\n");

    // Pixels, en binaire
    uint64_t area = size_x * size_y;
    uint32_t px;
    uint8_t r, g, b;

    for (uint64_t i = 0; i < area; i++) {
        px = pic[i];
        r = get_r(px);
        g = get_g(px);
        b = get_b(px);
        
        fwrite(&r, sizeof(uint8_t), 1, f);
        fwrite(&g, sizeof(uint8_t), 1, f);
        fwrite(&b, sizeof(uint8_t), 1, f);
    }

    fclose(f);
}
