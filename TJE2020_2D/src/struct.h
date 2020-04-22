#ifndef STRUCT_H
#define STRUCT_H

#include <fstream>
#include <sstream>
#include "framework.h"
#include "utils.h"

enum eCellType  { EMPTY = 255, STAIRS0 = 0, STAIRS1 = 1, HOLE = 2, STAIRS2 = 3, STAIRS3 = 4 ,STAIRS4 = 5,STAIRS5 = 6,STAIRS6 = 7, STAIRS7 = 8, STAIRS8 = 9, STAIRS9 = 10, TELEPORT = 11, TELEPORT1 = 12, TELEPORT2 = 13, TELEPORT3 = 14, STAIRS10 = 15, CHEST0 = 16, CHEST1 = 17, CHEST2 = 18,  CHEST3 = 19, CHEST4 = 20, STAIRS13 = 151, STAIRS12 = 152, STAIRS11 = 153, CHESTWIN = 181};
enum eItemType  { NOTHING = 0, KEY1, KEY2, KEY3, KEY4, KEY5, KEY6, KEY7, KEY8, KEYWIN, OPEN, SWORD = 200};

class sCell {
public:
    Vector2 pos;
    Vector2 transport;
    eItemType item;
};

class myMap {
public:
    int isFloor[21] = {116, 117, 118, 119, 102, 103, 104, 105, 130, 131, 144, 145, 121, 132, 133, 146, 147, 38, 39, 35, 36};
    int isChest[4] = {136, 137, 150, 151};
    int isDoor[4] = {130, 131, 144, 145};
    int isTeleport[9] = {140,141,142,154,155,156,168,169,170};
    int isRock[4] = {138,139, 152, 153};
    int size_components[2] = { 120, 120 };
    int size = 14400;
    int mapa[14400];
    int demo[14400];
    eCellType objdemo[14400];
    eCellType obj[14400];
    sCell celdasdemo[14400];
    sCell celdas[14400];
};

class myPlayer {
public:
    enum {FACE_DOWN, FACE_RIGHT, FACE_LEFT, FACE_UP};
    Vector2 actualpos;
    Vector2 finpos;
    Vector2 camerapos;
    Vector2 camfinpos;
    int ismoving = 0;
    int facing = FACE_DOWN;
    int objpicked = 0;
    eItemType myobj[25];
    int numobj = 0;
};

class myGameData {
public:
    myMap world;
    myPlayer player;
    int demoactive = 0;
    int isplaying = 0;
};

#endif
