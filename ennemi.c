#include "header.h"


/*
typedef struct{
SDL_Surface * image;
SDL_Rect pos_ob;
}obstacle; 

typedef struct{
SDL_Surface * image;
SDL_Rect pos_e; 
SDL_Rect pos_s; 
int direction;
int faster , speed ;

float x_vel, y_vel, x_pos, y_pos; //

int screenheight, screenwidth;

}ennemi;

*/

//void updown();


// --- colision_bb -- colision_bb -- colision_bb 
int collision_bb( personne p, ennemi es)
{
  if( (p.pos_p.x + p.pos_p.w < es.pos_e.x) || ( p.pos_p.x > es.pos_e.x +es.pos_e.w)
   || (p.pos_p.y + p.pos_p.h < es.pos_e.y) || ( p.pos_p.y > es.pos_e.y +es.pos_e.h)  )
   return 0;
     else
       return 1; 
}
// __collision_bb-- colision_bb 

//*************************************************************************************
// *-*-*-simple_ES*-*-*-simple_ES*-*-*-simple_ES*-*-*-simple_ES*-*-*-simple_ES
void initennemi(ennemi *es)
{
  es->image=IMG_Load("ennemi.png" );
  
  float z=((float) es->image->w)/4; //using float in case of error when dividing by int
  
  es->pos_e.w = (int) z;
  es->pos_e.h = es->image->h/4;
  
  //i chose the comment those functions because ill be using them in optional function
 //es->pos_e.x= es->screenwidth-simple_es->pos_e.w; 
 //es->pos_e.y= screenheight -simple_es->pos_e.h;  
 
   //loding animation sheet_loading
   es->image =IMG_Load("ennemi4sides.png");
   es->pos_s.x=0;
   es->pos_s.y=0;
   es->pos_s.w=es->image->w/4;
   es->pos_s.h=es->image->h/4;
  
  // setting speed amount ;
   es->x_vel = es->y_vel = es->speed;
 
}

void afficher_ennemi(ennemi es, SDL_Surface * screen)// cant make it work no return no pointer to pass !!!?????
{
 
    SDL_BlitSurface( es.image , &es.pos_s ,screen, &es.pos_e);
          
}
// optional afficher this one using pointer *es and allow me to call animerfunc inside that's all
void afficher_ennemi2(ennemi * es, SDL_Surface * screen)
{
    animer_ennemi(es);
    SDL_BlitSurface( es->image , &es->pos_s ,screen, &es->pos_e);
}

//-----
void animer_ennemi( ennemi * es)
{  
   if(es->pos_s.x==800 - es->pos_s.w)
     es->pos_s.x=0; // image back to 0 to show first image in sheet
     else
       es->pos_s.x += es->pos_s.w; // move sprite cheet image forward 
       
       es->pos_s.y = es->direction * es->pos_s.h; // setting which line f the sprite sheet will be showen 
}
//12345****animation*

//--- deplacement Es--- deplacement Es---

void deplacement_settings(ennemi * es,int s_posx ,int s_posy)
{
    // setting speed amount ;
   es->x_vel = es->y_vel = es->speed;
    // setting velovity
    es->x_vel= es->speed;
    es->y_vel= es->speed;
    
    //tsetting position 
   es->x_pos= s_posx -es->pos_e.w;//=(?????-200);
   es->y_pos= s_posy -es->pos_e.h;//=(??????-200);
}
    
    
//-----------
void deplacement_settings2(ennemi * es,personne *p)
{
    // setting speed amount ;
   es->x_vel = es->y_vel = es->speed;
    // setting velovity
    es->x_vel= es->speed ;
    es->y_vel= es->speed ;
    
    // setting  es position where to show up in front of ennemi
   es->x_pos=( p->pos_p.x + p->pos_p.w )+700;//=(?????-200);
   es->y_pos= ( es->screenheight - es->pos_e.h)/2; // middle
   
}
    

void deplacer_ennemi( ennemi * es)
{
  if (es->image==NULL)
  {
  
  }
  else
{
  
  if(es->x_pos <= 0) 
  {
    es->faster++;
     
    if (es->faster >7 )
     es->image=NULL;
      
    es->x_pos= 0; 
      es->x_vel = -(es->x_vel); 
  } 
                   
   if(es->y_pos <= 0) 
   {
     es->y_pos = 0; 
     es->y_vel = -(es->y_vel) ; 
   }
    if(es->x_pos >= es->screenwidth - es->pos_s.w) 
    {
      es->x_pos= es->screenwidth - es->pos_s.w; 
      es->x_vel = -(es->x_vel); 
    }
     if(es->y_pos >= es->screenheight - es->pos_s.h)  
      {
        es->y_pos = es->screenheight - es->pos_s.h; 
        
        es->y_vel = - (es->y_vel);  
      }

        // updating position
      es->x_pos += es->x_vel * es->faster;                        
      es->y_pos += es->y_vel *es->faster ;
      	
      	
      	// affecting it to rect variable;
        es->pos_e.x = es->x_pos ;
        es->pos_e.y = es->y_pos ;    
          
	//direct animation
      if( es->x_vel < 0 ) 
      es->direction=1;
      if( es->x_vel > 0 )
        es->direction=0; 

        // attack
       if( es->x_vel < 0 && es->collision==1 ) // facing left side
      es->direction=3;
      if( es->x_vel > 0 && es->collision==1 )// face right side
        es->direction=2; 
        
}          
}


void updown(ennemi *e)
{
    
   if(e->pos_e.y <= 0) // when es->pos reachs left_side
  {
    e->pos_e.y= 0; 
      
      e->y_vel = -(e->y_vel);
  }
  if(e->pos_e.y >= e->screenheight - e->pos_s.h) 
    {
      e->pos_e.y= e->screenheight - e->pos_s.h; 
      
      e->y_vel = -(e->y_vel);
    }
     if(e->pos_e.x <= 0) // when es->pos reachs left_side
  {
   /* e->image=NULL;  */
  }
    
  
        e->direction=1; // face right side
        
        
        // attack
        if( e->x_vel < 0 && (e->pos_e.x <900 && e->collision==1) ) // facing left side
      e->direction=3;
      if( e->x_vel > 0 && ( e->pos_e.x >500 && e->collision==1) )// face right side
        e->direction=2; 
        

      e->pos_e.y+= e->y_vel; // moving up and down depending on signe of y_velocity (+) || 
      
     
}

void rightleft(ennemi *e)
{
   
    if(e->pos_e.x <= 0) // when es->pos reachs left_side
  {
    e->pos_e.x= 0; 
      
      e->x_vel = -(e->x_vel);
  }
  if(e->pos_e.x >= e->screenwidth - e->pos_s.w) 
    {
      e->pos_e.x= e->screenwidth - e->pos_s.w; 
      
      e->x_vel = -(e->x_vel);
    }
  
  
      // flipping the animated photo left or right
      if( e->x_vel < 0 ) // facing left side
      e->direction=1;
      if( e->x_vel > 0 )// face right side
        e->direction=0; 
        
        // attack
         if( e->x_vel < 0 && (e->pos_e.x <900 && e->collision==1) ) // facing left side
      e->direction=3;
      if( e->x_vel > 0 && ( e->pos_e.x >500 && e->collision==1) )// face right side
        e->direction=2; 
        
        

      e->pos_e.x+= e->x_vel; // moving Rect   
      e->pos_e.y= e->screenheight - e->pos_s.h; 
     
   
}


// *-*-*-simple_ES*-*-*-simple_ES*-*-*-simple_ES*-*-*-simple_ES*-*-*-simple_ES
//*********************************************************************************************



