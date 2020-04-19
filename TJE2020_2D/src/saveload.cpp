#include "saveload.h"
#include <iostream>



SaveLoad::SaveLoad(Vector2 pos, int lvl){
    Vector2 position = pos;
    int level = lvl;
}

void SaveLoad::saveGameInfo()
{
    //sGameInfo game_info(currentGame.player.actualpos, 1);
    SaveLoad game_info(Vector2(0,0),1);
    //fill here game_info with all game data
    //...
    //save to file
    FILE* fp = fopen("savegame.bin","wb");
    fwrite(&game_info, sizeof(SaveLoad),1,fp);
    fclose(fp);
}

bool SaveLoad::loadGameInfo()
{
    //sGameInfo game_info(Vector2(0,0),1);
    SaveLoad game_info(Vector2(0,0),1);
    //load file
    FILE* fp = fopen("savegame.bin","rb");
    if(fp == NULL) //no savegame found
       return false;

    fread(&game_info, sizeof(SaveLoad),1,fp);
    fclose(fp);

    //currentGame.player.actualpos = game_info.position;

    return true;
}

int * SaveLoad::readCSV(string filesrc, int size) { //archivo y tamaño de area
    int pos = 0;
    int* mapborder = new int[size];
    ifstream file;
    file.open(filesrc, fstream::in);
    if (!file.is_open()) {
        fprintf(stderr, "Error locating the file map");
    }
    while (file.good()){
        string line;
        while (getline(file, line)) {   // get a whole line
            std::stringstream ss(line);
            while (getline(ss, line, ',')) {
                int aux;
                istringstream(line) >> aux;
                mapborder[pos++] = aux;
            }
        }
    }
    /*
    int actualpos = 0;
    while (120*120 > actualpos){
        fprintf(stderr, "%d,", mapborder[actualpos]);
        if (actualpos == 0) {
        }
        else if ((actualpos+1) % 10 == 0)
        {
            cout << '\n';
        }
        actualpos += 1;
    }*/
    return mapborder;
}

