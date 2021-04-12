#include "background.h"
int main()
{

  int c=1; 
int direction;
int pasAvancement=0;
  
  SDL_Event event;
  SDL_Surface *ecran=NULL;
  
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("scrolling like a loser hahaha",NULL);
  ecran=SDL_SetVideoMode(7500,750,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  
  


  
  
  personne p ;
  background back; // declaration struct_background
  
  intialiser_back(&back);  // loading 
   init_perso(&p);
  //--------------------------


   while(c==1)
  {   
  
   affichback(&back,ecran);
   
   afficher_perso(&p,ecran);
   

  // afficher_perso(&personnage,ecran,event); // for testing scrolling with perso_p
	
	
   SDL_Flip(ecran);
	
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
     
     
  }
    
SDL_FreeSurface(back.im_bg);
SDL_FreeSurface(ecran);
SDL_Quit();
    
	return 0;
}

