/*
 * animatedimage.cpp
 *
 *  Created on: 11/07/2018
 *      Author: AEW
 */

#include "animatedimage.h"

AnimatedImage::AnimatedImage(std::string filename,Sint16 x, Sint16 y, Uint8 z,
		Uint16 frame_width, Uint16 frame_height, Uint16 current_frame,
		double animated_speed): StaticImage(filename, x, y, z) {
	this->fwidth = frame_width;
	this->fheight = frame_height;
	this->aspeed = animated_speed;
	this->cframe = current_frame;

	//linhas
	int rows = int(this->image->h / this->fheight);
    int cols = int(this->image->w / this->fwidth);
    this->tframe = rows * cols;

    for(int i=0;i<this->tframe;i++){
    	int c = i % cols;
    	int r = int(i / cols);

    	SDL_Rect tmp = { c * this->fwidth, r * this->fheight, this->fwidth,this->fheight};
    	this->clip.push_back(tmp);

    	this->start = SDL_GetTicks();
    }

}
void AnimatedImage::show(SDL_Surface* screen){

SDL_BlitSurface(this->image,&this->clip[this->cframe],screen,&this->offset);

	if(SDL_GetTicks() - this->start > this->aspeed){
		this->start = SDL_GetTicks();
		if(this->cframe < this->lframe){
			this->cframe++;
		}else{
			this->cframe = this->fframe;
		}
	}
}
void AnimatedImage::setFrame(Uint16 first_frame,Uint16 frame_count){
this->fframe = first_frame;
this->cframe = first_frame;
this->lframe = first_frame + frame_count - 1;
}
