/*==================================

	[SceneGame.cpp]
	Author : �o���đ�

===================================*/

#include "SceneGame.h"
#include "SceneManager.h"
#include "Controller.h"
#include "Character.h"
#include "XFile.h"
#include "Model.h"
#include "main.h"

//	�Q�[���̏���������
void SceneGame::Init()
{

}

//	�Q�[���̏I������
void SceneGame::Uninit()
{
	
}

//	�Q�[���̍X�V����
void SceneGame::Update()
{
	if (KeyBoard::IsTrigger(DIK_W))
	{
		SceneManager::ChangeSceneState();
	}
}

//	�Q�[���̕`�揈��
void SceneGame::Draw()
{

}
