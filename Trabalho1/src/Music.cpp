#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "Music.h"

Music::Music(){
    music = nullptr;
}

Music::Music(string file){
    music = nullptr;
    Open(file);
}

Music::~Music(){
    Stop(1500);
    Mix_FreeMusic(music);
}

void Music::Play(int times){
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}  

void Music::Open(string file){
    music = Mix_LoadMUS(file.c_str());
    if(music == nullptr){
        SDL_Log("Unable to initialize texture: %s", SDL_GetError());
        exit(1);
    } 
}
bool Music::IsOpen(){
    if (music == nullptr)
        return(false);
    else
        return(true);
    
}
