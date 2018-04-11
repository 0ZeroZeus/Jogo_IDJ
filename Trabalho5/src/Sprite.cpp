#include "Game.h"

Sprite::Sprite() : Component(associated){
	texture = nullptr;
	scale.x = 1;
	scale.y = 1;
	angle = 0;
}

Sprite::Sprite(GameObject* associated) : Component(associated){
	texture = nullptr;
	scale.x = 1;
	scale.y = 1;
	angle = 0;
}

Sprite::Sprite(GameObject* associated, string file) : Component(associated){
	texture = nullptr;
	scale.x = 1;
	scale.y = 1;
	angle = 0;
	Open(file);
}

Sprite::~Sprite(){}

void Sprite::Open(string file){

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
	dstrect.w = ClipRect.w*scale.x;
	dstrect.h = ClipRect.h*scale.y;
	angle = associated->angleDeg;

	int aux = SDL_RenderCopyEx(game->GetRenderer(), texture, &ClipRect, &dstrect, angle, nullptr, SDL_FLIP_NONE);
	if (aux < 0){
		SDL_Log("Unable to initialize texture: %s", SDL_GetError());
	}

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
	return(width*scale.x);
}
int Sprite::GetHeight(){
	return(height*scale.y);
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

void Sprite::SetScaleX(float scaleX, float scaleY){
	if(scaleX != 0)
		scale.x = scaleX;
	if(scaleY != 0)
		scale.y = scaleY;

	Vec2 aux = associated->Box.GetCenter();
	associated->Box.w *= scaleX;
	associated->Box.h *= scaleY;
	associated->Box.Centralize(aux.x,aux.y);
}
Vec2 Sprite::GetScale(){
	return(scale);
}