#include "header.h"
//#include "seifheader.h"

int main()
{
   char path_bg[]="bg.png"; char path_p[]="p.png"; char path_es[]="es.png";
 //  char path_ob[]="nails.png"; char path_fire[]="fire_ball"; char path_life[]="life";
   
   background b;
   personne p;
   surface * screen;
   event  event;
   int c=1, width=1400, height=600;
   
   c=init_sdl(); 
   set_screen_void(&screen,width,height);
   
   intialiser_back( &b );  
   
while(c==1) //game loop
{
     while(SDL_PollEvent(&event))
     {
      quit_event(&event,&c);
     }

    //affichage bg et scroling
    affichback(&b,screen);
   

    SDL_Delay(1000/60); 
   

    SDL_Flip(screen);
    
}
   //for(int i=0;i<6;i++)
   //SDL_FreeSurface(es->tab[i]);
   
   //SDL_FreeSurface(p.image);
   SDL_FreeSurface(b.image);
   SDL_FreeSurface(screen);
   SDL_Quit(); 


}





void intialiser_back(background *back) 
{ 
char chaine[]="stage.png";
char chaine1[]="bg.png";
back->image=IMG_Load(chaine1);

back->pos_bg.x=0;
back->pos_bg.y=0;  
back->pos_bg.h=600;
back->pos_bg.w=1400;
}

void affichback(background *back,SDL_Surface *ecran)
{ 

SDL_BlitSurface( back->image,&back->pos_bg, ecran,NULL);
}































































































































































































































int init_sdl()
{
   if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER )!=0)
   {
   printf("\n error initialasing %s",SDL_GetError());
   return 0; // affec t it to the game loop to not enter in case of error;
   }else
   return 1; 
}

void set_screen_void(surface ** screen,int width,int height)
{  
   
   SDL_WM_SetCaption("My Game Window",NULL);
   *screen=SDL_SetVideoMode(width,height,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
}

void quit_event(SDL_Event *event , int * loop) // better used in void mode
{
  switch(event->type ) 
      { 
        case SDL_QUIT:  
        *loop=0;
        // dont forget to add the other loops to quit completly the window
        break;  
        case SDL_KEYDOWN:  
          switch(event->key.keysym.sym)
           {
             case SDLK_ESCAPE : 
             case SDLK_q: 
             *loop=0;  // quit current loop only 
              break ;
           } 
        break;     
      }
}

