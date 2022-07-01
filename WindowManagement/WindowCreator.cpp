#include "WindowCreator.h"

WindowCreator::WindowCreator(IStateManager* stateManager)
{
	pStateManager = stateManager;
}

HWND WindowCreator::Create(const wchar_t* className, const wchar_t* title, HINSTANCE hInstance)
{
	return CreateWindowEx(
		0,
		className,
		title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		pStateManager);
}