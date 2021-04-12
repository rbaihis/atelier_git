#include "background.h"




void init_perso(personne *p)

{
    p->pos_p.x=890;
    p->pos_p.y=690;
    p->im_perso=IMG_Load("d1.png");
}
///***************************************

void afficher_perso(personne *p,SDL_Surface *screen)
{
    SDL_BlitSurface(p->im_perso,NULL,screen,&p->pos_p);

}
///******************************

void intialiser_back(background *b)
{
b->im_bg=NULL;
b->im_bg=IMG_Load("back.png");

b->pos_bg.x=400;
b->pos_bg.y=10;

b->pos_bg.h=750;
b->pos_bg.w=7500;


b->pos_left.x=700;
b->pos_left.y=0;

b->pos_right.x=1280;
b->pos_right.y=0;

}

///********************************************************

void affichback(background *b, SDL_Surface *screen)
{
     SDL_BlitSurface(b->im_bg,NULL, screen, &b->pos_bg);
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


///******************************************   

  
  
  
  
  
  
  
  
                     

