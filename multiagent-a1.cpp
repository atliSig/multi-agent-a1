// multiagent-a1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "KineMaticPoint.h"
#include "DynamicPoint.h"
#include "Goal.h"
#include "stdio.h"

using namespace std;

int main()
{
	//Area boundary = Area(arPoints);
	// create the window
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");
	//KineMaticPoint k = KineMaticPoint(799.0f, 100, -5.0f, -1.0f, 0.05f, 10.0f);
	DynamicPoint k = DynamicPoint(100.0f, 900.0f, -5.0f, -1.0f, 0.1f, 1.1f, 1.3f);
	Goal g = Goal(500.0f, 500.0f, 10.0f, 20.0f);
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
		k.setVelocity(g);
		while (!k.isFinished()) {
			window.clear(sf::Color::Black);
			k.move();
			k.setVelocity(g);
			//Draw the player
			window.draw(k.getDrawableBody());
			sf::Vertex velLine[] = { k.getCenterVertex(), k.getOuterDirectionVertex() };
			window.draw(velLine, 2, sf::Lines);
			sf::Vertex accLine[] = { k.getCenterVertex(), k.getOuterAccelerationVertex() };
			window.draw(accLine, 2, sf::Lines);
			//Draw the goal
			window.draw(g.getDrawableBody());
			sf::Vertex goalLine[] = { g.getCenterVertex(), g.getOuterDirectionVertex() };
			window.draw(goalLine, 2, sf::Lines);
			sf::Vertex tangentLine1[] = { g.getCenterVertex(), k.getTangentPoint(g, -1) };
			window.draw(tangentLine1, 2, sf::Lines);
			sf::Vertex tangentLine2[] = { g.getCenterVertex(), k.getTangentPoint(g, 1) };
			window.draw(tangentLine2, 2, sf::Lines);
			window.display();
		}
		//int c;
		//c = getchar();
	}

	return 0;
}

