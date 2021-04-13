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
    
   
   /* 
//------------
void deplacer_ennemi( ennemi * es)
{
  
  if(es->x_pos <= 0) // when es->pos reachs left_side
  {
    es->image=NULL; //make it disappear  . i am keeping the image address in an other address
                   // to free it later and reaffect it to sprite again in different location.
  }
   if(es->y_pos <= 0) //when reaches the top of the scree
   {
     es->y_pos = 0; // set the position af the sprite at 0
     es->y_vel = -(es->y_vel); // velocity_y_axes is positive at first this code will be executed the moment the sprite touches the top of the screen velocity 's value turns back positive .
   }
    if(es->x_pos >= es->screenwidth - es->pos_s.w) // when width of sprite touches screen on the right side
    {
      es->x_pos= es->screenwidth - es->pos_s.w; // posiion will be set to screen_width -  sprite's width
      
      es->x_vel = -(es->x_vel); // the value of the velocity_x_axes was positive now multiplyin it with negative value -1(5 )  ==> resulting negative velocity .
    }
     if(es->y_pos >= es->screenheight - es->pos_s.h)// when sprite 's height touches the floor  
      {
        es->y_pos = es->screenheight - es->pos_s.h; // setting sprite is position ex 960*480 ( 480 - sprite 's hight ) 
        
        es->y_vel = - (es->y_vel); // the velocity_y_axes turns from positive value to negative 
      }
      
      // flipping the animated photo left or right
      if( es->x_vel < 0 ) // if velocity_x_axes is "negative value" sprite image facing left side
      es->direction=1;
      if( es->x_vel > 0 )// if velocity_x_axes is "positive value" sprite image facing right side
        es->direction=0; 
        
        // updating position
      es->x_pos += es->x_vel;  
                              // my explanation to you Mz AMAL .
                              
                              // ex : lets say "screen 800*600 " and sprite height's 50 pixel.
                              // at first velocity = (5) 
                              // sprite is position at the 1st blit time is " y=0" "x= 600-50"
                              // !!! note illustrating the Y_axes only !!!
      es->y_pos += es->y_vel; // now adding the velocity to the position es->pos_e.y
      			       //  0 += 5 ; ==> y_axes incremented by +5 ==> sprite going down.
      	     // first case    // when "ES->pos_H" reachs 600  !! condition start !!
      	                      //=> ES->pos_y == 600-50 
      	                      // velocity_y = -1(5) 
      	                      // now this line of codes es->y_pos += es->y_vel;
                              // 550 +=  -1(5) and the ES->pos_y_axes will be incremented by -5 .
                              //===> Result going UP.
                              // now when opposite happens :
                              //ex when ES->pos_y reachs  0 . !!! condition !!!
                              // es_pos_y = 0 ;
                              // velocity_y = -1(-5) => resulting in positive velocity . +5
                              //now this line of codes again es->y_pos += es->y_vel;
                              // 0 +=  5 and the y_axes will be incremented by +5 .
                              // RESULT =====> going Down 
                              //-----------------------
                              
                              // thats all same idea used on the x_axes. to make it bounce
                              // on the right side . at the left side i chose to disappear image
                              // no bouncing on the left side . just pointing image to NULL .
                              
      
      // affecting position to the Rect to work with 
      // the original Rect of the ES_sprite will get the result of it updated wich will make 
      // the original sprite move 
      // note !! i chosed to use the extra  variable x=es_y_pos  for more portability and less errors in case i wanted to divide the velocity (float) , i could have used directly 
    //  es->pos_e.x and es->pos_e.y in place of es->y_pos and es->x_pos.
        es->pos_e.x = es->x_pos ;
        es->pos_e.y = es->y_pos ;      
        
        
        
        // attack
         if( es->x_vel < 0 &&  es->pos_e.x <900 && es->collision==1 ) // facing left side
       es->direction=3;
      if( es->x_vel > 0 && es->pos_e.x >400 && es->collision==1)// face right side
        es->direction=2;   
}
*/
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



