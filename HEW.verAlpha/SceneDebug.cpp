/*================================================

	[Scenedebug.cpp]
	Author : �o���đ�

=================================================*/

#include "SceneDebug.h"
#include "SceneManager.h"
#include "input.h"
#include "XFile.h"
#include "Model.h"
#include "main.h"
#include "DebugCamera.h"
#include "light.h"
#include "Field.h"
#include "debugproc.h"

//# �f�o�b�O�V�[���̏����� 
void SceneDebug::Init()
{
	DebugCamera::Init();
	Light::Init();
	Field::Init();
	DebugProc_Initialize();
}

//# �f�o�b�O�V�[���̏I������
void SceneDebug::Uninit()
{
	Field::Uninit();
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
	Field::ActorDraw();
	Field::PlaneDraw();
	DebugCamera::Set();
}
