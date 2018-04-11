#include "Alien.h"

Alien::Alien(GameObject* associated, int nMinions) : Component(associated){
	Sprite* novo = new Sprite(associated,"assets/img/alien.png");
	associated->Box.w = novo->GetWidth();
	associated->Box.h = novo->GetHeight();
	associated->AddComponent(novo);

	this->nMinions = nMinions;
	
}
Alien::~Alien(){
	minionArray.clear();
}
void Alien::Start(){

	Game* game = Game::GetInstance();
	State* state = game->GetState();

	for (int i = 0; i < nMinions; ++i){
		GameObject* go = new GameObject();

		Minion* minion = new Minion(go, state->GetObjectPtr(associated), 0);
		minion->SetArc((float)i*2*PI/(float)nMinions);

		go->AddComponent(minion);

		minionArray.push_back((state->AddObject(go)).lock());
	}
}
void Alien::Update(float dt){
	InputManager& input = InputManager::GetInstance();
	speed.x = 0;
	speed.y = 0;
	float hipo = dt*200;

	associated->angleDeg += 3;
	
	if(input.IsMouseDown(SDL_BUTTON_RIGHT)){
		taskQueue.push(Action(Action::ActionType::MOVE, input.GetMouseX()-Camera::pos.x, input.GetMouseY()-Camera::pos.y));
	}
	if(input.IsMouseDown(SDL_BUTTON_LEFT)){
		taskQueue.push(Action(Action::ActionType::SHOOT, input.GetMouseX()-Camera::pos.x, input.GetMouseY()-Camera::pos.y));
	}

	if (!taskQueue.empty()){
		Action& aux = taskQueue.front();
		if (aux.type == Action::ActionType::MOVE){

			Vec2 centro = associated->Box.GetCenter();
			float angulo = centro.GetAngle(aux.pos);

			speed.y = hipo*sin(angulo);
			speed.x = hipo*cos(angulo);
			
			if (centro.Distance(aux.pos) < hipo){
				associated->Box.Centralize(aux.pos.x , aux.pos.y);
				taskQueue.pop();
			}
			else{
				associated->Box.x += speed.x;
				associated->Box.y += speed.y;
			}
			
		}
		if (aux.type == Action::ActionType::SHOOT){

			int index = rand()%nMinions;
			float maxDistance = -1;

			for (int i = 0; i < nMinions; ++i){
				Vec2 temp = minionArray[i]->Box.GetCenter();
				if(temp.Distance(aux.pos) < maxDistance || maxDistance <= 0){
					maxDistance = temp.Distance(aux.pos);
					index = i;
				}
			}
			Minion* source = (Minion*) minionArray[index]->GetComponent("Minion");
			source->Shoot(aux.pos);


			taskQueue.pop();
		}
	}

	if(hp <= 0){
		associated->RequestDelete();
	}
}
void Alien::render(){}
bool Alien::Is(string type){
	return(type == "Alien");
}

Alien::Action::Action(ActionType type, float x, float y){
	this->type = type;
	pos.x = x;
	pos.y = y;
}