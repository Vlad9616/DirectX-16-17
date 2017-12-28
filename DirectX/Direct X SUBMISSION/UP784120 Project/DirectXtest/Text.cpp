/*
Description: cpp file of Text.h
Last Modification Data:01/03/2017
Status:wORKING
To Do:-
Source: Jones, W., Sherrod, A. (2012). Beginning DirectX 11 Game Programming.
*/
#include <windows.h>
#include <windowsx.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <DirectXMath.h>
#include <xnamath.h>
#include "VERTEX.h"
#include "Text.h"


void text::set_texture(ID3D11ShaderResourceView* texture)
{
	objTexture = texture;
}
void text::setSamplerStatee(ID3D11SamplerState* sampler)
{
	objSamplerState = sampler;
}

void text::Load()
{
	D3D11_BUFFER_DESC vertexDesc;
	ZeroMemory(&vertexDesc, sizeof(vertexDesc));
	vertexDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_BUFFER_DESC cbbd;
	ZeroMemory(&cbbd, sizeof(D3D11_BUFFER_DESC));
	cbbd.Usage = D3D11_USAGE_DEFAULT;
	cbbd.ByteWidth = sizeof(cbPerObject);
	cbbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cbbd.CPUAccessFlags = 0;
	cbbd.MiscFlags = 0;
	objDevice->CreateBuffer(&cbbd, NULL, &objCbBuffer);

	const int sizeOfSprite = sizeof(VERTEX) * 6;
	const int maxLetters = 24;
	
	vertexDesc.ByteWidth = sizeOfSprite*maxLetters;
	objDevice->CreateBuffer(&vertexDesc, 0, &objBuffer);
}

void text::selectTexture(int setNumber)
{
	texture = setNumber;
}
void text::DrawString(char* message, float startX, float startY)
{
	const int sizeOfSprite = sizeof(VERTEX) * 6;

	const int maxLetters = 24;

	int length = strlen(message);

	if (length > maxLetters)
	{
		length = maxLetters;
	}

	float charWidth = 400.0f / 800.0f;
	float charHeight = 400.0f / 640.0f;
	float texelWidth = 32.0f / 864.0f;
	const int verticesPerLetter = 6;

	D3D11_MAPPED_SUBRESOURCE mapResource;
	objDevcon->Map(objBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapResource);

	VERTEX*spritePtr = (VERTEX*)mapResource.pData;

	const int indexA = static_cast<char>('A');
	const int indexZ = static_cast<char>('Z');

	for (int i = 0; i < length; i++)
	{
		float thisStartX = startX + (charWidth*static_cast<float>(i));
		float thisEndX = thisStartX + charWidth;
		float thisEndY = startY + charHeight;

		spritePtr[0].pos = XMFLOAT3(thisEndX, thisEndY, 1.0f);
		spritePtr[1].pos = XMFLOAT3(thisEndX, startY, 1.0f);
		spritePtr[2].pos = XMFLOAT3(thisStartX, startY, 1.0f);
		spritePtr[3].pos = XMFLOAT3(thisStartX, startY, 1.0f);
		spritePtr[4].pos = XMFLOAT3(thisStartX, thisEndY, 1.0f);
		spritePtr[5].pos = XMFLOAT3(thisEndX, thisEndY, 1.0f);

		int texLookup = 0;
		int letter = static_cast<char>(message[i]);

		if (letter<indexA || letter>indexZ)
		{
			texLookup = (indexZ - indexA) + 1;
		}
		else
		{
			texLookup = (letter - indexA);
		}

		float tuStart = 0.0f + (texelWidth*static_cast<float>(texLookup));
		float tuEnd = tuStart + texelWidth;

		spritePtr[0].texCoord = XMFLOAT2(tuEnd, 0.0f);
		spritePtr[1].texCoord = XMFLOAT2(tuEnd, 1.0f);
		spritePtr[2].texCoord = XMFLOAT2(tuStart, 1.0f);
		spritePtr[3].texCoord = XMFLOAT2(tuStart, 1.0f);
		spritePtr[4].texCoord = XMFLOAT2(tuStart, 0.0f);
		spritePtr[5].texCoord = XMFLOAT2(tuEnd, 0.0f);

		spritePtr += 6;
	}

	objDevcon->Unmap(objBuffer, 0);
	objDevcon->Draw(6 * length, 0);
}

void text::setString(int name)
{
	selectString = name;
}

int text::getString()
{
	return selectString;
}
void text::set_texture(ID3D11Device* setDevice)
{
	if (texture == -1)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"-1.png", NULL, NULL, &objTexture, NULL);
	}

	if (texture == 0)
	{
		D3DX11CreateShaderResourceViewFromFile(setDevice, L"0.png", NULL, NULL, &objTexture, NULL);
	}
}
void text::LoadShader()
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

void text::objCamera(XMMATRIX* setWVP, XMMATRIX* setView, XMMATRIX* setProjection)
{
	objWVP = *setWVP;
	objView = *setView;
	objProjection = *setProjection;
}

void text::objRender()
{
	UINT stride = sizeof(VERTEX);
	UINT offset = 0;
	objDevcon->IASetVertexBuffers(0, 1, &objBuffer, &stride, &offset);
	objDevcon->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	/////////////////////////////////////////////////////////////////////////////

	objWVP = objMatrix *objView*objProjection;
	cbPerObj.WVP = XMMatrixTranspose(objWVP);
	objDevcon->UpdateSubresource(objCbBuffer, 0, NULL, &cbPerObj, 0, 0);
	objDevcon->VSSetConstantBuffers(0, 1, &objCbBuffer);
	objDevcon->PSSetShaderResources(0, 1, &objTexture);
	objDevcon->PSSetSamplers(0, 1, &objSamplerState);

	if (selectString == 0)
	{
		DrawString("START GAME", -0.2f, 0.0f);
	}
	if (selectString == 1)
	{
		DrawString("END GAME", -0.2f, 0.0f);
	}
	if (selectString == 2)
	{
		DrawString("SELECT ONE",-0.2f,0.0f);
	}
	if (selectString == 3)
	{
		DrawString("ESC-MINE MENU",-0.2f,0.0f);
	}
}
void text::update(XMMATRIX *Translation, XMMATRIX *Rotation, XMMATRIX *Scaling)
{
	objMatrix = XMMatrixIdentity();
	XMVECTOR  rotaxis = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	*Rotation = XMMatrixRotationAxis(rotaxis, 0.1f);
	*Translation = XMMatrixTranslation(get_xAxis(), get_yAxis(), 5.0f);
	objMatrix = *Translation * *Rotation;
}