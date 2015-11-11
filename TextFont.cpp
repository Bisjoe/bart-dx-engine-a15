#include "TextFont.h"


TextFont::TextFont()
	: Component()
	, mFont(nullptr)
	, text(nullptr)
	, fontName(nullptr)
{
	D3DXFONT_DESC fontDesc;
	fontDesc.Width = 40;
	fontDesc.Height = 40;
	fontDesc.MipLevels = 0;
	fontDesc.Italic = false;
	fontDesc.CharSet = DEFAULT_CHARSET;
	fontDesc.OutputPrecision = OUT_DEFAULT_PRECIS;
	fontDesc.Quality = DEFAULT_QUALITY;
	fontDesc.PitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	strcpy_s(fontDesc.FaceName, _T("ceriph 05_64"));

	D3DXCreateFontIndirect(gD3DDevice, &fontDesc, &mFont);
}

TextFont::TextFont(std::string text, std::string fontName)
	: Component()
{
	this->text = text;

	D3DXFONT_DESC fontDesc;
	fontDesc.Width = 40;
	fontDesc.Height = 40;
	fontDesc.MipLevels = 0;
	fontDesc.Italic = false;
	fontDesc.CharSet = DEFAULT_CHARSET;
	fontDesc.OutputPrecision = OUT_DEFAULT_PRECIS;
	fontDesc.Quality = DEFAULT_QUALITY;
	fontDesc.PitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	strcpy_s(fontDesc.FaceName, _T(fontName.c_str()));

	D3DXCreateFontIndirect(gD3DDevice, &fontDesc, &mFont);
}

TextFont::TextFont(std::string text, float x, float y, float z, float width, float heigth, std::string fontName)
	: Component(x, y, z)
{
	this->text = text;

	D3DXFONT_DESC fontDesc;
	fontDesc.Width = width;
	fontDesc.Height = heigth;
	fontDesc.MipLevels = 0;
	fontDesc.Italic = true;
	fontDesc.CharSet = DEFAULT_CHARSET;
	fontDesc.OutputPrecision = OUT_DEFAULT_PRECIS;
	fontDesc.Quality = DEFAULT_QUALITY;
	fontDesc.PitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	strcpy_s(fontDesc.FaceName, _T(fontName.c_str()));

	D3DXCreateFontIndirect(gD3DDevice, &fontDesc, &mFont);
}

TextFont::~TextFont()
{
}

void TextFont::Draw()
{
	if (GetIsVisible())
	{
		RECT formatRect;
		GetClientRect(gD3DApp->GetMainWindowHandle(), &formatRect);
		formatRect.left = Component::GetPosition().x;
		formatRect.top = Component::GetPosition().y;
		HR(mFont->DrawText(0, _T(text.c_str())
			, -1, &formatRect
			, DT_CENTER | DT_VCENTER
			, D3DCOLOR_XRGB(256, 256, 256)));
	}
}
