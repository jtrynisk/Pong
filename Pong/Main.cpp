#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>

using namespace sf;

int main()
{
	// Set the bounds for the window
	int windowWidth = 1024;
	int windowHeight = 768;

	// Make a window 1024x768 and title it 'Pong'
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");

	int score = 0;
	int lives = 3;
	bool gameStarted = false;

	// Create a bat
	Bat bat(windowWidth / 2, windowHeight - 20);

	// Create a ball
	Ball ball(windowWidth / 2, 1);

	Text hud;

	Font font;
	// Load from the gnerous www.dafont.com font
	font.loadFromFile("DS-DIGIT.ttf");

	// Set the font to our message
	hud.setFont(font);

	// Make it big
	hud.setCharacterSize(75);

	//Choose a color
	hud.setFillColor(Color::White);

	// Now for the game loop
	while (window.isOpen())
	{
		if (gameStarted == false)
		{
			std::stringstream ss;
			ss << "Welcome to Pong!" << std::endl;
			ss << "Press enter to begin.";
			hud.setString(ss.str());

			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				gameStarted = true;
			}
			window.clear(Color(26, 128, 182, 255));
			window.draw(hud);
			window.display();
		}
		else
		{
			/*
			* Handle Player input
			*/
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					// Window is closed need to exit
					window.close();
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				if (bat.getPosition().left > 0)
				{
					bat.moveLeft();
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				if (bat.getPosition().left + 100 < windowWidth)
				{
					bat.moveRight();
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				// Quit the game
				window.close();
			}

			/*
			* Update the frame
			*/

			//Handle the ball hitting the bottom
			if (ball.getPosition().top > windowHeight)
			{
				// reverse the ball direction and remove a life
				ball.hitBottom();
				lives--;

				// Check for end game state
				if (lives < 1)
				{
					gameStarted = false;
					score = 0;
					lives = 3;
				}
			}

			// Handle the ball hitting the top
			if (ball.getPosition().top < 0)
			{
				ball.reboundBatOrTop();
				score++;
			}

			// Handle ball hitting sides
			if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
			{
				ball.reboundSides();
			}
			// Has the ball hit the bat
			if (ball.getPosition().intersects(bat.getPosition()))
			{
				// hit detected reverse direction and score a point
				ball.reboundBatOrTop();
			}

			ball.update();
			bat.update();

			// Update the HUD text
			std::stringstream ss;
			ss << "Score: " << score << "      Lives: " << lives;
			hud.setString(ss.str());

			/*
			* Draw the frame
			*/

			// Clear the window from the last frame.
			window.clear(Color(26, 128, 182, 255));

			// Draw the bat and ball and HUD
			window.draw(bat.getShape());
			window.draw(ball.getShape());
			window.draw(hud);
			window.display();
		}
	}

	return 0;
}