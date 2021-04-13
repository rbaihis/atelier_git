#include "background.h"
int main()
{
  int width=1900,height=750;// window size
  // ES init 
  ennemi es ; int x=1,y=0,z=0; int speed=5;  es.speed=speed; es.faster=1; 
  es.screenheight= height; es.screenwidth=  width ; SDL_Surface * a[5];
  
  
  int c=1; 
int direction;
int pasAvancement=0;
  
  
  
  SDL_Event event;
  SDL_Surface *ecran=NULL;
  
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("game",NULL);
  ecran=SDL_SetVideoMode(width,height,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  
  
  personne p ;
  background back; // declaration struct_background
  
   intialiser_back(&back);  // loading 
   init_perso(&p);
  //--------------------------


   // ES init function 
    initennemi(&es);
    deplacement_settings2( &es , &p );
    a[0]=es.image;

   while(c==1)
  {   
  
   affichback(&back,ecran);
   
   afficher_perso(&p,ecran);
   

  // afficher_perso(&personnage,ecran,event); // for testing scrolling with perso_p
	
	
	
	
	// ES function called 
	     afficher_ennemi(es, ecran);
             animer_ennemi(&es);
        
	
	if(back.pos_bg.x==1400)  // setting where ES will show up 
                  { 
                 es.image = a[0];
                  x=1 ; y=0;
                deplacement_settings2( &es , &p );
                }
                 if(back.pos_bg.x==3000)
   		   { 
     			es.image = a[0];
     			x=0 ; y=1;
     			deplacement_settings2( &es , &p );
     		   }
      	     	    if(back.pos_bg.x==8300)
                     { 
                       es.image = a[0];
                       y=0;z=1;
                      deplacement_settings2( &es , &p );
                     }
	 //if(x==1)  
              rightleft(&es);
          if(y==1)            // chose deplacement option 
              updown(&es);
           if(z==1)
              deplacer_ennemi(& es);
          
           es.collision = collision_bb(p,es);
    
       if(collision_bb(p,es)== 1)
          p.pos_p.x=1200;
	
	//************************************************************************
  
	
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
     SDL_Delay(1000/60);
     SDL_Flip(ecran);
  }
    
SDL_FreeSurface(back.im_bg);
SDL_FreeSurface(ecran);
SDL_Quit();
    
	return 0;
}

