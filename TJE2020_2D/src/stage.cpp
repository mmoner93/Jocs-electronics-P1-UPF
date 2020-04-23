#include "stage.h"
#include <iostream>

Vector2 celdaspos(myGameData& currentGame, int a, int b){
    return Vector2((int(currentGame.player.actualpos.x + a + currentGame.player.camfinpos.x)*120/960) ,((int(currentGame.player.actualpos.y + b + currentGame.player.camfinpos.y)*120/960)));
}

int Stage::canMove(myGameData& currentGame) {
    Vector2 aux = celdaspos(currentGame, 8, 16);
    if (currentGame.demoactive == 0) {
            for (int z = 0; z<21; z++) {
            if (currentGame.world.mapa[int(aux.x) + 120 *int(aux.y) ] == currentGame.world.isFloor[z]) {
                return 1;
            }
        }
    }
    else{
        for (int z = 0; z<21; z++) {
            if (currentGame.world.demo[int(aux.x) + 120 *int(aux.y) ] == currentGame.world.isFloor[z]) {
                return 1;
            }
        }

    }
    return 0;
}

int Stage::chest(myGameData& currentGame) {
    bool move = false;
    int num = currentGame.player.numobj;
    Vector2 aux;
    if (currentGame.demoactive == 0) {
        for (int z = 0; z<4; z++) {
            if (currentGame.player.facing == myPlayer::FACE_UP) {
                aux = celdaspos(currentGame, 8, 8);
                if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST0) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST1) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST2) {
                    move = true;
                    std::cout << currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item << endl;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST3) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST4) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHESTWIN) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
            }
            else if (currentGame.player.facing == myPlayer::FACE_DOWN) {
                aux = celdaspos(currentGame, 8, 24);
                if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST0) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST1) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST2) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST3) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST4) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
            }
            else if (currentGame.player.facing == myPlayer::FACE_LEFT) {
                aux = celdaspos(currentGame, 0, 16);
                if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST0) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST1) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST2) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST3) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST4) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
            }
            else {
                aux = celdaspos(currentGame, 16, 16);
                if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST0) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST1) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST2) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST3) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST4) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
            }
        }
    }
    else{
        for (int z = 0; z<4; z++) {
            if (currentGame.player.facing == myPlayer::FACE_UP) {
                aux = celdaspos(currentGame, 8, 8);
                if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == CHEST0) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == CHESTWIN) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
            }
            else if (currentGame.player.facing == myPlayer::FACE_DOWN) {
                aux = celdaspos(currentGame, 8, 24);
                if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == CHEST0) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == CHESTWIN) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
            }
            else if (currentGame.player.facing == myPlayer::FACE_LEFT) {
                aux = celdaspos(currentGame, 0, 16);
                if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == CHEST0) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == CHESTWIN) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
            }
            else {
                aux = celdaspos(currentGame, 16, 16);
                if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == CHEST0) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
                else if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == CHESTWIN) {
                    move = true;
                    currentGame.player.objpicked = currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y) ].item;
                    currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] = EMPTY;
                }
            }
        }
    }
    if (move && currentGame.demoactive == 0){
        currentGame.player.myobj[num] = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y)].item;
        currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y)].item  = NOTHING;
        num++;
        std::cout << currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y)].item << endl;
        currentGame.player.numobj = num;
        if (currentGame.player.objpicked == KEYWIN) {
            changeStage("win");
        }
        else {
            changeStage("dialog");
        }
    }
    if (move && currentGame.demoactive == 1){
        currentGame.player.myobj[num] = currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y)].item;
        currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y)].item  = NOTHING;
        num++;
        std::cout << currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y)].item << endl;
        currentGame.player.numobj = num;
        if (currentGame.player.objpicked == KEYWIN) {
            changeStage("win");
        }
        else {
            changeStage("dialog");
        }
    }
    return 0;
}


int Stage::teleport(myGameData& currentGame) {
    bool move = false;
    Vector2 aux;
    if (currentGame.demoactive == 0) {
        for (int z = 0; z<4; z++) {
            if (currentGame.player.facing == myPlayer::FACE_UP) {
                aux = celdaspos(currentGame, 8, 8);
                if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT) {
                    move = true;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT1) {
                    move = true;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT2) {
                    move = true;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT3) {
                    move = true;
                }
            }
            else if (currentGame.player.facing == myPlayer::FACE_DOWN) {
                aux = celdaspos(currentGame, 8, 24);
                if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT) {
                    move = true;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT1) {
                    move = true;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT2) {
                    move = true;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT3) {
                    move = true;
                }
            }
            else if (currentGame.player.facing == myPlayer::FACE_LEFT) {
                aux = celdaspos(currentGame, 0, 16);
                if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT) {
                    move = true;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT1) {
                    move = true;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT2) {
                    move = true;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT3) {
                    move = true;
                }
            }
            else {
                aux = celdaspos(currentGame, 16, 16);
                if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT) {
                    move = true;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT1) {
                    move = true;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT2) {
                    move = true;
                }
                else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT3) {
                    move = true;
                }
            }
        }
        if (move){
            //Game::instance->synth.playSample("data/stairs.wav", 0.2, true);
            currentGame.player.camerapos = currentGame.world.celdas[int(aux.x) + 120 *int(aux.y) ].transport;
            currentGame.player.camfinpos = currentGame.world.celdas[int(aux.x) + 120 *int(aux.y) ].transport;
            //Game::instance->synth.playSample("data/teleport.wav", 1, false);
        }
    }
    else {
        for (int z = 0; z<4; z++) {
            if (currentGame.player.facing == myPlayer::FACE_UP) {
                aux = celdaspos(currentGame, 8, 8);
                if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT) {
                    move = true;
                }
                else if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT1) {
                    move = true;
                }
            }
            else if (currentGame.player.facing == myPlayer::FACE_DOWN) {
                aux = celdaspos(currentGame, 8, 24);
                if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT) {
                    move = true;
                }
                else if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT1) {
                    move = true;
                }
            }
            else if (currentGame.player.facing == myPlayer::FACE_LEFT) {
                aux = celdaspos(currentGame, 0, 16);
                if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT) {
                    move = true;
                }
                else if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT1) {
                    move = true;
                }
            }
            else {
                aux = celdaspos(currentGame, 16, 16);
                if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT) {
                    move = true;
                }
                else if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == TELEPORT1) {
                    move = true;
                }
            }
        }
        if (move){
            //Game::instance->synth.playSample("data/teleport.wav", 1, false);
            currentGame.player.camerapos = currentGame.world.celdasdemo[int(aux.x) + 120 *int(aux.y) ].transport;
            currentGame.player.camfinpos = currentGame.world.celdasdemo[int(aux.x) + 120 *int(aux.y) ].transport;
        }
    }
    if (move) {
        Game::instance->synth.playSample("data/teleport.wav", 1, false);
    }
    return 0;
}

int Stage::isopen(myGameData& currentGame) {
    Vector2 aux = celdaspos(currentGame, 8, 16);
    if (currentGame.demoactive == 0) {
        if (    currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item == OPEN) {
            return 1;
        }
        else if (    currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item != OPEN) {
            for (int i = 0; i < 25; i++) {
                if (currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y) ].item == currentGame.player.myobj[i]) {
                    return 1;
                }
                
            }
            return 0;
        }

    }
    else if (currentGame.demoactive == 1){
        if (    currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y) ].item == OPEN) {
            return 1;
        }
        else if (    currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y) ].item != OPEN) {
            for (int i = 0; i < 25; i++) {
                if (currentGame.world.celdasdemo[ int(aux.x) + 120 *int(aux.y) ].item == currentGame.player.myobj[i]) {
                    return 1;
                }
                
            }
            return 0;
        }

    }
    return 0;
}

int Stage::stairs(myGameData& currentGame) {
    bool move = false;
    bool anim = true;
    double init = 0;
    Vector2 aux = celdaspos(currentGame, 8, 16);
    if (currentGame.demoactive == 0) {
        if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS0) {
        if (isopen(currentGame)) {
            move = true;
        }
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS1) {
            move = true;
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == HOLE) {
            move = true;
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS2) {
            move = true;
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS3) {
            move = true;
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS4) {
            move = true;
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS5) {
            move = true;
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS6) {
            if (isopen(currentGame)) {
                move = true;
            }
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS7) {
            move = true;
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS8) {
            move = true;
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS9) {
            if (isopen(currentGame)) {
                move = true;
            }
            
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS10) {
            move = true;
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS11) {
            if (isopen(currentGame)) {
                move = true;
            }
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS12) {
            move = true;
        }
        else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS13) {
            move = true;
        }
    }
    else if (currentGame.demoactive == 1){
        if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == STAIRS0) {
            if (isopen(currentGame)) {
                move = true;
            }
        }
        else if (currentGame.world.objdemo[ int(aux.x) + 120 *int(aux.y) ] == STAIRS1) {
            move = true;
        }
    }

    if (move && currentGame.demoactive == 0){
        Game::instance->synth.playSample("data/stairs.wav", 1, false);
        changeStage("move");
        anim = true;
        while (anim) {
            std::cout << init <<endl;
            if (init == 0){
                init = Game::instance->elapsed_time;
            }
            else if (init > 250){
                currentGame.player.camerapos = currentGame.world.celdas[int(aux.x) + 120 *int(aux.y) ].transport;
                currentGame.player.camfinpos = currentGame.world.celdas[int(aux.x) + 120 *int(aux.y) ].transport;
                anim = false;
                init = 0;
            }
            else {init += Game::instance->elapsed_time;}
        }
    }
    if (move && currentGame.demoactive == 1){
        Game::instance->synth.playSample("data/stairs.wav", 1, false);
        changeStage("move");
        anim = true;
        while (anim) {
            std::cout << init <<endl;
            if (init == 0){
                init = Game::instance->elapsed_time;
            }
            else if (init > 250){
                currentGame.player.camerapos = currentGame.world.celdasdemo[int(aux.x) + 120 *int(aux.y) ].transport;
                currentGame.player.camfinpos = currentGame.world.celdasdemo[int(aux.x) + 120 *int(aux.y) ].transport;
                anim = false;
                init = 0;
            }
            else {init += Game::instance->elapsed_time;}
        }
    }

    return 1;
}




void Stage::changeStage (const char* name){
    current_stage = s_stages[name];
}

Stage::Stage(const char* name) {
    s_stages[name] = this;
}

void IntroStage::render(Image& fb,  myGameData& currentGame) {
    fb.fill(Color::BLACK);
    fb.drawImage(Game::instance->intro, 0, 30, 160, 120);
    fb.drawText("Sock Mate", 50, 10, Game::instance->font);
    fb.drawText("Press Z to start", 50, 50, Game::instance->minifont,4,6);
}

void IntroStage::update(double seconds_elapsed, myGameData& currentGame) {
    if (Input::wasKeyPressed(SDL_SCANCODE_Z)) {
        changeStage("intromenu");
    }
    if (currentGame.isplaying == 0) {
        Game::instance->synth.playSample("data/music.wav", 0.2, true);
        currentGame.isplaying = 1;
    }
}

void PlayStage::render(Image& fb, myGameData& currentGame) {
    fb.fill(Color::GREEN);
    //fb.drawMap(Game::instance->tiles, currentGame.world.mapa, currentGame.world.size_components, 1, currentGame.player.actualpos);
    //fb.drawImage(bgmap, 0, 0, 160, 120);
    //bgmap.drawMap(Game::instance->tiles, currentGame.world.mapa, currentGame.world.size_components, 1, currentGame.player.actualpos);
    fb.drawImage(Game::instance->bgmap, 0, 0, Area(currentGame.player.camerapos.x,currentGame.player.camerapos.y,160,120));
    fb.drawImage( Game::instance->sprite, currentGame.player.actualpos.x, currentGame.player.actualpos.y, Area((int (Game::instance->time * 6) % 4) * 14*currentGame.player.ismoving,currentGame.player.facing * 18,14,18) );
}

void PlayStage::update(double seconds_elapsed, myGameData& currentGame) {
    Game::instance->synth.samples_playback->stop();
    currentGame.isplaying = 0;
    if (Input::wasKeyPressed(SDL_SCANCODE_R)) {
        changeStage("intro");
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_X)) {
        changeStage("menu");
    }
    int speed = 80;
    //Read the keyboard state, to see all the keycodes: https://wiki.libsdl.org/SDL_Keycode
    if (Input::isKeyPressed(SDL_SCANCODE_UP)) //if key up
    {
        //currentGame.player.finpos.y -= speed*seconds_elapsed;
        
        currentGame.player.camfinpos.y -= speed*seconds_elapsed;
        currentGame.player.ismoving = 1;
        currentGame.player.facing = currentGame.player.FACE_UP;
    }
    if (Input::isKeyPressed(SDL_SCANCODE_DOWN)) //if key down
    {
        //currentGame.player.finpos.y += speed*seconds_elapsed;
        currentGame.player.camfinpos.y += speed*seconds_elapsed;
        currentGame.player.ismoving = 1;
        currentGame.player.facing = currentGame.player.FACE_DOWN;
    }
    
    if (Input::isKeyPressed(SDL_SCANCODE_RIGHT)) //if key up
    {
        //currentGame.player.finpos.x += speed*seconds_elapsed;
        currentGame.player.camfinpos.x += speed*seconds_elapsed;
        currentGame.player.ismoving = 1;
        currentGame.player.facing = currentGame.player.FACE_RIGHT;
    }
    if (Input::isKeyPressed(SDL_SCANCODE_LEFT)) //if key down
    {
        //currentGame.player.finpos.x -= speed*seconds_elapsed;
        currentGame.player.camfinpos.x -= speed*seconds_elapsed;
        currentGame.player.ismoving = 1;
        currentGame.player.facing = currentGame.player.FACE_LEFT;
    }
    
  
    
    //camerapos += ( camfinpos - camerapos ) * 0.1;
    //std::cout << bgmap.height << ", " << bgmap.width << std::endl;
    if (canMove(currentGame)) {
        currentGame.player.camerapos += ( currentGame.player.camfinpos - currentGame.player.camerapos ) * 0.1;
    }
    else {
        currentGame.player.camfinpos = currentGame.player.camerapos;
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_Z)) {
          
          if (chest(currentGame)) {
              cout << "is chest" << Game::instance->time <<  endl;
              changeStage("dialog");
          }
          if (teleport(currentGame)) {
              cout << "is chest" << Game::instance->time <<  endl;
              //changeStage("dialog");
          }
    }
    stairs(currentGame);
    Vector2 difpos = currentGame.player.camfinpos - currentGame.player.camerapos;
    if (fabs(difpos.y) < 2 && fabs((difpos).x) < 2) {
        currentGame.player.ismoving = 0;
    }
}

void MenuStage::render(Image& fb,  myGameData& currentGame) {
    //fb.fill(Color(0,0,0,130));
    Stage::s_stages["play"]->render(fb, currentGame);
    fb.fillBlend(Color(0,0,0,180));
    fb.drawLine(50, menupos*15+57, 115, menupos*15+57, Color::YELLOW);
    fb.drawText("Sock Mate Menu", 30, 10, Game::instance->font);
    fb.drawText("    Save Game", 50, 50, Game::instance->minifont,4,6);
    fb.drawText("    Load Game", 50, 65, Game::instance->minifont,4,6);
    fb.drawText("    Exit menu", 50, 80, Game::instance->minifont,4,6);
    fb.drawText("    Main enu", 50, 95, Game::instance->minifont,4,6);
    /*if (menupos == 1 && time < 2) {
        fb.fillBlend(Color(0,0,0,180));
        fb.drawText("Game Saved", 50, 60, Game::instance->minifont,4,6);
        //menupos = 0;
    }
    else if (menupos == 2 && time < 2) {
        fb.fillBlend(Color(0,0,0,180));
        fb.drawText("Game Loaded", 50, 60, Game::instance->minifont,4,6);
        //menupos = 0;
    }*/

}

void MenuStage::update(double seconds_elapsed, myGameData& currentGame) {

    if (Input::wasKeyPressed(SDL_SCANCODE_UP)) {
        menupos -= 1;
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_DOWN)) {
        SaveLoad::saveGameInfo(currentGame);
        menupos += 1;
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_Z)) {
        if (menupos == 0) {
            SaveLoad::saveGameInfo(currentGame);
        }
        else if (menupos == 1) {
            SaveLoad::loadGameInfo(currentGame);
            if (currentGame.demoactive == 0) {
                Game::instance->bgmap = Game::instance->bghouse;
            }
            else {
                Game::instance->bgmap = Game::instance->bgdemo;
            }
        }
        else if(menupos == 2){
            changeStage("play");
        }
        else {
            changeStage("intromenu");
        }
        
    }
    if (menupos < 0) {
        menupos = 0;
    }
    else if (menupos > 3){
        menupos = 3;
    }
    if (time < 2) {
        time += Game::instance->time;
    }
}



void IntroMenuStage::render(Image& fb,  myGameData& currentGame) {
    //fb.fill(Color(0,0,0,130));
    Stage::s_stages["play"]->render(fb, currentGame);
    fb.fillBlend(Color(0,0,0,180));
    fb.drawLine(50, menupos*15+57, 115, menupos*15+57, Color::YELLOW);
    fb.drawText("Sock Mate Menu", 30, 10, Game::instance->font);
    fb.drawText("    New  Game ", 50, 50, Game::instance->minifont,4,6);
    fb.drawText("    Load Game ", 50, 65, Game::instance->minifont,4,6);
    fb.drawText("       DEMO   ", 50, 80, Game::instance->minifont,4,6);
    fb.drawText("ESC - Exit Game", 50, 95, Game::instance->minifont,4,6);
    /*if (menupos == 1 && time < 2) {
        fb.fillBlend(Color(0,0,0,180));
        fb.drawText("Game Saved", 50, 60, Game::instance->minifont,4,6);
        //menupos = 0;
    }
    else if (menupos == 2 && time < 2) {
        fb.fillBlend(Color(0,0,0,180));
        fb.drawText("Game Loaded", 50, 60, Game::instance->minifont,4,6);
        //menupos = 0;
    }*/

}

void IntroMenuStage::update(double seconds_elapsed, myGameData& currentGame) {

    if (Input::wasKeyPressed(SDL_SCANCODE_UP)) {
        menupos -= 1;
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_DOWN)) {
        menupos += 1;
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_Z)) {
        if (menupos == 0) {
            SaveLoad::init(currentGame, 0);
            Game::instance->bgmap = Game::instance->bghouse;
            currentGame.demoactive = 0;
            changeStage("play");
        }
        else if (menupos == 1) {
            SaveLoad::loadGameInfo(currentGame);
            changeStage("play");
        }
        else {
            SaveLoad::init(currentGame, 1);
            Game::instance->bgmap = Game::instance->bgdemo;
            currentGame.demoactive = 1;
            changeStage("play");
        }
        
    }
    if (menupos < 0) {
        menupos = 0;
    }
    else if (menupos > 2){
        menupos = 2;
    }
    if (time < 2) {
        time += Game::instance->time;
        cout << Game::instance->time;
        cout << " " << time;
    }
}



void Dialog::render(Image& fb,  myGameData& currentGame) {
    //fb.fill(Color(0,0,0,130));
    Stage::s_stages["play"]->render(fb, currentGame);
    fb.fillBlend(Color(0,0,0,180));
    fb.drawRectangle(20, 20, 119, 42, Color(200, 200, 200, 230));
    std::cout << currentGame.player.myobj[currentGame.player.objpicked] << endl;
    if (currentGame.player.objpicked == SWORD) {
        fb.drawText("You found a sword", 40, 55, Game::instance->minifont, 4, 6);
    }
    else {fb.drawText("You found a key", 50, 55, Game::instance->minifont, 4, 6);}
}

void Dialog::update(double seconds_elapsed, myGameData& currentGame) {

    if (Input::wasKeyPressed(SDL_SCANCODE_X)) {
        changeStage("play");
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_Z)) {
        cout << "key a " << endl;
    }
}


void Move::render(Image& fb,  myGameData& currentGame) {
    //fb.fill(Color(0,0,0,130));
    Stage::s_stages["play"]->render(fb, currentGame);
    fb.fillBlend(Color(0,0,0,blur));
    //fb.drawRectangle(20, 20, 119, 42, Color(200, 200, 200, 230));
    //fb.drawText("You fond the key" + std::to_string(currentGame.player.objpicked), 80, 55, Game::instance->minifont, 4, 6);
}

void Move::update(double seconds_elapsed, myGameData& currentGame) {
    time += seconds_elapsed;
    blur += blur*time;
    blur = clamp(blur, 50, 255);
    if (time > 2) {
        changeStage("play");
        time = 0;
        blur = 50;
        print = 0;
    }
}


void Win::render(Image& fb,  myGameData& currentGame) {
    //fb.fill(Color(0,0,0,130));
    //Stage::s_stages["play"]->render(fb, currentGame);
    fb.fillBlend(Color(0,0,0,180));
    fb.drawRectangle(20, 20, 119, 42, Color(200, 200, 200, 230));
    fb.drawText("    You Win ", 50, 50, Game::instance->minifont,4,6);
    fb.drawText("Z - To Restart", 50, 95, Game::instance->minifont,4,6);
}

void Win::update(double seconds_elapsed, myGameData& currentGame) {
    if (isplaying == 0) {
        Game::instance->synth.playSample("data/victori.wav", 1, false);
        isplaying = 1;
    }
    
    if (Input::wasKeyPressed(SDL_SCANCODE_Z)) {
        SaveLoad::init(currentGame, 0);
        changeStage("intro");
        isplaying = 0;
    }
}
