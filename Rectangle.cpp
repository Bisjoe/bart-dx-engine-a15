#include "Rectangle.h"


CRectangle::CRectangle()
	:Collider(nullptr, Type::RECTANGLE, 0, 0)
	, width(0)
	,height(0)
{
}
CRectangle::CRectangle(Component* caller, float x, float y, float width, float height)
	: Collider(caller,Type::RECTANGLE,x,y)
	, width(width)
	, height(height)
{
}
CRectangle::~CRectangle()
{
}
void CRectangle::SetSize(const float w, const float h)
{
	this->width = w;
	this->height = h;
}
bool CRectangle::Contains(const float x, const float y)
{
	return (x >= this->GetPosition().x && x <= (this->GetPosition().x + this->GetWidth()) && y >= this->GetPosition().y && y <= (this->GetPosition().y + this->GetHeight()));
}
bool CRectangle::CollidesWith(CRectangle* const rect)
{
	bool areColliding = false;
	if (this->GetPosition().x < (rect->GetPosition().x + rect->GetWidth()) && (this->GetPosition().x + this->GetWidth()) > rect->GetPosition().x &&
		this->GetPosition().y < (rect->GetPosition().y + rect->GetHeight()) && (this->GetPosition().y + this->GetHeight())> rect->GetPosition().y)
	{
		areColliding = true;
	}
	return areColliding;
}
bool CRectangle::CheckCollision(Collider* const collider)
{
	bool isColliding = false;

	//if (collider->GetType() == Type::CIRCLE)
	//{
	//	isColliding = static_cast<CCircle*>(collider)->CheckCollision(this);
	//}
	//else 
	if (collider->GetType() == Type::RECTANGLE)
	{
		isColliding = CollidesWith(static_cast<CRectangle*>(collider));
	}

	return isColliding;
}