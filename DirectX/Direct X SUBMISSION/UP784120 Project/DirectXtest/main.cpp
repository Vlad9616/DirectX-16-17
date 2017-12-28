/*
Description: The main file 
Last Modification Data: 28/03/2017
Status: Working
To Do:-
Source: built on http://www.directxtutorial.com/Lesson.aspx?lessonid=11-4-5 template
*/
// include the basic windows header files and the Direct3D header files
#include <windows.h>
#include <windowsx.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <DirectXMath.h>
#include <xnamath.h>
#include <math.h>

#include <iostream>

#include "VERTEX.h"
#include "object.h"
#include "Text.h"
#include "cbPerObj.h"
#include "gameControl.h"


// include the Direct3D Library file
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")
#pragma comment (lib, "dinput8.lib")

using namespace std;

// define the screen resolution
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600
#define idealFrameRate 120
#define idealDelta (1000/idealFrameRate)
gameControl control;
bool loadMenu = true;
bool playGame = false;
// function prototypes
void InitD3D(HWND hWnd, HINSTANCE hInstance);    // sets up and initializes Direct3D


// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = L"WindowClass";

	RegisterClassEx(&wc);

	RECT wr = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	hWnd = CreateWindowEx(NULL,
		L"WindowClass",
		L"UP784120",
		WS_OVERLAPPEDWINDOW,
		300,
		300,
		wr.right - wr.left,
		wr.bottom - wr.top,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hWnd, nCmdShow);

	// set up and initialize Direct3D
	InitD3D(hWnd,hInstance);

	// enter the main loop:

	MSG msg;

	while (TRUE)
	{
		//D1-GAME EVENT HANDLER
		control.frameStartTime=GetTickCount();
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if ( control.updateMenu() == 0 && control.menuSelect)
				break;
			else
				if (msg.message==WM_KEYDOWN)
			{
				//KEY INPUT
				switch (msg.wParam)
				{
				case VK_LEFT: control.player.moveLeft=true;
					break;
				case VK_RIGHT:control.player.moveRight = true;
					break;
				case 'F':control.player.activate = true;
					break;
				case VK_UP:control.menuUp = true;
					break;
				case VK_DOWN:control.menuDown = true;
					break;
				case VK_SPACE:control.menuSelect = true;
					break;
				}
			}
				else
					if (msg.message == WM_KEYUP)
					{
						switch (msg.wParam)
						{
						case VK_LEFT: control.player.moveLeft = false;
							break;
						case VK_RIGHT:control.player.moveRight = false;
							break;
						case 'F':control.player.activate = false;
							break;
						case VK_UP:control.menuUp = false;
							break;
						case VK_DOWN:control.menuDown = false;
							break;
						case VK_SPACE:control.menuSelect = false;
							break;
						}
					}
		}
		
		
		if (control.loaded == false)
		{
			control.loadLevel();
			control.loaded = true;
		}

		if (loadMenu == true )
		{
			control.loadMenu();
			control.updateMenu();
			control.renderMenu();
		}

		if (control.updateMenu() == 1 && control.menuSelect)
		{
			playGame = true;
			loadMenu = false;
			control.player.isAlive = true;
			control.player.set_all(0.0f,0.0f,0.0f,0.0f);
		}
		if (GetAsyncKeyState(VK_ESCAPE) || control.player.isAlive == false)
		{
			control.menuSelect = false;
			playGame = false;
			loadMenu = true;
			control.loaded = false;
		}
		if (playGame == true && control.player.isAlive==true)
		{
			control.Update();
			control.RenderFrame();
		}

		control.frameEndTime = GetTickCount();
		control.currentDelta = control.frameEndTime - control.frameStartTime;
		control.scaleFactor = control.currentDelta / idealDelta;
	}

	// clean up DirectX and COM
	control.CleanD3D();
	return msg.wParam;
}


// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	} break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}


// this function initializes and prepares Direct3D for use
void InitD3D(HWND hWnd, HINSTANCE hInstance)
{
	// create a struct to hold information about the swap chain
	DXGI_SWAP_CHAIN_DESC scd;

	// clear out the struct for use
	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

	// fill the swap chain description struct
	scd.BufferCount = 1;                                   // one back buffer
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;    // use 32-bit color
	scd.BufferDesc.Width = SCREEN_WIDTH;                   // set the back buffer width
	scd.BufferDesc.Height = SCREEN_HEIGHT;                 // set the back buffer height
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;     // how swap chain is to be used
	scd.OutputWindow = hWnd;                               // the window to be used
	scd.SampleDesc.Count = 4;                              // how many multisamples
	scd.Windowed = TRUE;                                   // windowed/full-screen mode
	scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;    // allow full-screen switching

	// create a device, device context and swap chain using the information in the scd struct
	D3D11CreateDeviceAndSwapChain(NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		NULL,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		&scd,
		&control.swapchain,
		&control.dev,
		NULL,
		&control.devcon);

	ID3D11DepthStencilView* depthStencilView_;
	// get the address of the back buffer
	ID3D11Texture2D *pBackBuffer;
	control.swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	// use the back buffer address to create the render target
	control.dev->CreateRenderTargetView(pBackBuffer, NULL, &control.backbuffer);
	pBackBuffer->Release();

	D3D11_TEXTURE2D_DESC depthTexDesc;
	ZeroMemory(&depthTexDesc, sizeof(depthTexDesc));
	depthTexDesc.Width = SCREEN_WIDTH;
	depthTexDesc.Height = SCREEN_HEIGHT;
	depthTexDesc.MipLevels = 1;
	depthTexDesc.ArraySize = 1;
	depthTexDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthTexDesc.SampleDesc.Count = 1;
	depthTexDesc.SampleDesc.Quality = 0;
	depthTexDesc.Usage = D3D11_USAGE_DEFAULT;
	depthTexDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthTexDesc.CPUAccessFlags = 0;
	depthTexDesc.MiscFlags = 0;
	
	control.dev->CreateTexture2D(&depthTexDesc,NULL,&control.depthTexture_);

	D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
	ZeroMemory(&descDSV, sizeof(descDSV));
	descDSV.Format = depthTexDesc.Format;
	descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	descDSV.Texture2D.MipSlice = 0;

	control.dev->CreateDepthStencilView(control.depthTexture_,NULL,&depthStencilView_);

	// set the render target as the back buffer
	control.devcon->OMSetRenderTargets(1, &control.backbuffer, control.depthStencilView_);
	// Set the viewport
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = SCREEN_WIDTH;
	viewport.Height = SCREEN_HEIGHT;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	control.devcon->RSSetViewports(1, &viewport);	

	ZeroMemory(control.keyboardKeys_,sizeof(control.keyboardKeys_));
	ZeroMemory(control.prevKeyboardKeys_,sizeof(control.prevKeyboardKeys_));

	DirectInput8Create(hInstance,DIRECTINPUT_VERSION,IID_IDirectInput8,(void**)&control.directInput_,0);
	control.directInput_->CreateDevice(GUID_SysKeyboard,&control.keyboardDevice_,0);
	control.keyboardDevice_->SetDataFormat(&c_dfDIKeyboard);
	control.keyboardDevice_->SetCooperativeLevel(hWnd,DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	control.keyboardDevice_->Acquire();

	control.InitGraphics();
}

