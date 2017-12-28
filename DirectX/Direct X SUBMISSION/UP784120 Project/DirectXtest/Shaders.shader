
cbuffer cbPerObject
{
	float4x4 WVP;
};

Texture2D ObjTexture;
SamplerState ObjSamplerState;

struct VOut
{
	float4 Pos : SV_POSITION;
	float2 TexCoord: TEXCOORD;
};

VOut VShader(float4 inPos : POSITION, float2 inTexCoord : TEXCOORD)
{
	VOut output;
	output.Pos = mul(inPos,WVP);
	output.TexCoord = inTexCoord;

	return output;
}


float4 PShader(VOut input) : SV_TARGET
{
	return ObjTexture.Sample(ObjSamplerState, input.TexCoord);
}