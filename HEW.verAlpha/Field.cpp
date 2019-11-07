/*==========================================================

	[Field.cpp]
	Author : �o���đ�

===========================================================*/

#include <map>
#include "main.h"
#include "Field.h"
#include "Model.h"
#include "XFile.h"

//	�}�N����`
#define FILELIST 1	//	�ǂݍ��ރt�@�C���̐�

//	�O���[�o���ϐ�
Model *Field::Object[OBJECT_NUM];
extern std::map<std::string, XFile *>g_pXFileList;

//	�}�b�v�̏�����
void  Field::Init()
{
	//!	XFlie�̃��[�h����
	// �ǂݍ��݃t�@�C�������X�g
	std::string file_name_list[] =
	{
		"asset/model/ri.x",
	};

	// XFile�ǂݍ���
	for (int i = 0; i < FILELIST; i++)
	{
		g_pXFileList[file_name_list[i]] = new XFile();
		g_pXFileList[file_name_list[i]]->Load(file_name_list[i]);
	}
}

void Field::Uninit()
{
	delete Object[0];
}

//	�}�b�v�̕`��
void Field::Draw()
{
#if 0
	g_field->pDevice = GetD3DDevice();

	D3DXMATRIX mtxScl, mtxRot, mtxTranslate;
	//	���[���h�ϊ��i���[���h�}�g���N�X�̏������j
	D3DXMatrixIdentity(&g_mtxWorldField);
	D3DXMatrixScaling(&mtxScl, g_sclField.x, g_sclField.y, g_sclField.z);
	D3DXMatrixMultiply(&g_mtxWorldField, &g_mtxWorldField, &mtxScl);	//�@������2�Ԗڂ�3�Ԗڂ̌v�Z���ʂ�1�Ԗڂɓ����
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotField.x, g_rotField.y, g_rotField.z);
	D3DXMatrixMultiply(&g_mtxWorldField, &g_mtxWorldField, &mtxRot);
	D3DXMatrixTranslation(&mtxTranslate, g_posField.y, g_posField.x, g_posField.z);
	D3DXMatrixMultiply(&g_mtxWorldField, &g_mtxWorldField, &mtxTranslate);
	// ���[���h�}�g���N�X�̐ݒ�
	g_field->pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldField);
#endif
	//	3D���f���̕`��
	Object[0] = new Model(
		D3DXVECTOR3(0.0f, 0.0f, -10.0f),
		D3DXVECTOR3(100.0f, 1.0f, 10.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		g_pXFileList["asset/model/ri.x"]);

	Object[0]->Draw();
#if 0
	//	���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���Ƀo�C���h
	g_field->pDevice->SetStreamSource(0, g_pVtxBuffField, 0, sizeof(VERTEX_3D));

	//	���_�t�H�[�}�b�g�̐ݒ�
	g_field->pDevice->SetFVF(FVF_VERTEX_3D);

	//	�����ō�������_�o�b�t�@��`��i�������̊m�ہA��������Ȃ���΂Ȃ�Ȃ����x���Ȃ�j
	g_field->pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
#endif
}

//	���_�쐬�֐�
#if 0 
HRESULT Field::MakeVertexField(LPDIRECT3DDEVICE9 pDevice)
{
	//�I�u�W�F�N�g�̒��_�o�b�t�@�𐶐�
	if (FAILED(pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 5, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffField, NULL)))
	{
		return E_FAIL;
	}

	{
		//���_�o�b�t�@�̒��g�𖄂߂�
		VERTEX_3D *pVtx;

		//���_�o�b�t�@�͈̔͂̃��b�N���A���_�o�b�t�@�ւ̃|�C���^�����炤
		g_pVtxBuffField->Lock(0, 0, (void**)&pVtx, 0);

		//# �V��|���S��
			//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-1000, -10, 1000);
		pVtx[1].pos = D3DXVECTOR3(1000, -10, 1000);
		pVtx[2].pos = D3DXVECTOR3(-1000, -10, -1000);
		pVtx[3].pos = D3DXVECTOR3(1000, -10, 1000);
		pVtx[4].pos = D3DXVECTOR3(1000, -10, -1000);
		pVtx[5].pos = D3DXVECTOR3(-1000, -10, -1000);

		//�@���x�N�g���̐ݒ�
		pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[4].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[5].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);


		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[4].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[5].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//���_�o�b�t�@���A�����b�N
		g_pVtxBuffField->Unlock();
	}

	return S_OK;
}
#endif

