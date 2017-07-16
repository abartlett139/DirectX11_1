//***************************************************************************************
// D3D.h 
// by Amy Bartlett
// created July 16, 2017
// last edited July 16, 2017
//
// custom DirectX 11 namespace
//
//***************************************************************************************

#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")


#include <windows.h>
#include <windowsx.h>
#include <d3d11.h>
#include <d3dx11.h>


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


static IDXGISwapChain *swapchain;             // the pointer to the swap chain interface
static ID3D11Device *dev;                     // the pointer to our Direct3D device interface
static ID3D11DeviceContext *devcon;           // the pointer to our Direct3D device context
static ID3D11RenderTargetView *backbuffer;    // global declaration
static HWND hwnd;

namespace D3D {
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void InitWindow(HINSTANCE hInstance);
	void InitD3D(void);
	void RenderFrame(void);
	void CleanD3D(void);

	const FLOAT RED[4] = { 1.0f, 0.0f, 0.0f, 0.0f };
}