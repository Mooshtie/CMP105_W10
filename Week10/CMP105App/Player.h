#pragma once
#include "Framework/GameObject.h"
class Player :
	public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt) override;
	void update(float dt) override;
	void collisionResponse(GameObject* collider) override;
	sf::RenderWindow* window;
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }

private:
	float scale;
	bool isJumping;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
	sf::Vector2f gravity;
};