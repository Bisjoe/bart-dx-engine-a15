#include <iostream>
#include <fstream>

#include <d3dx9.h>
#include "FontApp.h"

#pragma region Exemple: Destructeur Virtuel
class A
{
public:
	A();
	A(int i);
	~A();

protected: 
	int i;
};
A::A(){}
A::A(int i){ this->i = i; }
A::~A(){ std::cout << "A Destroyed!"; }

class B : public A
{
public:
	B();
	B(int i);
	~B();
};
B::B(): A(){}
B::B(int i): A(i){}
B::~B(){ std::cout << "B Destroyed!"; }
#pragma endregion

int WINAPI WinMain( HINSTANCE hInstance
				  , HINSTANCE prevInstance
				  , PSTR cmdLine
				  , int showCmd)
{
	FontApp app( hInstance, "Hello Direct 3D!"
			  , D3DDEVTYPE_HAL, D3DCREATE_HARDWARE_VERTEXPROCESSING);

	gD3DApp = &app;

	return gD3DApp->Run();
}