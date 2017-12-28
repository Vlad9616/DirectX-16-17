/*
Description: getters and setters of baseVariables.h
Last Modification Data:25/03/2018
Status:Working
To Do:-
*/
#include "baseVariables.h"

//GETTERS//

float baseVariables::get_xAxis()
{
	return xAxis;
}

float baseVariables::get_yAxis()
{
	return yAxis;
}

float baseVariables::get_zAxis()
{
	return zAxis;
}

float baseVariables::get_Rotation()
{
	return rotation;
}

//SETTERS//

void baseVariables::set_xAxis(float setX)
{
	xAxis = setX;
}
void baseVariables::set_yAxis(float setY)
{
	yAxis = setY;
}

void baseVariables::set_zAxis(float setZ)
{
	zAxis = setZ;
}

void baseVariables::set_Rotation(float setRot)
{
	rotation = setRot;
}

void baseVariables::set_all(float setX, float setY, float setZ, float setRot)
{
	xAxis = setX;
	yAxis = setY;
	zAxis = setZ;
	rotation = setRot;
}
//Set Object//
void baseVariables::setData(ID3D11Device* setDevice, ID3D11DeviceContext* setDevcon, ID3D11InputLayout * setLayout, ID3D11Buffer* setBuffer, ID3D11Buffer* setIndex, ID3D11Buffer* setCb)
{
	objDevice = setDevice;
	objDevcon = setDevcon;
	objLayout = setLayout;
	objBuffer = setBuffer;
	objIndex = setIndex;
	objCbBuffer = setCb;
}

//Load Shaders//
void baseVariables::LoadShader()
{
	ID3D10Blob *VS, *PS;
	D3DX11CompileFromFile(L"shaders.shader", 0, 0, "VShader", "vs_4_0", 0, 0, 0, &VS, 0, 0);
	D3DX11CompileFromFile(L"shaders.shader", 0, 0, "PShader", "ps_4_0", 0, 0, 0, &PS, 0, 0);

	// encapsulate both shaders into shader objects
	objDevice->CreateVertexShader(VS->GetBufferPointer(), VS->GetBufferSize(), NULL, &objVS);
	objDevice->CreatePixelShader(PS->GetBufferPointer(), PS->GetBufferSize(), NULL, &objPS);

	// set the shader objects
	objDevcon->VSSetShader(objVS, 0, 0);
	objDevcon->PSSetShader(objPS, 0, 0);
	// create the input layout object
	D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	objDevice->CreateInputLayout(ied, 2, VS->GetBufferPointer(), VS->GetBufferSize(), &objLayout);
	objDevcon->IASetInputLayout(objLayout);
}