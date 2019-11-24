/*=======================================================

	[SecneModeSelect.cpp]
	Author : �o���đ�

=======================================================*/

#include "SceneModeSelect.h"
#include "SceneManager.h"
#include "Controller.h"

//	������
void SceneModeSelect::Init()
{

}

//	�I������
void SceneModeSelect::Uninit()
{
	
}

//	�X�V����
void SceneModeSelect::Update()
{
	if (KeyBoard::IsTrigger(DIK_W))
	{
		SceneManager::ChangeSceneState();
	}
}

//	�`�揈��
void SceneModeSelect::Draw()
{
	m_Sprite.Draw(TEXTURE_INDEX_MODESELECT, 0.0f, 0.0f);
}
