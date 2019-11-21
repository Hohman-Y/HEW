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
#include "mondai.h"

SceneDebug::SceneDebug()
{
	m_pDebugCamera = new DebugCamera;
}

SceneDebug::~SceneDebug()
{
	delete m_pDebugCamera;
}

//# �f�o�b�O�V�[���̏����� 
void SceneDebug::Init()
{
	m_pDebugCamera->Init();
	Light::Init();
	Map::Init();
	DebugProc_Initialize();
	//Mondai::Init();
}

//# �f�o�b�O�V�[���̏I������
void SceneDebug::Uninit()
{
	m_pDebugCamera->Uninit();
	Map::Uninit();
	Light::Uninit();
	DebugProc_Finalize();
	//Mondai::Uninit();
}

//# �f�o�b�O�V�[���̍X�V����
void SceneDebug::Update()
{
	m_pDebugCamera->Update();
	//Mondai::Update();
}

//# �f�o�b�O�V�[���̕`�揈��
void SceneDebug::Draw()
{
	m_pDebugCamera->Set();
	DebugProc_Draw();
	Map::Draw();

	//Mondai::Draw();
}
