#include <SDL/SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <pthread.h>
#include "lib/Game.h"
using namespace std;

int main(int argc, char** argv){	

Game sm("Super Mario Bros - Wagner Goncalves de Jesus");
     sm.start();
	
	return 0;
}
