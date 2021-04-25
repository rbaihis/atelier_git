

#include "background.h"

void initPerso(personne *p)
{

p->image[0][0]=NULL;
p->image[0][1]=NULL;
p->image[0][2]=NULL;

p->image[0][0]=NULL;
p->image[1][0]=NULL;
p->image[2][0]=NULL;

p->image[0][0] =IMG_Load("d1.png");
p->image[0][1] =IMG_Load("d2.png");
p->image[0][2]=IMG_Load("d3.png");

p->image[1][0] =IMG_Load("g1.png");
p->image[1][1] =IMG_Load("g2.png");
p->image[1][2] =IMG_Load("g3.png");


p->pos_p.x=890;
p->pos_p.y=690;
}

//*---------------------------------------------------------------*

void init_deuxieme_Perso(personne *a)
{

a->image[0][0]=NULL;
a->image[0][1]=NULL;
a->image[0][2]=NULL;

a->image[0][0]=NULL;
a->image[1][0]=NULL;
a->image[2][0]=NULL;

a->image[0][0] =IMG_Load("d1.png");
a->image[0][1] =IMG_Load("d2.png");
a->image[0][2]=IMG_Load("d3.png");

a->image[1][0] =IMG_Load("g1.png");
a->image[1][1] =IMG_Load("g2.png");
a->image[1][2] =IMG_Load("g3.png");


a->pos_p.x=890;
a->pos_p.y=690;
///***************************************

void afficherPerso(personne p, SDL_Surface *screen)
{
SDL_BlitSurface(p.image[p.direction][p.num], NULL, screen,&p.pos_p);
}
///******************************

void intialiser_back(background *b)
{
b->im_bg1=NULL;
b->im_bg1=IMG_Load("back1.png");
b->im_bg2=NULL;
b->im_bg2=IMG_Load("back2.png");
b->camera1.x=0;
b->camera1.y=0;
b->camera1.w=600;
b->camera1.h=1920;

b->camera2.x=600;
b->camera2.y=0;
b->camera2.w=600;
b->camera2.h=1920;

b->pos_bg.x=400;
b->pos_bg.y=10;

b->pos_bg.h=750;
b->pos_bg.w=7500;


b->pos_left.x=700;
b->pos_left.y=0;

b->pos_right.x=1280;
b->pos_right.y=0;

}

                                    
                     
  ////****************************************
  
  void scrolling(background *back,int direction , int pasAvancement)
{   

if(direction==1)
{
if(pasAvancement>=10)
       {
         back->pos_bg.x-=50;
       }
}
if (direction ==2)
{
 if(pasAvancement>10)
             {
         back->pos_bg.x+=50;
}
}
}
}
//*------------------------------------------------------------------------------*
void afficherBack1(background *b1, SDL_Surface * screen1,int partage)
{
SDL_Rect pos1;
if(partage)
{
pos1.x=0;
pos1.y=0;
pos1.w=600;
pos1.h=1920;
SDL_BlitSurface(b1->im_bg1,&b1->camera1,screen1,&pos1);
}
}
void afficherBack2(background *b2, SDL_Surface * screen2,int partage)
{
SDL_Rect pos2;
if(partage)
{
pos2.x=600;
pos2.y=0;
pos2.w=600;
pos2.h=1920;
SDL_BlitSurface(b2->im_bg2,&b2->camera2,screen2,&pos2);
}
}

