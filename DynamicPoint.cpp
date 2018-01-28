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

sf::Vertex DynamicPoint::getCenterVertex() {
	return sf::Vertex(sf::Vector2f(xLoc + 10, yLoc + 10));
}

sf::Vertex DynamicPoint::getOuterDirectionVertex() {
	float unitX = xVel / sqrt(pow(xVel, 2) + pow(yVel, 2));
	float unitY = yVel / sqrt(pow(xVel, 2) + pow(yVel, 2));
	return sf::Vertex(sf::Vector2f(xLoc + 10 + 50 * unitX, yLoc + 10 + 50 * unitY));
}

void DynamicPoint::move() {
	xLoc = xLoc + dt*xVel + 0.5*xAcc*dt*dt;
	yLoc = yLoc + dt*yVel + 0.5*yAcc*dt*dt;
	xVel = xAcc * dt; 
	yVel = yAcc * dt;
}



DynamicPoint::~DynamicPoint()
{
}
