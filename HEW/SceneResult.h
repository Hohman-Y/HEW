/*===================================================
	
	[SceneResult.h]
	Author : �o���đ�

===================================================*/

#pragma once
#include"SceneBase.h"
#include "sprite.h"

class SceneResult : public SceneBase
{
private:
	Sprite		m_Sprite;				//	Sprite�C���X�^���X
	static	int	m_Ranking[5];	//	�����L���O�̒l���i�[����z��
public:
	//SceneBase�̃����o�[�֐��̃I�[�o�[���C�h
	void Init();	//	�Q�[���̏���������	
	void Uninit();	//	�Q�[���̏I������
	void Update();	//	�Q�[���̍X�V����
	void Draw();	//	�Q�[���̕`�揈��

private:
	void Sort(int Score);	//	�\�[�g�֐�
};

