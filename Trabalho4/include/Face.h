#define INCLUDE_SDL
#include "SDL_include.h"
#include "TileMap.h"
#include "Camera.h"

#ifndef FACE
#define FACE

class Face : public Component{

public:
	
	Face(GameObject* associated);
	~Face();
	void Damage(int damage);
	void Update(float dt);
	void Render();
	bool Is(string type);

private:
	int hitpoints;
	
};

#endif