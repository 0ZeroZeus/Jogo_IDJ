#include <cmath>
#define PI 3.14159265

#ifndef VEC2
#define VEC2

class Vec2{
	public:
		Vec2();
		Vec2(int X, int Y);
		~Vec2();
		float x;
		float y;
		Vec2 operator+(Vec2 vec);
		Vec2 operator-(Vec2 vec);
		Vec2 GetRotated(float angulo);
	
};

#endif