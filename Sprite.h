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

	void SetPosition(D3DXVECTOR3& pos){
		Component::SetPosition(pos);
		//position = pos;
		boxCollision->SetPosition(pos.x, pos.y);
	}

<<<<<<< HEAD
	void SetPosition(float x,float y){
		position.x = x;
		position.y = y;
		boxCollision->SetPosition(x, y);
	}

	D3DXVECTOR3 SetSize()
	{
		return D3DXVECTOR3(infos.Width, infos.Height, 0.f);
	}

=======
>>>>>>> 1e37756406014ea309a8fa04215414c33416eaf8
	void SetSprite(std::string path);
	
	virtual ~Sprite();

	virtual void Update(float dt){}
	virtual void Draw();

protected:

	D3DXIMAGE_INFO infos;
	std::string path;
	IDirect3DTexture9* texture;
	bool isVisible;
	CRectangle* boxCollision;
	RECT srcRect;
	D3DXVECTOR3 center;

private:
	D3DXVECTOR3 position;
	
};

