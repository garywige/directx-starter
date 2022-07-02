#pragma once
#include <d3d11.h>
#pragma comment (lib, "d3d11.lib")


class D3DInitializer
{
public:
	D3DInitializer();
	~D3DInitializer();

	void Initialize(HWND hWnd, IDXGISwapChain** ppSwapChain, ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext);

protected:
	IDXGISwapChain* pSwapChain;
	ID3D11Device* pDevice;
	ID3D11DeviceContext* pContext;
};