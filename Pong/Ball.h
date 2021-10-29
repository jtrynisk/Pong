#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
public:

    Ball(float startX, float startY);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    float getXVelocity();

    void reboundSides();

    void reboundBatOrTop();

    void hitBottom();

    void update();

private:

    sf::Vector2f position;

    sf::RectangleShape ballShape;

    float xVelocity = .175f;
    float yVelocity = .175f;
};

