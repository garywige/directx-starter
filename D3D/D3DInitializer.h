#pragma once
#include <d3d11.h>
#pragma comment (lib, "d3d11.lib")


class D3DInitializer
{
public:
	D3DInitializer(HWND hWnd, FLOAT width, FLOAT height);
	~D3DInitializer();

	void Initialize(IDXGISwapChain** ppSwapChain, ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext);

protected:
	HWND hWnd;
	FLOAT width;
	FLOAT height;
	IDXGISwapChain* pSwapChain;
	ID3D11Device* pDevice;
	ID3D11DeviceContext* pContext;
	ID3D11RenderTargetView* pRTVBackBuffer;

	void initD3D();
	void setRenderTarget();
	void setViewport();
};