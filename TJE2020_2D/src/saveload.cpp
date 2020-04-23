#include "saveload.h"
#include <iostream>




void SaveLoad::saveGameInfo(myGameData& currentGame)
{
    myGameData save = currentGame;
    //fill here game_info with all game data
    //...
    //save to file
    FILE* fp = fopen("savegame.bin","wb");
    fwrite(&save, sizeof(myGameData),1,fp);
    fclose(fp);
}

bool SaveLoad::loadGameInfo(myGameData& currentGame)
{
    myGameData load;
    //load file
    FILE* fp = fopen("savegame.bin","rb");
    if(fp == NULL) //no savegame found
       return false;

    fread(&load, sizeof(myGameData),1,fp);
    fclose(fp);
    currentGame = load;

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



void SaveLoad::init(myGameData& currentGame, int u)
{
    if (u == 0) {
        currentGame.player.camerapos = Vector2(40, 140);
        currentGame.player.camfinpos = Vector2(40, 140);
        std::memmove(&currentGame.world.mapa, SaveLoad::readCSV("data/house.csv", 14400), 14400 * sizeof(int));
        std::memmove(&currentGame.world.obj, SaveLoad::readCSV("data/obj.csv", 14400), 14400 * sizeof(int));
        for (int i = 0; i<25; i++) {
            currentGame.player.myobj[i] = NOTHING;
        }
        for (int n = 0; n < 120; n++) {
            for (int m = 0; m < 120; m++) {
                if (currentGame.world.obj[m * 120 + n] == TELEPORT) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(465, 760);
                }
                else if (currentGame.world.obj[m * 120 + n] == TELEPORT1) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(690, 320);
                }
                else if (currentGame.world.obj[m * 120 + n] == TELEPORT2) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(320, 370);
                }
                else if (currentGame.world.obj[m * 120 + n] == TELEPORT3) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(320, 370);
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS0) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(710, 45);
                    currentGame.world.celdas[m * 120 + n].item = OPEN;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS1) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(120, 140);
                    currentGame.world.celdas[m * 120 + n].item = OPEN;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS2) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(520, 280);
                    currentGame.world.celdas[m * 120 + n].item = KEY1;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS3) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(120, 140);
                    currentGame.world.celdas[m * 120 + n].item = OPEN;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS4) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(370, 340);
                    currentGame.world.celdas[m * 120 + n].item = OPEN;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS5) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(120, 20);
                    currentGame.world.celdas[m * 120 + n].item = OPEN;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS6) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(290, 320);
                    currentGame.world.celdas[m * 120 + n].item = KEY1;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS7) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(715, 110);
                    currentGame.world.celdas[m * 120 + n].item = OPEN;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS8) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(65, 425);
                    currentGame.world.celdas[m * 120 + n].item = OPEN;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS9) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(257, 15);
                    currentGame.world.celdas[m * 120 + n].item = KEY2;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS10) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(505, 720);
                    currentGame.world.celdas[m * 120 + n].item = OPEN;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS11) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(640, 670);
                    currentGame.world.celdas[m * 120 + n].item = KEY3;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS12) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(290, 550);
                    currentGame.world.celdas[m * 120 + n].item = OPEN;
                }
                else if (currentGame.world.obj[m * 120 + n] == STAIRS13) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(640, 670);
                    currentGame.world.celdas[m * 120 + n].item = OPEN;
                }
                else if (currentGame.world.obj[m * 120 + n] == HOLE) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].transport = Vector2(220, 270);
                    currentGame.world.celdas[m * 120 + n].item = OPEN;
                }
                
                else if (currentGame.world.obj[m * 120 + n] == CHEST0) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].item = KEY1;
                }
                else if (currentGame.world.obj[m * 120 + n] == CHEST1) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].item = KEY2;
                }
                else if (currentGame.world.obj[m * 120 + n] == CHEST2) { /// espada para romper piedras
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].item = SWORD;
                }
                else if (currentGame.world.obj[m * 120 + n] == CHEST3) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].item = KEY3;
                }
                else if (currentGame.world.obj[m * 120 + n] == CHEST4) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].item = KEY4;
                }
                else if (currentGame.world.obj[m * 120 + n] == CHESTWIN) {
                    currentGame.world.celdas[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdas[m * 120 + n].item = KEYWIN;
                }
                else{
                    currentGame.world.celdas[m * 120 + n].item = NOTHING;
                }
            }
        }
    }
    if (u == 1) {
        currentGame.player.camerapos = Vector2(300, 500);
        currentGame.player.camfinpos = Vector2(300, 500);
       std::memmove(&currentGame.world.demo, SaveLoad::readCSV("data/demo.csv", 14400), 14400 * sizeof(int));
       std::memmove(&currentGame.world.objdemo, SaveLoad::readCSV("data/demo_obj.csv", 14400), 14400 * sizeof(int));
        for (int i = 0; i<25; i++) {
            currentGame.player.myobj[i] = NOTHING;
        }
        for (int n = 0; n < 120; n++) {
            for (int m = 0; m < 120; m++) {
                if (currentGame.world.objdemo[m * 120 + n] == TELEPORT) {
                    currentGame.world.celdasdemo[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdasdemo[m * 120 + n].transport = Vector2(560, 460);
                }
                else if (currentGame.world.objdemo[m * 120 + n] == TELEPORT1) {
                    currentGame.world.celdasdemo[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdasdemo[m * 120 + n].transport = Vector2(390, 220);
                }

                else if (currentGame.world.objdemo[m * 120 + n] == STAIRS0) {
                    //std::cout << "chest 0" << endl;
                    currentGame.world.celdasdemo[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdasdemo[m * 120 + n].transport = Vector2(360, 190);
                    currentGame.world.celdasdemo[m * 120 + n].item = KEY1;
                }
                else if (currentGame.world.objdemo[m * 120 + n] == STAIRS1) {
                    //std::cout << "chest 1" << endl;
                    currentGame.world.celdasdemo[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdasdemo[m * 120 + n].transport = Vector2(265, 425);
                    currentGame.world.celdasdemo[m * 120 + n].item = KEY1;
                }
                
                
                else if (currentGame.world.objdemo[m * 120 + n] == CHEST0) {
                    currentGame.world.celdasdemo[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdasdemo[m * 120 + n].item = KEY1;
                }
                else if (currentGame.world.objdemo[m * 120 + n] == CHESTWIN) {
                    currentGame.world.celdasdemo[m * 120 + n].pos = Vector2(m,n);
                    currentGame.world.celdasdemo[m * 120 + n].item = KEYWIN;
                }
                else{
                    currentGame.world.celdas[m * 120 + n].item = NOTHING;
                }
            }
        }
    }
    else{
        std::memmove(&currentGame.world.demo, SaveLoad::readCSV("data/demo.csv", 14400), 14400 * sizeof(int));
        std::memmove(&currentGame.world.objdemo, SaveLoad::readCSV("data/demo_obj.csv", 14400), 14400 * sizeof(int));
        std::memmove(&currentGame.world.mapa, SaveLoad::readCSV("data/house.csv", 14400), 14400 * sizeof(int));
        std::memmove(&currentGame.world.obj, SaveLoad::readCSV("data/obj.csv", 14400), 14400 * sizeof(int));

    }
    
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
