#pragma once
#include <d3d11.h>
#include "IMessageHandler.h"

class GameLoop
{
public:
	GameLoop(
		IMessageHandler* messageHandler, 
		MSG* msg, 
		IDXGISwapChain* pSwapChain, 
		ID3D11Device* pDevice, 
		ID3D11DeviceContext* pContext, 
		ID3D11RenderTargetView* pBackBuffer);

	void Loop();

protected:
	IMessageHandler* pMessageHandler;
	MSG* pMsg;
	IDXGISwapChain* pSwapChain;
	ID3D11Device* pDevice;
	ID3D11DeviceContext* pContext;
	ID3D11RenderTargetView* pBackBuffer;

	void renderFrame();
};