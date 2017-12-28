#include "gameControl.h"

void gameControl::setCamera()
{
	camPosition = XMVectorSet(0.0f, 0.0f, -8.0f, 0.0f);
	camTarget = XMVectorSet(0.0f, 0.0f, 0.0, 0.0f);
	camUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	camView = XMMatrixLookAtLH(camPosition, camTarget, camUp);
	camProjection = XMMatrixPerspectiveFovLH(0.4f*3.14f, (float)800.0f / 600.0f, 1.0f, 1000.0f);

}

void gameControl::RenderFrame()
{
	devcon->ClearRenderTargetView(backbuffer, D3DXCOLOR(0.0f, 0.2f, 0.4f, 1.0f));
	devcon->ClearDepthStencilView(depthStencilView_, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	

	swapchain->Present(0, 0);
}

void gameControl::CleanD3D()
{
	swapchain->SetFullscreenState(FALSE, NULL);
	swapchain->Release();
	backbuffer->Release();
	dev->Release();
	devcon->Release();
}

void gameControl::InitGraphics()
{

	
	setCamera();
}

void gameControl::Update()
{


	

	keyboardDevice_->GetDeviceState(sizeof(keyboardKeys_), (LPVOID)&keyboardKeys_);
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
	//	objOne.set_xAxis(objOne.get_xAxis() + 0.001f);

	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		//objOne.set_xAxis(objOne.get_xAxis() - 0.001f);
	}

	camPosition = XMVectorSet(objOne.get_xAxis(), 0.0f, -8.0f, 0.0f);
	camTarget = XMVectorSet(objOne.get_xAxis(), 0.0f, 0.0f, 0.0f);
	camUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	camView = XMMatrixLookAtLH(camPosition, camTarget, camUp);
	camProjection = XMMatrixPerspectiveFovLH(0.4f*3.14f, (float)1.0f, 1.0f, 1000.0f);
	memcpy(prevKeyboardKeys_, keyboardKeys_, sizeof(keyboardKeys_));

}
