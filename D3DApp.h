#pragma once

#include "D3DUtils.h"
#include "Component.h"

class D3DApp
{
public:
	// CTORS / DTORS
	D3DApp();
	D3DApp( HINSTANCE hInstance
		  , std::string winCaption
		  ,	D3DDEVTYPE devType
		  , DWORD requestedVP);

	virtual ~D3DApp();
	
	// Getters / Setters
	HWND GetMainWindowHandle()		{ return mhMainWindow; }
	HINSTANCE GetInstanceHandle()	{ return mhInstance; }
	bool GetDeviceLost();
	ID3DXSprite* GetSpriteBatch()	{ return spriteBatch; }

	// Methods
	virtual bool CheckDeviceCaps()	{ return true; }
	virtual void OnLostDevice();
	virtual void OnResetDevice();
	virtual void Update(float dt);
	virtual void PreDraw();
	virtual void Draw();
	virtual void PostDraw();
	virtual void InitMainWindow();
	virtual void InitDirect3D();
	virtual int Run();
	virtual HRESULT MsgProc( UINT msg
						   , WPARAM wParam
						   , LPARAM lParam);

private:
	// Variables
	bool mIsPaused;
	HWND mhMainWindow;
	DWORD mRequestedVP;
	D3DDEVTYPE mDevType;
	HINSTANCE mhInstance;
	std::string mWinCaption;

	// Interface COM
	IDirect3D9* mD3DObject;
	D3DPRESENT_PARAMETERS mD3Dpp;

	ID3DXSprite* spriteBatch;
};

