/*===========================================================

	[Model.h]
	Author : �o���đ�

============================================================*/

#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "XFile.h"

//#	Model�N���X : XFile�N���X�̔h���N���X
/* ���f����`�悷��N���X */
class XFile;

class Model
{
private:
	D3DXVECTOR3	position;					//	�ʒu
	D3DXVECTOR3	scale;						//	�傫��
	D3DXVECTOR3	angle;						//	��]
	XFile *pmodel;							//	XFile�^�|�C���^�ϐ�
	static LPDIRECT3DDEVICE9 g_pD3DDevice;	//	�f�o�C�X

public:
	Model(D3DXVECTOR3 position, D3DXVECTOR3 scale, D3DXVECTOR3 angle, XFile *pmodel) :position(position), scale(scale), angle(angle), pmodel(pmodel) {}	//	�R���X�g���N�^�F�ϐ��̏����l
	void Draw();	//	�`�揈��
};


