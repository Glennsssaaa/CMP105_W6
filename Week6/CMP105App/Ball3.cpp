#include "Ball3.h"

Ball3::Ball3() {
	speed = 200.f;
	dragged = false;
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
}

Ball3::~Ball3() {

}

void Ball3::update(float dt) {

	yBef = getPosition().y;
	if (dragged && getPosition()!=target) {
		if (yBef >= yPeak) {
			yPeak == yBef;
			direction = target - getPosition();
			direction = Vector::normalise(direction);
			velocity = (direction * speed);
			setPosition(getPosition() + (velocity * dt));
		}
		
	}

	
	else if (yBef <= yPeak) {
		dragged = false;
		yBef = 0;
		yPeak = 0;

		sf::Vector2f pos = stepVelocity * dt + .5f * gravity * dt * dt;
		stepVelocity += gravity * dt;
		setPosition(getPosition() + pos);
		if (getPosition().y >= 500) {
			setPosition(getPosition().x, 500);
			stepVelocity = sf::Vector2f(0, 0);
		}
	}
}

void Ball3::drag(int x, int y) {
	dragPos = getPosition() + (sf::Vector2f(x, y));
	target = dragPos+sf::Vector2f(0,50.f);
	dragged = true;
}