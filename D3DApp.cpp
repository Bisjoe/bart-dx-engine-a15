#include "D3DApp.h"

extern D3DApp* gD3DApp = 0;
extern IDirect3DDevice9* gD3DDevice = 0;

LRESULT CALLBACK MainWndProc( HWND hwnd
						    , UINT msg
						    , WPARAM wParam
						    , LPARAM lParam)
{
	if (gD3DApp != 0)
	{
		return gD3DApp->MsgProc(msg, wParam, lParam);
	}
	else
	{
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

D3DApp::D3DApp()
{

}

D3DApp::D3DApp( HINSTANCE hInstance
			  , std::string winCaption
			  , D3DDEVTYPE devType
			  , DWORD requestedVP)
			  
	: mIsPaused(false)
	, mhMainWindow(0)
	, mRequestedVP(requestedVP)
	, mDevType(devType)
	, mhInstance(hInstance)
	, mWinCaption(winCaption)
{
	srand((unsigned int)time(0));

	// Standard input/output/error file pointers
	FILE *fpStdIn, *fpStdOut, *fpStdErr;

#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (AllocConsole())
	{
		// Assign the stdin/stdout/stderr streams to the newly created console
		_tfreopen_s(&fpStdIn, _T("CONIN$"), _T("r"), stdin);
		_tfreopen_s(&fpStdOut, _T("CONOUT$"), _T("w"), stdout);
		_tfreopen_s(&fpStdErr, _T("CONOUT$"), _T("w"), stderr);
	}
#endif

	InitMainWindow();
	InitDirect3D();
}

D3DApp::~D3DApp()
{
	ReleaseCOM(mD3DObject);
	ReleaseCOM(spriteBatch);
	delete gTimer;
}

void D3DApp::InitMainWindow()
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = MainWndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = mhInstance;
	wc.hIcon = ::LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = ::LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = static_cast<HBRUSH>(::GetStockObject(WHITE_BRUSH));
	wc.lpszMenuName = 0;
	wc.lpszClassName = _T("Hello");

	if (!::RegisterClass(&wc))
	{
		MessageBox(0, _T("RegisterClass - Failed"), 0, 0);
		PostQuitMessage(0);
	}

	RECT r = { 0, 0, 800, 551 };
	mhMainWindow = CreateWindow( wc.lpszClassName
							   , mWinCaption.c_str()
							   , WS_OVERLAPPEDWINDOW
							   , r.left, r.top
							   , r.right, r.bottom
							   , 0, 0
							   , mhInstance
							   , 0);

	if (!mhMainWindow)
	{
		::MessageBox(0, _T("CreateWindow - Failed"), 0, 0);
		PostQuitMessage(0);
	}

	::ShowWindow(mhMainWindow, SW_SHOW);
	::UpdateWindow(mhMainWindow);
}

void D3DApp::InitDirect3D()
{
	// Step 1
	mD3DObject = Direct3DCreate9(D3D_SDK_VERSION);
	if (!mD3DObject)
	{
		MessageBox(0, _T("Direct3DCreate9 - Failed"), _T("Error!"), MB_OK);
		PostQuitMessage(0);
	}

	// Step 2
	D3DDISPLAYMODE mode;
	HR(mD3DObject->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &mode));
	HR(mD3DObject->CheckDeviceType(D3DADAPTER_DEFAULT, mDevType, mode.Format, mode.Format, true));
	HR(mD3DObject->CheckDeviceType(D3DADAPTER_DEFAULT, mDevType, D3DFMT_X8R8G8B8, D3DFMT_X8R8G8B8, false));

	// Step 3
	D3DCAPS9 caps;
	HR(mD3DObject->GetDeviceCaps(D3DADAPTER_DEFAULT, mDevType, &caps));
	DWORD devBehaviourFlags = 0;

	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		devBehaviourFlags |= mRequestedVP;
	else
		devBehaviourFlags |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	if (caps.DevCaps & D3DDEVCAPS_PUREDEVICE && devBehaviourFlags & D3DCREATE_HARDWARE_VERTEXPROCESSING)
		devBehaviourFlags |= D3DCREATE_PUREDEVICE;

	mD3Dpp.BackBufferWidth = 0;
	mD3Dpp.BackBufferHeight = 0;
	mD3Dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	mD3Dpp.BackBufferCount = 1;
	mD3Dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	mD3Dpp.MultiSampleQuality = 0;
	mD3Dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	mD3Dpp.hDeviceWindow = mhMainWindow;
	mD3Dpp.Windowed = true;
	mD3Dpp.EnableAutoDepthStencil = true;
	mD3Dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	mD3Dpp.Flags = 0;
	mD3Dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	mD3Dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	HR(mD3DObject->CreateDevice(D3DADAPTER_DEFAULT, mDevType, mhMainWindow, devBehaviourFlags, &mD3Dpp, &gD3DDevice));
	if (!gD3DDevice)
	{
		MessageBox(0, 0, "CreateDevice - Failed!", MB_OK);
	}

	HR(D3DXCreateSprite(gD3DDevice, &spriteBatch));
	OnResetDevice();
}

int D3DApp::Run()
{
	//
	//
	//

	DirectInput di(mhInstance, mhMainWindow, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	gDInput = &di;
	
	gTimer = new GameTimer();
	gTimer->Reset();
	gTimer->Start();

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			RedrawWindow(mhMainWindow, 0, 0, RDW_INVALIDATE);
			if (gD3DDevice != 0)
			{
				if (mIsPaused)
				{
					Sleep(20);
					SKIP;
				}

				if (!GetDeviceLost())
				{
					gDInput->poll();
					gTimer->Tick();

					Update(gTimer->GetDeltaTime());

					PreDraw();
					Draw();
					PostDraw();
				}
			}
		}
	}
	return (int)msg.wParam;
}

HRESULT D3DApp::MsgProc(UINT msg
	, WPARAM wParam
	, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		::MessageBox(0, _T("Hello world"), _T("Hello"), MB_OK);
		return 0;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			DestroyWindow(mhMainWindow);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CLOSE:
		DestroyWindow(mhMainWindow);
		return 0;
	}

	return DefWindowProc(mhMainWindow, msg, wParam, lParam); 
}

bool D3DApp::GetDeviceLost()
{
	HRESULT hr = gD3DDevice->TestCooperativeLevel();

	switch (hr)
	{
	case D3DERR_DEVICELOST:
		Sleep(20);
		return true;
	case D3DERR_DRIVERINTERNALERROR:
		MessageBox(0, "Internal drive error... Exiting", "Driver error", 0);
		PostQuitMessage(0);
		return true;
	case D3DERR_DEVICENOTRESET:
		OnLostDevice();
		HR(gD3DDevice->Reset(&mD3Dpp));
		OnResetDevice();
		return false;
	default:
		return false;
	}
}

void D3DApp::OnLostDevice()
{
	HR(gD3DApp->GetSpriteBatch()->OnLostDevice());
}

void D3DApp::OnResetDevice()
{
	RECT r;
	D3DXMATRIX view, proj;
	D3DXVECTOR3 pos(0.f, 0.f, 1000.f);
	D3DXVECTOR3 up(0.f, 1.f, 0.f);
	D3DXVECTOR3 target(0.f, 0.f, 0.f);

	GetClientRect(GetMainWindowHandle(), &r);
	D3DXMatrixLookAtLH(&view, &pos, &target, &up);
	D3DXMatrixOrthoLH(&proj, (float)r.right, (float)r.bottom, 1.f, 5000.f);

	HR(gD3DDevice->SetRenderState(D3DRS_LIGHTING, false));
	HR(gD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE));

	HR(gD3DDevice->SetTransform(D3DTS_VIEW, &view));
	HR(gD3DDevice->SetTransform(D3DTS_PROJECTION, &proj));

	
	HR(spriteBatch->OnResetDevice());
}

void D3DApp::Update(float dt)
{
	for (auto x: Component::components )
	{
		x->Update(dt);
	}
}

void D3DApp::Draw()
{
	for (auto x : Component::components)
	{
		x->Draw();
	}
}

void D3DApp::PreDraw()
{
	HR(gD3DDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(128, 128, 128), 1.0f, 0));

	HR(gD3DDevice->BeginScene());

	HR(spriteBatch->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE | D3DXSPRITE_DONOTMODIFY_RENDERSTATE));
}

void D3DApp::PostDraw()
{
	HR(spriteBatch->End());

	HR(gD3DDevice->EndScene());

	HR(gD3DDevice->Present(0, 0, 0, 0));
}

