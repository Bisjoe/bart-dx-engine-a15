#ifndef D3D_UTILS_H
#define D3D_UTILS_H

// Includes Direct3D
#include <d3dx9.h>
#include <DxErr.h>

// Includes STL
#include <iostream>
#include <string>
#include <sstream>

// Includes C
#include <tchar.h>
#include <time.h>

#include "DirectInput.h"
#include "GameTimer.h"

#define SKIP continue

// Forward declaration
class D3DApp;
extern D3DApp* gD3DApp;
extern IDirect3DDevice9* gD3DDevice;

#define ReleaseCOM(x)	\
{						\
	if(x)				\
	{					\
		x->Release();	\
		x = 0;			\
	}					\
}

#if defined(DEBUG) | defined(_DEBUG)
#ifndef HR
#define HR(x)										\
{													\
	HRESULT hr = x;									\
	if(FAILED(hr))									\
	{												\
		DXTrace(__FILE__,__LINE__, hr, #x, true);	\
	}												\
}
#endif
#else
#ifndef HR
#define HR(x) x;
#endif
#endif // Debug
#endif // _H