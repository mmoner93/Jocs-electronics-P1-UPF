/*  by Javi Agenjo 2013 UPF  javi.agenjo@gmail.com
	This class encapsulates the game, is in charge of creating the game, getting the user input, process the update and render.
*/

#ifndef SAVELOAD_H
#define SAVELOAD_H


#include "struct.h"
#include <fstream>

using namespace std;

class SaveLoad {
public:
    myGameData backup;
    static void saveGameInfo(myGameData& currentGame);
    static bool loadGameInfo(myGameData& currentGame);
    static int * readCSV(string filesrc, int size);
    static void init(myGameData& currentGame, int u);
};



#endif 
