/*
Description: Class used to create platform objects that are moving from point A to point B horizontally
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

class platform:public object
{
public:
	
	bool end;  //value that checks if the platform has reached the end point
	bool start;  //value that checks if the platfrom has reached the start poing
	void moveAtoB(float startPosition, float endPosition);

	platform()
	{
		start = true;
		end = false;
	}
	
};