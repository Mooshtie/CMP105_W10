#include "Tiles.h"
Tiles::Tiles()
{
	//this loads the tileSet for the tiles
	tileMap.loadTexture("gfx/marioTiles.png");

	//applying the tileSet to the tiles
	for (int i = 0; i < 7; i++)
	{
		tile.setSize(sf::Vector2f(32, 32));
		tile.setCollisionBox(0, 0, 32, 32);
		tile.setCollider(true);
		tiles.push_back(tile);
	}

	tiles[0].setCollider(false);
	tiles[0].setTextureRect(sf::IntRect(187, 51, 16, 16));
	tiles[1].setTextureRect(sf::IntRect(0, 0, 16, 16));
	tiles[2].setTextureRect(sf::IntRect(17, 0, 16, 16));
	tiles[3].setTextureRect(sf::IntRect(34, 0, 16, 16));
	tiles[4].setTextureRect(sf::IntRect(0, 34, 16, 16));
	tiles[5].setTextureRect(sf::IntRect(17, 34, 16, 16));
	tiles[6].setTextureRect(sf::IntRect(34, 34, 16, 16));

	tileMap.setTileSet(tiles);

	//Map Dimensions
	sf::Vector2u mapSize(10, 6);

	//Building Map
	std::vector<int> map = {
		1, 3, 0, 0, 0, 0, 0, 0, 1, 3,
		4, 6, 0, 0, 0, 0, 0, 0, 4, 6,
		0, 0, 1, 3, 0, 0, 1, 3, 0, 0,
		0, 0, 4, 6, 0, 0, 4, 6, 0, 0,
		0, 0, 0, 0, 1, 3, 0, 0, 0, 0,
		0, 0, 0, 0, 4, 6, 0, 0, 0, 0,
	};

	tileMap.setTileMap(map, mapSize);
	tileMap.setPosition(sf::Vector2f(0, 408));
	tileMap.buildLevel();
}

Tiles::~Tiles()
{
}

void Tiles::render(sf::RenderWindow* window)
{
	tileMap.render(window);
}

void Tiles::collision(GameObject* player)
{
	world = tileMap.getLevel();
	for (int i = 0; i < (int)world->size(); i++)
	{
		// if collision check should occur
		if ((*world)[i].isCollider())
		{
			if (Collision::checkBoundingBox(player, &(*world)[i]))
			{
				player->collisionResponse(&(*world)[i]);
			}
		}
	}
}