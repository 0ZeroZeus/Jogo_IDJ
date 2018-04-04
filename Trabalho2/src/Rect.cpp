#include "Rect.h"

Rect::Rect(){}
Rect::~Rect(){}
bool Rect::Contains(float X, float Y){
	return((X > x) && (X < x+w) && (Y > y) && (Y < y+h));
}