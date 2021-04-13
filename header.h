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
typedef struct{  //   this os for testing only not mohamed's struct
SDL_Surface * im_perso;
SDL_Rect pos_p; 
}personne;
//-----------------------------------------

//seif   no more modification
typedef struct{
SDL_Surface * image;
SDL_Rect pos_ob; //  <== obstacle's is position rect 
SDL_Rect pos_sheet;
int screenheight, screenwidth;
int collision;
}obstacle;       //obstacle ... losing 

typedef struct{
SDL_Surface * image;
SDL_Rect pos_prize; //  <== prize is position rect 
SDL_Rect pos_sheet;
int screenheight, screenwidth;
int collision;
}prize;       // coins , hearts ......

typedef struct{
SDL_Surface * image;
SDL_Rect pos_e;  // ennemi rect for collision 
SDL_Rect pos_s; 
int direction;
int faster , speed ; // have to be set in main 1st
int x_vel, y_vel, x_pos, y_pos; 
int screenheight, screenwidth;
int collision;
}ennemi;


//-------------------------------------

//yesmin

typedef struct
{
SDL_Surface *im_bg ;
SDL_Surface *text,*title;
SDL_Rect pos_bg,pos_right,pos_left,pos_mid,postxt,postitle;
TTF_Font *police,*police2;
Mix_Music *music;
Mix_Chunk *son;
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



// seif allah rbaihi 
// *-*-*-*-Enemi_prototype_ES ---**-*-
// *-*-*-*-Enemi_prototype_ES ---**-*-  
void initennemi(ennemi *es);//ok****
void afficher_ennemi(ennemi es, SDL_Surface * screen);//ok***
void animer_ennemi( ennemi * es);//ok*****
void deplacer_ennemi( ennemi * es);//ok****
// es other deplacement 
void updown();
void rightleft(ennemi * e);

int collision_bb( personne p, ennemi es);//ok*****

//my optional funct
void afficher_ennemi2(ennemi * es, SDL_Surface * screen); // calling animerfunction inside if used 
void deplacement_settings(ennemi * es,int s_posx ,int s_posy); // inter x and y position via parametre
void deplacement_settings2(ennemi * es,personne *p); // placing ennemi in fron of perso by just call it 




//Background tache: => Yesmin mezel
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*








// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//perso_p  => med  => mazel

//-------------------------------------------------------
//minimap => fedi mazel


//-------------------------------------------------------

#endif //  #include "header.h"


