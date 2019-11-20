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
	DebugCamera::Init();
	Light::Init();
	Map::Init();
	DebugProc_Initialize();
}

//# �f�o�b�O�V�[���̏I������
void SceneDebug::Uninit()
{
	Map::Uninit();
	Light::Uninit();
	DebugCamera::Uninit();
	DebugProc_Finalize();
}

//# �f�o�b�O�V�[���̍X�V����
void SceneDebug::Update()
{
	DebugCamera::Update();
}

//# �f�o�b�O�V�[���̕`�揈��
void SceneDebug::Draw()
{
	DebugProc_Draw();
	Map::Draw();
	DebugCamera::Set();
}
