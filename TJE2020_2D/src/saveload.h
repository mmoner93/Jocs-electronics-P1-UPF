/*  by Javi Agenjo 2013 UPF  javi.agenjo@gmail.com
	This class encapsulates the game, is in charge of creating the game, getting the user input, process the update and render.
*/

#ifndef SAVELOAD_H
#define SAVELOAD_H

#include "stage.h"

using namespace std;

class SaveLoad {
public:
    //myGameData saveloadGame;
    SaveLoad(Vector2 pos, int lvl);
    static void saveGameInfo();
    static bool loadGameInfo();
    static int * readCSV(string filesrc, int size);
    
};



#endif 
