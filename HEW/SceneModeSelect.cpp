/*=======================================================

	[SecneModeSelect.cpp]
	Author :���a�� 

=======================================================*/

#include "SceneModeSelect.h"
#include "SceneManager.h"
#include "Controller.h"
#include "main.h"

static bool flg=true;
//	������
void SceneModeSelect::Init()
{

}

//	�I������
void SceneModeSelect::Uninit()
{

	//flg = Getflg();

		if (flg == true)
		{
			//�`���[�g���A��
			m_Sprite.Draw(TEXTURE_INDEX_SCENE_TUTORIAL, 0.0f, 0.0f, 0.0f, 0.0f, 10.0f, 20.0f, 2.0f, 0.0f, 5.0f, 0.0f);
		}
		else if (flg == false)
		{
			//�Q�[��
			m_Sprite.Draw(TEXTURE_INDEX_SCENE_GAME, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,0.0f);
		}

}

//	�X�V����
void SceneModeSelect::Update()
{

	if (KeyBoard::IsTrigger(DIK_Q))
	{
		flg = true;
	}
	if (KeyBoard::IsTrigger(DIK_E))
	{
		flg = false;
	}
	if (KeyBoard::IsTrigger(DIK_W))
	{
		SceneManager::ChangeSceneState();
	}
}

//	�`�揈��
void SceneModeSelect::Draw()
{
	//m_Sprite.Draw(TEXTURE_INDEX_MODESELECT, 0.0f, 0.0f);
	
	//m_Sprite.Draw; //(�ʏ�̂��)
	//m_Sprite.Draw; //(�ʏ�̂��)

		if (flg == true)
		{
			m_Sprite.Draw(TEXTURE_INDEX_SCENE_TUTORIAL,0.0f,0.0f,0.0f,0.0f,500.0f,500.0f,255.0f,255.0f,255.0f,255.0f);// (�F�ύX)
		}
		else if (flg == false)
		{
			m_Sprite.Draw(TEXTURE_INDEX_SCENE_GAME, 0.0f, 0.0f, 0.0f, 0.0f, 500.0f, 500.0f, 20.0f,200.0f, 0.0f, 0.0f);// (�F�ύX)
		}
	
}


bool Getflg()
{
	return flg;
}
