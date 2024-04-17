#include "player.h"
#include <iostream>
#include <allegro.h>

Player* Player::instance = NULL;

// Implementação do construtor
Player::Player() {
	instance = this;
    heroi =  load_bitmap("heroi.bmp",NULL);
    heroi2 = load_bitmap("heroi2.bmp",NULL);
     heroi_atak=load_bitmap("heroi_atak.bmp",NULL);
     heroi_atak2=load_bitmap("heroi_atak2.bmp",NULL);
     
     int pos=0;
         // posicionamento do heroi
     lado=2;
     tam_her=65;
     her_x=167;
     her_y=109-tam_her;
     her_lar=50;
     dano=false;
     // movimento heroi
     tem_mov=0;
     direita=false;
     esquerda=false;
     pulo=false;
  	 // ataque
     atak=false;
}

void Player::tem_esquerda() // tempo animacao personagem esquerda
{
     if(tem_mov<4) tem_mov++;
     else tem_mov=1;
}

void Player::tem_direita() // tempo animacao personagem direita
{
     if(tem_mov<4) tem_mov++;
     else tem_mov=1;
}

void Player::tem_atakF() { // tempo para animacao de ataque
 if(tem_atak!=4) {
  tem_atak++;
 } else{
   remove_int(animate_atack_timer);
   atak=false;
   }
}

// Implementação do método para desenhar o jogador
void Player::draw(BITMAP *buffer) {
     if(atak) // caso ataque
     {
             if(lado==2) masked_blit(heroi_atak,buffer,1+(tem_atak*70),1,her_x-pos,her_y-4,70,70); // heroi
             else masked_blit(heroi_atak2,buffer,1+(tem_atak*70),1,her_x-pos-20,her_y-4,70,70); // heroi
     }
     else if(pulo) // caso pulo
     {
          if(lado==2) masked_blit(heroi,buffer,1+(5*50),1,her_x-pos,her_y,50,66); // heroi
          else masked_blit(heroi2,buffer,1+(5*50),1,her_x-pos,her_y,50,66); // heroi
     }
     else if(dano) // caso esteja levando dano
     {
          if(lado==2) masked_blit(heroi_atak,buffer,1+(5*70),1,her_x-pos-5,her_y-4,70,70); // heroi
          else masked_blit(heroi_atak2,buffer,1+(5*70),1,her_x-pos-10,her_y-4,70,70); // heroi
     }
     else // padrão
     {
         if(lado==2) masked_blit(heroi,buffer,1+(tem_mov*50),1,her_x-pos,her_y,50,66); // heroi
         else masked_blit(heroi2,buffer,1+(tem_mov*50),1,her_x-pos,her_y,50,66); // heroi
     }
}

// Implementação do método para verificar colisões
bool Player::checkCollision() {
    // Lógica para verificar colisões
    // Retorne true se houver colisão, false caso contrário
    return false;
}

// Implementação do método para animar o jogador
void Player::animate() {
    // Lógica para animar o jogador
    std::cout << "Animando o jogador..." << std::endl;
}

void Player::verifica(int grav){
     
     if(!pulo && !atak && !dano){
     	
	    if(key[KEY_RIGHT]){ // direita
		lado=2;
		// int aux=contato(her_x+50,her_x+50+6,2); // calcula a distancia do passo
		int aux = 6;
		if(aux!=0) // caso possa se mover
		{
		   
			her_x+=aux;
		   if(her_x>pos+400 && pos<640){ // tela 
             int aux2=her_x-(400+pos);
             if(pos+aux2<=640) pos+=aux2;
             else pos=640;
		   }
		   if(!direita){ // ativa animação direita
            direita=true;
            tem_mov=1;
			// install_int_ex(tem_direita,MSEC_TO_TIMER(150));
			install_int_ex(Player::animate_direita_timer,MSEC_TO_TIMER(150));
		   }
		}
		else { // caso haja algo que impessa o movimento
         direita=false;
		 tem_mov=0;
		 // remove_int(tem_direita);
		}
	} else if(direita){ // deleta animação direita
      direita=false;
      tem_mov=0;
      remove_int(Player::animate_direita_timer);
     }
     
     if(key[KEY_LEFT]) // esquerda
     {
      lado=1;
      // int aux=contato(her_x,her_x-6,1);
      int aux = 6;
      if(aux!=0)
      {
        her_x-=aux;
        if(her_x<pos+160 && pos>0){ // tela
         int aux2=(pos+160)-her_x;
         if(pos-aux2>=0) pos-=aux2;
         else pos=0;
        }
    
        if(!esquerda){
         esquerda=true;
         tem_mov=1;
          install_int_ex(Player::animate_esquerda_timer,MSEC_TO_TIMER(150));
          
        }
      }
      else
      {
          esquerda=false;
          tem_mov=0;
          // remove_int(tem_esquerda);
          remove_int(Player::animate_esquerda_timer);
      }
     }
     else if(esquerda) // deleta animacao esquerda
     {
          esquerda=false;
          tem_mov=0;
          remove_int(Player::animate_esquerda_timer);
     }
     
	 	// pulo
		 if(key[KEY_UP]){
      	  // pulo=true;
      	  her_y -= 140;
          // grav=-20;
		 } 
		 
         if(key[KEY_Z] ){ // ataque
          atak=true;
          tem_atak=0;
           install_int_ex(Player::animate_atack_timer,MSEC_TO_TIMER(60));
     	 }

     }
     // gravidade(&grav,&her_y,tam_her,her_lar,her_x); // gravidade herói
     
     // gravidade(&grav_ini,&ini_y,ini_tam,ini_lar,ini_x); // gravidade inimigo
     
     // if(!dano && tomaDano(her_x,(her_x+her_lar),her_y,(her_y+tam_her),ini_x,(ini_x+ini_lar),ini_y,(ini_y+ini_tam),&dano_lado)){
     //  atak=false;
     //  pulo=false;
     //  dano=true;
     //  grav=-10;
     // } else if(dano){
     //    if(dano_lado==1){
	    //       lado=2;
	    //       int aux3=contato(her_x,her_x-6,1);
	    //       if(aux3!=0){
     //           her_x-=aux3;
     //           if(her_x<pos+160 && pos>0){ // tela
     //            int aux2=(pos+160)-her_x;
     //            if(pos-aux2>=0) pos-=aux2;
     //             else pos=0;
     //           }
	    //       }
     //   } else {
     //          lado=1;
     //          int aux3=contato(her_x+50,her_x+50+6,2); // calcula a distancia do passo
     //          if(aux3!=0){ // caso possa se mover
     //           her_x+=aux3;
     //           if(her_x>pos+400 && pos<640){ // tela
     //            int aux2=her_x-(400+pos);
     //            if(pos+aux2<=640) pos+=aux2;
     //             else pos=640;
     //           }
     //          }
     //         }
     //  }
     
     // if(!dano && atak && !pulo && !danoIni){
     //  if(tem_atak>=1 && tem_atak<=3)
     //  {
     //     if(lado==2 && tomaDano((her_x+50),(her_x+65),(her_y+5),(her_y+tam_her-5),ini_x,(ini_x+ini_lar),ini_y,(ini_y+ini_tam),&dano_lado2)){
     //      danoIni=true;
     //      grav_ini=-10;
     //     } else if(lado==1 && tomaDano((her_x+5-20),(her_x+20-20),(her_y+5),(her_y+tam_her-5),ini_x,(ini_x+ini_lar),ini_y,(ini_y+ini_tam),&dano_lado2)){
     //      danoIni=true;
     //      grav_ini=-10;
     //     }
     //  }
     // } else if(danoIni){
     //   if(dano_lado2==1) ini_x+=2;
     //   else ini_x-=2;
     // }
}