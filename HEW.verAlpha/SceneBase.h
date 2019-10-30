/*=====================================================

	[SceneBase.h]
	Author : �o���đ�

======================================================*/

#pragma once
#include "main.h"

//#	SceneBase�N���X : �e�N���X
class SceneBase
{
public:
	//���z�֐��w��
	virtual ~SceneBase() {};	//	�f�X�g���N�^
	virtual void Init() = 0;	//	����������
	virtual void Uninit() = 0;	//	�I������
	virtual void Update() = 0;	//	�X�V����
	virtual void Draw() = 0;	//	�`�揈��
};
