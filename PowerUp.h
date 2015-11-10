#pragma once

#include "Sprite.h"
#include "RessourceID.h"
#include "D3DApp.h"


class PowerUp
	: public Sprite
{
public:
	PowerUp();
	enum POWERUP { Powerup1, Powerup2, Powerup3, Powerup4 };
	~PowerUp();

	PowerUp(POWERUP);

	void Update(float dt);
	void Draw();

private:


};

