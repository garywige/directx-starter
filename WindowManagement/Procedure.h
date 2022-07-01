#pragma once
#include <Windows.h>
#include "..\State\IStateManager.h"

class Procedure
{
public:
	static LRESULT CALLBACK Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:
	static void create(HWND hWnd, LPARAM lParam);
	static void paint(HWND hWnd);
	static void destroy();
	static IStateManager* getStateManager(HWND hWnd);
};