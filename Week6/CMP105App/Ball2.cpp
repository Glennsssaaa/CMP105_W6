#include "Ball2.h"

Ball2::Ball2() {
	speed = 100.f;
	acceleration = 20.f;
}

Ball2::~Ball2() {

}

void Ball2::update(float dt) {
	direction = target - getPosition();
	direction = Vector::normalise(direction);

	velocity += (direction * acceleration) * dt;
	
	setPosition(getPosition() + (velocity * dt));

	if (Vector::magnitude(target - getPosition()) < 10.f) {
		setPosition(target);
	}

	if (getPosition() == target) {
		velocity = (sf::Vector2f(0,0));
	}
}

void Ball2::follow(int x,int y) {
	target = (sf::Vector2f(x, y));
}