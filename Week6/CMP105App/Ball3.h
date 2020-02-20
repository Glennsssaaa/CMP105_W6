#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Ball3 : public GameObject
{
public:
	Ball3();
	~Ball3();

	void update(float dt);
	void drag(int x, int y);

private:
	sf::Vector2f dragPos;
	float speed;
	sf::Vector2f target;
	sf::Vector2f direction;
	bool dragged;

	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;

	float yPeak;
	float yBef;
};

