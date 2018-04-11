#ifndef COMPONENT
#define COMPONENT

#define INCLUDE_SDL
#include "SDL_include.h"
#include <string>

using namespace std;

class GameObject;

class Component{
	public:
		Component(GameObject* associated);
		virtual ~Component();
		void virtual Update(float dt);
		void virtual Render();
		bool virtual Is(string type);
		void virtual Start();

	protected:
		GameObject* associated;
};

#endif