#pragma once
#include "Component.h"
class Model :
	public Component
{
public:
	Model();
	Model(int nbtriangles);
	Model(int nbVertices, int nbTriangles);
	virtual ~Model();

	void OnLostDevice()		{ }
	void OnResetDevice()	{ }

	virtual void Update(float dt)	{ }
	virtual void Draw();

	virtual void BuildVertexBuffer() = 0;
	virtual void BuildIndexBuffer() = 0;

protected:

	int nbVertices;
	int nbTriangles;

	IDirect3DVertexBuffer9* mVB;
	IDirect3DIndexBuffer9* mIB;
};

