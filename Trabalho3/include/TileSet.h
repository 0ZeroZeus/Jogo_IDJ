#include "Sprite.h"
#include <cmath>

#ifndef TILESET
#define TILESET

class TileSet{

	public:
		TileSet(int tileWidth, int tileHeight, string file);
		~TileSet();

		void RenderTile(unsigned index, float x, float y);
		int GetTileWidth ();
		int GetTileHeight(); 
	
	private:

		Sprite tileSet;
		int rows;
		int columns;
		int tileWidth;
		int tileHeight;
		
};

#endif