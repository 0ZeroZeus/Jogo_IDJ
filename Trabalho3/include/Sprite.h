#define INCLUDE_SDL
#include "SDL_include.h"
#include <string>
#include "Sound.h"

#ifndef SPRITE
#define SPRITE

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

    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect ClipRect;
};

#endif