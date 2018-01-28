#pragma once
class DynamicPoint
{

private:
	float xLoc, yLoc, xVel, yVel, xAcc, yAcc;
	float dt; // Time step 
	float xVelMax, yVelMax, xAccMax, yAccMax; //Maximum constraints for the model

public:
	DynamicPoint(float xLoc, float yLoc, float xVel, float yVel, float xAcc, float yAcc);
	float getXLoc();
	float getYLoc();
	float getXVel();
	float getYVel();
	float getXAcc();
	float getYAcc();
	void move();
	sf::CircleShape getDrawableBody();
	sf::Vertex* getdDrawableDirection();
	sf::Vertex getCenterVertex();
	sf::Vertex getOuterDirectionVertex();
	~DynamicPoint();
};

