#include "Sprite.h"

Sprite::Sprite()
	:Component()
	,center(0.f, 0.f, 0.f)
	, texture(nullptr)
{
	boxCollision = new CRectangle(this, 0, 0, 0, 0);
	boxCollision->SetPosition(0.f, 0.f);
}

Sprite::Sprite(std::string path)
	:Component()
	,center(0.f,0.f,0.f)
{
	boxCollision = new CRectangle(this, 0, 0, infos.Width, infos.Height);
	SetSprite(path);
}

Sprite::Sprite(std::string path, float x, float y, float z)
	:Component()
	,center(0.f, 0.f, 0.f)
{
	
	boxCollision = new CRectangle(this, x, y, infos.Width, infos.Height);
	SetSprite(path);
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

	boxCollision->SetSize(infos.Width, infos.Height);
}
void Sprite::SetSprite(std::string path, float top, float left)
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, path.c_str(), 0, 0, 0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT,
		D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), &infos, NULL, &texture));
	
	srcRect.top = top;
	srcRect.left = left;
	srcRect.right = infos.Width;
	srcRect.bottom = infos.Height;

	boxCollision->SetSize(infos.Width, infos.Height);
}
void Sprite::Draw()
{	
	if (texture)
	{
		gD3DApp->GetSpriteBatch()->Draw(texture, &srcRect, &center, &Component::GetPosition(), D3DCOLOR_XRGB(255, 255, 255));
		HR(gD3DApp->GetSpriteBatch()->Flush());
	}
}
