#include "stage.h"
#include <iostream>

Vector2 celdaspos(myGameData& currentGame, int a, int b){
    return Vector2((int(currentGame.player.actualpos.x + a + currentGame.player.camfinpos.x)*120/960) ,((int(currentGame.player.actualpos.y + b + currentGame.player.camfinpos.y)*120/960)));
}

int Stage::canMove(myGameData& currentGame) {
    Vector2 aux = celdaspos(currentGame, 8, 16);
    for (int z = 0; z<21; z++) {
        if (currentGame.world.mapa[int(aux.x) + 120 *int(aux.y) ] == currentGame.world.isFloor[z]) {
            return 1;
        }
    }
    return 0;
}

int Stage::chest(myGameData& currentGame) {
    bool move = false;
    int num = currentGame.player.numobj;
    Vector2 aux;
    for (int z = 0; z<4; z++) {
        if (currentGame.player.facing == myPlayer::FACE_UP) {
            aux = celdaspos(currentGame, 8, 8);
            if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST0) {
                move = true;
            }
            else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST1) {
                move = true;
            }
            else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST2) {
                move = true;
            }
            else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST3) {
                move = true;
            }
        }
        else if (currentGame.player.facing == myPlayer::FACE_DOWN) {
            aux = celdaspos(currentGame, 8, 24);
            if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST0) {
                move = true;
            }
            else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST1) {
                move = true;
            }
            else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST2) {
                move = true;
            }
            else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST3) {
                move = true;
            }
        }
        else if (currentGame.player.facing == myPlayer::FACE_LEFT) {
            aux = celdaspos(currentGame, 0, 16);
            if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST0) {
                move = true;
            }
            else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST1) {
                move = true;
            }
            else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST2) {
                move = true;
            }
            else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST3) {
                move = true;
            }
        }
        else {
            aux = celdaspos(currentGame, 16, 16);
            if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST0) {
                move = true;
            }
            else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST1) {
                move = true;
            }
            else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST2) {
                move = true;
            }
            else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == CHEST3) {
                move = true;
            }
        }
    }
    if (move){
        currentGame.player.myobj[num] = currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y)].item;
        currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y)].item  = NOTHING;
        num++;
        std::cout << currentGame.world.celdas[ int(aux.x) + 120 *int(aux.y)].item << endl;
        currentGame.player.numobj = num;
        
    }
    return 0;
}


int Stage::teleport(myGameData& currentGame) {
    bool move = false;
    Vector2 aux;
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
        currentGame.player.camerapos = currentGame.world.celdas[int(aux.x) + 120 *int(aux.y) ].transport;
        currentGame.player.camfinpos = currentGame.world.celdas[int(aux.x) + 120 *int(aux.y) ].transport;
    }
    return 0;
}

int Stage::isopen(myGameData& currentGame) {
    Vector2 aux = celdaspos(currentGame, 8, 16);
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
    else {return 0;}
}

int Stage::stairs(myGameData& currentGame) {
    bool move = false;
    Vector2 aux = celdaspos(currentGame, 8, 16);
    if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS0) {
        if (isopen(currentGame)) {
            move = true;
        }
        else {/*misatge esta tancat*/}
        
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
        else {/*misatge esta tancat*/}
    }
    else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS7) {
        move = true;
    }
    else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS8) {
        move = true;
    }
    else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS9) {
        move = true;
    }
    else if (currentGame.world.obj[ int(aux.x) + 120 *int(aux.y) ] == STAIRS10) {
        move = true;
    }
    if (move){
        currentGame.player.camerapos = currentGame.world.celdas[int(aux.x) + 120 *int(aux.y) ].transport;
        currentGame.player.camfinpos = currentGame.world.celdas[int(aux.x) + 120 *int(aux.y) ].transport;
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
    fb.drawText("Press P to play", 50, 50, Game::instance->minifont,4,6);
}

void IntroStage::update(double seconds_elapsed, myGameData& currentGame) {
    if (Input::wasKeyPressed(SDL_SCANCODE_P)) {
        changeStage("play");
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
    if (Input::wasKeyPressed(SDL_SCANCODE_P)) {
        changeStage("intro");
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_M)) {
        changeStage("menu");
    }
    int speed = 40;
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
    if (Input::wasKeyPressed(SDL_SCANCODE_A)) {
          
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
    fb.drawText("ESC - Exit Game", 50, 95, Game::instance->minifont,4,6);
    if (menupos == 1 && time < 2) {
        fb.fillBlend(Color(0,0,0,180));
        fb.drawText("Game Saved", 50, 60, Game::instance->minifont,4,6);
        menupos = 0;
    }
    else if (menupos == 2 && time < 2) {
        fb.fillBlend(Color(0,0,0,180));
        fb.drawText("Game Loaded", 50, 60, Game::instance->minifont,4,6);
        menupos = 0;
    }

}

void MenuStage::update(double seconds_elapsed, myGameData& currentGamep) {

    if (Input::wasKeyPressed(SDL_SCANCODE_UP)) {
        menupos -= 1;
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_DOWN)) {
        SaveLoad::saveGameInfo();
        menupos += 1;
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_A)) {
        if (menupos == 0) {
            SaveLoad::saveGameInfo();
        }
        else if (menupos == 1) {
            SaveLoad::loadGameInfo();
        }
        else {
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
    fb.drawText("soy un dialogo!", 80, 55, Game::instance->minifont, 4, 6);
}

void Dialog::update(double seconds_elapsed, myGameData& currentGamep) {

    if (Input::wasKeyPressed(SDL_SCANCODE_S)) {
        changeStage("play");
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_A)) {
        cout << "key a " << endl;
    }
}
