#ifndef GAMEOBJECT
#define GAMEOBJECT

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include "Rect.h"
#include <string>
#include <vector>
#include "Component.h"

using namespace std;

class GameObject{
	public:
		GameObject();
		~GameObject();
		void Update(float dt);
		void Render();
		bool IsDead();
		void RequestDelete();
		void AddComponent(Component* cpt);
		void RemoveComponent(Component* cpt);
		void Start();
		Component* GetComponent(string type);
		Rect Box;
		double angleDeg = 0.0;
		
	private:
		bool isDead;
		bool started = false;
		vector<Component*> components;
};

#endif