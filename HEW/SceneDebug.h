/*==============================================

	[SceneDebug.h]
	Author : �o���đ�

==============================================*/

#pragma once
#include "main.h"
#include "SceneBase.h"
#include "DebugCamera.h"
#include "Map.h"

//# SceneDebug : �e�N���XSceneBase
class SceneDebug: public SceneBase
{
	DebugCamera m_Camera;
	Map			m_Map;
public:
	//SceneBase�̃����o�[�֐��̃I�[�o�[���C�h
	void Init();	//	�Q�[���̏���������	
	void Uninit();	//	�Q�[���̏I������
	void Update();	//	�Q�[���̍X�V����
	void Draw();	//	�Q�[���̕`�揈��
};
