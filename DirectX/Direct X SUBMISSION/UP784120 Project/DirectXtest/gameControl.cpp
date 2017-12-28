/*
Description: Contains functions of gameControl.h  
Last Modification Data: 28/03/2017
Status: Working
To Do: Some bits of code are repetitive (replace it with functions)
Source: built on http://www.directxtutorial.com/Lesson.aspx?lessonid=11-4-5 template
*/
#include "gameControl.h"
#include "Player.h"
#define KEYDOWN( name, key ) ( name[key] & 0x80 )
char buffer[256];

//Render objects on screen//
void gameControl::RenderFrame()
{
	devcon->ClearRenderTargetView(backbuffer, D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
	devcon->ClearDepthStencilView(depthStencilView_, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	player.objCamera(&WVP, &camView, &camProjection);
	player.objRender();

	for (int i = 0; i < 3; i++)
	{
		spikes[i].objCamera(&WVP, &camView, &camProjection);
		spikes[i].objRender();
	}

	platform.objCamera(&WVP, &camView, &camProjection);
	platform.objRender();

	greenWater.objCamera(&WVP, &camView, &camProjection);
	greenWater.objRender();

	trap.objCamera(&WVP, &camView, &camProjection);
	trap.objRender();

	for (int i = 0; i < 4; i++)
	{
		button[i].objCamera(&WVP, &camView, &camProjection);
		button[i].objRender();
	}
	for (int i = 0; i < 2; i++)
	{
		spikeWheel[i].objCamera(&WVP, &camView, &camProjection);
		spikeWheel[i].objRender();
	}

	for (int i = 0; i < 6; i++)
	{
		boxeBase[i].objCamera(&WVP, &camView, &camProjection);
		boxeBase[i].objRender();
	}
	
	for (int i = 0; i < 8; i++)
	{
		floorOne[i].objCamera(&WVP, &camView, &camProjection);
		floorOne[i].objRender();
	}
	for (int i = 0; i <= 3; i++)
	{
		door[i].objCamera(&WVP, &camView, &camProjection);
		door[i].objRender();
	}
	
	select.objCamera(&WVP, &camView, &camProjection);
	select.objRender();

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

//Load Graphics//
void gameControl::InitGraphics()
{
	player.selectTexture(1);
	player.setVertexType(1);
	player.set_texture(dev);
	player.setData(dev,devcon,pLayout,globalIndexBuffer,globalIndexBuffer,cbPerObjectBuffer);
	player.LoadShader();
	player.Load();

	platform.selectTexture(2);
	platform.setVertexType(3);
	platform .set_texture(dev);
	platform.setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
	platform.LoadShader();
	platform.Load();

	for (int i = 0; i < 3; i++)
	{
		spikes[i].selectTexture(5);
		spikes[i].setVertexType(9);
		spikes[i].set_texture(dev);
		spikes[i].setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
		spikes[i].LoadShader();
		spikes[i].Load();
	}

	trap.selectTexture(13);
	trap.setVertexType(9);
	trap.set_texture(dev);
	trap.setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
	trap.LoadShader();
	trap.Load();

	greenWater.selectTexture(4);
	greenWater.setVertexType(2);
	greenWater.set_texture(dev);
	greenWater.setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
	greenWater.LoadShader();
	greenWater.Load();

	for (int i = 0; i < 4; i++)
	{
		button[i].selectTexture(7);
		button[i].setVertexType(10);
		button[i].set_texture(dev);
		button[i].setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
		button[i].LoadShader();
		button[i].Load();
	}
	for (int i = 0; i < 6; i++)
	{
		boxeBase[i].selectTexture(3);
		boxeBase[i].setVertexType(7);
		boxeBase[i].set_texture(dev);
		boxeBase[i].setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
		boxeBase[i].LoadShader();
		boxeBase[i].Load();
	}

	for (int i = 0; i < 8; i++)
	{
		floorOne[i].selectTexture(1);
		floorOne[i].setVertexType(8);
		floorOne[i].set_texture(dev);
		floorOne[i].setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
		floorOne[i].LoadShader();
		floorOne[i].Load();
	}

	for (int i = 0; i < 3; i++)
	{
		door[i].selectTexture(8);
		door[i].setVertexType(4);
		door[i].set_texture(dev);
		door[i].setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
		door[i].LoadShader();
		door[i].Load();
	}
	for (int i = 0; i < 2; i++)
	{
		spikeWheel[i].selectTexture(10);
		spikeWheel[i].setVertexType(1);
		spikeWheel[i].set_texture(dev);
		spikeWheel[i].setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
		spikeWheel[i].LoadShader();
		spikeWheel[i].Load();
	}

	menuBack.selectTexture(11);
	menuBack.setVertexType(6);
	menuBack.set_texture(dev);
	menuBack.setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
	menuBack.LoadShader();
	menuBack.Load();

	startGame.selectTexture(-1);
	startGame.setString(0);
	startGame.set_texture(dev);
	startGame.setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
	startGame.LoadShader();
	startGame.Load();
	

	exitGame.selectTexture(-1);
	exitGame.setString(1);
	exitGame.set_texture(dev);
	exitGame.setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
	exitGame.LoadShader();	
	exitGame.Load();

	restart.selectTexture(-1);
	restart.setString(2);
	restart.set_texture(dev);
	restart.setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
	restart.LoadShader();
	restart.Load();

	goBack.selectTexture(-1);
	goBack.setString(3);
	goBack.set_texture(dev);
	goBack.setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
	goBack.LoadShader();
	goBack.Load();

	menuButton.selectTexture(12);
	menuButton.setVertexType(5);
	menuButton.set_texture(dev);
	menuButton.setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
	menuButton.LoadShader();
	menuButton.Load();

	select.selectTexture(-1);
	select.setString(2);
	select.set_texture(dev);
	select.setData(dev, devcon, pLayout, globalIndexBuffer, globalIndexBuffer, cbPerObjectBuffer);
	select.LoadShader();
	select.Load();
	
}

bool set = false;

//Set opjects positions
void gameControl::loadLevel()
{

//	if (loaded == false)
	//{
		boxeBase[0].set_all(-2.0f, 0.0f, 0.0f, 0.0f);
		boxeBase[1].set_all(-2.0f, 6.0f, 0.0f, 0.0f);
		boxeBase[2].set_all(56.0f, 2.0f, 0.0f, 0.0f);
		boxeBase[3].set_all(58.0f, 0.0f, 0.0f, 0.0f);

		for (int i = 0; i < 3; i++)
		boxeBase[i].update(&Translation, &Rotation, &Scale);

		floorOne[0].set_all(2.0f, -2.0f, 0.0f, 0.0f);
		floorOne[1].set_all(14.0f, -2.0f, 0.0f, 0.0f);
		floorOne[2].set_all(24.0f, -2.0f, 0.0f, 0.0f);
		floorOne[3].set_all(30.0f, -2.0f, 0.0f, 0.0f);
		floorOne[4].set_all(36.0f, -2.0f, 0.0f, 0.0f);
		floorOne[5].set_all(42.0f, -2.0f, 0.0f, 0.0f);
		floorOne[6].set_all(48.0f, -2.0f, 0.0f, 0.0f);
		floorOne[7].set_all(54.0f,-2.0f,0.0f,0.0f);
		for (int i = 0; i < 8; i++)
			floorOne[i].update(&Translation, &Rotation, &Scale);

		door[0].set_all(14.0f, 1.0f, 0.0f, 0.0f);
		door[1].set_all(24.0f, 1.0f, 0.0f, 0.0f);
		door[2].set_all(52.0f, 1.0f, 0.0f, 0.0f);

		door[0].selectTexture(8);
		door[1].selectTexture(8);
		door[2].selectTexture(8);

		door[0].set_texture(dev);
		door[1].set_texture(dev);
		door[2].set_texture(dev);
		
		
		for (int i = 0; i < 3; i++)
		door[i].update(&Translation, &Rotation, &Scale);

		greenWater.set_all(8.0f, -2.0f, 0.0f, 0.0f);
		greenWater.update(&Translation, &Rotation, &Scale);

		trap.set_all(19.0f, -1.0f, 0.0f, 0.0f);
		trap.isActive = false;
		trap.update(&Translation, &Rotation, &Scale);

		spikes[0].set_all(19.0f, 6.0f, 0.0f, 0.0f);
		spikes[0].update(&Translation, &Rotation, &Scale);

		spikes[1].set_all(42.0f, 6.0f, 0.0f, 0.0f);
		spikes[1].update(&Translation, &Rotation, &Scale);

		spikes[2].set_all(38.0f, 6.0f, 0.0f, 0.0f);
		spikes[2].update(&Translation, &Rotation, &Scale);

		platform.set_all(8.0f, -1.0f, 0.0f, 0.0f);
		platform.update(&Translation, &Rotation, &Scale);

		
		spikeWheel[0].set_all(30.0f, 4.0f, 0.0f, 0.0f);
		spikeWheel[0].update(&Translation, &Rotation, &Scale);

		spikeWheel[1].set_all(34.0f, 4.0f, 0.0f, 0.0f);
		spikeWheel[1].update(&Translation, &Rotation, &Scale);

		button[0].set_all(12.0f, 0.5f, -1.0f, 0.0f);
		button[0].update(&Translation, &Rotation, &Scale);

		button[1].set_all(42.0f, 0.5f, 0.0f, 0.0f);
		button[1].update(&Translation, &Rotation, &Scale);

		button[2].set_all(38.0f, 0.5f, -1.0f, 0.0f);
		button[2].update(&Translation, &Rotation, &Scale);

		button[3].set_all(46.0f, 0.5f, 0.0f, 0.0f);
		button[3].update(&Translation, &Rotation, &Scale);


		select.set_all(38.0f, 3.0f, 0.0f, 0.0f);
		select.update(&Translation, &Rotation, &Scale);

		button[0].selectTexture(7);
		button[0].set_texture(dev);
		button[0].isActive = false;
		button[0].isOn = false;

		button[1].selectTexture(7);
		button[1].set_texture(dev);
		button[1].isActive = false;
		button[1].isOn = false;

		button[2].selectTexture(7);
		button[2].set_texture(dev);
		button[1].isActive = false;
		button[1].isOn = false;

		button[3].selectTexture(7);
		button[3].set_texture(dev);
		button[1].isActive = false;
		button[1].isOn = false;


	//	loaded = true;
	//}
}

bool start = true;
bool end = false;
bool active = false;
bool locked = false;

//Update objects positions
void gameControl::Update()
{
	keyboardDevice_->GetDeviceState(sizeof(keyboardKeys_), (LPVOID)&keyboardKeys_);
	//D2-PLAYER STATE
	if (player.isAlive == true) //if player is alive
	{
		//get key input
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			PostQuitMessage(0);
		}
		if (player.moveRight == true)
		{
			player.set_xAxis(player.get_xAxis() + 0.01f*scaleFactor);
			locked = false;
		}
		if (player.moveLeft == true)
		{
			player.set_xAxis(player.get_xAxis() - 0.01f*scaleFactor);
			locked = false;
		}

		platform.moveAtoB(6.0f, 10.0f);  //move platform
		spikeWheel[0].verticalAtoB(0.0f, 6.0f);  //move spikes[0]
		spikeWheel[0].update(&Translation, &Rotation, &Scale);//update spikes[0]

		spikeWheel[1].verticalAtoB(0.0f, 6.0f); //move spikeWheel[1]
		spikeWheel[1].update(&Translation, &Rotation, &Scale); //update spikeWheels[1]

		//test distance between player and first button and if button 'F' is pressed
		if (player.distance(button[0].get_xAxis(), button[0].get_yAxis()) < 1.0f && player.activate == true)
		{
			if (button[0].isActive == false)
				button[0].isActive = true;
		}
		//D6 (interact with buttons) for button[0]
		if (button[0].isActive == true)
		{  //if button is switched on

			//D11-Door/Button Animation
			if (door[0].isOpen == false)
			{
				//if door is not open
				//change button texture
				
				button[0].isOn = true;
				button[0].selectTexture(6);
				button[0].set_texture(dev);

				//change door[0] and door [1] textures
				door[0].isOpen = true;
				door[0].selectTexture(9);
				door[0].set_texture(dev);

				door[1].isOpen = true;
				door[1].selectTexture(9);
				door[1].set_texture(dev);
				
			}
			else
				//if door[0] is open
				if (door[0].isOpen == true)
				{
					
					button[0].isOn = false;
					//if button is switched off

					//change button[0] texture
					button[0].selectTexture(7);
					button[0].set_texture(dev);

					//change door[0] and door[1] textures
					door[0].isOpen = false;
					door[0].selectTexture(8);
					door[0].set_texture(dev);

					door[1].isOpen = false;
					door[1].selectTexture(8);
					door[1].set_texture(dev);

				}
			player.activate = false;  
			button[0].isActive = false;
		}


		//test distance between player and second button and if key 'F' is pressed
		if (player.distance(button[1].get_xAxis(), button[1].get_yAxis()) < 1.0f && player.activate == true)
		{
			//D6 (interact with buttons) for button[1]
			if (button[1].isActive == false)
				button[1].isActive = true;
				//switch button on
		}

		if (button[1].isActive == true)
		{

			//change button texture
			button[1].isOn = true;
			button[1].selectTexture(6);
			button[1].set_texture(dev);


			player.activate = false;
			//activate spikes[1]
			spikes[1].isActive = true;
			button[1].isActive = false;
		}
		if (spikes[1].isActive == true)
		{
			if (spikes[1].get_yAxis() >= 0.0f)
			{
				spikes[1].set_yAxis(spikes[1].get_yAxis() - 0.01f*scaleFactor);
				spikes[1].update(&Translation, &Rotation, &Scale);
				//update spikes position
			}
		}

		//test distance between player and door[0] and if key 'F' is pressed
		//D5-Teleportation
		if (player.distance(door[0].get_xAxis(), door[0].get_yAxis()) < 2.0f && player.activate == true)
		{
			//if door[0] is open
			if (door[0].isOpen == true)
			{
				player.set_xAxis(door[1].get_xAxis());
				//change player position to door[1]
			}
		}

		//D12-SPIKES TRAP (pressure plate)

		//test distance between player and trap and if the trap is activated 
		if (player.distance(trap.get_xAxis(), trap.get_yAxis()) <= 2.0f && active == false)
		{
			trap.set_all(19.0f, -1.2f, 0.0f, 0.0f);
			active = true;
			trap.update(&Translation, &Rotation, &Scale);
			//update trap position
		}

		if (active == true)
		{//if trap is activated
			if (spikes[0].get_yAxis() >= 0.0f)
			{
				spikes[0].set_yAxis(spikes[0].get_yAxis() - 0.01f*scaleFactor);
				spikes[0].update(&Translation, &Rotation, &Scale);
				//update spikes [0] position
			}
		}


		//test distance between player and button[2] and if button 'F' is pressed
		if (player.distance(button[2].get_xAxis(), button[2].get_yAxis()) < 1.0f && player.activate == true)
		{
			//D6 (interact with buttons) for button[2]
			if (button[2].isActive == false)
				button[2].isActive = true;
			//activate button[2]
		}

		if (button[2].isActive == true)
		{
			//change button[2] texture
			button[2].isOn = true;
			button[2].selectTexture(6);
			button[2].set_texture(dev);


			player.activate = false;
			spikes[2].isActive = true;
			button[2].isActive = false;
		}

		if (spikes[2].isActive == true)
		{
			if (spikes[2].get_yAxis() >= 0.0f)
			{
				spikes[2].set_yAxis(spikes[2].get_yAxis() - 0.01f*scaleFactor);
				spikes[2].update(&Translation, &Rotation, &Scale);
				//spikes[2] update position
			}
		}

		//check distance between player and button[3] and if key 'F' is pressed 
		if (player.distance(button[3].get_xAxis(), button[3].get_yAxis()) < 1.0f && player.activate == true)
		{
			//D6 (interact with buttons) for button[3]
			if (button[3].isActive == false)
				button[3].isActive = true;
			//switch button on
		}
		
		//if button is on
		if (button[3].isActive == true)
		{
			//if door[2] is close
			if (door[2].isOpen == false)
			{
				button[3].isOn = true;
				button[3].selectTexture(6);
				button[3].set_texture(dev);
				//change button texture

				door[2].isOpen = true;
				door[2].selectTexture(9);
				door[2].set_texture(dev);
				//change door[2] texture

		
			}
			else
				//if door is open 
				if (door[2].isOpen == true)
				{
					button[3].isOn = false;
					button[3].selectTexture(7);
					button[3].set_texture(dev);
					//update button[3] texture

					door[2].isOpen = false;
					door[2].selectTexture(8);
					door[2].set_texture(dev);
					//update door[2] texture
				}
			player.activate = false;
			button[3].isActive = false;
		}


		//check distance between player and door[2] and if key 'F' is pressed
		if (player.distance(door[2].get_xAxis(), door[2].get_yAxis()) < 2.0f && player.activate == true)
		{
			if (door[2].isOpen == true)
			{
				player.isAlive = false;
			}
		}

		//check distance between player and spikes
		if (player.distance(spikes[0].get_xAxis(), spikes[0].get_yAxis()) <= 1.0f || player.distance(spikeWheel[0].get_xAxis(), spikeWheel[0].get_yAxis()) <= 1.0f || player.distance(spikeWheel[1].get_xAxis(), spikeWheel[1].get_yAxis()) < 1.0f || player.distance(spikes[1].get_xAxis(), spikes[1].get_yAxis()) <= 1.0f || player.distance(spikes[2].get_xAxis(), spikes[2].get_yAxis()) <= 1.0f)
		{
			player.isAlive = false;
		}


		if (player.distance(platform.get_xAxis(), platform.get_yAxis()) <= 1.5f && !((GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))))
		{
			locked = true;
		}
		else
		{
			locked = false;
		}

		if (locked == true)
		{
			player.set_xAxis(platform.get_xAxis());
		}



		spikeWheel[0].update(&Translation, &Rotation, &Scale);
		platform.update(&Translation, &Rotation, &Scale);
		trap.update(&Translation, &Rotation, &Scale);
		player.update(&Translation, &Rotation, &Scale);

		camPosition = XMVectorSet(player.get_xAxis(), 0.0f, -0.5f, 0.0f);
		camTarget = XMVectorSet(player.get_xAxis(), 0.0f, 0.0f, 0.0f);
		camUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
		camView = XMMatrixLookAtLH(camPosition, camTarget, camUp);
		camProjection = XMMatrixOrthographicRH(10.0f, 10.0f, -100.0f, 1000.0f);


		memcpy(prevKeyboardKeys_, keyboardKeys_, sizeof(keyboardKeys_));
	}
}