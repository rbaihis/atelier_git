/** 
* @file background.c 
* @brief Testing Program. 
* @author yesmin zaghden 
* 
* Testing program for background scrollilng * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
/** 
* @brief  initialiser personne . 
* @param p : *p = personne 
* @return Nothing 
*/ 

void init_perso(personne *p)

{
    p->pos_p.x=10;
    p->pos_p.y=500;
    p->im_perso=IMG_Load("d1.png");
}
/** 
* @brief afficher le personnage . 
* @param *p = personne , *screen = surface  
* @return Nothing 
*/ 

void afficher_perso(personne *p,SDL_Surface *screen)
{
    SDL_BlitSurface(p->im_perso,NULL,screen,&p->pos_p);

}
/** 
* @brief inisialiser background  
* @param *b =background  
* @return Nothing 
*/ 

void initBack(background *b)
{

    b->image = IMG_Load("stage1.png"); /// chargement de l'image  de background 

//// initialisation position background1
    b->positionbackground.x = 0;
    b->positionbackground.y = -10;
    b->positionbackground.w = 0;
    b->positionbackground.h = 0;


//// initialisation position camera 1
    b->camera1.x = 0;
    b->camera1.y = 0;
    b->camera1.w = 600;
    b->camera1.h = 1000;


//// initialisation position background 2
    b->positionback_partage.x = 600;
    b->positionback_partage.y = -10;
    b->positionback_partage.h = 0;
    b->positionback_partage.w = 0;


//// initialisation position camera 2
    b->camera2.x = 0;
    b->camera2.y = 0;
    b->camera2.w = 600;
    b->camera2.h = 1000;


}


/** 
* @brief afficher  le premier background
* @param *b=background , *screen=surface  
* @return Nothing 
*/ 

void aficherBack(SDL_Surface *screen,background *b)
{

    SDL_BlitSurface(b->image, &b->camera1, screen, &b->positionbackground); /// blite de 1ere background

}


/*********************************************************************************/

/** 
* @brief afficher le deuxieme background ( background paratger) 
* @param *b =background , *screen = surface  
* @return Nothing 
*/ 

void aficherBack_partage(SDL_Surface *screen,background *b)
{


    SDL_BlitSurface(b->image, &b->camera2, screen, &b->positionback_partage);/// blite de 2eme background avec partage

}


/*********************************************************************************/
/** 
* @brief scrolling right 
* @param *b= background , velocity =pasAvancement , mouvement = direction  
* @return Nothing 
*/ 


void scrolling_right(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.right == 1 )
    {
        if (b->camera1.x < 5000 - 530)
        {
            b->camera1.x += velocity;
        }
    }

}


/*********************************************************************************/

/** 
* @brief scrolling right ( deuxieme background ( partager ))
* @param b= background , velocity =pasAvancement , mouvement = direction  
* @return Nothing 
*/
void scrolling_right_partage(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.d == 1)
    {
        if (b->camera2.x < 5000 - 530)
        {
            b->camera2.x += velocity;
        }
    }
}


/*********************************************************************************/

/** 
* @brief scrolling left 
* @param b= background , velocity =pasAvancement , mouvement = direction  
* @return Nothing 
*/
void scrolling_left(background *b, float velocity, SDL_Surface *screen, mouvement M)
{

    if (M.left == 1)
    {
        if (b->camera1.x > 0)
        {
            b->camera1.x -= velocity;
        }
    }

}


/*********************************************************************************/

/** 
* @brief scrolling left ( deuxieme background (paratger)) 
* @param b= background , velocity =pasAvancement , mouvement = direction  
* @return Nothing 
*/
void scrolling_left_partage(background *b, float velocity, SDL_Surface *screen, mouvement M)
{

    if (M.q == 1)
    {
        if (b->camera2.x > 0)
        {
            b->camera2.x -= velocity;
        }
    }

}


/*********************************************************************************/

/** 
* @brief scrolling up ( en haut)
* @param b= background , velocity =pasAvancement , mouvement = direction  
* @return Nothing 
*/
void scrolling_up(background *b, float velocity, SDL_Surface *screen, mouvement M)
{

    if (M.up == 1)
    {
        if (b->camera1.y > 0)
        {
            b->camera1.y -= velocity;
        }
    }

}


/*********************************************************************************/
/** 
* @brief scrolling up ( sur deuxieme bakcground ( partager))  
* @param b= background , velocity =pasAvancement , mouvement = direction  
* @return Nothing 
*/

void scrolling_up_partage(background *b, float velocity, SDL_Surface *screen, mouvement M)
{

    if (M.z == 1)
    {
        if (b->camera2.y > 0)
        {
            b->camera2.y -= velocity;
        }
    }

}


/*********************************************************************************/
/** 
* @brief scrolling down ( bas)
* @param b= background , velocity =pasAvancement , mouvement = direction  
* @return Nothing 
*/

void scrolling_down(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.down == 1 )
    {
        if (b->camera1.y < 600 - 528)
        {
            b->camera1.y += velocity;
        }
    }

}


/*********************************************************************************/
/** 
* @brief scrolling down ( sur deuxieme background ( partager )) 
* @param b= background , velocity = pasAvancement , mouvement = direction  
* @return Nothing 
*/

void scrolling_down_partage(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.s == 1 )
    {
        if (b->camera2.y < 600 - 528)
        {
            b->camera2.y += velocity;
        }
    }

}


/*********************************************************************************/


/** 
* @brief initialiser le mouvement : initialiser la direction  
* @param b: mouvement = direction
* @return Nothing 
*/
void init_Mouvement(mouvement *M)
{
    M->left = 0;
    M->right = 0;

    M->q = 0;
    M->d = 0;

}
