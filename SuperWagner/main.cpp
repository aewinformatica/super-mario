#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <allegro.h>

#include "main.h"


void my_timer_handler(void)
{
   counter++;
}
END_OF_FUNCTION(my_timer_handler);

int inicia_allegro(int max_x, int max_y, int prof)
{
	allegro_init(); install_keyboard();
	install_mouse(); install_timer();

	if (install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL) < 0)
	{
		printf("Erro no som a�!\n");
		return(FALSE);
	}

	// set_volume(vol_som,vol_musica);
	set_color_depth(prof);
	if (set_gfx_mode(GFX_AUTODETECT,max_x,max_y,0,0) < 0)
	{
		printf("Erro no video a�!\n");
		return(FALSE);
	}

   LOCK_VARIABLE(counter);
   LOCK_FUNCTION(my_timer_handler);
   install_int_ex(my_timer_handler,BPS_TO_TIMER(FRAME_RATE));

	return(TRUE);
}

int main(int argc, char **argv)
{
    

//    processa_linha_de_comando(argc,argv);
   
   inicia_allegro(RES_X,RES_Y,(modo_16_bits) ? 16 : 8);
//    inicia_jogo();

    counter = 0;
    lacos = 1;

   while(!key[KEY_ESC] && mario_vidas > -1)
   {
      if (counter)
      {
        //  clear_to_color(tela,224);
        //  if (mario->estado < ESTADO_MORTO) move_sprites();
        //  move_mario();
        //  calcula_scroll();
        //  detecta_colisoes();
        //  desenha();
         counter = 0;
         lacos++;
      }

     
      
    //   if (mario->estado == ESTADO_MORTO) le_fase(arq_fase[fase_atual]);
    //   if (passou_de_fase) le_fase(arq_fase[1]);
  	//  blit_scrolled(); 
   }

   // if (passou_de_fase) le_fase(arq_fase[1]);
	//  fim_de_jogo();


   allegro_exit();
	return(0);
}
END_OF_MAIN();