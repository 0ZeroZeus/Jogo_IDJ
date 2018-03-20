#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "Game.h"
#include <iostream>

Game* Game::instance = nullptr;

Game* Game::GetInstance(){
	if (instance == nullptr){
		instance = new Game("RafaelCampos 14/0159401", 1024, 600);
	}
	return(instance);
}

State* Game::GetState(){
	return(state);
}

SDL_Renderer* Game::GetRenderer(){
	return(renderer);
}

void Game::Run(){

	bool quit = false;
	state->LoadAssets();
	
	while(!quit){
		quit = state->QuitRequested();
		
		state->Update(0);
		state->Render();
		SDL_RenderPresent(renderer);

		SDL_Delay(33);
	}
}

Game::~Game(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

Game::Game(string title, int width, int height){
	if (instance == nullptr){
		instance = this;
	}

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
    	SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    	exit(1);
	}

	
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0) {
    	SDL_Log("Unable to initialize IMG: %s", IMG_GetError());
    	exit(1);
	}
	
	Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_AllocateChannels(32);
	
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	if(window == 0) {
    	SDL_Log("Unable to initialize window: %s", SDL_GetError());
    	exit(1);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == 0) {
    	SDL_Log("Unable to initialize renderer: %s", SDL_GetError());
    	exit(1);
	}

	state = new State();

}