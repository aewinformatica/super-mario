#ifndef WINDOW_H_
#define WINDOW_H_

#include <iostream>
#include <SDL/SDL.h>

class Window {
private:
        SDL_Surface * screen;
        std::string  title;
        int width;
        int height;
        int bbp;
        
        void init();
public:
       Window(std::string title,int width, int height, int bbp);
       void show();
       void clear(char r,char g, char b);
       SDL_Surface * getScreen();
       virtual ~Window();
};
#endif /*WINDOW_H_*/
