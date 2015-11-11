#pragma once

#include "Component.h"
#include "D3DApp.h"
#include "Rectangle.h"

class Sprite :
	public Component
{
public:
	Sprite();
	Sprite(std::string path);
	Sprite(std::string path, float x, float y, float z);

	void SetPosition(D3DXVECTOR3& pos){
		Component::SetPosition(pos);
		boxCollision->SetPosition(pos.x, pos.y);
	}

	void SetSprite(std::string path);
	void SetSprite(std::string path, float top, float left);
	
	virtual ~Sprite();

	virtual void Update(float dt){}
	virtual void Draw();

protected:

	D3DXIMAGE_INFO infos;
	std::string path;
	IDirect3DTexture9* texture;
	CRectangle* boxCollision;
	RECT srcRect;
	D3DXVECTOR3 center;
};

