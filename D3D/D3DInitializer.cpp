#include "D3DInitializer.h"

D3DInitializer::D3DInitializer(HWND hWnd, FLOAT width, FLOAT height)
{
	this->hWnd = hWnd;
	this->width = width;
	this->height = height;
	pSwapChain = 0;
	pDevice = 0;
	pContext = 0;
	pRTVBackBuffer = 0;
}

D3DInitializer::~D3DInitializer()
{
	if (pContext) pContext->Release();
	if (pDevice) pDevice->Release();
	if (pSwapChain) pSwapChain->Release();
	if (pRTVBackBuffer) pRTVBackBuffer->Release();

	pContext = 0;
	pDevice = 0;
	pSwapChain = 0;
	pRTVBackBuffer = 0;
}

void D3DInitializer::Initialize(IDXGISwapChain** ppSwapChain, ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext, ID3D11RenderTargetView** ppRTVBackBuffer)
{
	initD3D();
	setRenderTarget();
	setViewport();

	*ppSwapChain = pSwapChain;
	*ppDevice = pDevice;
	*ppContext = pContext;
	*ppRTVBackBuffer = pRTVBackBuffer;
}

void D3DInitializer::initD3D()
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
		&pSwapChain,
		&pDevice,
		NULL,
		&pContext);
}

void D3DInitializer::setRenderTarget()
{
	ID3D11Texture2D* pBackBuffer;
	pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	pDevice->CreateRenderTargetView(pBackBuffer, NULL, &pRTVBackBuffer);
	pBackBuffer->Release();
	pContext->OMSetRenderTargets(1, &pRTVBackBuffer, NULL);
}

void D3DInitializer::setViewport()
{
	D3D11_VIEWPORT viewport = {};
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = width;
	viewport.Height = height;
	pContext->RSSetViewports(1, &viewport);
}