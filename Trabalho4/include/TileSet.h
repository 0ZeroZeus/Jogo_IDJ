#include "Sprite.h"
#include "Component.h"
#include "GameObject.h"
#include <cmath>

#ifndef TILESET
#define TILESET

class TileSet : public Component{

	public:
		TileSet(GameObject* associated, int tileWidth, int tileHeight, string file);
		~TileSet();
		void Update(float dt);
		void Render();
		bool Is(string type);

		void RenderTile(unsigned index, float x, float y);
		int GetTileWidth ();
		int GetTileHeight(); 
	
	private:

		Sprite tileSet = Sprite(associated);
		int rows;
		int columns;
		int tileWidth;
		int tileHeight;
		
};

#endif
