#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

// mouhamed
typedef struct{
SDL_Surface * image;
}personne;

//seif
typedef struct{
SDL_Surface * image;
}ennemi;

typedef struct{
SDL_Surface * image;
}obstacle; 

//yesmin
typedef struct{
SDL_Surface * image;
SDL_Rect pos_bg; 
}background;


//Background tache: Yesmin
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void intialiser_back(background *back);
void affichback(background *back,SDL_Surface *ecran);
void scrolling(personne *p,background *back);
// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#endif //  #include "header.h"
