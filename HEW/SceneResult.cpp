/*===================================================

	[SceneResult.cpp]
	Author : �o���đ�

====================================================*/

#include "SceneResult.h"
#include "SceneManager.h"
#include "Controller.h"

//	�X�^�e�B�b�N�ϐ�
int SceneResult::m_Ranking[5];

void SceneResult::Init()
{

	//Sort(�Q�b�^�[�Ŕ򋗗��̒l�������Ă���);
}

void SceneResult::Uninit()
{

}

void SceneResult::Update()
{

	if (KeyBoard::IsTrigger(DIK_W))
	{
		SceneManager::ChangeSceneState();
	}
}

void SceneResult::Draw()
{
	m_Sprite.Draw(TEXTURE_INDEX_RESULT,0.0f,0.0f);
	
	/*�X�R�A�̕`��
	for (int i = 0; i < RANKING_MAX; i++)	//	�`����܉�J��Ԃ�
	{
		Score_Draw(SCREEN_WIDTH / 2 - 48, SCREEN_HEIGHT / 3 + i * 32, ranking[i], 3, true);	
	}	
	*/
	
}

void SceneResult::Sort(int Score)
{
	for (int i = 0; i < 5; i++)
	{//1�ʂ����r
		//���̏��ʂ���������΂��ꂪ����̏��ʂƂȂ�
		//(1�ʂ�荂�����1�ʁA1�ʂ��Ⴍ2�ʂ�荂�����2�ʁA�c)
		if (Score > m_Ranking[i])
		{
			for (int j = 5 - 1; j > i; j--) //����̏��ʈȍ~�̃X�R�A�����炷
			{
				m_Ranking[j] = m_Ranking[j - 1];
			}
			m_Ranking[i] = Score;//����̃X�R�A���L��
			break;//�ȍ~�̏��ʂ͒��ׂȂ�
		}
	}
}
