#pragma once
#include <vector>
#include "D3DApp.h"
#include <math.h>
#include "Component.h"
class Collider
{
	
public:
	enum Type
	{
		RECTANGLE, CIRCLE
	};
	Collider();
	Collider(Component* gameObject, Type type, float x, float y);

	~Collider();
	D3DXVECTOR2 GetPosition() { return position; }

	Component* GetGameObject() { return gameObject; }
	const Type GetType() { return type; }
	void SetEnabled(bool isEnabled) { this->isEnabled = isEnabled; }

	//Setters
	void SetPosition(const float x, const float y);


	//Checks if a point is contained within the collider
	virtual bool Contains(const float x, const float y) = 0;


	//Checks collision with another collider
	virtual bool CheckCollision(Collider* const collider) = 0;

	//Returns the current colliding colliders as a vector
	std::vector<Collider*> LookForCollisions();

protected:
	D3DXVECTOR2 position;

private:
	//Holds a pointer to the object that own this collider. It's the most crucial part.
	Component* gameObject;

	//Collider type, see enum
	Type type;

	//Will trigger collisions or not. true by default.
	bool isEnabled;

	//Holds a list of the colliders currently colliding
	std::vector<Collider*> collidees;

	//Every colliders currently existing
	static std::vector<Collider*> colliders;

};

