#include "Vec2.h"

Vec2::Vec2(){

}

Vec2::Vec2(int X, int Y){
	x = X;
	y = Y;
}

Vec2::~Vec2(){}

Vec2 Vec2::GetRotated(float angulo){
	return( Vec2( (x*cos(angulo) - y*sin(angulo)) , (y*cos(angulo) - x*sin(angulo))) );
}

Vec2 Vec2::operator+(Vec2 vec){
	Vec2 ret;
	ret.x = this->x + vec.x;
	ret.y = this->y + vec.y;
	return(ret);
}
Vec2 Vec2::operator-(Vec2 vec){
	Vec2 ret;
	ret.x = this->x - vec.x;
	ret.y = this->y - vec.y;
	return(ret);
}

float Vec2::GetAngle(Vec2 vec){
	return(atan2((vec.y - y) , (vec.x - x)));
}

float Vec2::Distance(Vec2 vec){
	return( sqrt( pow((x - vec.x),2)- pow((y - vec.y),2)) );
}