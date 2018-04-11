#include "State.h"

State::State(){

	quitRequested = false;
	music.Open("assets/audio/stageState.ogg");
	music.Play(-1);
}

State::~State(){
	ObjectArray.clear();
}

void State::Start(){
	LoadAssets();
	for (int i = 0; i < ObjectArray.size(); ++i){
		ObjectArray[i]->Start();
	}
	started = true;
}

bool State::QuitRequested(){
	return(quitRequested);
}
void State::LoadAssets(){

	GameObject* aux = new GameObject();

	CameraFollower* follow = new CameraFollower(aux);

	aux->AddComponent(follow);

	aux->Box.x = 0;
	aux->Box.y = 0;

	Sprite* bg = new Sprite(aux, "assets/img/ocean.jpg");

	aux->AddComponent(bg);

	ObjectArray.emplace_back(aux);

	GameObject* aux2 = new GameObject();

	aux2->Box.x = 0;
	aux2->Box.y = 0;

	TileSet* set = new TileSet(64, 64, "assets/img/tileset.png");

	TileMap* mapa = new TileMap(aux2,"assets/map/tileMap.txt", set);

	aux2->AddComponent(mapa);

	ObjectArray.emplace_back(aux2);


	GameObject* aux3 = new GameObject();

	aux3->Box.x = 512;
	aux3->Box.y = 300;

	Alien* alien = new Alien(aux3, 3);

	aux3->AddComponent(alien);

	ObjectArray.emplace_back(aux3);


}
void State::Update(float dt){

	InputManager& input = InputManager::GetInstance();
	
	if(input.QuitRequested() || input.IsKeyDown(SDLK_ESCAPE))
		quitRequested = true;

	if (input.KeyPress(SDLK_SPACE)){
		Vec2 objPos = Vec2( 200, 0 ).GetRotated( -PI + PI*(rand() % 1001)/500.0 ) + Vec2( input.GetMouseX(), input.GetMouseY() );
		AddObject((int)objPos.x, (int)objPos.y);
	}

	Camera::Update(dt);

	for (int i = 0; i < ObjectArray.size(); ++i){
		ObjectArray[i]->Update(dt);
	}
	for (int i = 0; i < ObjectArray.size(); ++i){
		if(ObjectArray[i]->IsDead()){
			ObjectArray.erase(ObjectArray.begin()+i);
		}
	}
}
void State::Render(){
	for (int i = 0; i < ObjectArray.size(); ++i){
		ObjectArray[i]->Render();
	}
}

void State::AddObject(int mouseX, int mouseY){

	GameObject* aux = new GameObject();

	Sprite* img = new Sprite(aux, "assets/img/penguinface.png");

	aux->AddComponent(img);

	aux->Box.w = img->GetWidth();
	aux->Box.h = img->GetHeight();
	aux->Box.Centralize(mouseX-Camera::pos.x, mouseY-Camera::pos.y);

	Sound* snd = new Sound(aux,"assets/audio/boom.wav");

	aux->AddComponent(snd);

	Face* cara = new Face(aux);

	aux->AddComponent(cara);

	ObjectArray.emplace_back(aux);

}

weak_ptr<GameObject> State::AddObject(GameObject* go){

	shared_ptr<GameObject> aux(go);

	ObjectArray.push_back(aux);

	if (started){
		go->Start();
	}

	weak_ptr<GameObject> ret(aux);

	return(ret);
}

weak_ptr<GameObject> State::GetObjectPtr(GameObject* go){

	weak_ptr<GameObject> ret;

	for (int i = 0; i < ObjectArray.size(); ++i){
		if(ObjectArray[i].get() == go)
			ret = ObjectArray[i];
	}
	return(ret);
}