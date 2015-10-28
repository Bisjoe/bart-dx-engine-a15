#pragma once
#include<vector>
#include <string>
class Component
{
	friend class  D3DApp;

public:
	Component();
	virtual ~Component();
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;

private:
	static std::vector<Component*>components;
};

