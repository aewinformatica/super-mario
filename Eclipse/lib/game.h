#ifndef GAME_H_
#define GAME_H_
#include "window.h"

class Game{
private:
        Window * win;
        std::string title;
        void gameLoop();
        bool done;
public:
        Game(std::string title);
        void start();
        virtual~Game();
};
      
#endif /*GAME_H_*/
