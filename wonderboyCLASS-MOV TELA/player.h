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
    // Método para desenhar o jogador
    void draw(BITMAP * buffer);

    // Método para verificar colisões
    bool checkCollision();

    // Método para animar o jogador
    void animate();
    //verificar
    void verifica(int grav);
    
        // Função estática que chama animate
    static void animate_esquerda_timer() {
        // Aqui você precisa de uma maneira de acessar a instância da classe Player
        // Por exemplo, você pode ter um ponteiro estático para a instância dentro da classe
          instance->tem_esquerda();
    }
    
  static void animate_direita_timer() {
        // Aqui você precisa de uma maneira de acessar a instância da classe Player
        // Por exemplo, você pode ter um ponteiro estático para a instância dentro da classe
          instance->tem_direita();
    }
    
      static void animate_atack_timer() {
        // Aqui você precisa de uma maneira de acessar a instância da classe Player
        // Por exemplo, você pode ter um ponteiro estático para a instância dentro da classe
          instance->tem_atakF();
    }
    
    private:
    	static Player* instance;  // Ponteiro para a instância

    
};
#endif // PLAYER_H