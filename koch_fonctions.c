/*
 * Fichier : koch_fonctions.c
 * Description : Trace de fractales geometriques - flocon de koch - generation des points et rendu des lignes
 */

#include <stdlib.h>
#include <stdio.h> // TODO
#include <math.h>
#include "koch_fonctions.h"
#include "create_image.h"

#define PI 3.14159265

/* Initialisation de la liste chainee koch correspondant au triangle
   de Koch initial */
void init_koch(struct list **koch, uint32_t size, uint32_t segment_length)
{
    /*    pt2 
          /\
         /  \
        /    \
        ------ pt3
    */
    struct list *pt3 = malloc(sizeof(struct list));
    pt3->x = segment_length;
    pt3->y = size/3.0;
    pt3->next = NULL;

    struct list *pt2 = malloc(sizeof(struct list));
    pt2->x = segment_length/2.0;
    pt2->y = 0;
    pt2->next = pt3;

    (*koch)->x = 0;
    (*koch)->y = size/3.0;
    (*koch)->next = pt2;
}

/* Initialisation de l'image avec la couleur de fond definie dans les
   parametres */
void init_picture(uint32_t **picture, uint32_t size, uint32_t bg_color)
{
  *picture = calloc(size * size, sizeof(uint32_t));

  for (uint64_t i = 0; i < size * size; i++) {
    (*picture)[i] = bg_color;
  }
}

/* Calcul de la fractale de Koch apres un nombre d'iterations donne ;
   generation de la liste chainee koch correspondante */
void generer_koch(struct list *koch, uint32_t nb_iterations)
{
  if (!nb_iterations) return;

  // Lire l'enonce pour comprendre les noms de variables
  struct list *a = koch;
  struct list *e = koch->next;
  struct list *b, *c, *d;

  for (uint8_t i = 0; i < nb_iterations; i++) {
      while (e != NULL) {
          // On cree les points
          b = malloc(sizeof(struct list));
          b->x = a->x + (e->x - a->x)/3.0;
          b->y = a->y + (e->y - a->y)/3.0;

          d = malloc(sizeof(struct list));
          d->x = a->x + 2 * (e->x - a->x)/3.0;
          d->y = a->y + 2 * (e->y - a->y)/3.0;

          c = malloc(sizeof(struct list));
          c->x = (b->x + d->x) * cos(PI/3.0) - (d->y - b->y) * sin(PI/3.0);
          c->y = (b->y + d->y) * cos(PI/3.0) - (d->x - b->x) * sin(PI/3.0);

          // On insere les points dans la liste
          a->next = b;
          b->next = c;
          c->next = d;
          d->next = e;

          // On change de segment
          a = e;
          e = e->next;
      }
  }
}

void tracer_ligne(uint32_t *picture, uint32_t size, struct list *pt0, struct list *pt1, uint32_t color)
{
  uint32_t x0 = pt0->x; 
  uint32_t y0 = pt0->y; 
  uint32_t x1 = pt1->x; 
  uint32_t y1 = pt1->y; 

  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = -1;
  int sy = -1;

  if (x0 < x1) sx = 1;
  if (y0 < y1) sy = 1;

  int err = dx - dy;
  int e2;
  
  // TODO
  int i = 0;

  while (i < 100) {
    i++;

    picture[x0 + (size - y0) * size] = color;

    if (x0 == x1 && y0 == y1) break;

    e2 = 2 * err;

    if (e2 > -dy) {
      err -= dy;
      x0 += sx;
    }

    if (e2 < dx) {
      err += dx;
      y0 += sy;
    }
  }
}

/* Rendu image via algorithme bresehem - version generalisee
   simplifiee */
void render_image_bresenham(uint32_t *picture, struct list *koch, uint32_t size, uint32_t fg_color)
{
  struct list *a = koch;
  struct list *e = koch->next;

  while (e != NULL) {
    tracer_ligne(picture, size, a, e, fg_color);
    return; // TODO
    a = e;
    e = e->next;
  }
  // On ferme le trace
  tracer_ligne(picture, size, a, koch, fg_color);
}

/* Liberation de la memoire allouee a la liste chainee */
void free_koch(struct list *koch)
{
  // On ne peut liberer que de la memoire allouee via (m/c/re)alloc
  koch = koch->next;

  struct list *next;

  do {
    next = koch->next;
    free(koch);
    koch = next;
  } while (koch != NULL);
}
