#pragma once

#include "Sprite.h"

class AnimatedSprite :
	public Sprite
{
public:
	AnimatedSprite();
	AnimatedSprite(std::string path, int srcTop, int srcLeft, float frameWidth, int frameHeight, int nbRow, int nbCol, int frameRate, bool looping);
	~AnimatedSprite();

	virtual void Update(float dt);
	virtual void Draw();

private:

	RECT initialRect;
	bool isLooping;
	int nbFrame;
	int nbRow;
	int nbCol;
	int frameRate;

	RECT currentRect;
	float currentTime;
	int currentRow;
	int currentCol;

	D3DXVECTOR3 position1;
	float x, y, z;
};