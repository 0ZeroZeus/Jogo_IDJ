#ifndef STATE
#define STATE

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <memory>
#include "Component.h"
#include "GameObject.h"
#include "Face.h"
#include "Vec2.h"
#include "TileMap.h"
#include "InputManager.h"
#include "Camera.h"
#include "CameraFollower.h"
#include "Music.h"
#include "Game.h"
#include "Alien.h"

using namespace std;

class State{
    public:
        State();
        ~State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
        void Start();
        weak_ptr<GameObject> AddObject(GameObject* go);
        weak_ptr<GameObject> GetObjectPtr(GameObject* go);

    private:
        bool started = false;
        void AddObject(int mouseX, int mouseY);
        Music music;
        bool quitRequested;
        vector<shared_ptr<GameObject>> ObjectArray;
};

#endif