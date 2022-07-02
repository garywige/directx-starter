#include "D3DInitializer.h"

D3DInitializer::D3DInitializer()
{
	pSwapChain = 0;
	pDevice = 0;
	pContext = 0;
}

D3DInitializer::~D3DInitializer()
{
	if (pContext) pContext->Release();
	if (pDevice) pDevice->Release();
	if (pSwapChain) pSwapChain->Release();
}

void D3DInitializer::Initialize(HWND hWnd, IDXGISwapChain** ppSwapChain, ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext)
{
	DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = hWnd;
	swapChainDesc.SampleDesc.Count = 4;
	swapChainDesc.Windowed = TRUE;

	D3D11CreateDeviceAndSwapChain(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		NULL,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		&swapChainDesc,
		ppSwapChain,
		ppDevice,
		NULL,
		ppContext);

	pSwapChain = *ppSwapChain;
	pDevice = *ppDevice;
	pContext = *ppContext;
}