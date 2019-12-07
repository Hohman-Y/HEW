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

//	�R���W�������Ǘ�����N���X
class Collision
{
private:
	Character	m_Character;
	Map			m_Map;

public:
	static void Update();	//�X�V����
private:
	//	�w���p�[�֐��Q
	void Player_vs_Map();	//	�v���C���[�ƃ}�b�v�̓����蔻��
	HRESULT FindVerticesOnPoly(LPD3DXMESH pMesh, DWORD dwPolyIndex, D3DXVECTOR3* pvVertices);							//	�|���S���̒��_��������
	BOOL Collide(D3DXVECTOR3 vStart, D3DXVECTOR3 vDir, Character* pChara, FLOAT* pfDistance, D3DXVECTOR3* pvNormal);	//	���C�ɂ��Փ˔���
	D3DXVECTOR3 Slip(D3DXVECTOR3 L, D3DXVECTOR3 N);																		//	����x�N�g��
};

/*	����

�����蔻��̓��[�J�����W�Ŏw�� -> �t�s��ŕϊ�����B�i�]�u�s��̂ق����͂₢�H�j

�����x�N�g���̒��ӓ_
4�����x�N�g���̈ړ��p�����[�^���O�ɂ��� -> ���s�ړ��𖳌��ɂ���

*/