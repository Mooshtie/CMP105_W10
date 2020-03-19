#pragma once
#include "Framework/TileMap.h"
#include "Framework/Collision.h"
class Tiles :
	public TileMap
{
public:
	Tiles();
	~Tiles();

	void render(sf::RenderWindow* window);
	void collision(GameObject* player);
	sf::RenderWindow* window;
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }

private:
	TileMap tileMap;
	GameObject tile;
	std::vector<GameObject> tiles;
	std::vector<GameObject>* world;
};

