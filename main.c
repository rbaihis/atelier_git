#include "header.h"

int main()
{

  int c=1; 
  
  
  
  SDL_Surface *screen=NULL;
  SDL_Event event;
  
  background back; 
  personne p;
  
  
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("game",NULL);
  screen=SDL_SetVideoMode(1920,960,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  
  
  //personne personnage;
  //init_perso(&personnage); // is needed for testing scrolling with perso_p

  intialiser_back(&back); 

   while(c==1)
  {   
  
   
   
     // affichage background & scrolling :	
   scrolling( & p , &back ); // perso's needed for scrolling to properly work
   affichback( & back,screen);

   SDL_Delay(1000/60);
   

   SDL_Flip(screen); // mise a jour .
	
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
           } 
        break;     
      }
     }
     
     
  }// end of game_loop
  
 
 //do not forget to free all surfaces created. 
SDL_FreeSurface(screen);   
SDL_FreeSurface(back.image);
//SDL_FreeSurface( !!!!!!!! );
//SDL_FreeSurface( !!!!!!!!!! );
//SDL_FreeSurface( !!!!!!!!!!! );
//SDL_FreeSurface( !!!!!!!!!!! );

SDL_Quit();
    
	return 0;
}

