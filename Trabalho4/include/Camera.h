#include "GameObject.h"
#include "Vec2.h"
#include "InputManager.h"

#ifndef CAMERA
#define CAMERA

class Camera{
	public:
		Camera();
		~Camera();
		static void Follow(GameObject* newFocus);
		static void Unfollow();
		static void Update(float dt);
 		static Vec2 pos;
		static Vec2 speed;

	private:
		static GameObject* focus;
		
};

#endif