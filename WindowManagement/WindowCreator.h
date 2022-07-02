#pragma once
#include <Windows.h>
#include "..\State\IStateManager.h"

class WindowCreator
{
public:
	WindowCreator(IStateManager* stateManager);

	HWND Create(const wchar_t* className, const wchar_t* title, HINSTANCE hInstance, LONG width, LONG height);

private:
	IStateManager* pStateManager;
};