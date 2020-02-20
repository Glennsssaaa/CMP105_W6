#pragma once
#include "Framework/GameObject.h"

class Ball1 : public GameObject
{
public:

	Ball1();
	~Ball1();

	void update(float dt);
	void jump(float dt);
	void tele(int x, int y);

private:
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	bool isJumping;
	sf::Vector2f jumpVector;
};

