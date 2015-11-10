#include "PowerUP.h"


PowerUp::PowerUp()
// Initialiseur
: Sprite()
{
	SetID(POWERUP_ID);
	SetSize(D3DXVECTOR3(27.0f, 36.0f, 0.0f));
}

PowerUp::PowerUp(POWERUP powerup)
	:Sprite()
{
	SetID(POWERUP_ID);
	SetSize(D3DXVECTOR3(27.0f, 36.0f, 0.0f));

	switch (powerup)
	{

	}
}

PowerUp::~PowerUp()
{

}

void PowerUp::Update(float dt)
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

void PowerUp::Draw()
{
	Sprite::Draw();

	D3DXMATRIX rotation;
	D3DXMatrixRotationZ(&rotation, D3DX_PI);

	HR(gD3DApp->GetSpriteBatch()->SetTransform(&rotation));
}
