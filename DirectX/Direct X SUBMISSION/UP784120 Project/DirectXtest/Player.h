/*
Description: Class used for the player
Last Modification Data: 20/03/2017
Status:Working
To Do:-
*/
#pragma once
#include <windows.h>
#include <windowsx.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <DirectXMath.h>
#include <xnamath.h>
#include "VERTEX.h"
#include "cbPerObj.h"
#include "object.h"

class player:public object
{
public:
	player()
	{
		isAlive = true;
	} 

	//key input 
	bool moveLeft;   //LEFT KEY
	bool moveRight;  //RIGHT KEY
	bool activate;   //F key

	//player status
	bool isAlive;
};

