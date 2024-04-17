#ifndef PLAYER_H
#define PLAYER_H
#include <allegro.h>

class Player {

public:
		BITMAP *heroi;
		BITMAP *heroi2;
		
		BITMAP *heroi_atak;
		BITMAP *heroi_atak2;

		int pos;
		// posicionamento do heroi
		int lado;
		int her_x, her_y;
		int her_lar, tam_her;
		bool dano;
		int dano_lado;
		
		bool direita,esquerda;
		bool pulo;
		// ataque
		bool atak;
		int tem_atak;
		int  tem_mov;

    // Construtor
    Player();
    
    void tem_esquerda();
    void tem_direita();
    void tem_atakF();
    // M�todo para desenhar o jogador
    void draw(BITMAP * buffer);

    // M�todo para verificar colis�es
    bool checkCollision();

    // M�todo para animar o jogador
    void animate();
    //verificar
    void verifica(int grav);
    
        // Fun��o est�tica que chama animate
    static void animate_esquerda_timer() {
        // Aqui voc� precisa de uma maneira de acessar a inst�ncia da classe Player
        // Por exemplo, voc� pode ter um ponteiro est�tico para a inst�ncia dentro da classe
          instance->tem_esquerda();
    }
    
  static void animate_direita_timer() {
        // Aqui voc� precisa de uma maneira de acessar a inst�ncia da classe Player
        // Por exemplo, voc� pode ter um ponteiro est�tico para a inst�ncia dentro da classe
          instance->tem_direita();
    }
    
      static void animate_atack_timer() {
        // Aqui voc� precisa de uma maneira de acessar a inst�ncia da classe Player
        // Por exemplo, voc� pode ter um ponteiro est�tico para a inst�ncia dentro da classe
          instance->tem_atakF();
    }
    
    private:
    	static Player* instance;  // Ponteiro para a inst�ncia

    
};
#endif // PLAYER_H