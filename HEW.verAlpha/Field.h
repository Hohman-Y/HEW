/*===========================================================

	[Field.h]
	Author : �o���đ�

=============================================================*/

#pragma once
#include "Model.h"

//	�}�N����`
#define OBJECT_NUM 1	// Object�̐�

//# Field�N���X
/* �Q�[���̔w�i�̕`�������N���X */
class Field
{
private:
	static Model *Object[OBJECT_NUM];					//	Model�^�|�C���^�z��
public:
	static void Init();		//	����������
	static void Uninit();	//	�I������
	static void Draw();		//	�`�揈��
};

