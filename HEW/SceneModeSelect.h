/*=======================================================

	[SecneModeSelect.h]
	Author : �o���đ�

=======================================================*/

#pragma once
#include "SceneBase.h"
#include "sprite.h"

class SceneModeSelect : public SceneBase
{
	
private:
	Sprite m_Sprite;
public:
	void Init();	//	�Q�[���̏���������	
	void Uninit();	//	�Q�[���̏I������
	void Update();	//	�Q�[���̍X�V����
	void Draw();	//	�Q�[���̕`�揈��
};
bool Getflg();
