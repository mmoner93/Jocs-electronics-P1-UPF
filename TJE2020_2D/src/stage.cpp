#include "stage.h"
#include <iostream>


int Stage::canMove(myGameData& currentGame) {
    for (int z = 0; z<8; z++) {
        if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 8 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 16 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isFloor[z]) {
            /*if (debugon) {
                std::cout << (int(position.x)*20/160) << ',' << (int(position.y)*15/120)+1;
                std::cout << currentGame.world.mapa[ ((int(currentGame.player.finpos.x)*20/160) + 1) + (20 * (int(currentGame.player.finpos.y)*15/120) + 2) ] ;
                std::cout << currentGame.world.isFloor[z];
                
            }*/
            return 1;
        }
    }
    return 0;
}

int Stage::rock(myGameData& currentGame) {
    for (int z = 0; z<4; z++) {
        if (currentGame.player.facing == myPlayer::FACE_UP) {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 8 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 8 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isRock[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    <#statements#>
                }*/
                return 1;
            }
        }
        else if (currentGame.player.facing == myPlayer::FACE_DOWN) {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 8 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 24 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isRock[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    statements
                }*/
                return 1;
            }
        }
        else if (currentGame.player.facing == myPlayer::FACE_LEFT) {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 16 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isRock[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    <#statements#>
                }*/
                return 1;
            }
        }
        else {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 16 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 16 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isRock[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    <#statements#>
                }*/
                return 1;
            }
        }
    }
    return 0;
}

int Stage::door(myGameData& currentGame) {
    for (int z = 0; z<4; z++) {
        if (currentGame.player.facing == myPlayer::FACE_UP) {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 8 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 8 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isDoor[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    <#statements#>
                }*/
                return 1;
            }
        }
        else if (currentGame.player.facing == myPlayer::FACE_DOWN) {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 8 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 24 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isDoor[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    statements
                }*/
                return 1;
            }
        }
        else if (currentGame.player.facing == myPlayer::FACE_LEFT) {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 16 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isDoor[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    <#statements#>
                }*/
                return 1;
            }
        }
        else {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 16 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 16 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isDoor[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    <#statements#>
                }*/
                return 1;
            }
        }
    }
    return 0;
}

int Stage::teleport(myGameData& currentGame) {
    for (int z = 0; z<9; z++) {
        if (currentGame.player.facing == myPlayer::FACE_UP) {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 8 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 8 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isTeleport[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    <#statements#>
                }*/
                return 1;
            }
        }
        else if (currentGame.player.facing == myPlayer::FACE_DOWN) {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 8 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 24 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isTeleport[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    statements
                }*/
                return 1;
            }
        }
        else if (currentGame.player.facing == myPlayer::FACE_LEFT) {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 16 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isTeleport[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    <#statements#>
                }*/
                return 1;
            }
        }
        else {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 16 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 16 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isTeleport[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    <#statements#>
                }*/
                return 1;
            }
        }
    }
    return 0;
}

int Stage::chest(myGameData& currentGame) {
    for (int z = 0; z<4; z++) {
        if (currentGame.player.facing == myPlayer::FACE_UP) {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 8 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 8 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isChest[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    <#statements#>
                }*/
                return 1;
            }
        }
        else if (currentGame.player.facing == myPlayer::FACE_DOWN) {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 8 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 24 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isChest[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    statements
                }*/
                return 1;
            }
        }
        else if (currentGame.player.facing == myPlayer::FACE_LEFT) {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 16 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isChest[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    <#statements#>
                }*/
                return 1;
            }
        }
        else {
            if (currentGame.world.mapa[ (((int(currentGame.player.actualpos.x + 16 + currentGame.player.camfinpos.x)*120/960) ) + 120 *((int(currentGame.player.actualpos.y + 16 + currentGame.player.camfinpos.y)*120/960)) ) ] == currentGame.world.isChest[z]) {
                /*if (currentGame.player.) {     Posar si te objecte
                    <#statements#>
                }*/
                return 1;
            }
        }
    }
    return 0;
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
          
          if (rock(currentGame)) {
              cout << "is rock" << Game::instance->time << endl;
              changeStage("menu");
          }
          if (chest(currentGame)) {
              cout << "is chest" << Game::instance->time <<  endl;
              changeStage("dialog");
          }
          if (teleport(currentGame)) {
              cout << "is teleport" << Game::instance->time << endl;
              changeStage("menu");
          }
          if (door(currentGame)) {
              cout << "is door" << Game::instance->time << endl;
              changeStage("menu");
          }
      }
    Vector2 difpos = currentGame.player.camfinpos - currentGame.player.camerapos;
    if (fabs(difpos.y) < 2 && fabs((difpos).x) < 2) {
        currentGame.player.ismoving = 0;
    }
}

void MenuStage::render(Image& fb,  myGameData& currentGame) {
    //fb.fill(Color(0,0,0,130));
    Stage::s_stages["play"]->render(fb, currentGame);
    fb.fillBlend(Color(0,0,0,180));
    fb.drawText("Sock Mate Menu", 30, 10, Game::instance->font);
    fb.drawText("I - Save Game", 50, 50, Game::instance->minifont,4,6);
    fb.drawText("O - Load Game", 50, 65, Game::instance->minifont,4,6);
    fb.drawText("M - Exit menu", 50, 80, Game::instance->minifont,4,6);
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

    if (Input::wasKeyPressed(SDL_SCANCODE_M)) {
        changeStage("play");
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_I)) {
        SaveLoad::saveGameInfo();
        menupos = 1;
        time = 0;
    }
    if (Input::wasKeyPressed(SDL_SCANCODE_O)) {
        SaveLoad::loadGameInfo();
        menupos = 2;
        time = 0;
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
