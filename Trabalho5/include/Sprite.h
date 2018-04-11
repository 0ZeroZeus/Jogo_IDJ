#ifndef SPRITE
#define SPRITE

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <string>
#include "Sound.h"
#include "Vec2.h"
//#include "Game.h"

class Component;

using namespace std;

class Sprite : public Component{
    public:
        Sprite();
        Sprite(GameObject* associated);
        Sprite(GameObject* associated, string file);
        ~Sprite();
        void Open(string file);
        void SetClip(int x, int y, int w, int h);
        void Render();
        void Render(int x, int y);
        int GetWidth();
        int GetHeight();
        bool IsOpen();
        bool Is(string type);
        void SetScaleX(float scaleX, float scaleY);
        Vec2 GetScale();

    private:
        SDL_Texture* texture;
        int width;
        int height;
        Vec2 scale;
        double angle;
        SDL_Rect ClipRect;
};

#endif