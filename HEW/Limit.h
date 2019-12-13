#pragma once

#include <d3d9.h>
#include "texture.h"


class Limit
{
private:
	static D3DXMATRIX				m_mtxWorld;			//	���[���h�}�g���b�N�X
	static LPDIRECT3DVERTEXBUFFER9	m_pVertexBuffer;	//	���_�o�b�t�@
	static LPDIRECT3DINDEXBUFFER9	m_pIndexBuffer;		//	�C���f�b�N�X�o�b�t�@
	static LPDIRECT3DDEVICE9		m_Device;			//	�f�o�C�X
	
public:

	void Update();
	void Draw(TextureIndex texture_index, float dx, float dy, int tx, int ty, int tw, int th, float cx, float cy, float sx, float sy, float rotation);
};