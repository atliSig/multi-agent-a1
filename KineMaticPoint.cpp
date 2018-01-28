#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "KineMaticPoint.h"


KineMaticPoint::KineMaticPoint(float xLocation, float yLocation, float xRotation, float yRotation)
{
	xLoc = xLocation;
	yLoc = yLocation;
	xRot = xRotation;
	yRot = yRotation;
}

float KineMaticPoint::getXLoc() {
	return xLoc;
}

float KineMaticPoint::getYLoc() {
	return yLoc;
}

float KineMaticPoint::getXRot() {
	return xRot;
}

float KineMaticPoint::getYRot() {
	return yRot;
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



KineMaticPoint::~KineMaticPoint()
{
}
