#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"
#include <string>

using namespace std;

class Game{
    public:
        static Game* GetInstance();   /*Na especificação, esses dois métodos retornariam referencias ao invés de ponteiros,*/
        State* GetState();           /*porem eu os fiz assim para que ficasse mais confortavel para eu trabalhar no codigo*/
        SDL_Renderer* GetRenderer();   

        ~Game();
        void Run();

    private:
        static Game* instance;
        SDL_Renderer* renderer;
        State* state;
        SDL_Window* window;
        Game(string title, int width, int height);   
};
