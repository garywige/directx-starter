#pragma once
#include <Windows.h>

class WindowRegistrar
{
public:
	WindowRegistrar();
	void Register(LPCWSTR className, WNDPROC wndProc, HINSTANCE hInstance);
};