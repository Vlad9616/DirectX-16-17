/*
Description: default class for all the objects (non text objects) in the game
Last Modification Data:20/03/2017
Status:Working
To Do: add getters and setters
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
#include "baseVariables.h"
class object : public baseVariables
{

public:
	object()
	{
		xAxis = 0.0f;
		yAxis = 0.0f;
		zAxis = 0.0f;	
		rotation = 0.0f;
		isActive = false;
	}

	//float collisionTop;

	XMMATRIX objMatrix;
	XMMATRIX objWVP;
	XMMATRIX objView;
	XMMATRIX objProjection;

	int vertexType;			//select vertex data
	void setVertexType(int number);  //
	bool isActive;  //player-object interaction status
	ID3D11SamplerState* objSamplerState;
	ID3D11ShaderResourceView* objTexture;
	int texture;  //texture number

	void objCamera(XMMATRIX* setWVP,XMMATRIX *setView,XMMATRIX *setProjection);
	void objRender();
	
	void update(XMMATRIX *Translation,XMMATRIX *Rotation,XMMATRIX *Scaling);
	void selectTexture(int setNumber); //select texture
	void setSamplerStatee(ID3D11SamplerState * sampler);
	void set_texture(ID3D11ShaderResourceView*  texture);
	void set_texture(ID3D11Device* setDevice);
	float distance( float z, float w);  //calculates the distance between the object and another object that has  
	void Load();
	//void Load2();
};