#include "D3D.h"


//	MESSAGE HANDLER
LRESULT CALLBACK D3D::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}


//	MAIN ENTRY POINT
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//	Step 1: Create the window
	D3D::InitWindow(hInstance);
	//	Step 2: Create DirectX
	D3D::InitD3D();

	//	Step 3: enter the main loop
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (TRUE) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				break;
		}
		else {
			D3D::RenderFrame();
		}

	}
}