#include "Sprite.h"

Sprite::Sprite()
	: center(0.f, 0.f, 0.f)
	, position(0.f, 0.f, 0.f)
	, texture(nullptr)
{
	boxCollision->SetPosition(0.f, 0.f);
	boxCollision = new CRectangle(this, 0, 0, 0, 0);
}

Sprite::Sprite(std::string path)
	: center(0.f,0.f,0.f)
	, position(0.f,0.f, 0.f)
{
	SetSprite(path);
	boxCollision = new CRectangle(this, 0, 0, infos.Width, infos.Height);
}

Sprite::Sprite(std::string path, float x, float y, float z)
	: center(0.f, 0.f, 0.f)
	, position(x, y, z)
{
	SetSprite(path);
	boxCollision = new CRectangle(this, x, y, infos.Width, infos.Height);
}



Sprite::~Sprite()
{
}

void Sprite::SetSprite(std::string path)
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, path.c_str(), 0, 0, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT,
		D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), &infos, NULL, &texture));

	srcRect.top = 0;
	srcRect.left = 0;
	srcRect.right = infos.Width;
	srcRect.bottom = infos.Height;
}

void Sprite::Draw()
{
	//if (isVisible)
	//{
		if (texture)
		{
			HR(gD3DApp->GetSpriteBatch()->Draw(texture, &srcRect, &center, &position, D3DCOLOR_XRGB(255, 255, 255)));
			HR(gD3DApp->GetSpriteBatch()->Flush());
		}
	//}
	
}
