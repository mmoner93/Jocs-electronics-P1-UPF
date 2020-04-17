#include "game.h"
#include "utils.h"
#include "input.h"
#include "image.h"
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

Game* Game::instance = NULL;

Image font;
Image minifont;
Image sprite;
Image bgmap;
Image intro;
Color bgcolor(130, 80, 100);

Vector2 playerpos(90,85);
Vector2 playerfinpos(90,85);
Vector2 camerapos;
Vector2 camerafinpos;
int ismoving = 0;
enum {FACE_DOWN, FACE_RIGHT, FACE_LEFT, FACE_UP};
int isFloor[8] = {116, 117, 118, 119, 102, 103, 104, 105};
const int listsize = 20 * 15;
int isplaying = 0;
//std::string file = "data/map.csv";

int * readCSV(string filesrc, int size) { //archivo y tamaño de area
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
    int actualpos = 0;
    while (10 * 7 > actualpos){
        fprintf(stderr, "%d,", mapborder[actualpos]);
        if (actualpos == 0) {
        }
        else if ((actualpos+1) % 10 == 0)
        {
            cout << '\n';
        }
        actualpos += 1;
    }
    return mapborder;
}


enum eCellType : uint8 { EMPTY, NPC, WALL, DOOR, OBJECT};
enum eItemType : uint8 { NOTHING, SWORD, POTION};
enum directions :uint8 {UP,DOWN,LEFT,RIGHT};

struct sCell { // no se usa aun
    eCellType type;
    eItemType item;
};

struct myMap {
    int size_components[2] = { 20,15 };
    int size = 300;
    sCell celdas[300];
    int mapa[300];
    int npcs[300];
};

struct myPlayer {//no se usa aun
    Vector2 pos;
    int life;
    int facing = FACE_DOWN;
};

struct myGame {
    myMap map;
    myPlayer player;
    int actualArea;
};

myGame currentState;


int canMove(Vector2 position) {
    for (int z = 0; z<8; z++) {
        if (currentState.map.mapa[ ((int(playerfinpos.x)*20/160) + 1) + (20 * (int(playerfinpos.y)*15/120) + 2) ] == isFloor[z]) {
            //std::cout << (int(position.x)*20/160) << ',' << (int(position.y)*15/120)+1;
            //std::cout << mapborders[ ((int(playerfinpos.x)*20/160) + 1) + (20 * (int(playerfinpos.y)*15/120) + 2) ] ;
            //std::cout << isFloor[z];
            return 1;
        }
    }
    std::cout << currentState.map.mapa[ ((int(playerfinpos.x)*20/160) + 1) + (20 * (int(playerfinpos.y)*15/120) + 2) ] ;
    return 0;
}

struct sGameInfo {
    Vector2 position;
    int level;
    sGameInfo(Vector2 pos, int l){
        position = pos;
        level = l;
    }
};

void saveGameInfo()
{
    sGameInfo game_info(playerpos, 1);
    //fill here game_info with all game data
    //...
    //save to file
    FILE* fp = fopen("savegame.bin","wb");
    fwrite(&game_info, sizeof(sGameInfo),1,fp);
    fclose(fp);

}

bool loadGameInfo()
{
    sGameInfo game_info(Vector2(0,0),1);

    //load file
    FILE* fp = fopen("savegame.bin","rb");
    if(fp == NULL) //no savegame found
       return false;

    fread(&game_info, sizeof(sGameInfo),1,fp);
    fclose(fp);

    playerpos = game_info.position;

    return true;
}



class Stage
{
public:
    static std::map<std::string, Stage*> s_stages;
    static Stage* current_stage;
    static void changeStage (const char* name){
        current_stage = s_stages[name];
    }
    
    Stage(const char* name) {s_stages[name] = this;}
    virtual void render(Image& fb) {}
    virtual void update(double seconds_elapsed) {}
    
};

Stage* Stage::current_stage = NULL;
std::map<std::string, Stage*> Stage::s_stages;

class IntroStage : public Stage
{
public:
    IntroStage() : Stage("intro"){}
    void render(Image& fb) {
        //fb.fill(Color::BLACK);
        //fb.drawImage(intro, 0, 30, 160, 120);
        fb.drawText("Sock Mate", 50, 10, font);
        //fb.drawText("Press P to play", 50, 50, minifont,4,6);
    }
    
    void update(double seconds_elapsed) {
        if (Input::wasKeyPressed(SDL_SCANCODE_P)) {
            changeStage("play");
        }
        /*if (Stage::current_stage == Stage::s_stages["intro"] && isplaying == 0) {
            Game::instance->synth.playSample("data/music.wav", 0.8, false);
            isplaying = 1;
        }*/
    }
    
};



class MenuStage : public Stage
{
public:
    MenuStage() : Stage("menu") {}
    int menupos = 0;
    double initime = Game::instance->time;
    double time = 2;
    void render(Image& fb) {
        //fb.fill(Color(0,0,0,130));
        Stage::s_stages["play"]->render(fb);
        fb.fillBlend(Color(0,0,0,180));
        fb.drawText("Sock Mate Menu", 30, 10, font);
        fb.drawText("I - Save Game", 50, 50, minifont,4,6);
        fb.drawText("O - Load Game", 50, 65, minifont,4,6);
        fb.drawText("M - Exit menu", 50, 80, minifont,4,6);
        fb.drawText("ESC - Exit Game", 50, 95, minifont,4,6);
        if (menupos == 1) {
            fb.fillBlend(Color(0,0,0,180));
            fb.drawText("Game Saved", 50, 60, minifont,4,6);
            menupos = 0;
        }
        else if (menupos == 2) {
            fb.fillBlend(Color(0,0,0,180));
            fb.drawText("Game Loaded", 50, 60, minifont,4,6);
            menupos = 0;
        }

        
    }
    void update(double seconds_elapsed) {

        if (Input::wasKeyPressed(SDL_SCANCODE_M)) {
            changeStage("play");
        }
        if (Input::wasKeyPressed(SDL_SCANCODE_I)) {
            saveGameInfo();
            menupos = 1;
            time = 0;
        }
        if (Input::wasKeyPressed(SDL_SCANCODE_O)) {
            loadGameInfo();
            menupos = 2;
            time = 0;
        }
    }
    
};



class PlayStage : public Stage
{
public:
    PlayStage() : Stage("play") {}
    void render(Image& fb) {
        fb.fill(Color::GREEN);
        fb.drawImage( bgmap, 0, 0, Area(0, 0, 160, 120));
        fb.drawImage( sprite, playerpos.x, playerpos.y, Area((int (Game::instance->time * 6) % 4) * 14*ismoving,currentState.player.facing * 18,14,18) );
    }
    void update(double seconds_elapsed) {
        Game::instance->synth.samples_playback->stop();
        isplaying = 0;
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
            playerfinpos.y -= speed*seconds_elapsed;
            //camerafinpos.y -= speed*seconds_elapsed;
            ismoving = 1;
            currentState.player.facing = FACE_UP;
        }
        if (Input::isKeyPressed(SDL_SCANCODE_DOWN)) //if key down
        {
            playerfinpos.y += speed*seconds_elapsed;
            //camerafinpos.y += speed*seconds_elapsed;
            ismoving = 1;
            currentState.player.facing = FACE_DOWN;
        }
        
        if (Input::isKeyPressed(SDL_SCANCODE_RIGHT)) //if key up
        {
            playerfinpos.x += speed*seconds_elapsed;
            //camerafinpos.x += speed*seconds_elapsed;
            ismoving = 1;
            currentState.player.facing = FACE_RIGHT;
        }
        if (Input::isKeyPressed(SDL_SCANCODE_LEFT)) //if key down
        {
            playerfinpos.x -= speed*seconds_elapsed;
            //camerafinpos.x -= speed*seconds_elapsed;
            ismoving = 1;
            currentState.player.facing = FACE_LEFT;
        }
        //playerpos += ( playerfinpos - playerpos ) * 0.1;
        //if (playerfinpos.x != playerpos.x || playerfinpos.y != playerpos.y) {
            if (canMove(playerfinpos)) {
                playerpos += ( playerfinpos - playerpos ) * 0.1;
            }
            else if (canMove( Vector2( playerfinpos.x, playerpos.y))) {
                playerpos += (Vector2( playerfinpos.x, playerpos.y) - playerpos ) * 0.1;
                playerfinpos = Vector2(playerfinpos.x, playerpos.y);
            }
            else if (canMove( Vector2( playerpos.x, playerfinpos.y))) {
                playerpos += (Vector2( playerpos.x, playerfinpos.y) - playerpos ) * 0.1;
                playerfinpos = Vector2(playerpos.x, playerfinpos.y);
            }
        //}
        //std::cout << (int(playerfinpos.x)*20/160) + 1 << ',' << (int(playerfinpos.y)*15/120) + 2;
        //std::cout << mapborders[ ((int(playerfinpos.x)*20/160) + 1) + (20 * (int(playerfinpos.y)*15/120) + 2) ] ;
        //std::cout << mapborders[ (11 + 20*11) ] ;
        if (fabs((playerfinpos - playerpos).y) < 2 && fabs((playerfinpos - playerpos).x) < 2) {
            ismoving = 0;
        }
        

    }
    
};









IntroStage* intro_stage = NULL;
PlayStage* play_stage = NULL;
Stage* current_stage = NULL;

Game::Game(int window_width, int window_height, SDL_Window* window)
{
	this->window_width = window_width;
	this->window_height = window_height;
	this->window = window;
	instance = this;
	must_exit = false;

	fps = 0;
	frame = 0;
	time = 0.0f;
	elapsed_time = 0.0f;

	font.loadTGA("data/bitmap-font-white.tga"); //load bitmap-font image
	minifont.loadTGA("data/mini-font-white-4x6.tga"); //load bitmap-font image
	sprite.loadTGA("data/spritesheet.tga"); //example to load an sprite
	bgmap.loadTGA("data/lvl1.tga");
    intro.loadTGA("data/introcastle.tga");
    intro.flipY();
	bgmap.flipY();
    
    memcpy(&currentState.map.mapa, readCSV("data/lvl1.csv", 70), 70 * sizeof(int));
    
    Stage::current_stage = new IntroStage();
    new PlayStage();
    new MenuStage();
    
	//enableAudio(); //enable this line if you plan to add audio to your application
	//synth.playSample("data/coin.wav",1,true);
	//synth.osc1.amplitude = 0.5;
}

//what to do when the image has to be draw
void Game::render(void)
{
	//Create a new Image (or we could create a global one if we want to keep the previous frame)
	Image framebuffer(160, 120); //do not change framebuffer size
    //Stage::current_stage->render(framebuffer);
    
	//add your code here to fill the framebuffer
	//...

	//some new useful functions
		//framebuffer.fill( Color::RED );								//fills the image with one color
		//framebuffer.drawLine( 0, 0, 100,100, Color::RED );		//draws a line
		//framebuffer.drawImage( sprite, 0, 0 );					//draws full image
		//framebuffer.drawImage( sprite, 0, 0, framebuffer.width, framebuffer.height );			//draws a scaled image
	
    //intro_stage->render(framebuffer);
    
    
    
    framebuffer.drawImage( bgmap, 0, 0, Area(camerapos.x, camerapos.y, 160, 120));
        //framebuffer.drawImage( sprite, 80, 60, Area((int (time * 6) % 4) * 14*ismoving,facing * 18,14,18) );    //draws only a part of an image
    
        //framebuffer.drawImage( sprite, playerpos.x + camerapos.x, playerpos.y + camerapos.y, Area((int (time * 6) % 4) * 14,facing * 18,14,18) );	//draws only a part of an image
        //framebuffer.drawImage( sprite, playerpos.x + camerapos.x, playerpos.y + camerapos.y, Area( 0,facing * 18,14,18) );    //draws only a part of an image
		//framebuffer.drawText( "Hello World", 0, 0, font );				//draws some text using a bitmap font in an image (assuming every char is 7x9)
		//framebuffer.drawText( toString(time), 1, 10, minifont,4,6);	//draws some text using a bitmap font in an image (assuming every char is 4x6)

	//send image to screen
	showFramebuffer(&framebuffer);
}

void Game::update(double seconds_elapsed)
{
	//Add here your update method
	//...
    
    Stage::current_stage->update(seconds_elapsed);
    
	//camerapos += (camerafinpos - camerapos) * 0.1;

    
	//example of 'was pressed'
	if (Input::wasKeyPressed(SDL_SCANCODE_A)) //if key A was pressed
	{
	}
	if (Input::wasKeyPressed(SDL_SCANCODE_Z)) //if key Z was pressed
	{
	}

	//to read the gamepad state
	if (Input::gamepads[0].isButtonPressed(A_BUTTON)) //if the A button is pressed
	{
	}

	if (Input::gamepads[0].direction & PAD_UP) //left stick pointing up
	{
		bgcolor.set(0, 255, 0);
	}
}

//Keyboard event handler (sync input)
void Game::onKeyDown( SDL_KeyboardEvent event )
{
	switch(event.keysym.sym)
	{
		case SDLK_ESCAPE: must_exit = true; break; //ESC key, kill the app
	}
}

void Game::onKeyUp(SDL_KeyboardEvent event)
{
}

void Game::onGamepadButtonDown(SDL_JoyButtonEvent event)
{

}

void Game::onGamepadButtonUp(SDL_JoyButtonEvent event)
{

}

void Game::onMouseMove(SDL_MouseMotionEvent event)
{
}

void Game::onMouseButtonDown( SDL_MouseButtonEvent event )
{
}

void Game::onMouseButtonUp(SDL_MouseButtonEvent event)
{
}

void Game::onMouseWheel(SDL_MouseWheelEvent event)
{
}

void Game::onResize(int width, int height)
{
    std::cout << "window resized: " << width << "," << height << std::endl;
	glViewport( 0,0, width, height );
	window_width = width;
	window_height = height;
}

//sends the image to the framebuffer of the GPU
void Game::showFramebuffer(Image* img)
{
	static GLuint texture_id = -1;
	static GLuint shader_id = -1;
	if (!texture_id)
		glGenTextures(1, &texture_id);

	//upload as texture
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, img->width, img->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img->pixels);

	glDisable(GL_CULL_FACE); glDisable(GL_DEPTH_TEST); glEnable(GL_TEXTURE_2D);
	float startx = -1.0; float starty = -1.0;
	float width = 2.0; float height = 2.0;

	//center in window
	float real_aspect = window_width / (float)window_height;
	float desired_aspect = img->width / (float)img->height;
	float diff = desired_aspect / real_aspect;
	width *= diff;
	startx = -diff;

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(startx, starty + height);
	glTexCoord2f(1.0, 0.0); glVertex2f(startx + width, starty + height);
	glTexCoord2f(1.0, 1.0); glVertex2f(startx + width, starty);
	glTexCoord2f(0.0, 1.0); glVertex2f(startx, starty);
	glEnd();

	/* this version resizes the image which is slower
	Image resized = *img;
	//resized.quantize(1); //change this line to have a more retro look
	resized.scale(window_width, window_height);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	if (1) //flip
	{
	glRasterPos2f(-1, 1);
	glPixelZoom(1, -1);
	}
	glDrawPixels( resized.width, resized.height, GL_RGBA, GL_UNSIGNED_BYTE, resized.pixels );
	*/
}

//AUDIO STUFF ********************

SDL_AudioSpec audio_spec;

void AudioCallback(void*  userdata,
	Uint8* stream,
	int    len)
{
	static double audio_time = 0;

	memset(stream, 0, len);//clear
	if (!Game::instance)
		return;

	Game::instance->onAudio((float*)stream, len / sizeof(float), audio_time, audio_spec);
	audio_time += len / (double)audio_spec.freq;
}

void Game::enableAudio()
{
	SDL_memset(&audio_spec, 0, sizeof(audio_spec)); /* or SDL_zero(want) */
	audio_spec.freq = 48000;
	audio_spec.format = AUDIO_F32;
	audio_spec.channels = 1;
	audio_spec.samples = 1024;
	audio_spec.callback = AudioCallback; /* you wrote this function elsewhere. */
	if (SDL_OpenAudio(&audio_spec, &audio_spec) < 0) {
		fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
		exit(-1);
	}
	SDL_PauseAudio(0);
}

void Game::onAudio(float *buffer, unsigned int len, double time, SDL_AudioSpec& audio_spec)
{
	//fill the audio buffer using our custom retro synth
	synth.generateAudio(buffer, len, audio_spec);
}
