#pragma once

#include <SFML/Graphics.hpp>

class Bat {
public:

	// Constructor class
	Bat(float startX, float startY);

	// Returns position of the rectangle portion of bat
	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	void moveLeft();

	void moveRight();

	void update();

private:

	sf::Vector2f position;

	//A RectangleShape object
	sf::RectangleShape batShape;

	float batSpeed = .3f;

};