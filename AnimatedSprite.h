#pragma once

#include "Sprite.h"
class AnimatedSprite :
	public Sprite
{
public:
	AnimatedSprite();
	AnimatedSprite(std::string path, int srcTop, int srcLeft, float frameWidth, int frameHeight, int nbRow, int nbCol, int frameRate, bool looping);
	~AnimatedSprite();
	void SetAnimatedVisible(bool visible){ isVisible = visible; }

	virtual void Start(){}
	virtual void Update(float dt);

private:
	//bool isVisible;
	RECT initialRect;
	bool isLooping;
	int nbFrame;
	int nbRow;
	int nbCol;
	int frameRate;
	float currentTime;
	int currentRow;
	int currentCol;

	D3DXVECTOR3 position1;
	float x, y, z;
	//bool isVisible;


protected:
	bool isVisible;
};