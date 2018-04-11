#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"
#include <string>

using namespace std;

class Game{
    public:
        static Game* GetInstance();
        SDL_Renderer* GetRenderer();
        State* GetState();     

        ~Game();
        void Run();

    private:
        static Game* instance;
        SDL_Renderer* renderer;
        State* state;
        SDL_Window* window;
        Game(string title, int width, int height);   
};