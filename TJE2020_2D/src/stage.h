/*  by Javi Agenjo 2013 UPF  javi.agenjo@gmail.com
	This class encapsulates the game, is in charge of creating the game, getting the user input, process the update and render.
*/

#ifndef STAGE_H
#define STAGE_H

#include <fstream>
#include "utils.h"
#include "input.h"
#include "image.h"
#include "game.h"
#include "saveload.h"
#include <cmath>

using namespace std;

enum eCellType  { EMPTY = 255, STAIRS0 = 0, STAIRS1 = 1, HOLE = 2, STAIRS2 = 3, STAIRS3 = 4 ,STAIRS4 = 5,STAIRS5 = 6,STAIRS6 = 7, STAIRS7 = 8, STAIRS8 = 9, STAIRS9 = 10, TELEPORT = 11, TELEPORT1 = 12, TELEPORT2 = 13, TELEPORT3 = 14, STAIRS10 = 15, CHEST0 = 16, CHEST1 = 17, CHEST2 = 18,  CHEST3 = 19, CHEST4 = 20};
enum eItemType  { NOTHING = 0, KEY1, KEY2, KEY3, KEY4, KEY5, KEY6, KEY7, KEY8, OPEN, CLOSED};

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
    eCellType obj[14400];
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
    int life;
    eItemType myobj[25];
    int numobj = 0;
};

class myGameData {
public:
    myMap world;
    myPlayer player;
    int actualArea;
    int isplaying = 0;
};



class Stage
{
public:
    
    static std::map<std::string, Stage*> s_stages;
    static Stage* current_stage;
    void changeStage (const char* name);
    static int canMove(myGameData& currentGame);
    static int chest(myGameData& currentGame);
    static int teleport(myGameData& currentGame);
    static int stairs(myGameData& currentGame);
    static int isopen(myGameData& currentGame);
    Stage(const char* name);
    virtual void render(Image& fb,  myGameData& currentGame) {}
    virtual void update(double seconds_elapsed, myGameData& currentGame) {}
};


class IntroStage : public Stage
{
public:
    IntroStage() : Stage("intro"){}
    void render(Image& fb, myGameData& currentGame);
    void update(double seconds_elapsed, myGameData& currentGame);
};

class PlayStage : public Stage
{
public:
    Image bgmap;
    PlayStage() : Stage("play") {}
    void render(Image& fb, myGameData& currentGame);
    void update(double seconds_elapsed, myGameData& currentGame);
    
};


class MenuStage : public Stage
{
public:
    MenuStage() : Stage("menu") {}
    int menupos = 0;
    //double initime = Game::instance->time;
    double time = 2;
    void render(Image& fb,  myGameData& currentGame);
    void update(double seconds_elapsed, myGameData& currentGame);
    
};

class Dialog : public Stage
{
public:
    Dialog() : Stage("dialog") {}
    int menupos = 0;
    //double initime = Game::instance->time;
    double time = 2;
    void render(Image& fb,  myGameData& currentGame);
    void update(double seconds_elapsed, myGameData& currentGame);
    
};


#endif 
