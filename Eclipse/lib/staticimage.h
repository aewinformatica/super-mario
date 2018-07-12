/*
 * staticimage.h
 *
 *  Created on: 10/07/2018
 *      Author: AEW
 */

#ifndef LIB_STATICIMAGE_H_
#define LIB_STATICIMAGE_H_
#include <iostream>
#include <SDL/SDL.h>
class StaticImage {
protected:
	SDL_Rect offset;
	Uint8 z;
	SDL_Surface* image;
	void load_image(std::string filename);
public:
	StaticImage(std::string filename,Sint16 x,Sint16 y, Uint8 z);
	void show(SDL_Surface* screen);
	void setPos(Sint16 x, Sint16 y);
	SDL_Rect* getRect();
	virtual ~StaticImage();
};

#endif /* LIB_STATICIMAGE_H_ */
