#include "TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, string file){

	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;
	tileSet.Open(file);
	columns = (tileSet.GetWidth() / tileWidth);
	rows = (tileSet.GetHeight() / tileHeight);
}
TileSet::~TileSet(){}

void TileSet::RenderTile(unsigned index, float x, float y){

	int coordX;
	int coordY;

	if (index >= 0 && index < ((columns*rows)-1) ){
		coordX = index%columns;
		coordY = floor((float)index/(float)columns);

		tileSet.SetClip(coordX*tileWidth, coordY*tileHeight, tileWidth, tileHeight);
		tileSet.Render(x, y);
	}
}
int TileSet::GetTileWidth (){
	return(tileWidth);
}
int TileSet::GetTileHeight(){
	return(tileHeight);
}