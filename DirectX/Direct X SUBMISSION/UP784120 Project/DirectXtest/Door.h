/*
Description: Door class that has buit in functions in order to ch
Last Modification Data: 28/03/2017
Status: Working 
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

class door :public object
{
public:
	bool isOpen;      //checks if door is open or not

	door()
	{
		isOpen = false;  
	}
};
