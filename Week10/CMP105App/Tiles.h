#pragma once
#include "Framework/TileMap.h"
class Tiles :
	public TileMap
{
public:
	Tiles();
	~Tiles();

	void render(sf::RenderWindow* window);
	sf::RenderWindow* window;
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }

private:
	TileMap tileMap;
};

