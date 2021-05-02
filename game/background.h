/** 
* @file background.h 
* @brief Testing Program. 
* @author yesmin zaghden
* 
* Testing program for background scrollilng * 
*/


#ifndef bg_H_INCLUDED
#define bg_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
/** 
* @struct personne
* @brief struct for personne
*/ 

typedef struct
{
SDL_Surface * im_perso;
SDL_Rect pos_p; 
}personne;
/** 
* @struct Background 
* @brief struct for backround 
*/ 

typedef struct
{

    SDL_Surface *image;
    SDL_Rect positionbackground;
    SDL_Rect positionback_partage;

    SDL_Rect camera1;
    SDL_Rect camera2;

} background;

/** 
* @struct mouvement 
* @brief mouvement = direction
*/ 

typedef struct
{

    int left, right,up,down,d,q,z,s;

} mouvement;


void initBack(background *b);
void aficherBack(SDL_Surface *screen, background *b);
void aficherBack_partage(SDL_Surface *screen,background *b);
void scrolling_right(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_right_partage(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_left(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_left_partage(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_up(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_up_partage(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_down(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_down_partage(background *b, float velocity, SDL_Surface *screen, mouvement M);
void init_Mouvement(mouvement *M);
void init_perso(personne *p);
void afficher_perso(personne *p,SDL_Surface *screen);

#endif
