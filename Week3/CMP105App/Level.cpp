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

	circle1.setPosition(100, 400);
	circle1.setFillColor(sf::Color::Green);
	circle1.setRadius(25);
	circle1.setOrigin(25,25);
	circle1.setOrigin(25,25);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	distance1 = speed * dt;
	if (input->isKeyDown(sf::Keyboard::W) && (coord1.y > 0)) {
		coord1.y -= distance1;
	}
	if (input->isKeyDown(sf::Keyboard::S) && (coord1.y < (window->getSize().y-100))) {
		coord1.y += distance1;
	}
	if (input->isKeyDown(sf::Keyboard::A) && (coord1.x > 0)) {
		coord1.x -= distance1;
	}
	if (input->isKeyDown(sf::Keyboard::D) && (coord1.x < (window->getSize().x - 100))) {
		coord1.x += distance1;
	}
	rect.setPosition(coord1);

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

	//---------------------

	if (coord2.x < 25) {
		if (angle <= 180)
		{
			angle -= 90;
			speed2.x = speed1 * cos(angle);
			speed2.y = speed1 * sin(angle);
		}
		else 
		{
			angle += 90;
			speed2.x = speed1 * cos(angle);
			speed2.y = speed1 * sin(angle);
		}
	}
	if (coord2.x > (window->getSize().x - 25)) 
	{
		if (angle <= 90)
		{
			angle += 90;
			speed2.x = speed1 * cos(angle);
			speed2.y = speed1 * sin(angle);
		}
		else
		{
			angle -= 90;
			speed2.x = speed1 * cos(angle);
			speed2.y = speed1 * sin(angle);
		}
	}
	if (coord2.y < 25) {
		if (angle <= 90)
		{
			angle += 270;
			speed2.x = speed1 * cos(angle-270);
			speed2.y = speed1 * sin(angle-270);
		}
		else
		{
			angle += 90;
			speed2.x = speed1 * cos(angle);
			speed2.y = speed1 * sin(angle);
		}
	}
	if (coord2.y > (window->getSize().y - 25))
	{
		if (angle <= 270)
		{
			angle -= 90;
			speed2.x = speed1 * cos(angle);
			speed2.y = speed1 * sin(angle);
		}
		else
		{
			angle -= 270;
			speed2.x = speed1 * cos(angle);
			speed2.y = speed1 * sin(angle);
		}
	}
	distance2.x = speed2.x * dt;
	distance2.y = speed2.y * dt;
	coord2 += distance2;
	circle1.setPosition(coord2);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	window->draw(rect);
	window->draw(circle1);
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