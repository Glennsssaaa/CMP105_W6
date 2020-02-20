#include "Ball1.h"

Ball1::Ball1() {
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;
}

Ball1::~Ball1() {

}

void Ball1::update(float dt) {
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	stepVelocity += gravity * dt;
	setPosition(getPosition() + pos);

	if (getPosition().y >= 500) {
		setPosition(getPosition().x, 500);
		stepVelocity = sf::Vector2f(0, 0);
		isJumping = false;
	}
}

void Ball1::jump(float dt) {
	if (!isJumping) {
		stepVelocity = jumpVector;
		isJumping = true;
	}
}

void Ball1::tele(int x, int y) {
	setPosition(x, y);
}