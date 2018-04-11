#ifndef TILESET
#define TILESET

#include <cmath>
#include "Sprite.h"

class TileSet{

	public:
		TileSet(int tileWidth, int tileHeight, string file);
		~TileSet();

		void RenderTile(unsigned index, float x, float y);
		int GetTileWidth();
		int GetTileHeight(); 
	
	private:

		Sprite tileSet;
		int rows;
		int columns;
		int tileWidth;
		int tileHeight;
		
};

#endif