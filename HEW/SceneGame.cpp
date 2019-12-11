/*==================================

	[SceneGame.cpp]
	Author : �o���đ�

===================================*/

#include "SceneGame.h"
#include "SceneManager.h"
#include "Controller.h"
#include "Character.h"
#include "main.h"
#include "light.h"
#include "debugproc.h"


//	�Q�[���̏���������
void SceneGame::Init()
{
	
	m_Character.Init(D3DXVECTOR3(0.0f, 150.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_Map.Init();
	Light::Init();
	m_Camera.Init();
	DebugProc_Initialize();
	
}

//	�Q�[���̏I������
void SceneGame::Uninit()
{
	m_Character.Uninit();
	m_Map.Uninit();
	m_Camera.Uninit();
	DebugProc_Finalize();
}

//	�Q�[���̍X�V����
void SceneGame::Update()
{

	m_Character.Update();
	m_Camera.Update();
	//if (KeyBoard::IsTrigger(DIK_W))
	{
		//SceneManager::ChangeSceneState();
	}

}

//	�Q�[���̕`�揈��
void SceneGame::Draw()
{
	//	���C���[�t���[�����Z�b�g
	//pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	m_Character.Draw();
	m_Map.Draw();
	m_Camera.Set();
	DebugProc_Draw();
}
