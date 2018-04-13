#ifndef RECT
#define RECT

class Rect{
	public:
		Rect();
		~Rect();
		float x;
		float y;
		float w;
		float h;
		bool Contains(float X, float Y);
};

#endif