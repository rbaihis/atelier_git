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
//-----------------------------------------

//seif   no more modification
typedef struct{
SDL_Surface * image;
SDL_Rect pos_ob; //  <== obstacle's is position rect 
}obstacle;       //obstacle ... losing 

typedef struct{
SDL_Surface * image;
SDL_Rect pos_prize; //  <== prize is position rect 
}prize;       // coins , hearts ......

typedef struct{
SDL_Surface * image;
SDL_Rect pos_e; // <== prize is position rect 
SDL_Rect pos_s; 
int direction;
int faster;
float x_vel,y_vel,x_pos,y_pos;
}ennemi;
//-------------------------------------

//yesmin
typedef struct{
SDL_Surface * image;
SDL_Rect pos_bg;  
}background;

typedef SDL_Surface surface;
typedef SDL_Rect rect;
typedef SDL_Event event;
//-----------------------------------------
// test only bech yetfass5ou

// 

//basic_initial // hethom ye5dmou
//-_-_-_--_-_--_-_-_--_-__-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
int init_sdl();
void set_screen_void(surface ** screen,int width,int height);
void quit_event(SDL_Event *event , int * loop);
// a suuprimer
void loadbg(background *back);  // init backg to be deleted 
void blitbg(background *back,SDL_Surface *ecran); //blit backg to be deleted
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-_-_-_-_-_-_-_


// *-*-*-*-Enemi_prototype_ES ---**-*- => SEIF
void load_simple_es(ennemi *simple_es,char * path);//ok
void afficher_ennemi(ennemi es, SDL_Surface * screen);//***
void anim_loading(ennemi * es);//ok
void animer_ennemi( ennemi * es);//ok
void deplacer_ennemi( ennemi * es,int W,int H);//ok 
int collision_bb( personne p, ennemi es);//ok

//my optional func
void afficher_ennemi2(ennemi * es, SDL_Surface * screen);
void deplacement_settings(ennemi * es,int speed,int s_posx ,int s_posy);
void deplacement_settings2(ennemi * es,personne *p,int speed);
// *-*-*-*-Enemi_prototype_ES ---**-*- 




//Background tache: => Yesmin mezel
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//perso_p  => med  => mazel

//-------------------------------------------------------
//minimap => fedi mazel


//-------------------------------------------------------

#endif //  #include "header.h"


