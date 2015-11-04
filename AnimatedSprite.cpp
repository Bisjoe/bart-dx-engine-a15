#include "AnimatedSprite.h"

#define GRAVITY_FORCE 5

AnimatedSprite::AnimatedSprite()
	: Sprite()
	, isLooping(true)
	, nbFrame(0)
	, nbRow(0)
	, nbCol(0)
	, frameRate(0)
	, currentTime(0)
	, currentRow(0)
	, currentCol(0)
	, isVisible(true)
{
	initialRect.left = 0;
	initialRect.top = 0;
	initialRect.right = 0;
	initialRect.bottom = 0;

	currentRect = initialRect;
}

AnimatedSprite::AnimatedSprite(std::string path, int srcTop, int srcLeft, float frameWidth, int frameHeight, int nbRow, int nbCol, int frameRate, bool looping)
	: Sprite(path)
	, isLooping(looping)
	, nbFrame(nbRow * nbCol)
	, nbRow(nbRow)
	, nbCol(nbCol)
	, frameRate(frameRate)
	, currentTime(0)
	, currentRow(0)
	, currentCol(0)
	, isVisible(true)
{
	initialRect.left = srcLeft;
	initialRect.top = srcTop;
	initialRect.right = frameWidth;
	initialRect.bottom = frameHeight;

	currentRect = initialRect;
	boxCollision->SetSize(frameWidth, frameHeight);
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::Update(float dt)
{
	Sprite::Update(dt);
	currentTime += dt;

	if (currentTime >= 1.0f / frameRate)
	{
		if (currentCol >= nbCol)
		{
			currentCol = 0;
		}
		else
		{
			currentCol++;
		}

		if (currentRow >= nbRow)
		{
			currentRow = 0;
		}
		else
		{
			currentRow++;
		}
		currentRect.top = currentRow * initialRect.bottom;
		currentRect.left = currentCol * initialRect.right;
		currentRect.right = currentRect.left + initialRect.right;
		currentRect.bottom = currentRect.top + initialRect.bottom;
		currentTime = 0.f;
	}
}

void AnimatedSprite::Draw()
{
	D3DXMATRIX rotation;
	D3DXMatrixRotationZ(&rotation, D3DX_PI);
	if (isVisible)
	{
		if (texture)
		{
			HR(gD3DApp->GetSpriteBatch()->Draw(texture, &currentRect, &center, &position, D3DCOLOR_XRGB(255, 255, 255)));
			HR(gD3DApp->GetSpriteBatch()->Flush());
			HR(gD3DApp->GetSpriteBatch()->SetTransform(&rotation));
		}
	}
	
}