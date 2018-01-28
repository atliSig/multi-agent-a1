// multiagent-a1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "KineMaticPoint.h"

using namespace std;

int main()
{
	//Area boundary = Area(arPoints);
	// create the window
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);
		KineMaticPoint k = KineMaticPoint(200.0f, 200.0f, 180.0f, 190.0f);
		window.draw(k.getDrawableBody());
		window.draw(k.getdDrawableDirection(), 2, sf::Lines);
		sf::Vertex* line = k.getdDrawableDirection();
		window.draw(line, 2, sf::Lines);
		window.display();
		// draw everything here...
		// window.draw(...);
		//sf::CircleShape body(10);
		//body.setPosition(x, y);
		//body.setFillColor(sf::Color(254, 0, 0));
		//window.draw(body);
		//window.display();
		/*
		sf::CircleShape circle(10);
		circle.setPosition(200, 800);
		circle.setFillColor(sf::Color(254, 0, 0));
		window.draw(circle);
		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(210,810)),
			sf::Vertex(sf::Vector2f(210, 795))
		};
		window.draw(line, 2, sf::Lines);
		sf::CircleShape goal(10);
		goal.setPosition(900, 100);
		goal.setFillColor(sf::Color(0, 254, 0));
		window.draw(goal);
		window.display();
		*/

	}

	return 0;
}

