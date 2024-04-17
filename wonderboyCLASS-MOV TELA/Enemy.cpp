#include "Enemy.h"
#include <iostream>
#include <allegro.h>

Enemy* Enemy::instance = NULL;

Enemy::Enemy(){
	  instance = this;
     inimigo=load_bitmap("inimigo.bmp",NULL);
     inimigo2=load_bitmap("inimigo2.bmp",NULL);
     
	 int pos=0;
      // install_int_ex(ini_tem,MSEC_TO_TIMER(300));
      install_int_ex(Enemy::animate_move,MSEC_TO_TIMER(300));
	 // ataque
     // atak=false;
     // inimigo
     ini_x=600;
     ini_y=200;
     ini_dir=2;
     ini_Tem=0;
     ini_lar=34;
     ini_tam=34;
     danoIni=false;
}

void Enemy::ini_tem() // animacao inimigo
{
     if(ini_Tem==0) ini_Tem=1;
     else ini_Tem=0;
}

void Enemy::move(){
	if(!danoIni){
	  if(ini_dir==2){ // inimigo direcionado para a direita
	    if(ini_x<700){
	     ini_x++;
	    } else ini_dir=1;
	   } else { // direcionado para a esquerda
		  if(ini_x>550){
		   ini_x--;
		  } else ini_dir=2;
	   }
   }
}

void Enemy::draw(BITMAP *buffer){
	
    if(danoIni) // inimigo
     {
                if(ini_dir==2) masked_blit(inimigo,buffer,1+(2*34),1,ini_x,ini_y+1,34,34); // inimigo direita
                else masked_blit(inimigo2,buffer,1+(2*34),1,ini_x,ini_y+1,34,34); // inimigo esquerda
     }
     else // inimigo
     {
         if(ini_dir==2) masked_blit(inimigo,buffer,1+(ini_Tem*34),1,ini_x-pos,ini_y+1,34,34); // inimigo direita
         else masked_blit(inimigo2,buffer,1+(ini_Tem*34),1,ini_x-pos,ini_y+1,34,34); // inimigo esquerda
     }
}
