#pragma once
#include "Model.h"
class Plane :
	public Model
{
public:
	Plane();
	virtual ~Plane();

	virtual void Update(float dt) { }

	void BuildVertexBuffer();
	void BuildIndexBuffer();
};

