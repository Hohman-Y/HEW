/*==============================================

	[SceneManager.cpp]
	Author : �o���đ�

===============================================*/
#include "main.h"
#include "input.h"
#include "SceneGame.h"
#include "SceneManager.h"

//	�O���[�o���ϐ�
SceneBase			*SceneManager::scene[SCENE_NUMBER];
SCENE_STATE			SceneManager::scenestate;
LPDIRECT3DDEVICE9	SceneManager::p3DDevice;

//	����������
void SceneManager::Init()
{
	p3DDevice = GetD3DDevice();	//	�f�o�C�X�̎擾
	scene[0] = new SceneGame;	//	�V�[���̃C���X�^���X����
	scenestate = SCENE_GAME;	//	�����V�[���̐ݒ�
	scene[scenestate]->Init();	//	�����V�[���̏�����
}

//	�I������
void SceneManager::Uninit()
{
	scene[0]->Uninit();
	delete scene[0];
}

//	�X�V����
void SceneManager::Update()
{
	if (Input::GP_IsTrigger(0,BUTTON_2)) 
	{
		SceneManager::ChangeSceneState();
	}
	scene[scenestate]->Update();
}

//	�`�揈��
void SceneManager::Draw()
{
	scene[scenestate]->Draw();
}

//	�V�[���J�ڏ���
void SceneManager::ChangeSceneState()
{
	switch (scenestate)
	{
	case SCENE_GAME:
		scene[scenestate]->Uninit();
	}
}
