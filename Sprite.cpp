#include "Sprite.h"



Sprite::Sprite()
	: center(0.f, 0.f, 0.f)
	, position(0.f, 0.f, 0.f)
	, texture(nullptr)
	, isVisible(true)
{
	boxCollision.SetPosition(0.f, 0.f);
}

Sprite::Sprite(std::string path)
	: center(0.f,0.f,0.f)
	, position(0.f,0.f, 0.f)
	, isVisible(true)
{
	SetSprite(path);
	boxCollision.SetPosition(0.f, 0.f);
}

Sprite::Sprite(std::string path, float x, float y, float z)
	: center(0.f, 0.f, 0.f)
	, position(x, y, z)
	, isVisible(true)
{
	SetSprite(path);
	boxCollision.SetPosition(x, y);
}

Sprite::~Sprite()
{

}

void Sprite::Draw()
{
	if (texture)
	{
		HR(gD3DApp->GetSpriteBatch()->Draw(texture, 0, &center, &position, D3DCOLOR_XRGB(255, 255, 255)));
		HR(gD3DApp->GetSpriteBatch()->Flush());
	}
}
