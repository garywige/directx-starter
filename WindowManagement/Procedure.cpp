#include ".\Procedure.h"
#include "..\State\IStateManager.h"

LRESULT CALLBACK Procedure::Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		create(hWnd, lParam);
		return 0;
	case WM_PAINT:
		paint(hWnd);
		return 0;
	case WM_DESTROY:
		destroy();
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void Procedure::create(HWND hWnd, LPARAM lParam)
{
	IStateManager* pStateManager = 0;
	CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
	pStateManager = (IStateManager*)(pCreate->lpCreateParams);
	SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pStateManager);
}

void Procedure::paint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);

	FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
	EndPaint(hWnd, &ps);
}

void Procedure::destroy()
{
	PostQuitMessage(0);
}


IStateManager* Procedure::getStateManager(HWND hWnd)
{
	return (IStateManager*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
}