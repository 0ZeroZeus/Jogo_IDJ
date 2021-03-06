#ifndef FACE
#define FACE

#define INCLUDE_SDL
#include "SDL_include.h"
#include "Component.h"
#include "Camera.h"
#include "Sound.h"

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