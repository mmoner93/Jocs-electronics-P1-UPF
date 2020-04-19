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

enum eCellType : uint8 { EMPTY, WALL, DOOR, OBJECT, PJ};
enum eItemType : uint8 { NOTHING, KEY1, KEY2};

class sCell {
public:
    eCellType type;
    eItemType item;
};

class myMap {
public:
    int isFloor[8] = {116, 117, 118, 119, 102, 103, 104, 105};
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
    static int canMove(Vector2 position, myGameData& currentGame);
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


#endif 
