/*================================================

	[SceneTitle.h]
	Author : �o���đ�
	
================================================*/

#pragma once
#include "SceneBase.h"

//#	SceneGame�N���X:�e�N���X,SceneBase���p�������q�N���X
class SceneTitle : public SceneBase
{
public:
	//	SceneBase�̃����o�[�֐��̃I�[�o�[���C�h
	void Init();	//	����������
	void Uninit();	//	�I������
	void Update();	//	�X�V����
	void Draw();	//	�`�揈��
};

