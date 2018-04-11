#ifndef BULLET
#define BULLET

#include <memory>
#include "Component.h"
#include "GameObject.h"
#include "Vec2.h"
#include "Sprite.h"

class Bullet : public Component{
	public:
		Bullet(GameObject* associated, float angle, float speed, int damage, float maxDistance, string sprite);
		~Bullet();
		void Update(float dt);
		void Render();
		bool Is(string type);
		int GetDamage();
	private:
		Vec2 speed;
		float distanceLeft;
		int damage;
};

#endif