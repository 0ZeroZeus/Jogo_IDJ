#ifndef MINION
#define MINION

#include <memory>
#include "Component.h"
#include "GameObject.h"
#include "Vec2.h"
#include "Sprite.h"
#include "Bullet.h"
#include "Game.h"

class Minion : public Component{

	public:
		
		Minion(GameObject* associated, weak_ptr< GameObject > alienCenter, float arcOffsetDeg = 0);
		~Minion();
		void Update(float dt);
		void Render();
		bool Is(string type);
		void Shoot(Vec2 target);
		void SetArc(float val);

	private:
		weak_ptr<GameObject> alienCenter;
		float arc = 0;
	
};

#endif