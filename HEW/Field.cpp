/*============================================

	[Field.cpp]
	Author :�@�o���đ�

============================================*/

#include "Field.h"

//	�X�^�e�B�b�N�ϐ�
LPDIRECT3DTEXTURE9	Field::m_pTextureModel = NULL;		// �e�N�X�`���ւ̃|�C���^
LPD3DXMESH			Field::m_pMeshModel = NULL;			// ���b�V�����ւ̃|�C���^
LPD3DXBUFFER		Field::m_pBuffMatModel = NULL;		// �}�e���A�����ւ̃|�C���^
DWORD				Field::m_nNumMatModel;				// �}�e���A�����̑���
LPDIRECT3DDEVICE9	Field::m_pDevice;

HRESULT Field::Init(D3DXVECTOR3 Pos, D3DXVECTOR3 Scale, D3DXVECTOR3 Angle)
{
	m_pDevice = GetD3DDevice();

	/// <summary>
	/// X�t�@�C���̓ǂݍ���
	/// <summary>
	if (FAILED(D3DXLoadMeshFromX("asset/model/dai.x",D3DXMESH_SYSTEMMEM,m_pDevice,NULL,&m_pBuffMatModel,NULL,&m_nNumMatModel,&m_pMeshModel)))
	{
		return E_FAIL;
	}
	
	/// <summary> �ϐ��̏����� </summary>
	m_position = Pos;
	m_scale = Scale;
	m_angle = Angle;

	return S_OK;
}

void Field::Uninit()
{

}

void Field::Draw()
{
	m_pDevice = GetD3DDevice();

	D3DXMATRIX trans_matrix, rot_matrix, scale_matrix;
	D3DXMATERIAL *pD3DXMat;
	D3DMATERIAL9 matDef;
	
	D3DXMatrixIdentity(&m_mtxWorldModel);
	D3DXMatrixTranslation(&trans_matrix, m_position.x, m_position.y, m_position.z);
	D3DXMatrixScaling(&scale_matrix, m_scale.x, m_scale.y, m_scale.y);
	m_mtxWorldModel *= scale_matrix * trans_matrix;
	m_pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorldModel);

	//���݂̃}�e���A�����擾
	m_pDevice->GetMaterial(&matDef);

	//�}�e���A�����ɑ΂���|�C���^���擾
	pD3DXMat = (D3DXMATERIAL*)m_pBuffMatModel->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_nNumMatModel; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		m_pDevice->SetMaterial(&pD3DXMat[nCntMat].MatD3D);
		//�e�N�X�`���̐ݒ�
		m_pDevice->SetTexture(0, m_pTextureModel);
		//�`��
		m_pMeshModel->DrawSubset(nCntMat);

	}
	//�}�e���A�����f�t�H���g�ɖ߂�
	m_pDevice->SetMaterial(&matDef);
}

