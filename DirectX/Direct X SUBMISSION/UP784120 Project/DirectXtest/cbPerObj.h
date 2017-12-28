/*
Description: constant buffer structure
Last Modification Data: 15/02/2017
Status: Done
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

struct cbPerObject
{
	XMMATRIX  WVP;
};