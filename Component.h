#pragma once

#include "D3DApp.h"

class Component
{
	friend class  D3DApp;

public:
	Component();
	Component(float x, float y, float z);
	virtual ~Component();

	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;

	D3DXVECTOR3 GetPosition() const { return position; }
	virtual void SetPosition(D3DXVECTOR3& pos){
		position = pos;
	}
	void SetPosition(float x, float y){
		position.x = x;
		position.y = y;
	}
	std::string GetID() const { return id; }
	void SetID(std::string id){ this->id = id; }

private:
	static std::vector<Component*>components;
	std::string id;
	D3DXVECTOR3 position;

};

