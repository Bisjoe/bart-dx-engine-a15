#ifndef VERTEX_H
#define VERTEX_H

#include "D3DUtils.h"

struct VertexPos
{
	VertexPos()
		: pos(0.0f, 0.0f, 0.0f){}	
	VertexPos(float x, float y, float z)
		: pos(x, y, z){}

	D3DXVECTOR3 pos;

	static IDirect3DVertexDeclaration9* decl;
};

struct VertexPosCol
{
	VertexPosCol()
		: pos(0.0f, 0.0f, 0.0f), color(0x00000000){}
	VertexPosCol(float x, float y, float z, const D3DCOLOR& c)
		: pos(x, y, z), color(c){}

	D3DXVECTOR3 pos;
	D3DCOLOR color;

	static IDirect3DVertexDeclaration9* decl;
};

void InitAllVertexDeclaration();
void DestroyAllVertexDeclaration();

#endif