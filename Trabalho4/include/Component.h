#define INCLUDE_SDL
#include "SDL_include.h"
#include <string>

#ifndef COMPONENT
#define COMPONENT

using namespace std;

class GameObject;

class Component{
	public:
		Component(GameObject* associated);
		virtual ~Component();
		void virtual Update(float dt);
		void virtual Render();
		bool virtual Is(string type);

	protected:
		GameObject* associated;
};

#endif