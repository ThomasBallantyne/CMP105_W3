#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

	//circle variables
	float speed = 100, distance;
	bool facing=false;
	sf::Vector2f coord;

	//square variables
	sf::Vector2f coord1;
	int direction;
	float distance1;

	//random variables
	float angle=45, speed1=200;
	sf::Vector2f speed2 = sf::Vector2f(100, -100); 
	sf::Vector2f coord2 = (sf::Vector2f(100, 100));
	sf::Vector2f distance2;

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::CircleShape circle;
	sf::RectangleShape rect;
	sf::CircleShape circle1;

};