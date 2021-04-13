#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "header.h"






void intialiser_back(background *b);
void affichback(background *b, SDL_Surface *screen);
void scrolling(background *back,int direction , int pasAvancement);

void init_perso(personne *p);
void afficher_perso(personne *p,SDL_Surface *screen);
#endif

