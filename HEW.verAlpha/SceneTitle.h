/*===================================================

	[SceneTitle.h]
	Author : �o���đ�

====================================================*/

#pragma once
#include "SceneBase.h"
#include "TitleCamera.h"
#include "Map.h"

//	SCENETILE�N���X
/* �^�C�g���V�[�����Ǘ�����N���X */
class SceneTitle : public SceneBase 
{
private:
	TitleCamera m_Camera;
	Map			m_Map;
public:
	//SceneBase�̃����o�[�֐��̃I�[�o�[���C�h
	void Init();	//	�Q�[���̏���������	
	void Uninit();	//	�Q�[���̏I������
	void Update();	//	�Q�[���̍X�V����
	void Draw();	//	�Q�[���̕`�揈��
};

