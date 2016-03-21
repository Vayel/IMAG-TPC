/*
 * Fichier : create_image.c
 * Description : Creation d'un fichier ppm a partir d'une image sous la forme
 *               d'un tableau uint32_t *
 */
#include "create_image.h"
#include <stdio.h>

uint8_t get_r(uint32_t px)
{
  return px >> 16;
}

uint8_t get_g(uint32_t px)
{
  return px >> 8;
}

uint8_t get_b(uint32_t px)
{
  return px;
}

void create_image_ppm(uint32_t *pic, int32_t size_x, int32_t size_y, char *filename)
{
    FILE *f;
    f = fopen(filename, "w");

    fwrite("P6\n", sizeof(char), 3, f);
    fprintf(f, "%d", size_x);
    fwrite(" ", sizeof(char), 1, f);
    fprintf(f, "%d", size_y);
    fwrite("\n255\n", sizeof(char), 5, f);

    uint32_t px;
    uint8_t r, g, b;

    for (uint8_t y = 0; y < size_y; y++)
    {
      for (uint8_t x = 0; x < size_x; x++)
      {
        px = pic[x + y * size_x];
        r = get_r(px);
        g = get_g(px);
        b = get_b(px);
        
        fwrite(&r, sizeof(uint8_t), 1, f);
        fwrite(&g, sizeof(uint8_t), 1, f);
        fwrite(&b, sizeof(uint8_t), 1, f);
        fwrite(" ", sizeof(char), 1, f);
      }
      fwrite("\n", sizeof(char), 1, f);
    }

    fclose(f);
}
