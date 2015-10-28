#include "FontApp.h"

FontApp::FontApp( HINSTANCE hInstance
				, std::string winCaption
				, D3DDEVTYPE devType
				, DWORD requestedVP)
	: D3DApp(hInstance, winCaption,devType, requestedVP)
{
	D3DXFONT_DESC fontDesc;
	fontDesc.Width = 20;
	fontDesc.Height = 40;
	fontDesc.MipLevels = 0;
	fontDesc.Italic = true;
	fontDesc.CharSet = DEFAULT_CHARSET;
	fontDesc.OutputPrecision = OUT_DEFAULT_PRECIS;
	fontDesc.Quality = DEFAULT_QUALITY;
	fontDesc.PitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	strcpy_s(fontDesc.FaceName, _T("Time new Roman"));

	D3DXCreateFontIndirect(gD3DDevice, &fontDesc, &mFont);
}

FontApp::~FontApp()
{
	ReleaseCOM(mFont);
}

void FontApp::OnLostDevice()
{
	HR(mFont->OnLostDevice());
}

void FontApp::OnResetDevice()
{
	HR(mFont->OnResetDevice());
}

void FontApp::Draw()
{
	RECT formatRect;
	GetClientRect(GetMainWindowHandle(), &formatRect);

	mFont->DrawText( 0, _T("Hello Direct 3D!")
				   , -1, &formatRect
				   , DT_CENTER | DT_VCENTER
				   , D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256));
}
