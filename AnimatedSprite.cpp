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

	srcRect = initialRect;
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

	srcRect = initialRect;
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
		if (currentCol >= nbCol-1)
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

		srcRect.top = currentRow * initialRect.bottom;
		srcRect.left = currentCol * initialRect.right;
		srcRect.right = srcRect.left + initialRect.right;
		srcRect.bottom = srcRect.top + initialRect.bottom;
		currentTime = 0.f;
	}
}