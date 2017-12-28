/*
Description:Class used to define text objects
Last Modification Data:
Status:Working
To Do:-
Source: Jones, W., Sherrod, A. (2012). Beginning DirectX 11 Game Programming.
*/
#pragma once
#include <windowsx.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <DirectXMath.h>
#include <xnamath.h>
#include "VERTEX.h"
#include "cbPerObj.h"
#include "baseVariables.h"

class text : public baseVariables 
{
public:
	XMMATRIX objMatrix;
	ID3D11ShaderResourceView* objTexture;
	ID3D11SamplerState* objSamplerState;
	XMMATRIX objWVP;
	XMMATRIX objView;
	XMMATRIX objProjection;

	int texture;
	void objCamera(XMMATRIX* setWVP, XMMATRIX *setView, XMMATRIX *setProjection);
	void set_texture(ID3D11Device* setDevice);
	void objRender();
	void selectTexture(int setNumber);


	int selectString;
	void setString(int name);
	int  getString();
		
	void set_texture(ID3D11ShaderResourceView*  texture);
	void setSamplerStatee(ID3D11SamplerState * sampler);
	void update(XMMATRIX *Translation, XMMATRIX *Rotation, XMMATRIX *Scaling);
	void LoadShader();

	void Load();
	void DrawString(char* message, float startX, float startY);
};