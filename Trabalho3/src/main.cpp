#include "Game.h"

int main (int argc, char** argv) {
 
    Game* game;

    game = Game::GetInstance();
    game->Run();
    delete game;
 
    return 0;
}