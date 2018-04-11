#ifndef ALIEN
#define ALIEN

#define INCLUDE_SDL
#include "SDL_include.h"
#include <memory>
#include <queue>
#include "Component.h"
#include "Vec2.h"
#include "Sprite.h"
#include "InputManager.h"
#include "Camera.h"
#include "Minion.h"
#include "Game.h"
#include "GameObject.h"

class Alien : public Component{
	public:
		Alien(GameObject* associated, int nMinions);
		~Alien();
		void Start();
		void Update(float dt);
		void render();
		bool Is(string type);

	private:
		class Action{
			public:
				typedef enum ActionType {MOVE, SHOOT} ActionType;
				Action(ActionType type, float x, float y);
				ActionType type;
				Vec2 pos;
		};

		Vec2 speed;
		int hp;
		int nMinions;
		queue<Action> taskQueue;
		vector<shared_ptr<GameObject>> minionArray;	
};

#endif