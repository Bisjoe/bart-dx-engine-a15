#pragma once
#include "Collider.h"
class CRectangle :
	public Collider
{
public:
	CRectangle();
	~CRectangle();
	CRectangle(Component* caller, float x, float y, float width, float height);
	//Wheter or not a point is contained within a rectangle, considers points ON the rectangle as part of the rectangle.
	bool Contains(const float x, const float y);

	//Getters
	float GetWidth() const { return width; }
	float GetHeight() const { return height; }
	

	//Setters
	void SetSize(const float w, const float h);

	//Determines if a rectangle collides with another rectangle.
	bool CollidesWith(CRectangle* const rect);
	bool CheckCollision(Collider* const collider);

private:

	//Rectangle's width and height.
	float width;
	float height;
	
};

