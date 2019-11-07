/*==========================================================

	[Model.cpp]
	Author : �o���đ�

===========================================================*/


#include <map>
#include "main.h"
#include "Model.h"

//	�O���[�o���ϐ�
LPDIRECT3DDEVICE9 Model::g_pD3DDevice;

//	�A�����[�h����
void Model::Unload()
{
	DEVICE_RELEASE(g_pD3DDevice);	//	�f�o�C�X�̉��
}

//	���f���̕`�揈��
void Model::Draw()
{
	g_pD3DDevice = GetD3DDevice();
	// ���[���h���W�s��쐬
	D3DXMATRIX world_matrix, trans_matrix, rot_matrix, scale_matrix;
	D3DXMatrixIdentity(&world_matrix);
	D3DXMatrixTranslation(&trans_matrix, position.x, position.y, position.z);
	D3DXMatrixScaling(&scale_matrix, scale.x, scale.y, scale.y);
	world_matrix *= scale_matrix * trans_matrix;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &world_matrix);

	if (pmodel != NULL)
	{
		pmodel->Draw();
	}
}