#pragma once

#include "Sprite.h"
#include "D3DApp.h"


class Egg
	: public Sprite
{
public:
	Egg();
	enum EGG { Egg1, Egg2, Egg3, Egg4 };
	~Egg();

	Egg(EGG);

	void Update(float dt);
	void Draw();

	void Shout(){ std::cout << "Shout EGG!!" << std::endl; }

private:


};

