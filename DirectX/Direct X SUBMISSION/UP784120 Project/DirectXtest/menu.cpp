/*
Description: Part of gameControl.h. Handles the mine menu
Last Modification Data: 20/03/2017
Status:Working
To Do:-
*/
#include "gameControl.h"
#include "Player.h"

//Render Main Menu
void gameControl::renderMenu()
{
	devcon->ClearRenderTargetView(backbuffer, D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	devcon->ClearDepthStencilView(depthStencilView_, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	menuBack.objCamera(&WVP, &camView, &camProjection);
	menuBack.objRender();

	startGame.objCamera(&WVP, &camView, &camProjection);
	startGame.objRender();

	menuButton.objCamera(&WVP, &camView, &camProjection);
	menuButton.objRender();

	exitGame.objCamera(&WVP, &camView, &camProjection);
	exitGame.objRender();

	swapchain->Present(0, 0);
}

bool menuSet = false;

//Load Menu//
void gameControl::loadMenu()
{
	if (menuSet == false)
	{
		menuBack.set_all(0.0f, 0.0f, 0.0f, 0.0f);
		menuBack.update(&Translation, &Rotation, &Scale);

		startGame.set_all(-2.7f, 1.0f, 1.0f, 0.0f);
		startGame.update(&Translation, &Rotation, &Scale);

		exitGame.set_all(-2.3f, -1.5f, 1.0f, 0.0f);
		exitGame.update(&Translation, &Rotation, &Scale);

		menuButton.set_all(-2.7f, 1.3f, 1.0f, 0.0f);
		menuButton.update(&Translation, &Rotation, &Scale);
		menuSet = true;
	}
}


//Update Menu//
//Menu States
int gameControl::updateMenu()
{
	
	if (menuDown)
	{
		menuButton.set_all(-2.7f, -1.0f, 1.0f, 0.0f);
		menuButton.update(&Translation, &Rotation, &Scale);
		result = 0;
	}

	if (menuUp)
	{
		menuButton.set_all(-2.7f, 1.3f, 1.0f, 0.0f);
		menuButton.update(&Translation, &Rotation, &Scale);
		result = 1;
	}

	camPosition = XMVectorSet(0.0f, 0.0f, -0.5f, 0.0f);
	camTarget = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	camUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	camView = XMMatrixLookAtLH(camPosition, camTarget, camUp);
	camProjection = XMMatrixOrthographicRH(20.0f, 20.0f, -100.0f, 1000.0f);
	return result;
}




