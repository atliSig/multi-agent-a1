#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "Goal.h"
#include "KineMaticPoint.h"
#include <math.h>

KineMaticPoint::KineMaticPoint(float xLocation, float yLocation, float xVelocity, float yVelocity, float deltaTime, float maxVelocity)
{
	xLoc = xLocation;
	yLoc = yLocation;
	xVel = xVelocity;
	yVel = yVelocity;
	dt = deltaTime;
	vMax = maxVelocity;
	sMax = 0.0f;
	finished = false;
	setSMax();
}

void KineMaticPoint::setSMax() {
	sMax = vMax * dt;
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

bool KineMaticPoint::isFinished() {
	return finished;
}

void KineMaticPoint::setVelocity(Goal g) {
	double dist = sqrt(pow(xLoc - g.getXLoc(), 2) + pow(yLoc - g.getYLoc(), 2));
	//if at goal, set velocity to the same as goal
	//if within certain distance from goal
	if (dist <= 0.05) {
		xVel = g.getXVel();
		yVel = g.getYVel();

		finished = true;
		return;
	}
	
	//Recalibrate velocities if not aiming at goal
	//calculate the slope between self and goal

	double dirX = g.getXLoc() - xLoc;
	double dirY = g.getYLoc() - yLoc;
	double dirLength = sqrt(pow(dirX, 2) + pow(dirY, 2));
	double dirUnitX = dirX / dirLength;
	double dirUnitY = dirY / dirLength;
	xVel = vMax * dirUnitX;
	yVel = vMax * dirUnitY;

	//If close enough to goal to reach it in one timestep
	//calibrate the "size" of the velocity such that we hit
	//it excatly after the next time step
	if (dist <= sMax) {
		double vFinal = dist / dt;
		xVel = vFinal * dirUnitX;
		yVel = vFinal * dirUnitY;
	}
}

void KineMaticPoint::move() {
	xLoc = xLoc + dt * xVel;
	yLoc = yLoc + dt * yVel;
}


sf::CircleShape KineMaticPoint::getDrawableBody() {
	sf::CircleShape body(10);
	body.setPosition(xLoc, yLoc);
	body.setFillColor(sf::Color(254, 0, 0));
	return body;
}

sf::Vertex KineMaticPoint::getCenterVertex() {
	return sf::Vertex(sf::Vector2f(xLoc + 10, yLoc + 10));
}

sf::Vertex KineMaticPoint::getOuterDirectionVertex() {
	float unitX = xVel/sqrt(pow(xVel,2) + pow(yVel,2));
	float unitY = yVel / sqrt(pow(xVel, 2) + pow(yVel, 2));
	return sf::Vertex(sf::Vector2f(xLoc + 10 + 50*unitX, yLoc + 10 + 50*unitY));
}

KineMaticPoint::~KineMaticPoint()
{
}
