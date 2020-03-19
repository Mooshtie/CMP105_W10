#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	marioTiles.setWindow(window);

	shroomTexture.loadFromFile("gfx/Mushroom.png");
	shroom.setTexture(&shroomTexture);
	shroom.setSize(sf::Vector2f(50, 50));
	shroom.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	shroom.setPosition(100, 50);
	shroom.setInput(input);
	shroom.setWindow(window);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	shroom.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	shroom.update(dt);

	marioTiles.collision(&shroom);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(shroom);
	marioTiles.render(window);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}