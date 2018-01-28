#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "KineMaticPoint.h"
#include <math.h>

KineMaticPoint::KineMaticPoint(float xLocation, float yLocation, float xVelocity, float yVelocity)
{
	xLoc = xLocation;
	yLoc = yLocation;
	xVel = xVelocity;
	yVel = yVelocity;
}

float KineMaticPoint::getXLoc() {
	return xLoc;
}

float KineMaticPoint::getYLoc() {
	return yLoc;
}

float KineMaticPoint::getXVel() {
	return xVel;
}

float KineMaticPoint::getYVel() {
	return yVel;
}

sf::CircleShape KineMaticPoint::getDrawableBody() {
	sf::CircleShape body(10);
	body.setPosition(xLoc, yLoc);
	body.setFillColor(sf::Color(254, 0, 0));
	return body;
}

sf::Vertex* KineMaticPoint::getdDrawableDirection() {
	sf::Vertex direction[] ={
		sf::Vertex(sf::Vector2f(210,810)),
		sf::Vertex(sf::Vector2f(210, 795))
	};
	return direction;
}

sf::Vertex KineMaticPoint::getCenterVertex() {
	return sf::Vertex(sf::Vector2f(xLoc + 10, yLoc + 10));
}

sf::Vertex KineMaticPoint::getOuterDirectionVertex() {
	float unitX = xVel/sqrt(pow(xVel,2) + pow(yVel,2));
	float unitY = yVel / sqrt(pow(xVel, 2) + pow(yVel, 2));
	return sf::Vertex(sf::Vector2f(xLoc + 10 + 50*unitX, yLoc + 10 + 50*unitY));
}

void KineMaticPoint::move() {
	xLoc = xLoc + xVel;
	yLoc = yLoc + yVel;
}


KineMaticPoint::~KineMaticPoint()
{
}
