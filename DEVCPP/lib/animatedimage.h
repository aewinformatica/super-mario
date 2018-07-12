/*
 * animatedimage.h
 *
 *  Created on: 11/07/2018
 *      Author: AEW
 */

#ifndef LIB_ANIMATEDIMAGE_H_
#define LIB_ANIMATEDIMAGE_H_
#include "staticimage.h"
#include <iostream>
#include <SDL/SDL.h>
#include <vector>

class AnimatedImage: public StaticImage{
protected:
	Uint16 fwidth,fheight;
	double aspeed;
	//first frame  last frame total frames current frame
	Uint16 fframe,lframe,tframe,cframe;
	//os recortes do Spritesheet
	std::vector<SDL_Rect>clip;
	//iniciar
	Uint32 start;
public:
	AnimatedImage(std::string filename,Sint16 x, Sint16 y, Uint8 z,
			Uint16 frame_width, Uint16 frame_height, Uint16 current_frame,
			double animated_speed);
	void show(SDL_Surface* screen);
	void setFrame(Uint16 first_frame,Uint16 frame_count);
};

#endif /* LIB_ANIMATEDIMAGE_H_ */
