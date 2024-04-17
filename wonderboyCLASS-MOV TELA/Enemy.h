#ifndef ENEMY_H
#define ENEMY_H
#include <allegro.h>

class Enemy {
public:
		BITMAP *inimigo;
		BITMAP *inimigo2;

		int pos;
		int ini_x ,ini_y;
		int ini_dir;
		int ini_Tem;
		int grav_ini;
		int ini_lar, ini_tam;
		int dano_lado2;
		bool danoIni;

	    // Construtor
	    Enemy();
	
	    // M�todo para desenhar o jogador
	    void draw(BITMAP * buffer);
		
		void ini_tem();
	    // M�todo para animar o jogador
	    void move();
	    
 static void animate_move() {
        // Aqui voc� precisa de uma maneira de acessar a inst�ncia da classe Player
        // Por exemplo, voc� pode ter um ponteiro est�tico para a inst�ncia dentro da classe
          instance->ini_tem();
}
	    
private:
    	static Enemy* instance;  // Ponteiro para a inst�ncia
    
};
#endif // ENEMY_H