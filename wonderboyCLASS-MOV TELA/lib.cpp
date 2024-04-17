#include <allegro.h>

void init() // funcao padrão do allegro
{
	int depth, res;
	allegro_init();
	install_timer();
	install_keyboard();
	install_mouse();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 440, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}
	/* add other initializations here */
}

void deinit() // funcao padrão do allegro
{
	clear_keybuf();
	/* add other deinitializations here */
}