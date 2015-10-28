#pragma once

#include "Component.h"
#include "D3DApp.h"

class Sprite :
	public Component
{
public:
	Sprite();
	Sprite(std::string path);
	Sprite(std::string path, float x, float y, float z);

	virtual ~Sprite();

	virtual void Update(){}
	void Draw();

private:
	
	std::string path;
	IDirect3DTexture9* texture;
	D3DXVECTOR3 position;
	D3DXVECTOR3 center;
};

