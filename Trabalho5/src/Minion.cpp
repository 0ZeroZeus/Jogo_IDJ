#include "Minion.h"

Minion::Minion(GameObject* associated, weak_ptr< GameObject > alienCenter, float arcOffsetDeg) : Component(associated){

	Sprite* novo = new Sprite(associated,"assets/img/minion.png");
	associated->Box.w = novo->GetWidth();
	associated->Box.h = novo->GetHeight();

	int random = rand()%6;
	float aux = 1.0+((float)random/10);
	novo->SetScaleX(aux, aux);

	associated->AddComponent(novo);

	this->alienCenter = alienCenter;
}
Minion::~Minion(){}
void Minion::Update(float dt){

	shared_ptr<GameObject> alien;
	alien = alienCenter.lock();
	
	if (!alien){
		associated->RequestDelete();
		return;
	}
	Vec2 centro = alien->Box.GetCenter();

	Vec2 pos = Vec2(150, 0).GetRotated(arc) + Vec2( centro.x, centro.y);
	arc+=PI/200;

	associated->Box.Centralize(pos.x, pos.y);

	//associated->angleDeg = (arc + PI)*(180.0/PI);
	associated->angleDeg = (PI/4)*(180.0/PI);
	//associated->angleDeg = 370;
}
void Minion::Render(){}
bool Minion::Is(string type){
	return(type == "Minion");
}

void Minion::SetArc(float val){
	arc = val;
}

void Minion::Shoot(Vec2 target){

	Game* game = Game::GetInstance();
	State* state = game->GetState();

	GameObject* go = new GameObject();
	go->Box.Centralize(associated->Box.GetCenter().x , associated->Box.GetCenter().y);
	float angle = associated->Box.GetCenter().GetAngle(target);

	Bullet* bullet = new Bullet(go, angle, 350.0, 30, associated->Box.GetCenter().Distance(target)*2,"assets/img/minionbullet1.png");
	go->AddComponent(bullet);
	state->AddObject(go);
}

//Vec2 objPos = Vec2( 200, 0 ).GetRotated( -PI + PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );