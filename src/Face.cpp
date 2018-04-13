#include "Face.h"

Face::Face(GameObject* associated) : Component(associated){
	hitpoints = 30;
}
Face::~Face(){}
void Face::Damage(int damage){
	hitpoints -= damage;
	if (hitpoints <= 0){
		associated->RequestDelete();
		Sound* aux = (Sound*) associated->GetComponent("sound");
		if (aux != nullptr){
			aux->Play(1);
		}
	}
}
void Face::Update(float dt){}
void Face::Render(){}
bool Face::Is(string type){
	return(type == "Face");
}

