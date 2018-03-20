#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "State.h"

State::State(){

	quitRequested = false;
	music.Open("assets/music/stageState.ogg");
	music.Play(-1);
}

State::~State(){
	ObjectArray.clear();
}

bool State::QuitRequested(){
	return(quitRequested);
}
void State::LoadAssets(){
	bg.Open("assets/img/ocean.jpg");
}
void State::Update(float dt){
	Input();
	for (int i = 0; i < ObjectArray.size(); ++i){
		ObjectArray[i].Update(0);
	}
	for (int i = 0; i < ObjectArray.size(); ++i){
		if(ObjectArray[i].IsDead()){
			ObjectArray.erase(ObjectArray.begin()+i);
		}
	}
}
void State::Render(){
	bg.Render();
	for (int i = 0; i < ObjectArray.size(); ++i){
		ObjectArray[i].Render();
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
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.Contains( {(float)mouseX, (float)mouseY} ) ) {
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

	Sprite* img = new Sprite("assets/img/penguinface.png") : Component(aux);

	aux->AddComponent(img);

	aux->Box.x = mouseX;
	aux->Box.y = mouseY;
	//compensar

	Sound* snd = new Sound("assets/sound/boom.wav") : Component(aux);

	aux->AddComponent(snd);

	Face* cara = new Face(aux);

	ObjectArray.emplace_back(aux);

}