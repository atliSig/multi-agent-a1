#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <math.h>
#include "DynamicPoint.h"
#include "Goal.h"

Goal::Goal(float xLocation, float yLocation, float xVelocity, float yVelocity)
{
	xLoc = xLocation;
	yLoc = yLocation;
	xVel = xVelocity;
	yVel = yVelocity;
}

sf::CircleShape Goal::getDrawableBody() {
	sf::CircleShape body(10);
	body.setPosition(xLoc, yLoc);
	body.setFillColor(sf::Color(0, 254, 0));
	return body;
}

sf::Vertex Goal::getCenterVertex() {
	return sf::Vertex(sf::Vector2f(xLoc + 10, yLoc + 10));
}

sf::Vertex Goal::getOuterDirectionVertex() {
	float unitX = xVel / sqrt(pow(xVel, 2) + pow(yVel, 2));
	float unitY = yVel / sqrt(pow(xVel, 2) + pow(yVel, 2));
	return sf::Vertex(sf::Vector2f(xLoc + 10 + 50 * unitX, yLoc + 10 + 50 * unitY));
}

float Goal::getXLoc() {
	return xLoc;
}

float Goal::getYLoc() {
	return yLoc;
}

float Goal::getXVel() {
	return xVel;
}

float Goal::getYVel() {
	return yVel;
}

Goal::~Goal()
{
}
