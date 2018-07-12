#include "game.h"
#include "Staticimage.h"
#include "animatedimage.h"

Game::Game(std::string title){
this->title = title;
this->done = false;
this->win = NULL;
}
void Game::start(){
 win = new Window(this->title, 640,480,16);
 this->gameLoop();              
}
void Game::gameLoop(){
     SDL_Event event;
    // StaticImage img("gfx/moeda.bmp",0,0,0);
     AnimatedImage img1("gfx/blocos.bmp",0,0,0,32,32,1,1000/20);
     img1.setFrame(1,4);

     AnimatedImage img2("gfx/blocos.bmp",32,0,0,32,32,1,1000/4);
     img2.setFrame(1,4);
     
     while(!done){
              if(SDL_PollEvent(&event)){
                  if(event.type == SDL_QUIT){
                  done = true;
                  }                                        
              }
             win->clear(255,255,0);
             //img.show(win->getScreen());
             img1.show(win->getScreen());
             img2.show(win->getScreen());
             win->show();

     }
     delete(win);
}

Game::~Game(){

}
