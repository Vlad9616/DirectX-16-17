/*
Description: getters and setters of object.h/ texture selection/ vertex selection
Last Modification Data: 20/03/2017
Status:Working
To Do:-
Source: built on http://www.directxtutorial.com/Lesson.aspx?lessonid=11-4-5 template
*/
#include <windows.h>
#include <windowsx.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <DirectXMath.h>
#include <xnamath.h>
#include <math.h>

#include "object.h"
#include "baseVariables.h"

#define KEYDOWN( name, key ) ( name[key] & 0x80 )


void object::set_texture(ID3D11ShaderResourceView* texture)
{
	objTexture = texture;
}
void object::setSamplerStatee(ID3D11SamplerState* sampler)
{
	objSamplerState = sampler;
}

//select textures. textures have values from -1 to 13
void object::selectTexture(int setNumber)
{
	texture = setNumber;
}

void object::set_texture(ID3D11Device* setDevice)
{
	if (texture == 1)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"1.png", NULL, NULL, &objTexture, NULL);
	}
	if (texture == 2)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"2.png", NULL, NULL, &objTexture, NULL);
	}
	if (texture == 3)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"3.png", NULL, NULL, &objTexture, NULL);
	}
	if (texture == 4)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"4.png", NULL, NULL, &objTexture, NULL);
	}
	if (texture == 5)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"5.png", NULL, NULL, &objTexture, NULL);
	}
	if (texture == 6)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"6.png", NULL, NULL, &objTexture, NULL);
	}
	if (texture == 7)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"7.png", NULL, NULL, &objTexture, NULL);
	}
	if (texture == 8)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"8.png", NULL, NULL, &objTexture, NULL);
	}
	if (texture == 9)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"9.png", NULL, NULL, &objTexture, NULL);
	}
	if (texture == 10)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"10.png", NULL, NULL, &objTexture, NULL);
	}
	if (texture == 11)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"11.png", NULL, NULL, &objTexture, NULL);
	}
	if (texture == 12)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"12.png", NULL, NULL, &objTexture, NULL);
	}
	if (texture == 13)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"13.png", NULL, NULL, &objTexture, NULL);
	}
}


void object::setVertexType(int number)
{
	vertexType = number;
}
void object::Load()
{
		VERTEX vertices_1[] =
		{
			{ XMFLOAT3(-1.0f, 1.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
			{ XMFLOAT3(1.0f, 1.0f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
			{ XMFLOAT3(1.0f, -1.0f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
			{ XMFLOAT3(-1.0f, -1.0f, 0.0f), XMFLOAT2(0.0f, 1.0f) },
		
		};

		VERTEX vertices_2[] =
		{
			{ XMFLOAT3(-3.0f, 0.3f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
			{ XMFLOAT3(3.0f, 0.3f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
			{ XMFLOAT3(3.0f, -1.0f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
			{ XMFLOAT3(-3.0f, -1.0f, 0.0f), XMFLOAT2(0.0f, 1.0f) },
		};

		VERTEX vertices_3[] =
		{
			{ XMFLOAT3(-1.0f, 0.25f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
			{ XMFLOAT3(1.0f, 0.25f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
			{ XMFLOAT3(1.0f, -1.0f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
			{ XMFLOAT3(-1.0f, -1.0f, 0.0f), XMFLOAT2(0.0f, 1.0f) },
		};
		VERTEX vertices_4[] =
		{
			{ XMFLOAT3(-1.0f, 2.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
			{ XMFLOAT3(1.0f, 2.0f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
			{ XMFLOAT3(1.0f, -2.0f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
			{ XMFLOAT3(-1.0f, -2.0f, 0.0f), XMFLOAT2(0.0f, 1.0f) },
		};

		VERTEX vertices_5[] =
		{
			{ XMFLOAT3(-0.2f, 0.2f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
			{ XMFLOAT3(0.2f, 0.2f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
			{ XMFLOAT3(0.2f, -0.2f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
			{ XMFLOAT3(-0.2f, -0.2f, 0.0f), XMFLOAT2(0.0f, 1.0f) },
		};

		VERTEX vertices_6[] =
		{
			{ XMFLOAT3(-4.0f, 3.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
			{ XMFLOAT3(4.0f, 3.0f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
			{ XMFLOAT3(4.0f, -3.0f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
			{ XMFLOAT3(-4.0f, -3.0f, 0.0f), XMFLOAT2(0.0f, 1.0f) },
		};
		VERTEX vertices_7[]=
		{
			{ XMFLOAT3(-1.0f, 3.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
			{ XMFLOAT3(1.0f, 3.0f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
			{ XMFLOAT3(1.0f, -3.0f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
			{ XMFLOAT3(-1.0f, -3.0f, 0.0f), XMFLOAT2(0.0f, 1.0f) },
		};
		VERTEX vertices_8[] =
		{
			{ XMFLOAT3(-3.0f, 1.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
			{ XMFLOAT3(3.0f, 1.0f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
			{ XMFLOAT3(3.0f, -1.0f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
			{ XMFLOAT3(-3.0f, -1.0f, 0.0f), XMFLOAT2(0.0f, 1.0f) },
		};
		VERTEX vertices_9[] =
		{
			{ XMFLOAT3(-2.0f, 0.25f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
			{ XMFLOAT3(2.0f, 0.25f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
			{ XMFLOAT3(2.0f, -1.0f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
			{ XMFLOAT3(-2.0f, -1.0f, 0.0f), XMFLOAT2(0.0f, 1.0f) },
		};
		VERTEX vertices_10[] =
		{
			{ XMFLOAT3(-0.5f, 1.5f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
			{ XMFLOAT3(0.5f, 1.5f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
			{ XMFLOAT3(0.5f, -1.5f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
			{ XMFLOAT3(-0.5f, -1.5f, 0.0f), XMFLOAT2(0.0f, 1.0f) },
		};
		// INDICES LIST
	UINT indices[] =
	{
		0, 1, 2,
		0, 2, 3,
	};


	D3D11_BUFFER_DESC indexBufferDesc;
	indexBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
	indexBufferDesc.ByteWidth = sizeof(UINT) *2* 3;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;
	// copy the vertices into the buffer

	D3D11_SUBRESOURCE_DATA iinitData;
	iinitData.pSysMem = indices;
	objDevice->CreateBuffer(&indexBufferDesc, &iinitData, &objIndex);
	objDevcon->IASetIndexBuffer(objIndex, DXGI_FORMAT_R32_UINT, 0);
	//////////////////////////////////////////////////////////////////

	// CREATE THE VERTEX BUFFER
	D3D11_BUFFER_DESC vertexBufferDesc;
	ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));

	vertexBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;                // write access access by CPU and GPU
	vertexBufferDesc.ByteWidth = sizeof(VERTEX) * 24;               // size is the VERTEX struct * 3
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;         // use as a vertex buffer
	vertexBufferDesc.CPUAccessFlags = 0;                           // allow CPU to write in buffer
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA vertexBufferData;
	ZeroMemory(&vertexBufferData, sizeof(vertexBufferData));

	if (vertexType == 1)
	{
		vertexBufferData.pSysMem = vertices_1;

	}
	if (vertexType == 2)
	{
		vertexBufferData.pSysMem = vertices_2;

	}
	if (vertexType == 3)
	{
		vertexBufferData.pSysMem = vertices_3;
	}
	if (vertexType == 4)
	{
		vertexBufferData.pSysMem = vertices_4;
	}
	if (vertexType == 5)
	{
		vertexBufferData.pSysMem = vertices_5;
	}
	if (vertexType == 6)
	{
		vertexBufferData.pSysMem = vertices_6;
	}
	if (vertexType == 7)
	{
		vertexBufferData.pSysMem = vertices_7;
	}
	if (vertexType == 8)
	{
		vertexBufferData.pSysMem = vertices_8;
	}

	if (vertexType == 9)
	{
		vertexBufferData.pSysMem = vertices_9;
	}
	if (vertexType == 10)
	{
		vertexBufferData.pSysMem = vertices_10;
	}
	objDevice->CreateBuffer(&vertexBufferDesc, &vertexBufferData, &objBuffer);

	D3D11_SAMPLER_DESC sampDesc;
	ZeroMemory(&sampDesc, sizeof(sampDesc));
	sampDesc.Filter = D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT;
	sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
	sampDesc.MinLOD = 0;
	sampDesc.MaxLOD = D3D11_FLOAT32_MAX;
	objDevice->CreateSamplerState(&sampDesc, &objSamplerState);

	D3D11_BUFFER_DESC cbbd;
	ZeroMemory(&cbbd, sizeof(D3D11_BUFFER_DESC));
	cbbd.Usage = D3D11_USAGE_DEFAULT;
	cbbd.ByteWidth = sizeof(cbPerObject);
	cbbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cbbd.CPUAccessFlags = 0;
	cbbd.MiscFlags = 0;
	objDevice->CreateBuffer(&cbbd, NULL, &objCbBuffer);
}

void object::objCamera(XMMATRIX* setWVP, XMMATRIX* setView, XMMATRIX* setProjection)
{
	objWVP = *setWVP;
	objView = *setView;
	objProjection = *setProjection;
}

void object::objRender()
{
	UINT stride = sizeof(VERTEX);
	UINT offset = 0;
	objDevcon->IASetVertexBuffers(0, 1, &objBuffer, &stride, &offset);
	objDevcon->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	objWVP = objMatrix *objView*objProjection;
	cbPerObj.WVP = XMMatrixTranspose(objWVP);
	objDevcon->UpdateSubresource(objCbBuffer, 0, NULL, &cbPerObj, 0, 0);
	objDevcon->VSSetConstantBuffers(0, 1, &objCbBuffer);
	objDevcon->PSSetShaderResources(0, 1, &objTexture);
	objDevcon->PSSetSamplers(0, 1, &objSamplerState);

	objDevcon->DrawIndexed(36, 0, 0);
}


//D3-Collision Detection
float object::distance(float z, float w)
{
	float e1 = (z - get_xAxis())*(z - get_xAxis());
	float e2 = (w - get_yAxis())*(w - get_yAxis());
	return fabs(sqrt(e1+e2));
}


void object::update(XMMATRIX *Translation, XMMATRIX *Rotation, XMMATRIX *Scaling)
{
	objMatrix = XMMatrixIdentity();
	XMVECTOR  rotaxis = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	*Rotation = XMMatrixRotationAxis(rotaxis, rotation);
	*Translation = XMMatrixTranslation(get_xAxis(), get_yAxis(), get_zAxis());
	objMatrix = *Translation * *Rotation;
}