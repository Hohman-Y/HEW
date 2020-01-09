/*==================================

	[SceneGame.cpp]
	Author : �o���đ�

===================================*/

#include "SceneGame.h"
#include "SceneManager.h"
#include "Controller.h"
#include "main.h"
#include "light.h"
#include "debugproc.h"
#include "BillBoard.h"
#include "camera.h"

bool SceneGame::EndCheck()
{
	return false;
}

//	�Q�[���̏���������
void SceneGame::Init()
{
	
	DebugProc_Initialize();
	m_Character.Init(D3DXVECTOR3(0.0f, 50.0f, 48.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_Map.Init(D3DXVECTOR3(0.0f,0.0f,0.0f), D3DXVECTOR3(100.0f,100.0f,100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	Light::Init();
	//m_Camera.Init();
	Camera_Initialize();
	//BillBoard_Init();
}

//	�Q�[���̏I������
void SceneGame::Uninit()
{
	Camera_Finalize();
	m_Character.Uninit();
	m_Map.Uninit();
	//m_Camera.Uninit();
	DebugProc_Finalize();
	
	//BillBoard_Uninit();
}

//	�Q�[���̍X�V����
void SceneGame::Update()
{
	switch (m_GamePhase)
	{
	case PHASE_FADE:
		if (Fade::IsFade())
		{
			m_GamePhase = PHASE_GAME;
		}
		break;
	case PHASE_GAME:
		Camera_Update();
		m_Character.Update();
		m_Camera.Update();
		if (EndCheck())
		{
			Fade::Start(true, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
			m_GamePhase = PHASE_CLEARCHECK;
		}
	case PHASE_CLEARCHECK:
		if (!Fade::IsFade())
		{
			SceneManager::ChangeSceneState();
		}
		break;
	}
	if (KeyBoard::IsTrigger(DIK_W))
	{
		SceneManager::ChangeSceneState();
	}
}

//	�Q�[���̕`�揈��
void SceneGame::Draw()
{
	Camera_SetCamera();
	m_Character.Draw();
	m_Map.Draw();
	//Camera.Set();
	DebugProc_Draw();
	
}

Character * SceneGame::SetCharacter()
{
	return &m_Character;
}

Field * SceneGame::SetField()
{
	return &m_Map;
}
