#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Ball2 : public GameObject
{
public:
	Ball2();
	~Ball2();

	void update(float dt);
	void follow(int x, int y);

private:
	float speed;
	float acceleration;
	sf::Vector2f target;
	sf::Vector2f direction;
};

