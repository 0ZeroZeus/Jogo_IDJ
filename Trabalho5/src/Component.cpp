#include "Component.h"

Component::Component(GameObject* associated){

	this->associated = associated;
}
Component::~Component(){}
void Component::Start(){}
void Component::Update(float dt){}
void Component::Render(){}
bool Component::Is(string type){}