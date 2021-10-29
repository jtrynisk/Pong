#include "Ball.h"

using namespace sf;

Ball::Ball(float startX, float startY)
{
    position.x = startX;
    position.y = startY;

    ballShape.setSize(Vector2f(10, 10));
    ballShape.setPosition(position);
}

sf::FloatRect Ball::getPosition()
{
    return ballShape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
    return ballShape;
}

float Ball::getXVelocity()
{
    return xVelocity;
}

void Ball::reboundSides()
{
    xVelocity = -xVelocity;
}

void Ball::reboundBatOrTop()
{
    position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;
}

void Ball::hitBottom()
{
    position.y = 1;
    position.x = 500;
}

void Ball::update()
{
    position.x += xVelocity;
    position.y += yVelocity;

    ballShape.setPosition(position);
}
