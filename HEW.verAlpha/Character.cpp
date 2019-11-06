/*============================================

	[Character.cpp]
	Author :�@�o���đ�

=============================================*/

#include "main.h"
#include "Model.h"
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
	// ���[���h���W�s��
	D3DXMATRIX world_matrix, trans_matrix, rot_matrix, scale_matrix;
	D3DXMatrixIdentity(&world_matrix);
	D3DXMatrixTranslation(&trans_matrix, Position.x, Position.y, Position.z);
	world_matrix *= scale_matrix * trans_matrix;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &world_matrix);                   

	if (pModel != NULL)
	{
		pModel->Draw();
	}
}

