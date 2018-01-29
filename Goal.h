#pragma once
class Goal
{
private:
	float xLoc, yLoc, xVel, yVel;
public:
	Goal(float xLoc, float yLoc, float xVel, float yVel);
	sf::CircleShape getDrawableBody();
	sf::Vertex getCenterVertex();
	sf::Vertex getOuterDirectionVertex();
	float getXLoc();
	float getYLoc();
	float getXVel();
	float getYVel();
	~Goal();
};

