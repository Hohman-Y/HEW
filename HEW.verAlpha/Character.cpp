/*============================================

	[Character.cpp]
	Author :�@�o���đ�

=============================================*/

#include "main.h"
#include "Model.h"
#include "Drawer.h"
#include "Character.h"

//	�t���[�o���ϐ�
LPDIRECT3DDEVICE9 Character::g_pD3DDevice;	//	�f�o�C�X


void Character::Init()
{
	//	�f�o�C�X�̎擾
	g_pD3DDevice = GetD3DDevice();

}

void Character::Uninit()
{
	DEVICE_RELEASE(g_pD3DDevice);
}

void Character::Update()
{
}

void Character::Draw()
{

}

