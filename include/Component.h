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
		void virtual Update(float dt) = 0;
		void virtual Render() = 0;
		bool virtual Is(string type) = 0;

	protected:
		GameObject* associated;
};

#endif