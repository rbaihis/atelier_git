#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include <unistd.h>

// mouhamed
typedef struct 
{
	
	
	TTF_Font    * poliscore; 
	SDL_Surface * txtscore;
	SDL_Rect     posscore ; 
	
}score  ; 
///*************************************
typedef struct  
{
	
	SDL_Surface * imvie[4];
	SDL_Rect     posvie ;
	int          nmbr_vie; 
	
}vie  ;

//**************************


/** 
* @struct personnage 
* @brief struct for personne 
*/


typedef struct 
    {
    
	SDL_Surface * image[3][3];  /*!< Surface*/
	SDL_Rect    pos_p;           /*!< Rectangle*/
	
	vie        vie_perso ;
	score      score_perso ; 
	
	int        mvtx,mvty,accelerer,super_jump;  /// mvtx = deplacement |  mvty = saut
	int        etat,gravite;       /// etat 1 en mvmnt 0 stable 
	int        direction,num,up;/// direc: 0 droite 1 gauche 2 attq  "ligne"  
                                 ///num : numero de limage "colone"
    
     } personne;
     
     
     
     

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

typedef SDL_Surface surface;
typedef SDL_Rect rect;
typedef SDL_Event event;

//basic_initial
//-_-_-_--_-_--_-_-_--_-__-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
int init_sdl();
void set_screen_void(surface ** screen,int width,int height);
void quit_event(SDL_Event *event , int * loop);
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-_-_-_-_-_-_-_

//Background tache: Yesmin
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void intialiser_back(background *back);
void affichback(background *back,SDL_Surface *ecran);
void scrolling(personne *p,background *back);
// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//perso_p tache :med 

void initPerso(personne *p);
void init(personne *p , int numperso);

void afficherPerso(personne p, SDL_Surface * screen);


void deplacer_perso(personne *p);
void accelrer_perso(personne *p);
void attack_perso(personne *p);

void jump_perso(personne *p);
void super_jump_perso(personne *p,SDL_Event * event);

 void animer_perso(personne *p);

//-------------------------------------------------------





#endif //  #include "header.h"
