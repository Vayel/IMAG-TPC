/*
 * Fichier : koch_fonctions.c
 * Description : Trace de fractales geometriques - flocon de koch - generation des points et rendu des lignes
 */

#include <stdlib.h>
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
    // TODO
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

/* Rendu image via algorithme bresehem - version generalisee
   simplifiee */
void render_image_bresenham(uint32_t *picture, struct list *koch, uint32_t size, uint32_t fg_color)
{
    // TODO
}

/* Liberation de la memoire allouee a la liste chainee */
void free_koch(struct list *koch)
{
    // TODO
}
