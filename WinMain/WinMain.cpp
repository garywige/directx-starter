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
	// Variables
	const wchar_t className[] = L"WigeDevMain";
	StateManager* pStateManager = SingletonFactory<StateManager>().Create();

	// Register the window class
	WindowRegistrar().Register(className, Procedure::Proc, hInstance);

	// Create the window
	HWND hWnd = WindowCreator(pStateManager).Create(className, L"My Window", hInstance);
	if (hWnd == NULL)
		return 0;

	ShowWindow(hWnd, nCmdShow);

	// Enter game loop
	MSG msg = {};
	MessageHandler handler;
	GameLoop((IMessageHandler*)&handler, &msg).Loop();
	
	return 0;
}
