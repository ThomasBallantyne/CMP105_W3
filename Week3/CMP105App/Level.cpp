#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setRadius(25);
	circle.setOrigin(25, 25);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(25, 400);

	rect.setPosition(400, 400);
	rect.setFillColor(sf::Color::Blue);
	rect.setSize(sf::Vector2f(100,100));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	distance = speed * dt;
	if ((facing == false) && (coord.x < (window->getSize().x-25))) {
		coord.x += distance;
	}
	else if ((facing == false) && (coord.x > (window->getSize().x - 25)))
	{
		facing=true;
	}
	else if ((facing) && (coord.x < 25))
	{
		facing=false;
	}
	else
	{
		coord.x -= distance;
	}
	circle.setPosition(coord.x, (window->getSize().y/2));
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}