#include "Component.h"

std::vector<Component*>Component::components;

Component::Component()
	: position(0.f, 0.f, 0.f)
{
	components.push_back(this);
}
Component::Component(float x, float y, float z)
	: position(x, y, z)
{
	components.push_back(this);
}
Component::~Component()
{
}
