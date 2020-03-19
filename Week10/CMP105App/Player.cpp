#include "Player.h"
Player::Player()
{
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;
	velocity = sf::Vector2f(0, 0);
}

Player::~Player()
{
}

void Player::handleInput(float dt)
{
	//jump!
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		stepVelocity = jumpVector;
		isJumping = true;
	}
	
	//move!
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		velocity.x = 200;
		setVelocity(velocity);
		move(getVelocity() * dt);
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		velocity.x = -200;
		setVelocity(velocity);
		move(getVelocity() * dt);
	}
}

void Player::update(float dt)
{
	//applying force of gravity
	//move shape by adding new velocity
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut + 1/2at^2
	stepVelocity += gravity * dt; //v = u + at
	setPosition(getPosition() + pos);

	if (getPosition().y > window->getSize().y - getSize().y)
	{
		velocity.y = 0;
		setPosition(getPosition().x, window->getSize().y - getSize().y);
	}
}

void Player::collisionResponse(GameObject* collider)
{
	velocity.y = 0; 
	setPosition(getPosition().x, collider->getPosition().y - getSize().y); 
}