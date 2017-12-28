/*
Description: Class that defines the buttons
Last Modification Data: 25/03/2017
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

class switchButton : public object
{
public:
	bool isOn;  //variable that detects the button status
	switchButton()
	{
		isOn = false;
	}
};