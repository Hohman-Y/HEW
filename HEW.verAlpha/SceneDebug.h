/*==============================================

	[SceneDebug.h]
	Author : �o���đ�

==============================================*/

#pragma once
#include "main.h"
#include "SceneBase.h"

//# SceneDebug : �e�N���XSceneBase
class SceneDebug: public SceneBase
{
public:
	//SceneBase�̃����o�[�֐��̃I�[�o�[���C�h
	void Init();	//	�Q�[���̏���������	
	void Uninit();	//	�Q�[���̏I������
	void Update();	//	�Q�[���̍X�V����
	void Draw();	//	�Q�[���̕`�揈��
};

