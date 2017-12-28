/*
Description: Game class
Last Modification Data: 28/03/2017
Status:Working
To Do:
*/
#pragma once

#include <windows.h>
#include <windowsx.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <DirectXMath.h>
#include <xnamath.h>
#include <math.h>
#include <xnamathvector.inl>
#include <XInput.h>
#include <dinput.h>
#include "object.h"
#include "Text.h"
#include "platform.h"
#include "Player.h"
#include "spikeWheel.h"
#include "Door.h"
#include "switchButton.h"

class gameControl : public baseVariables
{
public:
	gameControl()
	{
		result = 1;
		loaded = false;
		currentDelta=0;
		scaleFactor=0;
	}
	IDXGISwapChain *swapchain;             // the pointer to the swap chain interface
	ID3D11Device *dev;                     // the pointer to our Direct3D device interface
	ID3D11DeviceContext *devcon;           // the pointer to our Direct3D device context
	ID3D11RenderTargetView *backbuffer;    // the pointer to our back buffer
	ID3D11InputLayout *pLayout;            // the pointer to the input layout
	ID3D11VertexShader *pVS;               // the pointer to the vertex shader
	ID3D11PixelShader *pPS;                // the pointer to the pixel shader
	ID3D11Buffer* globalIndexBuffer;	 
	ID3D11Buffer* globalVertexBuffer;
	ID3D11Buffer* cbPerObjectBuffer;
	
	LPDIRECTINPUT8 directInput_;
	LPDIRECTINPUTDEVICE8 keyboardDevice_;
	char keyboardKeys_[256];
	char prevKeyboardKeys_[256];

	XMMATRIX WVP;
	XMMATRIX World;
	XMMATRIX camView;
	XMMATRIX camProjection;

	XMVECTOR camPosition;
	XMVECTOR camTarget;
	XMVECTOR camUp;
	ID3D11Texture2D* depthTexture_;
	ID3D11DepthStencilView* depthStencilView_;


	////////////////////////////////////
	XMMATRIX Rotation;
	XMMATRIX Scale;
	XMMATRIX Translation;

	player player;
	object boxeBase[4];
	object floorOne[8];
	object greenWater;
	platform platform;
	door door[3];
	object trap;
	object menuButton;
	object spikes[3];
	spikeWheel spikeWheel[2];
	switchButton button[4];
	bool result;
	bool menuUp;
	bool menuDown;
	bool menuSelect;
	object menuBack;
	DWORD frameStartTime;
	DWORD frameEndTime;
	float currentDelta;
	float scaleFactor;
	
	text startGame;
	text exitGame;
	text restart;
	text goBack;
	text select;

	bool loaded;
	float rot = 0.01f;

	void loadMenu();
	void renderMenu();
	int updateMenu();

	void setCamera();
	void RenderFrame();
	void CleanD3D();
	void loadLevel();
	void InitGraphics();
	void Update();
};