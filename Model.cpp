#include "Model.h"

Model::Model()
	: nbVertices(0)
	, nbTriangles(0)
	, mVB(nullptr)
	, mIB(nullptr) { }

Model::Model(int nbtriangles)
	: nbVertices(0)
	, nbTriangles(nbtriangles)
	, mVB(nullptr)
	, mIB(nullptr) { }

Model::Model(int nbVertices, int nbTriangles) 
	: nbVertices(nbVertices)
	, nbTriangles(nbTriangles)
	, mVB(nullptr)
	, mIB(nullptr) { }

Model::~Model() { }

void Model::Draw()
{
	if (mVB != nullptr)
	{
		HR(gD3DDevice->SetVertexDeclaration(VertexPos::decl));
		HR(gD3DDevice->SetStreamSource(0, mVB, 0, sizeof(VertexPos)));
		HR(gD3DDevice->SetIndices(mIB));

		if (mIB == nullptr)
		{
			HR(gD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, nbTriangles));
		}
		else
		{
			HR(gD3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, nbVertices, 0, nbTriangles));
		}
	}
}