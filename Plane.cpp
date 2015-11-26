#include "Plane.h"

Plane::Plane()
	: Model(4, 2)
{
	BuildVertexBuffer();
	BuildIndexBuffer();
}

Plane::~Plane()
{
	ReleaseCOM(mVB);
	ReleaseCOM(mIB);
}

void Plane::BuildVertexBuffer()
{
	HR(gD3DDevice->CreateVertexBuffer(4 * sizeof(VertexPos),
		D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &mVB, 0));

	D3DXVECTOR3* v = 0;
	HR(mVB->Lock(0, 0, (void**)&v, 0));

	// v0________v3
	//  |\       |
	//  |  \     |
	//  |    \   |
	//  v1_____\_v2

	v[0] = D3DXVECTOR3(-0.5f, 0.5f, 0.0f);
	v[1] = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);
	v[2] = D3DXVECTOR3(0.5f, -0.5f, 0.0f);
	v[3] = D3DXVECTOR3(0.5f, 0.5f, 0.0f);

	HR(mVB->Unlock());
}

void Plane::BuildIndexBuffer()
{
	HR(gD3DDevice->CreateIndexBuffer(6 * sizeof(WORD), D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16, D3DPOOL_MANAGED, &mIB, 0));

	WORD* k = 0;
	HR(mIB->Lock(0, 0, (void**)&k, 0));

	// Triangle 1
	k[0] = 0; k[1] = 1; k[2] = 2;

	// Trangle 2
	k[3] = 2; k[4] = 3; k[5] = 0;

	HR(mIB->Unlock());
}