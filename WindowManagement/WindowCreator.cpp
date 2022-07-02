#include "WindowCreator.h"

WindowCreator::WindowCreator(IStateManager* stateManager)
{
	pStateManager = stateManager;
}

HWND WindowCreator::Create(const wchar_t* className, const wchar_t* title, HINSTANCE hInstance, LONG width, LONG height)
{
	RECT wr = { 0, 0, width, height };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	return CreateWindowEx(
		0,
		className,
		title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		wr.right - wr.left,
		wr.bottom - wr.top,
		NULL,
		NULL,
		hInstance,
		pStateManager);
}