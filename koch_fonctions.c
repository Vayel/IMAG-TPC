/*
 * Fichier : koch_fonctions.c
 * Description : Trace de fractales geometriques - flocon de koch - generation des points et rendu des lignes
 */

#include <stdlib.h>
#include "koch_fonctions.h"
#include "create_image.h"
// TODO

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
    // TODO
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
