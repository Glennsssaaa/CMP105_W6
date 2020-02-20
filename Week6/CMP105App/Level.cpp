#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ball1Texture.loadFromFile("gfx/Beach_Ball.png");
	ball1.setTexture(&ball1Texture);
	ball1.setPosition(100, 100);
	ball1.setSize(sf::Vector2f(50, 50));

	ball2.setTexture(&ball1Texture);
	ball2.setPosition(0, 0);
	ball2.setSize(sf::Vector2f(50, 50));

	ball3.setTexture(&ball1Texture);
	ball3.setPosition(50, 300);
	ball3.setSize(sf::Vector2f(50, 50));
}

Level::~Level()
{

}

int mX;
int mY;

int mx1,mx2,my1,my2,mxT,myT;

bool mouseDrag = true;
bool mouseDragEnd = false;

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space)) {
		ball1.jump(dt);
	}

	mX = input->getMouseX();
	mY = input->getMouseY();

	if (input->isMouseLDown()) {
		ball1.tele(mX,mY);
	}

	ball2.follow(mX,mY);

	mX = 0;
	mY = 0;

	if (input->isMouseRDown() && mouseDrag) {
		mx1 = input->getMouseX();
		my1 = input->getMouseY();
		mouseDrag = false;
		mouseDragEnd = true;
	}

	if (!input->isMouseRDown() && mouseDragEnd) {
		mx2 = input->getMouseX();
		my2 = input->getMouseY();

		mxT = mx1 - mx2;
		myT = my1 - my2;

		ball3.drag(mxT, myT);

		mouseDragEnd=false;
		mouseDrag = true;
	}


}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);
	ball2.update(dt);
	ball3.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(ball2);
	window->draw(ball3);
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