// multiagent-a1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML/Graphics.hpp"

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Hello SFML");
	while (true) {
		renderWindow.clear();
		renderWindow.display();
	}
}

