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
    return mapborder;
}




/*
 for (int j = 0; j < numobjects; j++) {
 if (aux == 117) {
     mapobj[pos].cellType = TELEPORT;
     mapobj[pos].item = NOTHING;
     mapobj[pos].transport = Vector2(73*8,102*8);
 }
 else if (aux == 1) {
     mapobj[pos].cellType = TELEPORT;
     mapobj[pos].item = NOTHING;
     mapobj[pos].transport = Vector2(50,50);
 }
 else if (aux == 2) {
     mapobj[pos].cellType = TELEPORT;
     mapobj[pos].item = NOTHING;
     mapobj[pos].transport = Vector2(50,50);
 }
 else if (aux == 3) {
     mapobj[pos].cellType = TELEPORT;
     mapobj[pos].item = NOTHING;
     mapobj[pos].transport = Vector2(50,50);
 }
 else if (aux == 4) {
     mapobj[pos].cellType = TELEPORT;
     mapobj[pos].item = NOTHING;
     mapobj[pos].transport = Vector2(50,50);
 }
 else if (aux == 5) {
     mapobj[pos].cellType = TELEPORT;
     mapobj[pos].item = NOTHING;
     mapobj[pos].transport = Vector2(50,50);
 }
 else if (aux == 6) {
     mapobj[pos].cellType = TELEPORT;
     mapobj[pos].item = NOTHING;
     mapobj[pos].transport = Vector2(50,50);
 }
 else if (aux == 7) {
     mapobj[pos].cellType = TELEPORT;
     mapobj[pos].item = NOTHING;
     mapobj[pos].transport = Vector2(50,50);
 }
 else if (aux == 8) {
     mapobj[pos].cellType = TELEPORT;
     mapobj[pos].item = NOTHING;
     mapobj[pos].transport = Vector2(50,50);
 }
 else if (aux == 9) {
     mapobj[pos].cellType = TELEPORT;
     mapobj[pos].item = NOTHING;
     mapobj[pos].transport = Vector2(50,50);
 }
 else if (aux == 10) {
     mapobj[pos].cellType = TELEPORT;
     mapobj[pos].item = NOTHING;
     mapobj[pos].transport = Vector2(50,50);
 }
 else if (aux == 11) {
     mapobj[pos].cellType = TELEPORT;
     mapobj[pos].item = NOTHING;
     mapobj[pos].transport = Vector2(50,50);
 }
 
 else if (aux == 17) {
     mapobj[pos].cellType = CHEST;
     mapobj[pos].item = KEY1;
 }
 */
