#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Face.h"
#include <memory>

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
        void Input();
        void AddObject(int mouseX, int mouseY);
        Sprite bg;
        Music music;
        bool quitRequested;
        unique_ptr<GameObject> ObjectArray;
};