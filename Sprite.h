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
	void SetVisible(bool visible){ isVisible = visible; }
	D3DXVECTOR3 GetPosition() const { return position; }
	void SetSize(D3DXVECTOR3& scale)
	{
		boxCollision->SetSize(scale.x, scale.y);
	}
	void SetPosition(D3DXVECTOR3& pos)
	{ 
		position = pos; 
		boxCollision->SetPosition(pos.x, pos.y);
	}
	void SetSprite(std::string path )
	{ 
		HR(D3DXCreateTextureFromFileEx(gD3DDevice, path.c_str(), 0, 0, 0, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT,
			D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), &textureInfos, NULL,
			&texture));

		//boxCollision->SetSize(textureInfos.Width, textureInfos.Height);
	}

	virtual ~Sprite();

	virtual void Update(float dt){}
	void Draw();

protected:
	
	D3DXIMAGE_INFO textureInfos; 
	std::string path;
	IDirect3DTexture9* texture;
	
	D3DXVECTOR3 center;
	bool isVisible;
	CRectangle* boxCollision;

private:
	D3DXVECTOR3 position;
};

