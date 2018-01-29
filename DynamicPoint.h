#pragma once
#include "Goal.h"
class DynamicPoint
{
private:
	float xLoc, yLoc, xVel, yVel, xAcc, yAcc, dt, vMax, aMax, sMax;
	bool finished;
public:
	DynamicPoint(float xLoc, float yLoc, float xVel, float yVel, float deltaTime, float vMax, float aMax);
	float getXLoc();
	float getYLoc();
	float getXVel();
	float getYVel();
	void setVelocity(Goal g);
	void setSMax();
	void move();
	bool isFinished();
	float getVMax();
	float getAMax();
	float getALength();
	sf::CircleShape getDrawableBody();
	sf::Vertex getTangentPoint(Goal g, int f);
	sf::Vertex getCenterVertex();
	sf::Vertex getOuterDirectionVertex();
	sf::Vertex getOuterAccelerationVertex();
	~DynamicPoint();
};

