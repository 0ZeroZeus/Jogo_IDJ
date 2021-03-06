#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"

using namespace std;

class State{
    public:
        State();
        ~State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();

    private:
        Sprite bg;
        Music music;
        bool quitRequested;
};