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

	void SetPosition(D3DXVECTOR3& pos){ position = pos; }
	void SetSprite(std::string path){ HR(D3DXCreateTextureFromFile(gD3DDevice, path.c_str(), &texture)); }

	virtual ~Sprite();

	virtual void Update(float dt){}
	void Draw();

protected:
	
	std::string path;
	IDirect3DTexture9* texture;
	D3DXVECTOR3 position;
	D3DXVECTOR3 center;
};

