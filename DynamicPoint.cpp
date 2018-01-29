#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "DynamicPoint.h"

DynamicPoint::DynamicPoint(float xLocation, float yLocation, float xVelocity, float yVelocity, float deltaTime, float maxVelocity, float maxAcceleration)
{
	xLoc = xLocation;
	yLoc = yLocation;
	xVel = xVelocity;
	yVel = yVelocity;
	//xAcc = xAccel;
	//yAcc = yAccel;
	dt = deltaTime;
	vMax = maxVelocity;
	aMax = maxAcceleration;
	sMax = 0.0f;
	finished = false;
	setSMax();
}

void DynamicPoint::setSMax() {
	sMax = vMax * dt;
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

/*
float DynamicPoint::getXAcc() {
	return xAcc;
}

float DynamicPoint::getYAcc() {
	return yAcc;
}
*/

bool DynamicPoint::isFinished() {
	return finished;
}

void DynamicPoint::setVelocity(Goal g) {
	double dist = sqrt(pow(xLoc - g.getXLoc(), 2) + pow(yLoc - g.getYLoc(), 2));
	//if at goal, set velocity to the same as goal
	//if within certain distance from goal
	if (dist <= 0.001) {
		xVel = g.getXVel();
		yVel = g.getYVel();
		finished = true;
		return;
	}

	//Recalibrate velocities if not aiming at goal
	//calculate the slope between self and goal
	double slope = (yLoc - g.getYLoc()) / (xLoc - g.getXLoc());
	if (xLoc > g.getXLoc()) {
		xVel = - vMax * sqrt(1 / (pow(slope, 2) + 1));
	}
	else {
		xVel = vMax * sqrt(1 / (pow(slope, 2) + 1));
	}
	yVel = slope * xVel;

	//If close enough to goal to reach it in one timestep
	//calibrate the "size" of the velocity such that we hit
	//it excatly after the next time step
	if (dist <= sMax) {
		double vFinal = dist / dt;
		xVel = vFinal * sqrt(1 / (pow(slope, 2) + 1));
		yVel = slope * xVel;
	}
}
sf::CircleShape DynamicPoint::getDrawableBody() {
	sf::CircleShape body(10);
	body.setPosition(xLoc, yLoc);
	body.setFillColor(sf::Color(254, 0, 0));
	return body;
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
	xLoc = xLoc + dt * xVel;
	yLoc = yLoc + dt * yVel;
}

DynamicPoint::~DynamicPoint()
{
}
