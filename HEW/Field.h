/*============================================
	
	[Field.h]
	Author :�@�o���đ�

============================================*/

#pragma once
#include "main.h"

class Field
{
public:
	static LPDIRECT3DTEXTURE9	m_pTextureModel;	//	�e�N�X�`���ւ̃|�C���^
	static LPD3DXMESH			m_pMeshModel;		//	���b�V�����ւ̃|�C���^
	static LPD3DXBUFFER			m_pBuffMatModel;	//	�}�e���A�����ւ̃|�C���^
	static DWORD				m_nNumMatModel;		//	�}�e���A�����̑���
	static LPDIRECT3DDEVICE9	m_pDevice;			//	�f�o�C�X
	D3DXMATRIX					m_mtxWorldModel;	//	���[���h�}�g���b�N�X
	D3DXVECTOR3					m_position;			//	�ʒu
	D3DXVECTOR3					m_scale;			//	�X�P�[��
	D3DXVECTOR3					m_angle;			//	��]
public:
	HRESULT Init(D3DXVECTOR3 Pos, D3DXVECTOR3 Scale, D3DXVECTOR3 Angle);
	void Uninit();
	void Draw();
};



