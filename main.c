/** 
* @struct Background 
* @brief struct for backround 
*/

#include "background.h"
int main()
{

  int c=1; 
int direction;
int pasAvancement=0;
  
  SDL_Event event;
  SDL_Surface *screen1=NULL;
SDL_Surface *screen2=NULL;
  
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("scrolling like a loser hahaha",NULL);
  screen1=SDL_SetVideoMode(7500,750,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  
  


  
  
  personne p ,a;
  background b1 , b2 , back; // declaration struct_background
  
  intialiser_back(&b1); // loading 
init_perso(&p);
  //--------------------------


   while(c==1)
  {   
  
  affichback(&b1,screen1);
   
  afficher_perso(&p,screen1);
   

  // afficher_perso(&personnage,ecran,event); // for testing scrolling with perso_p
	
	
   SDL_Flip(screen1);
	
   while(SDL_PollEvent(&event))
   {
	switch(event.type ) 
      { 
        case SDL_QUIT:  
        c=0;
      
        break;  
        case SDL_KEYDOWN:   
          switch(event.key.keysym.sym)
           {
             case SDLK_ESCAPE : 
             case SDLK_q: 
              c=0;  
              break ;
              
              case SDLK_RIGHT:
direction=1;
pasAvancement+=1;
              
              if((p.pos_p.x > 0)&&(p.pos_p.x <1280))
                  p.pos_p.x += 50 ;
scrolling(&back,direction,pasAvancement);
              break;
              
              case SDLK_LEFT:
direction=2;
pasAvancement-=1;
               if((p.pos_p.x > 640)&&(p.pos_p.x <1920))
                  p.pos_p.x -= 50 ;
                  
              scrolling(&back,direction,pasAvancement);
              break;
           } 
        break;     
      }
     }
   
if (pos_p<300)//(1200/4)
{
{
deplacer_perso(&p);
}
else
scrolling(&back.camera1, direction,pasAvancement);
}
if(pos_p1>300)
{
{
deplacer_perso(&a);
}
else
scrolling(&back.camera2, direction,pasAvancement);
}
afficherback(&back,&ecran,partage);   
  }
    
    
SDL_FreeSurface(back.im_bg1);
SDL_FreeSurface(screen1);
SDL_FreeSurface(back.im_bg2);
SDL_FreeSurface(screen2);
SDL_Quit();
    
	return 0;
}
}

