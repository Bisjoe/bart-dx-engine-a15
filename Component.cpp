#include "Component.h"

std::vector<Component*>Component::components;

Component::Component()
{
	components.push_back(this);
}


Component::~Component()
{
}