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


typedef struct
{
SDL_Surface * im_perso;
SDL_Rect pos_p; 
}personne;





typedef struct
{
SDL_Surface *im_bg ;
SDL_Surface *text,*title;
SDL_Rect pos_bg,pos_right,pos_left,pos_mid,postxt,postitle;
TTF_Font *police,*police2;
Mix_Music *music;
Mix_Chunk *son;
}background;


void intialiser_back(background *b);
void affichback(background *b, SDL_Surface *screen);
void scrolling(background *back,int direction , int pasAvancement);

void init_perso(personne *p);
void afficher_perso(personne *p,SDL_Surface *screen);
#endif

