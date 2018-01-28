#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "DynamicPoint.h"


DynamicPoint::DynamicPoint(float xLocation, float yLocation, float xVelocity, float yVelocity, float xAccel, float yAccel)
{
	xLoc = xLocation;
	yLoc = yLocation;
	xVel = xVelocity;
	yVel = yVelocity;
	xAcc = xAccel;
	yAcc = yAccel;
}

float DynamicPoint::getXLoc() {
	return xLoc;
}

float DynamicPoint::getYLoc() {
	return yLoc;
}

float DynamicPoint::getXVel() {
	return xVel;
}

float DynamicPoint::getYVel() {
	return yVel;
}

float DynamicPoint::getXAcc() {
	return xAcc;
}

float DynamicPoint::getYAcc() {
	return yAcc;
}

sf::CircleShape DynamicPoint::getDrawableBody() {
	sf::CircleShape body(10);
	body.setPosition(xLoc, yLoc);
	body.setFillColor(sf::Color(254, 0, 0));
	return body;
}

sf::Vertex* DynamicPoint::getdDrawableDirection() {
	sf::Vertex direction[] = {
		sf::Vertex(sf::Vector2f(210,810)),
		sf::Vertex(sf::Vector2f(210, 795))
	};
	return direction;
}



DynamicPoint::~DynamicPoint()
{
}
