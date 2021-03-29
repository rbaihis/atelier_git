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
SDL_Rect pos_e; 
SDL_Rect pos_s; 
int direction;
}ennemi;

typedef struct{
SDL_Surface * image;
SDL_Rect pos_ob; 
}obstacle; 

//yesmin
typedef struct{
SDL_Surface * image;
SDL_Rect pos_bg; 
}background;

typedef SDL_Surface surface;
typedef SDL_Rect rect;
typedef SDL_Event event;

//basic_initial // hethom ye5dmou
//-_-_-_--_-_--_-_-_--_-__-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
int init_sdl();
void set_screen_void(surface ** screen,int width,int height);
void quit_event(SDL_Event *event , int * loop);
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-_-_-_-_-_-_-_

//Background tache: Yesmin  => kamlet 
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void intialiser_back(background *back);
void affichback(background *back,SDL_Surface *ecran);
void scrolling(personne *p,background *back);
// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//perso_p tache :med  => mazel
void init (personne * p, int numperso);
void initPerso(personne *p);
void afficherPerso(personne p, SDL_Surface * screen);
void deplacerPerso (personne *p);
void animerPerso (personne* p);
void saut (personne* p);
//-------------------------------------------------------

#endif //  #include "header.h"


