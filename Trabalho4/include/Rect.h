#include "Vec2.h"

#ifndef RECT
#define RECT

class Rect{
	public:
		Rect();
		Rect(float X, float Y, float W, float H);
		~Rect();
		float x;
		float y;
		float w;
		float h;
		void Centralize(float X, float Y);
		bool Contains(float X, float Y);
		Vec2 GetCenter();
};

#endif