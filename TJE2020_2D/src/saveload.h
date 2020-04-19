/*  by Javi Agenjo 2013 UPF  javi.agenjo@gmail.com
	This class encapsulates the game, is in charge of creating the game, getting the user input, process the update and render.
*/

#ifndef SAVELOAD_H
#define SAVELOAD_H

#include "includes.h"
#include "utils.h"
#include <fstream>

using namespace std;

class SaveLoad {
public:
    SaveLoad(Vector2 pos, int lvl);
    static void saveGameInfo();
    static bool loadGameInfo();
    static int * readCSV(string filesrc, int size);
};



#endif 
