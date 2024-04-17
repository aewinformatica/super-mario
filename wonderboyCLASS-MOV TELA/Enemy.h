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
	
	    // Método para desenhar o jogador
	    void draw(BITMAP * buffer);
		
		void ini_tem();
	    // Método para animar o jogador
	    void move();
	    
 static void animate_move() {
        // Aqui você precisa de uma maneira de acessar a instância da classe Player
        // Por exemplo, você pode ter um ponteiro estático para a instância dentro da classe
          instance->ini_tem();
}
	    
private:
    	static Enemy* instance;  // Ponteiro para a instância
    
};
#endif // ENEMY_H