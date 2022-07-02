#include ".\WinMain.h"
#include "..\WindowManagement\WindowRegistrar.h"
#include "..\WindowManagement\WindowCreator.h"
#include "..\WindowManagement\MessageHandler.h"
#include "..\WindowManagement\Procedure.h"
#include "..\Factory\SingletonFactory.h"
#include "..\Factory\SingletonFactory.cpp"
#include "..\State\StateManager.h"
#include "..\WindowManagement\GameLoop.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	// Register the window class
	const wchar_t className[] = L"WigeDevMain";
	WindowRegistrar().Register(className, Procedure::Proc, hInstance);

	// Create the window
	IStateManager* pStateMgr = SingletonFactory<StateManager>().Create();
	HWND hWnd = WindowCreator(pStateMgr).Create(className, L"DirectX Starter", hInstance);
	if (hWnd == NULL)
		return 0;

	ShowWindow(hWnd, nCmdShow);

	// Enter game loop
	MSG msg = {};
	MessageHandler handler;
	GameLoop((IMessageHandler*)&handler, &msg).Loop();
	
	return 0;
}
