#pragma once
class KineMaticPoint
{

private:
	float xLoc, yLoc, xVel, yVel;

public:
	KineMaticPoint(float xLoc, float yLoc, float xVel, float yVel);
	float getXLoc();
	float setVelocity(float xVel, float yVel);
	float getYLoc();
	float getXVel();
	float getYVel();
	void move();
	sf::CircleShape getDrawableBody();
	sf::Vertex* getdDrawableDirection();
	sf::Vertex getCenterVertex();
	sf::Vertex getOuterDirectionVertex();
	~KineMaticPoint();
};

