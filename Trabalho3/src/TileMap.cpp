#include "TileMap.h"
#include <stdio.h>

TileMap::TileMap(GameObject* associated, string file, TileSet* tileSet) : Component(associated){
	this->tileSet = tileSet;
	Load(file);
}
TileMap::~TileMap(){}
void TileMap::Load(string file){

	FILE* fp;
	int num;

	ifstream mapa(file);
	string aux;
	int ancora; 

	if (mapa.good()){
		SDL_Log("mapa is good");
	}

	getline(mapa,aux,',');
	mapWidth = atoi(aux.c_str());
	getline(mapa,aux,',');
	mapHeight = atoi(aux.c_str());
	getline(mapa,aux,',');
	mapDepth = atoi(aux.c_str());
	SDL_Log("numero lido: %d", mapDepth);

	getline(mapa,aux,'\n');
	while(getline(mapa,aux,',')){
		ancora = atoi(aux.c_str());
		ancora--;
		tileMatrix.push_back(ancora);	
	}
	mapa.close();
	

	/*fp = fopen(file.c_str(),"r");

	fscanf(fp,"%d,", &mapWidth);
	fscanf(fp,"%d,", &mapHeight);
	fscanf(fp,"%d,", &mapDepth);

	while(fgetc(fp) != EOF){
		fseek(fp, -1, SEEK_SET);
		fscanf(fp,"%d,", &num);
		SDL_Log("numero lido: %d", num);
		num--;
		tileMatrix.push_back(num);	
	}

	fclose(fp);*/

}
void TileMap::SetTileSet(TileSet* tileSet){
	this->tileSet = tileSet;
}
int* TileMap::At(int x, int y, int z){
	int aux = (x+y*mapHeight+z*mapHeight*mapWidth);

	return(&tileMatrix[aux]);
}
void TileMap::RenderLayer(int layer, int cameraX, int cameraY){

	int* index;
	float x = 0;
	float y = 0;

	for (int i = 0; i < mapHeight; ++i){
		for (int j = 0; j < mapWidth; ++j){

			index = At(j,i,layer);
			tileSet->RenderTile(*index, x, y);
			x+= tileSet->GetTileWidth();
		}
		x=0;
		y+= tileSet->GetTileHeight();
	}
	
}
void TileMap::Render(){

	for (int i = 0; i < mapDepth; ++i){
		RenderLayer(i, 0, 0);
	}
}
int TileMap::GetWidth(){
	return(mapWidth);
}
int TileMap::GetHeight(){
	return(mapHeight);
}
int TileMap::GetDepth(){
	return(mapDepth);
}

void TileMap::Update(float dt){}

bool TileMap::Is(string type){
	return(type == "TIleMap");
}