/*===================================================

	[SceneTitle.h]
	Author : �o���đ�

====================================================*/

#pragma once
#include "SceneBase.h"
#include "TitleCamera.h"

//#	SceneTitle�N���X
/* �^�C�g���V�[�����Ǘ�����N���X */
class SceneTitle : public SceneBase 
{
private:
	TitleCamera *m_pTitleCamera;
public:
	SceneTitle();
	~SceneTitle();
	void Init();	//	�Q�[���̏���������	
	void Uninit();	//	�Q�[���̏I������
	void Update();	//	�Q�[���̍X�V����
	void Draw();	//	�Q�[���̕`�揈��
};

