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

enum eCellType : uint8 { EMPTY, OPENDOOR, CLOSEDDOOR, CHEST, TELEPORT};
enum eItemType : uint8 { NOTHING, KEY1, KEY2, KEY3, KEY4, KEY5, KEY6, KEY7, KEY8, SWORD};

class sCell {
public:
    Vector2 xpos;
    Vector2 ypos;
    eItemType item;
    eCellType cellType;
};

class myMap {
public:
    int isFloor[8] = {116, 117, 118, 119, 102, 103, 104, 105};
    int isChest[4] = {136, 137, 150, 151};
    int isDoor[4] = {24, 25, 38, 39};
    int isTeleport[9] = {140,141,142,154,155,156,168,169,170};
    int isRock[4] = {138,139, 152, 153};
    int size_components[2] = { 120, 120 };
    int size = 14400;
    sCell celdas[14400];
    int mapa[14400];
    int npcs[300];
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
    static int rock(myGameData& currentGame);
    static int door(myGameData& currentGame);
    static int teleport(myGameData& currentGame);
    static int chest(myGameData& currentGame);
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
