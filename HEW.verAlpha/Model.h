/*===========================================================

	[Model.h]
	Author : �o���đ�

============================================================*/

#pragma once
#include "XFile.h"

//#	Model�N���X : �e�N���X->XFile�N���X
/* ���f����`�悷��N���X */
class Model : public XFile
{
private:
	D3DXVECTOR3	position;					//	�ʒu
	D3DXVECTOR3	scale;						//	�傫��
	D3DXVECTOR3	angle;						//	��]
	XFile *pmodel;							//	XFile�^�|�C���^�ϐ�
	static LPDIRECT3DDEVICE9 g_pD3DDevice;	//	�f�o�C�X

public:
	Model(D3DXVECTOR3	position, D3DXVECTOR3 scale, D3DXVECTOR3 angle, XFile *pmodel) :position(position), scale(scale), angle(angle), pmodel(pmodel) {}
	void Unload();
	void Draw();
};


