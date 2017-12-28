/*
Description: This class contains the most common variables that are used by most of the other classes
Last Modification Data:25/03/2017
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
#include "VERTEX.h"
#include "cbPerObj.h"

class baseVariables
{
public:
	void setData(ID3D11Device* setDevice, ID3D11DeviceContext* setDevcon, ID3D11InputLayout * setLayout, ID3D11Buffer* setBuffer, ID3D11Buffer* setIndex, ID3D11Buffer* setCb);
	void setSamplerStatee(ID3D11SamplerState * sampler);
	void set_texture(ID3D11ShaderResourceView*  texture);

	void set_xAxis(float setX);           //set X axis
	void set_yAxis(float setY);	          //set Y axis
	void set_zAxis(float setZ);           //set Z axis

	void set_all(float setX,float setY,float setZ,float setRot); //set X,Y,Z axis and rotation in the same time

	float get_xAxis();                     //get X axis
	float get_yAxis();                     //get Y axis
	float get_zAxis();	                   //get Z axus

	void set_Rotation(float setRot);       //set rotation
	float get_Rotation();                  //get rotation

	void LoadShader();                     //Load Shader

protected:
	ID3D11Device *objDevice;               //object device
	ID3D11DeviceContext *objDevcon;        //object device context
	ID3D11InputLayout *objLayout;          //object input layout
	
	ID3D11Buffer *objBuffer;               //object vertex buffer
	ID3D11Buffer *objIndex;                //object index buffer
	ID3D11Buffer* objCbBuffer;             //object constant buffer
	cbPerObject cbPerObj;

	ID3D11VertexShader *objVS;             //object vertex shader
	ID3D11PixelShader *objPS;			   //object pixel shader
	ID3D11SamplerState* objSamplerState;
	ID3D11ShaderResourceView* objTexture;  //object texture

	float xAxis;
	float yAxis;
	float zAxis;
	float rotation;

	XMMATRIX objWVP;                       //World View Projection Matrix
	XMMATRIX objView;                      //View Matrix
	XMMATRIX objProjection;                //Projection Matrix
};