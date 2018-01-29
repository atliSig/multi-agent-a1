#pragma once
#include "Goal.h"
class KineMaticPoint
{
private:
	float xLoc, yLoc, xVel, yVel, dt, vMax, sMax;
	bool finished;
	void setSMax();
public:
	KineMaticPoint(float xLoc, float yLoc, float xVel, float yVel, float deltaTime, float vMax);
	float getXLoc();
	float getYLoc();
	float getXVel();
	float getYVel();
	void setVelocity(Goal g);
	void move();
	bool isFinished();
	sf::CircleShape getDrawableBody();
	sf::Vertex getCenterVertex();
	sf::Vertex getOuterDirectionVertex();
	~KineMaticPoint();
};

