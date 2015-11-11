#pragma once

#include<vector>
#include <string>

class Component
{
	friend class  D3DApp;

public:
	Component();
	virtual ~Component();
	virtual void Start(){}
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	void SetID(std::string id){ this->id = id; }
	const std::string GetID(){ return id; }
	//void SetID(std::string path){ this->path = path; }
	//std::string getID(){ return path; }

private:
	static std::vector<Component*>components;
	 std::string id;
};

