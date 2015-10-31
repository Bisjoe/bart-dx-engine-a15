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
	void SetPosition(D3DXVECTOR3& pos)
	{ 
		position = pos; 
		boxCollision.SetPosition(pos.x, pos.y);
	}
	void SetSprite(std::string path){ HR(D3DXCreateTextureFromFile(gD3DDevice, path.c_str(), &texture)); }

	virtual ~Sprite();

	virtual void Update(float dt){}
	void Draw();

protected:
	
	std::string path;
	IDirect3DTexture9* texture;
	
	D3DXVECTOR3 center;
	bool isVisible;
	CRectangle boxCollision;

private:
	D3DXVECTOR3 position;
};

