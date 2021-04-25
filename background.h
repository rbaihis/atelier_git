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
    
	SDL_Surface * image[2][3];  // *im_perso
	SDL_Rect    pos_p;
 
	int        mvtx,mvty,accelerer,super_jump;  /// mvtx = deplacement |  mvty = saut
	int        etat,gravite;       /// etat 1 en mvmnt 0 stable 
	int        direction,num;/// direc: 0 droite 1 gauche 2 attq  "ligne"  
                                 ///num : numero de limage "colone"
    
     } personne;
//*-------------------------------------------------------------------*
typedef struct
{
SDL_Rect  camera1, camera2;
SDL_Surface *im_bg1 , *im_bg2 ;
SDL_Surface *text,*title;
SDL_Rect pos_bg,pos_right,pos_left,pos_mid,postxt,postitle;
TTF_Font *police,*police2;
Mix_Music *music;
Mix_Chunk *son;
}background;


void intialiser_back(background *b);
void afficherBack1(background *b1, SDL_Surface * screen1,int partage);
void afficherBack2(background *b2, SDL_Surface * screen2,int partage);
void scrolling(background *back,int direction , int pasAvancement);

void init_perso(personne *p);
void init_deuxieme_Perso(personne *a);
void afficherPerso(personne p, SDL_Surface *screen)
void deplacer_perso(personne *p)

#endif
