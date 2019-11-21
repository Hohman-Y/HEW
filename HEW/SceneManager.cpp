/*==============================================

	[SceneManager.cpp]
	Author : �o���đ�

===============================================*/
#include "main.h"
#include "input.h"
#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneModeSelect.h"
#include "SceneTutorial.h"
#include "SceneGame.h"
#include "SceneResult.h"
#include "SceneDebug.h"


//	�O���[�o���ϐ�
SceneBase			*SceneManager::scene[SCENE_NUMBER];
SCENE_STATE			SceneManager::scenestate;
LPDIRECT3DDEVICE9	SceneManager::p3DDevice;

//	����������
void SceneManager::Init()
{
	p3DDevice = GetD3DDevice();			//	�f�o�C�X�̎擾

	//	�������̊m��
	scene[0] = new SceneTitle;			
	scene[1] = new SceneModeSelect;		
	scene[2] = new SceneTutorial;		
	scene[3] = new SceneGame;			
	scene[4] = new SceneResult;
	scene[5] = new SceneDebug;

	scenestate = SCENE_DEBUG;			//	�����V�[���̐ݒ�
	scene[scenestate]->Init();			//	�����V�[���̏�����
}

//	�I������
void SceneManager::Uninit()
{
	//	�e�V�[����Uninit�֐����Ăяo��
	scene[5]->Uninit();
	scene[4]->Uninit();
	scene[3]->Uninit();
	scene[2]->Uninit();
	scene[1]->Uninit();
	scene[0]->Uninit();

	//	�e�V�[���̃������̉��
	delete scene[5];
	delete scene[4];
	delete scene[3];
	delete scene[2];
	delete scene[1];
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
	case SCENE_TITLE:
		scene[scenestate]->Uninit();
		scenestate = SCENE_MODESELECT;
		scene[scenestate]->Init();
	case SCENE_MODESELECT:
		scene[scenestate]->Uninit();
		scene[scenestate]->Init();
	case SCENE_TUTORIAL:
		scene[scenestate]->Uninit();
	case SCENE_GAME:
		scene[scenestate]->Uninit();
	case SCENE_RESULT:
		scene[scenestate]->Uninit();
	case SCENE_DEBUG:
		scene[scenestate]->Uninit();
	}
}
 