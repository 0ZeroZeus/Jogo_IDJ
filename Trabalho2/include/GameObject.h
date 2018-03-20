#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include "Component.h"
#include <string>
#include <vector>

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
		Component* GetComponent(string type);
		SDL_Rect Box;
		
	private:
		bool isDead;
		vector<Component*> components;
};