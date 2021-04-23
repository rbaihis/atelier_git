#include "perso.h"



///***************************
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


p->pos_p.x=300;
p->pos_p.y=500;

p->gravite=500;
p->mvtx=5;
p->mvty=430;
p->accelerer=10;
p->super_jump=390;
p->up=0;
p->direction=0;
p->num=0;
p->etat=0;

//****init score****///
char score[15]="score:0";
  TTF_Init();
  
p->score_perso.poliscore=NULL ;
p->score_perso.txtscore=NULL  ;

p->score_perso.poliscore=TTF_OpenFont("CCR.ttf",80); 
SDL_Color couleur={0,0,0};
p->score_perso.txtscore=TTF_RenderText_Blended(p->score_perso.poliscore,score,couleur);


p->score_perso.posscore.x=10;
p->score_perso.posscore.y=10; 


///***init vie***////////
p->vie_perso.posvie.x=1150;
p->vie_perso.posvie.y=20;

p->vie_perso.nmbr_vie=0;

p->vie_perso.imvie[0]=NULL;
p->vie_perso.imvie[1]=NULL;
p->vie_perso.imvie[2]=NULL;
p->vie_perso.imvie[3]=NULL;

p->vie_perso.imvie[0] =IMG_Load("vie3.png");
p->vie_perso.imvie[1] =IMG_Load("vie2.png");
p->vie_perso.imvie[2] =IMG_Load("vie1.png");
p->vie_perso.imvie[3] =IMG_Load("death.png");

}
///***************************

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


a->pos_p.x=300;
a->pos_p.y=500;

a->gravite=500;
a->mvtx=5;
a->mvty=430;
a->accelerer=10;
a->super_jump=390;
a->up=0;
a->direction=0;
a->num=0;
a->etat=0;



}

///****************************

void afficherPerso(personne p, SDL_Surface *screen)
{
SDL_BlitSurface(p.image[p.direction][p.num], NULL, screen,&p.pos_p);

SDL_BlitSurface(p.score_perso.txtscore ,NULL,screen,&p.score_perso.posscore);
  
SDL_BlitSurface(p.vie_perso.imvie[p.vie_perso.nmbr_vie], NULL, screen,&p.vie_perso.posvie);
}

///****************************

void deplacer_perso(personne *p)
{
  
    
              if(p->direction==0)
              {
               p->pos_p.x+=p->mvtx;
              
               
               p->etat=1;              
               
               }
                  
                        
               else if(p->direction==1)
               {
               
               p->pos_p.x-=p->mvtx;
               
               p->etat=1;
               
               }
                   
animer_perso(p);
}
//****************************

void accelrer_perso(personne *p)
{   
        

      if (p->direction==0)
         p->pos_p.x+=p->accelerer; 
     
     else if (p->direction==1)
         p->pos_p.x-=p->accelerer; 
         
animer_perso(p);
}


///***********************************

 void jump_perso(personne *p)
{
               
                    if(p->up==1)
                    {
              
                      p->num=1;       /// animate the jump
                      p->pos_p.y=p->mvty;      /// jump

                     }
                     
                                 
                     if(p->up==0) 
                     {            
                        p->num=0;          /// animate the jump
                        p->pos_p.y=p->gravite;  //// gravite
                   
                       }  
}


///************************************************

void super_jump_perso(personne *p,SDL_Event * event)
{

 switch(event->type ) 
   { 
      case SDL_KEYDOWN:

         switch(event->key.keysym.sym)
          {    
              case SDLK_SPACE: 
                  p->num=1;       /// animate the jump
               
                if(p->direction==0) 
                    p->pos_p.y=p->super_jump;      /// jump
                            
                else if(p->direction==1)
                    p->pos_p.y=p->super_jump;                                     
                    
                     break ;


           }
               break;  
     
       case SDL_KEYUP :
        
          switch(event->key.keysym.sym)
           {
               case SDLK_SPACE : 
                      p->num=0;          /// animate the jump

                    if(p->direction==0)
                        p->pos_p.y=500;  //// gravite
                 
                     else if(p->direction==1)           
                         p->pos_p.y=500; 
       }      
     break;     
    } 
}


///************************************************

 void animer_perso(personne *p)
{
       p->num++;
      if(p->num==3)
       p->num=0;

}



                       



