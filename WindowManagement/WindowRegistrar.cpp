#include ".\WindowRegistrar.h"

WindowRegistrar::WindowRegistrar(){}

void WindowRegistrar::Register(LPCWSTR className, WNDPROC wndProc, HINSTANCE hInstance)
{
	WNDCLASS wc = {};

	wc.lpfnWndProc = wndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = className;

	RegisterClass(&wc);
}