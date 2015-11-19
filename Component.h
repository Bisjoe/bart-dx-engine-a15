#pragma once

#include "D3DApp.h"

class Component
{
	friend class  D3DApp;

public:
	Component();
	Component(float x, float y, float z);
	virtual ~Component();
	virtual void Start(){}
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;

	bool GetIsEnable() const { return isActive && isVisible; }
	void SetEnable(bool isEnable){ 
		this->isActive = isEnable; 
		this->isVisible = isEnable; 
	}

	bool GetIsActive() const { return isActive; }
	void SetActive(bool isActive){ 
		this->isActive = isActive; 
	}

	void SetVisible(bool visible){ isVisible = visible; }
	bool GetIsVisible() const { return isVisible; }

	D3DXVECTOR3 GetPosition() const { return position; }
	virtual void SetPosition(D3DXVECTOR3& pos){
		position = pos;
	}
	void SetPosition(float x, float y){
		position.x = x;
		position.y = y;
	}
	void SetID(std::string id){ this->id = id; }
	const std::string GetID(){ return id; }

protected:
	static std::vector<Component*>components;
	bool isVisible;
	bool isActive;

private:
	
	 std::string id;
	 D3DXVECTOR3 position;

};

