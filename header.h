#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef SDL_Surface surface;
typedef SDL_Rect rect;
typedef SDL_Event event;

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

//GHAYTH 
typedef struct
{
   SDL_Surface *background;
SDL_Rect positionEcran,positionFont,positionFont1,positionFont2,positionFont3;
SDL_Surface *image1,*image2,*image3,*image4;
SDL_Surface *texte; /*!< test*/
TTF_Font *police; 
   SDL_Event event;
   SDL_Color colorchoice;
   char q[100];
   char r1[30];
   char r2[30];
   char r3[30];
Mix_Chunk *sound;

}enigme;




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



//Enigme tache: Ghayth
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


void init_alea(unsigned int n);
int alea();
int alea2();
enigme generer(char *ch,enigme e,SDL_Surface *screen,int *n2);
void afficher(SDL_Surface *screen,enigme e);
void free_memory(TTF_Font *police,SDL_Surface *texte,Mix_Chunk *sound);





// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*





//Background tache: => Yesmin mezel
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*








// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//perso_p  => med  => mazel

//-------------------------------------------------------
//minimap => fedi mazel


//-------------------------------------------------------

#endif //  #include "header.h"
