/*==================================

	[SceneGame.cpp]
	Author : �o���đ�

===================================*/

#include "SceneGame.h"
#include "SceneManager.h"
#include "input.h"
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
	Character::Uninit();
}

//	�Q�[���̍X�V����
void SceneGame::Update()
{
	Character::Update();
}

//	�Q�[���̕`�揈��
void SceneGame::Draw()
{

}
