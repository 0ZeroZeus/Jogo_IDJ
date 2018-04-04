#include "Sound.h"

Sound::Sound(GameObject* associated)  : Component(associated){
	chunk = nullptr;
	this->associated = associated;
}
Sound::Sound(GameObject* associated, string file)  : Component(associated){
	chunk = nullptr;
	this->associated = associated;
	Open(file);	
}

Sound::~Sound(){
	//o loop abaixo foi criado porque o som estava sendo desalocado antes de tocar
	
	while(!Mix_Playing(channel)){//checa se o som esta tocando, quando ele parar de tocar, desaloca
		if (chunk != nullptr){
			Mix_HaltChannel(channel);
			Mix_FreeChunk(chunk);
		}
	}
}

void Sound::Play (int times){
	channel = Mix_PlayChannel(-1, chunk, times-1);
}

void Sound::Stop(){

	Mix_HaltChannel(channel);
}

void Sound::Open(string file){

	chunk = Mix_LoadWAV(file.c_str());
	if (chunk == nullptr){
    	SDL_Log("Unable to initialize chunk: %s", Mix_GetError());
    	exit(1);
	}
}
bool Sound::IsOpen(){
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