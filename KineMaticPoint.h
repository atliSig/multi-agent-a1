#pragma once
class KineMaticPoint
{

private:
	float xLoc, yLoc, xRot, yRot;

public:
	KineMaticPoint(float xLoc, float yLoc, float xRot, float yRot);
	float getXLoc();
	float getYLoc();
	float getXRot();
	float getYRot();
	sf::CircleShape getDrawableBody();
	sf::Vertex* getdDrawableDirection();
	~KineMaticPoint();
};

