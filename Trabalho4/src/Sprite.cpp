#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "Game.h"

Sprite::Sprite() : Component(associated){
	texture = nullptr;
}

Sprite::Sprite(GameObject* associated) : Component(associated){
	texture = nullptr;
}

Sprite::Sprite(GameObject* associated, string file) : Component(associated){
	texture = nullptr;
	Open(file);
}

Sprite::~Sprite(){}

void Sprite::Open(string file){
	Game* game = Game::GetInstance();

	texture = Resources::GetImage(file);

	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h){

	ClipRect.x = x;
	ClipRect.y = y;
	ClipRect.w = w;
	ClipRect.h = h;
}

void Sprite::Render(){

	Game* game = Game::GetInstance();
	SDL_Rect dstrect;
	dstrect.x = associated->Box.x + Camera::pos.x;
	dstrect.y = associated->Box.y + Camera::pos.y;
	dstrect.w = ClipRect.w;
	dstrect.h = ClipRect.h;

	SDL_RenderCopy(game->GetRenderer(), texture, &ClipRect, &dstrect);
}

void Sprite::Render(int x, int y){

	Game* game = Game::GetInstance();
	SDL_Rect dstrect;
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = ClipRect.w;
	dstrect.h = ClipRect.h;

	SDL_RenderCopy(game->GetRenderer(), texture, &ClipRect, &dstrect);
}


int Sprite::GetWidth(){
	return(width);
}
int Sprite::GetHeight(){
	return(height);
}
bool Sprite::IsOpen(){
	if (texture == nullptr)
		return(false);
	else
		return(true);
}

bool Sprite::Is(string type){
	return(type == "sprite");
}

