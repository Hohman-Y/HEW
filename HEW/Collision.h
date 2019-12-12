/*===================================================
	
	[Collision.h]
	Author : �o���đ�

===================================================*/

#pragma once
#include "main.h"
#include "Character.h"
#include "Map.h"
#include "Field.h"

//	�R���W�������Ǘ�����N���X
class Collision
{
public:
	static BOOL Collide(D3DXVECTOR3 vStart, D3DXVECTOR3 vDir, Field* pField, FLOAT* pfDistance, D3DXVECTOR3* pvNormal);	//	���C�ɂ��Փ˔���
	static HRESULT FindVerticesOnPoly(LPD3DXMESH pMesh, DWORD dwPolyIndex, D3DXVECTOR3* pvVertices);					//	�|���S���̒��_��������
	static D3DXVECTOR3 Slip(D3DXVECTOR3 L, D3DXVECTOR3 N);																//	����x�N�g��
};

/*	����

�����蔻��̓��[�J�����W�Ŏw�� -> �t�s��ŕϊ�����B�i�]�u�s��̂ق����͂₢�H�j

�����x�N�g���̒��ӓ_
4�����x�N�g���̈ړ��p�����[�^���O�ɂ��� -> ���s�ړ��𖳌��ɂ���

*/