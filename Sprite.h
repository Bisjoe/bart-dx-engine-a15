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
	void SetSprite(std::string path);

	virtual ~Sprite();

	virtual void Update(float dt){}
	virtual void Draw();

protected:

	D3DXIMAGE_INFO infos;
	std::string path;
	IDirect3DTexture9* texture;
	D3DXVECTOR3 position;
	RECT srcRect;
	D3DXVECTOR3 center;
};

