#include "Component.h"

std::vector<Component*>Component::components;

Component::Component()
	: position(0.f, 0.f, 0.f)
	, isVisible(true)
	, isActive(true)
{
	components.push_back(this);
}
Component::Component(float x, float y, float z)
	: position(x, y, z)
	, isVisible(true)
	, isActive(true)
{
	components.push_back(this);
}
Component::~Component()
{
}
