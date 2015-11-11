#pragma once
#include "Component.h"
class TextFont :
	public Component
{
public:
	TextFont();
	TextFont(std::string text, std::string fontname);
	TextFont(std::string text, float x, float y, float z, float width, float heigth, std::string fontName);

	void SetText(std::string text){ this->text = text; }

	~TextFont();

	virtual void Draw();

protected:
	ID3DXFont*  mFont;
	std::string text;
	std::string fontName;
};

