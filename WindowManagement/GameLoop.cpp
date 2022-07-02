#include "GameLoop.h"
#include <D3DX10.h>

GameLoop::GameLoop(
	IMessageHandler* messageHandler,
	MSG* msg,
	IDXGISwapChain* pSwapChain,
	ID3D11Device* pDevice,
	ID3D11DeviceContext* pContext,
	ID3D11RenderTargetView* pBackBuffer)
{
	pMessageHandler = messageHandler;
	pMsg = msg;
	this->pSwapChain = pSwapChain;
	this->pDevice = pDevice;
	this->pContext = pContext;
	this->pBackBuffer = pBackBuffer;
}

void GameLoop::Loop()
{
	while (pMsg->message != WM_QUIT)
	{
		pMessageHandler->Handle(pMsg);
		renderFrame();
	}
}

void GameLoop::renderFrame()
{
	pContext->ClearRenderTargetView(pBackBuffer, D3DXCOLOR(0.0f, 0.6f, 0.8f, 1.0f));
	pSwapChain->Present(0, 0);
}

