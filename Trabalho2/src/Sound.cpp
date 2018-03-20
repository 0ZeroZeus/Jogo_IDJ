#include "Sound.h"

Sound::Sound(GameObject* associated)  : Component(associated){

}
Sound::Sound(GameObject* associated, string file)  : Component(associated){

	Open(file);	
}

Sound::~Sound(){

	Mix_FreeChunk(chunk);
}

void Sound::Play (int times){
	channel = Mix_PlayChannel(-1, chunk, times-1);
}

void Sound::Stop (){

	Mix_HaltChannel(channel);
}

void Sound::Open (string file){

	chunk = Mix_LoadWAV(file.c_str());
	if (chunk == nullptr){
    	SDL_Log("Unable to initialize chunk: %s", Mix_GetError());
    	exit(1);
	}
}
bool Sound::IsOpen (){
	if (chunk == nullptr)
        return(false);
    else
        return(true);
}
void Sound::Update(float dt){}
void Sound::Render(){}
bool Sound::Is(string type){
	return(type == "sound");
}