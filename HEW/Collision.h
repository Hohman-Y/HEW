/*===================================================
	
	[Collision.h]
	Author : �o���đ�

===================================================*/

#pragma once
#include "main.h"
#include "Character.h"
#include "Field.h"

//	�R���W�������Ǘ�����N���X
class Collision
{
public:
	static BOOL Collide(D3DXVECTOR3 vStart, D3DXVECTOR3 vDir, Field* pField, FLOAT* pfDistance, D3DXVECTOR3* pvNormal);	//	���C�ɂ��Փ˔���
	static HRESULT FindVerticesOnPoly(LPD3DXMESH pMesh, DWORD dwPolyIndex, D3DXVECTOR3* pvVertices);					//	�|���S���̒��_��������
	static D3DXVECTOR3 Slip(D3DXVECTOR3 L, D3DXVECTOR3 N);																//	����x�N�g��
};
