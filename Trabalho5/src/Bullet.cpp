#include "Bullet.h"

Bullet::Bullet(GameObject* associated, float angle, float speed, int damage, float maxDistance, string sprite) : Component(associated){
	Sprite* novo = new Sprite(associated, sprite);
	associated->Box.w = novo->GetWidth();
	associated->Box.h = novo->GetHeight();
	//associated->angleDeg = angle*(180.0/PI);
	associated->AddComponent(novo);

	this->damage = damage;
	distanceLeft = maxDistance;
	this->speed.y = speed*sin(angle);
	this->speed.x = speed*cos(angle);
}
Bullet::~Bullet(){}
void Bullet::Update(float dt){
	int tSpeed = sqrt( pow((speed.x),2)- pow((speed.y),2));

	associated->Box.x += speed.x*dt;
	associated->Box.y += speed.y*dt;

	distanceLeft-=tSpeed*dt;
	if (distanceLeft <= 0){
		associated->RequestDelete();
	}

}
void Bullet::Render(){}
bool Bullet::Is(string type){
	return(type == "Bullet");
}
int Bullet::GetDamage(){
	return(damage);
}