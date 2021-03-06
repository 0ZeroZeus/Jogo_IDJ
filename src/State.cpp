#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "State.h"

State::State(){

	quitRequested = false;
	music.Open("assets/audio/stageState.ogg");
	music.Play(-1);
}

State::~State(){
	ObjectArray.clear();
}

bool State::QuitRequested(){
	return(quitRequested);
}
void State::LoadAssets(){

	GameObject* aux = new GameObject();

	Sprite* bg = new Sprite(aux, "assets/img/ocean.jpg");

	aux->Box.x = 0;
	aux->Box.y = 0;

	aux->AddComponent(bg);

	TileSet* set = new TileSet(aux, 64, 64, "assets/img/tileset.png");

	TileMap* mapa = new TileMap(aux,"assets/map/tileMap.txt", set);

	aux->AddComponent(mapa);

	ObjectArray.emplace_back(aux);


}
void State::Update(float dt){
	Input();
	for (int i = 0; i < ObjectArray.size(); ++i){
		ObjectArray[i]->Update(0);
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

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}
		
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = ObjectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) ObjectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->Box.Contains( (float)mouseX, (float)mouseY ) ) {
					Face* face = (Face*)go->GetComponent( "Face" );
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if(event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2( 200, 0 ).GetRotated( -PI + PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}

void State::AddObject(int mouseX, int mouseY){

	GameObject* aux = new GameObject();

	Sprite* img = new Sprite(aux, "assets/img/penguinface.png");

	aux->AddComponent(img);

	aux->Box.w = img->GetWidth();
	aux->Box.h = img->GetHeight();
	//compensar
	aux->Box.x = mouseX - (aux->Box.w/2);
	aux->Box.y = mouseY - (aux->Box.h/2);

	Sound* snd = new Sound(aux,"assets/audio/boom.wav");

	aux->AddComponent(snd);

	Face* cara = new Face(aux);

	aux->AddComponent(cara);

	ObjectArray.emplace_back(aux);

}