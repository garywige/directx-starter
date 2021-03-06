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
	int width = 800;
	int height = 600;

	// Register the window class
	const wchar_t className[] = L"WigeDevMain";
	WindowRegistrar().Register(className, Procedure::Proc, hInstance);

	// Create the window
	IStateManager* pStateMgr = SingletonFactory<StateManager>().Create();
	HWND hWnd = WindowCreator(pStateMgr).Create(className, L"DirectX Starter", hInstance, width, height);
	if (hWnd == NULL)
		return 0;

	ShowWindow(hWnd, nCmdShow);

	// Initialize D3D
	IDXGISwapChain* pSwapChain = 0;
	ID3D11Device* pDevice = 0;
	ID3D11DeviceContext* pContext = 0;
	ID3D11RenderTargetView* pRTVBackBuffer = 0;
	D3DInitializer d3dInit(hWnd, width, height);
	d3dInit.Initialize(&pSwapChain, &pDevice, &pContext, &pRTVBackBuffer);

	// Enter game loop
	MSG msg = {};
	MessageHandler handler;
	GameLoop((IMessageHandler*)&handler, &msg, pSwapChain, pDevice, pContext, pRTVBackBuffer).Loop();
	
	return 0;
}
