#define INCLUDE_SDL
#include "SDL_include.h"
#include <string>
#include "GameObject.h"

using namespace std;

class Sprite : Component{
    public:
        Sprite();
        Sprite(string file);
        ~Sprite();
        void Open(string file);
        void SetClip(int x, int y, int w, int h);
        void Render();
        int GetWidth();
        int GetHeight();
        bool IsOpen();

    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect ClipRect;
};