#pragma once
class DynamicPoint
{

private:
	float xLoc, yLoc, xVel, yVel, xAcc, yAcc;

public:
	DynamicPoint(float xLoc, float yLoc, float xVel, float yVel, float xAcc, float yAcc);
	float getXLoc();
	float getYLoc();
	float getXVel();
	float getYVel();
	float getXAcc();
	float getYAcc();
	sf::CircleShape getDrawableBody();
	sf::Vertex* getdDrawableDirection();
	~DynamicPoint();
};

