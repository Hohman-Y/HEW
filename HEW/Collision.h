/*===================================================
	
	[Collision.h]
	Author : �o���đ�

===================================================*/

#pragma once
#include "main.h"
#include "Character.h"
#include "Map.h"
#include "Model.h"
#include "XFile.h"
#include "Field.h"

//	�R���W�������Ǘ�����N���X
class Collision
{
private:
	Character	m_Character;
	Field		m_Field;
public:
	Collision();
	D3DXVECTOR3 Player_vs_Map(D3DXVECTOR3 pos,D3DXVECTOR3 move);	//	�v���C���[�ƃ}�b�v�̓����蔻��
	
	BOOL Collide(D3DXVECTOR3 vStart, D3DXVECTOR3 vDir, XFile* XFile, Model* pModel, FLOAT* pfDistance, D3DXVECTOR3* pvNormal);	//	���C�ɂ��Փ˔���
	D3DXVECTOR3 Slip(D3DXVECTOR3 L, D3DXVECTOR3 N);																				//	����x�N�g��
};

BOOL Collide(D3DXVECTOR3, D3DXVECTOR3, Field*, FLOAT*, D3DXVECTOR3*);
VOID RenderRay(LPDIRECT3DDEVICE9, D3DXVECTOR3, D3DXVECTOR3);
D3DXVECTOR3 Slip(D3DXVECTOR3 L, D3DXVECTOR3 N);
HRESULT FindVerticesOnPoly(LPD3DXMESH pMesh, DWORD dwPolyIndex, D3DXVECTOR3* pvVertices);						//	�|���S���̒��_��������

/*	����

�����蔻��̓��[�J�����W�Ŏw�� -> �t�s��ŕϊ�����B�i�]�u�s��̂ق����͂₢�H�j

�����x�N�g���̒��ӓ_
4�����x�N�g���̈ړ��p�����[�^���O�ɂ��� -> ���s�ړ��𖳌��ɂ���

*/