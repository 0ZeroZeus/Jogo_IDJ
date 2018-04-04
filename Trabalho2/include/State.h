#define INCLUDE_SDL
#include "SDL_include.h"
#include "Music.h"
#include "Face.h"
#include "Vec2.h"
#include "Sprite.h"
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
        Music music;
        bool quitRequested;
        vector<unique_ptr<GameObject>> ObjectArray;
};