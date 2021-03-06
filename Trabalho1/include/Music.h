#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <string>

using namespace std;

class Music{
    public:
        Music();
        Music(string file);
        ~Music();
        
        void Play(int times);
        void Stop(int msToStop);
        void Open(string file);
        bool IsOpen();

    private:
        Mix_Music* music;
};