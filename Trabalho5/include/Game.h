#ifndef GAME
#define GAME

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <iostream>
#include "State.h"
#include "InputManager.h"
#include <string>

using namespace std;

class State;

class Game{
    public:
        static Game* GetInstance();
        SDL_Renderer* GetRenderer();
        State* GetState();  
        float GetDeltaTime();   

        ~Game();
        void Run();

    private:
        static Game* instance;
        SDL_Renderer* renderer;
        State* state;
        SDL_Window* window;
        int frameStart = 0;
        float dt;
        void CalculateDeltaTime();
        Game(string title, int width, int height);   
};

#endif