/*==============================================

	[SceneDebug.h]
	Author : �o���đ�

==============================================*/

#pragma once
#include "main.h"
#include "SceneBase.h"
#include "DebugCamera.h"

//# SceneDebug : �e�N���XSceneBase
class SceneDebug: public SceneBase
{
private:
	DebugCamera *m_pDebugCamera;
public:
	SceneDebug();
	~SceneDebug();
	void Init();	//	�Q�[���̏���������	
	void Uninit();	//	�Q�[���̏I������
	void Update();	//	�Q�[���̍X�V����
	void Draw();	//	�Q�[���̕`�揈��
};

