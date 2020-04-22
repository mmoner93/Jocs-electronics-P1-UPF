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

class Stage
{
public:
    static std::map<std::string, Stage*> s_stages;
    static Stage* current_stage;
    static void changeStage (const char* name);
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

class IntroMenuStage : public Stage
{
public:
    IntroMenuStage() : Stage("intromenu") {}
    int menupos = 0;
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


class Move : public Stage
{
public:
    Move() : Stage("move") {}
    int menupos = 0;
    //double initime = Game::instance->time;
    double time = 0;
    int blur = 50;
    int print = 0;
    void render(Image& fb,  myGameData& currentGame);
    void update(double seconds_elapsed, myGameData& currentGame);
    
};

class Win : public Stage
{
public:
    Win() : Stage("win") {}
    int isplaying = 0;
    //double initime = Game::instance->time;
    double time = 2;
    void render(Image& fb,  myGameData& currentGame);
    void update(double seconds_elapsed, myGameData& currentGame);
    
};


#endif 
