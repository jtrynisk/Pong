#include "Bat.h"

using namespace sf;

Bat::Bat(float startX, float startY) {
	
	position.x = startX;
	position.y = startY;

	batShape.setSize(Vector2f(100, 5));
	batShape.setPosition(position);

}

sf::FloatRect Bat::getPosition()
{
	return batShape.getGlobalBounds();
}

sf::RectangleShape Bat::getShape()
{
	return batShape;
}

void Bat::moveLeft()
{
	position.x -= batSpeed;
}

void Bat::moveRight()
{
	position.x += batSpeed;
}

void Bat::update()
{
	batShape.setPosition(position);
}
