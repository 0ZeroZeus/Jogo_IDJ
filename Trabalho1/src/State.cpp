#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "State.h"

State::State(){

	quitRequested = false;
	music.Open("assets/music/stageState.ogg");
	music.Play(-1);
}

bool State::QuitRequested(){
	return(quitRequested);
}
void State::LoadAssets(){
	bg.Open("assets/img/ocean.jpg");
}
void State::Update(float dt){
	quitRequested = SDL_QuitRequested();
}
void State::Render(){
	bg.Render(0,0);
}