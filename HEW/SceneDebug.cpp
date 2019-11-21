/*================================================

	[Scenedebug.cpp]
	Author : �o���đ�

=================================================*/

#include "SceneDebug.h"
#include "SceneManager.h"
#include "main.h"
#include "DebugCamera.h"
#include "light.h"
#include "debugproc.h"
#include "Map.h"

//# �f�o�b�O�V�[���̏����� 
void SceneDebug::Init()
{
	m_Camera.Init();
	Light::Init();
	m_Map.Init();
	DebugProc_Initialize();
}

//# �f�o�b�O�V�[���̏I������
void SceneDebug::Uninit()
{
	m_Map.Uninit();
	Light::Uninit();
	m_Camera.Uninit();
	DebugProc_Finalize();
}

//# �f�o�b�O�V�[���̍X�V����
void SceneDebug::Update()
{
	m_Camera.Update();
}

//# �f�o�b�O�V�[���̕`�揈��
void SceneDebug::Draw()
{
	DebugProc_Draw();
	m_Map.Draw();
	m_Camera.Set();
}
