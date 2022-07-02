#include ".\WinMain.h"
#include "..\WindowManagement\WindowRegistrar.h"
#include "..\WindowManagement\WindowCreator.h"
#include "..\WindowManagement\MessageHandler.h"
#include "..\WindowManagement\Procedure.h"
#include "..\Factory\SingletonFactory.h"
#include "..\Factory\SingletonFactory.cpp"
#include "..\State\StateManager.h"
#include "..\WindowManagement\GameLoop.h"
#include "..\D3D\D3DInitializer.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	// Register the window class
	const wchar_t className[] = L"WigeDevMain";
	WindowRegistrar().Register(className, Procedure::Proc, hInstance);

	// Create the window
	IStateManager* pStateMgr = SingletonFactory<StateManager>().Create();
	HWND hWnd = WindowCreator(pStateMgr).Create(className, L"DirectX Starter", hInstance, 800, 600);
	if (hWnd == NULL)
		return 0;

	ShowWindow(hWnd, nCmdShow);

	// Initialize D3D
	IDXGISwapChain* pSwapChain = 0;
	ID3D11Device* pDevice = 0;
	ID3D11DeviceContext* pContext = 0;
	D3DInitializer().Initialize(hWnd, &pSwapChain, &pDevice, &pContext);

	// Enter game loop
	MSG msg = {};
	MessageHandler handler;
	GameLoop((IMessageHandler*)&handler, &msg).Loop();
	
	return 0;
}
