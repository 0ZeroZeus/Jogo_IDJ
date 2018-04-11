#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"
#include "InputManager.h"
#include <string>

using namespace std;

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