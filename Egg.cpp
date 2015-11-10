#include "Egg.h"


Egg::Egg()
	: Sprite()
{
	//SetID(EGG_ID);
	boxCollision->SetSize(27.0f, 36.0f);
}

Egg::Egg(EGG egg)
	:Sprite()
{
	//SetID(EGG_ID);
	boxCollision->SetSize(27.0f, 36.0f);

	switch (egg)
	{
	case Egg::Egg1:
		SetSprite("images/Egg.png");
		break;
	case Egg::Egg2:
		SetSprite("images/Egg.png");
		break;
	case Egg::Egg3:
		SetSprite("images/Egg.png");
		break;
	case Egg::Egg4:
		SetSprite("images/Egg.png");
		break;
	default:
		break;
	}
}

Egg::~Egg()
{

}

void Egg::Update(float dt)
{
	if (gDInput->keyDown(DIK_RIGHTARROW))
	{
		SetPosition(D3DXVECTOR3(GetPosition().x - 50.f * dt, GetPosition().y, 0.f));
	}

	if ((gDInput->keyDown(DIK_LEFTARROW)))
	{
		SetPosition(D3DXVECTOR3(GetPosition().x + 50.f * dt, GetPosition().y, 0.f));
	}
}

void Egg::Draw()
{
	Sprite::Draw();

	D3DXMATRIX rotation;
	D3DXMatrixRotationZ(&rotation, D3DX_PI);

	HR(gD3DApp->GetSpriteBatch()->SetTransform(&rotation));
}
