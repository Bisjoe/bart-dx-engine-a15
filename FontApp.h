#pragma once
#include "D3DApp.h"
class FontApp :
	public D3DApp
{
public:
	FontApp(HINSTANCE hInstance
		, std::string winCaption
		, D3DDEVTYPE devType
		, DWORD requestedVP);
	~FontApp();

	// Methods
	void OnLostDevice();
	void OnResetDevice();
	void Draw();

private:
	FontApp(){}
	ID3DXFont* mFont;
};

