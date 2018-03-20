#define INCLUDE_SDL
#include "SDL_include.h"
#include "Component.h"

class Face : Component{

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