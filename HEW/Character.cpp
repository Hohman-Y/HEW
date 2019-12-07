/*=================================================

	[Character.cpp]
	Author : �o���đ�

=================================================*/

#include "Controller.h"
#include "Character.h"
#include "CharacterCamera.h"

//	�}�N����`
#define	VALUE_MOVE_MODEL	(0.5f)					// �ړ����x
#define	RATE_MOVE_MODEL		(0.2f)					// �ړ������W��
#define	VALUE_ROTATE_MODEL	(D3DX_PI * 0.05f)		// ��]���x
#define	RATE_ROTATE_MODEL	(0.2f)					// ��]�����W��


// �X�^�e�B�b�N�ϐ�
LPDIRECT3DTEXTURE9	Character::m_pTexture = NULL;	//	�e�N�X�`���ւ̃|�C���^
LPD3DXMESH			Character::m_pMesh	= NULL;		//	���b�V�����ւ̃|�C���^
LPD3DXBUFFER		Character::m_pBuffMat = NULL;		// �}�e���A�����ւ̃|�C���^
DWORD				Character::m_nNumMat;	//	�}�e���A�����̑���
D3DXMATRIX			Character::m_mtxWorld;	//	���[���h�}�g���b�N�X

//	����������
HRESULT Character::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	m_pDevice = GetD3DDevice();
	
	//X�t�@�C���̓ǂݍ���
	if (FAILED(D3DXLoadMeshFromX("asset/model/ri.x", D3DXMESH_SYSTEMMEM, m_pDevice, NULL, &m_pBuffMat, NULL, &m_nNumMat, &m_pMesh)))
	{
		return E_FAIL;
	}

	m_gravity = 0.9f;	//	�d��	

	m_position = pos;	//	�ʒu
	m_rotation = rot;	//	����
	m_rotDest = rot;	//	�ړI�̌���
	m_velocity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�ړ�
	
	return S_OK;
}

//	�I������
void Character::Uninit()
{
	SAFE_RELEASE(m_pBuffMat);
	SAFE_RELEASE(m_pMesh);
	SAFE_RELEASE(m_pTexture);
}

//	�X�V����
void Character::Update()
{
	m_velocity.y += m_gravity;	//	�d�͂̒l�����Z���
	CharacterCamera *pCamera;
	float fDiffRotY;

	// �J�����̎擾
	pCamera = GetCharCam();

	if (KeyBoard::IsPress(DIK_A) || GamePad::IsPress(0, LEFTSTICK_LEFT))
	{
		if (KeyBoard::IsPress(DIK_W) || GamePad::IsPress(0, LEFTSTICK_UP))
		{// �����ړ�
			m_velocity.x += sinf(-D3DX_PI * 0.75f - pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(-D3DX_PI * 0.75f - pCamera->rot.y) * VALUE_MOVE_MODEL;

			m_rotDest.y = pCamera->rot.y + D3DX_PI * 0.75f;
		}
		else if (KeyBoard::IsPress(DIK_S) || GamePad::IsPress(0, LEFTSTICK_DOWN))
		{// ����O�ړ�
			m_velocity.x += sinf(-D3DX_PI * 0.25f - pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(-D3DX_PI * 0.25f - pCamera->rot.y) * VALUE_MOVE_MODEL;

			m_rotDest.y = pCamera->rot.y + D3DX_PI * 0.25f;
		}
		else
		{// ���ړ�
			m_velocity.x += sinf(-D3DX_PI * 0.50f - pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(-D3DX_PI * 0.50f - pCamera->rot.y) * VALUE_MOVE_MODEL;

			m_rotDest.y = pCamera->rot.y + D3DX_PI * 0.50f;
		}
	}
	else if (KeyBoard::IsPress(DIK_D) || GamePad::IsPress(0, LEFTSTICK_RIGHT))
	{
		if (KeyBoard::IsPress(DIK_W) || GamePad::IsPress(0, LEFTSTICK_UP))
		{// �E���ړ�
			m_velocity.x += sinf(D3DX_PI * 0.75f - pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(D3DX_PI * 0.75f - pCamera->rot.y) * VALUE_MOVE_MODEL;

			m_rotDest.y = pCamera->rot.y - D3DX_PI * 0.75f;
		}
		else if (KeyBoard::IsPress(DIK_S) || GamePad::IsPress(0, LEFTSTICK_DOWN))
		{// �E��O�ړ�
			m_velocity.x += sinf(D3DX_PI * 0.25f - pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(D3DX_PI * 0.25f - pCamera->rot.y) * VALUE_MOVE_MODEL;

			m_rotDest.y = pCamera->rot.y - D3DX_PI * 0.25f;
		}
		else
		{// �E�ړ�
			m_velocity.x += sinf(D3DX_PI * 0.50f - pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(D3DX_PI * 0.50f - pCamera->rot.y) * VALUE_MOVE_MODEL;

			m_rotDest.y = pCamera->rot.y - D3DX_PI * 0.50f;
		}
	}
	else if (KeyBoard::IsPress(DIK_W) || GamePad::IsPress(0, LEFTSTICK_UP))
	{// �O�ړ�
		m_velocity.x += sinf(D3DX_PI * 1.0f - pCamera->rot.y) * VALUE_MOVE_MODEL;
		m_velocity.z -= cosf(D3DX_PI * 1.0f - pCamera->rot.y) * VALUE_MOVE_MODEL;

		m_rotDest.y = pCamera->rot.y + D3DX_PI * 1.0f;
	}
	else if (KeyBoard::IsPress(DIK_S) || GamePad::IsPress(0, LEFTSTICK_DOWN))
	{// ��ړ�
		m_velocity.x += sinf(D3DX_PI * 0.0f - pCamera->rot.y) * VALUE_MOVE_MODEL;
		m_velocity.z -= cosf(D3DX_PI * 0.0f - pCamera->rot.y) * VALUE_MOVE_MODEL;

		m_rotDest.y = pCamera->rot.y + D3DX_PI * 0.0f;
	}

	if (KeyBoard::IsPress(DIK_Q) || GamePad::IsPress(0, PS4RIGHTSTICK_LEFT))
	{// ����]
		m_rotDest.y -= VALUE_ROTATE_MODEL;
		if (m_rotDest.y < -D3DX_PI)
		{
			m_rotDest.y += D3DX_PI * 2.0f;
		}
	}
	if (KeyBoard::IsPress(DIK_E) || GamePad::IsPress(0, PS4RIGHTSTICK_RIGHT))
	{// �E��]
		m_rotDest.y += VALUE_ROTATE_MODEL;
		if (m_rotDest.y > D3DX_PI)
		{
			m_rotDest.y -= D3DX_PI * 2.0f;
		}
	}

	// �ړI�̊p�x�܂ł̍���
	fDiffRotY = m_rotDest.y - m_rotation.y;
	if (fDiffRotY > D3DX_PI)
	{
		fDiffRotY -= D3DX_PI * 2.0f;
	}
	if (fDiffRotY < -D3DX_PI)
	{
		fDiffRotY += D3DX_PI * 2.0f;
	}

	// �ړI�̊p�x�܂Ŋ�����������
	m_rotation.y += fDiffRotY * RATE_ROTATE_MODEL;
	if (m_rotation.y > D3DX_PI)
	{
		m_rotation.y -= D3DX_PI * 2.0f;
	}
	if (m_rotation.y < -D3DX_PI)
	{
		m_rotation.y += D3DX_PI * 2.0f;
	}

	/// �ʒu�ړ�
	m_position.x += m_velocity.x;
	m_position.z += m_velocity.z;

	// �ړ��ʂɊ�����������
	m_velocity.x += (0.0f - m_velocity.x) * RATE_MOVE_MODEL;
	m_velocity.z += (0.0f - m_velocity.z) * RATE_MOVE_MODEL;
	//	�X�e�[�g
	switch (m_state)
	{
	case PLAYER_INIT:
		break;
	case PLAYER_STRAT:
		break;
	case PlAYER_ANSWERSTAY:
		break;
	case PLAYER_ANSWER: 
		break;
	case PLAYER_JUMP:
		break;
	case PLAYER_END:
		break;
	}
}

//	�`�揈��
void Character::Draw()
{
	m_pDevice = GetD3DDevice();
	D3DXMATRIX mtxRot, mtxTranslate;
	D3DXMATERIAL *pD3DXMat;
	D3DMATERIAL9 matDef;

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//��]�𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rotation.y, m_rotation.x, m_rotation.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//�ړ��𔽉f
	D3DXMatrixTranslation(&mtxTranslate, m_position.x, m_velocity.y, m_position.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTranslate);

	//���[���h�}�g���b�N�X�̐ݒ�
	m_pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���݂̃}�e���A�����擾
	m_pDevice->GetMaterial(&matDef);

	//�}�e���A�����ɑ΂���|�C���^���擾
	pD3DXMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_nNumMat; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		m_pDevice->SetMaterial(&pD3DXMat[nCntMat].MatD3D);
		//�e�N�X�`���̐ݒ�
		m_pDevice->SetTexture(0, m_pTexture);
		//�`��
		m_pMesh->DrawSubset(nCntMat);

	}
	//�}�e���A�����f�t�H���g�ɖ߂�
	m_pDevice->SetMaterial(&matDef);
}

//!	�Q�b�^�[
//	�ʒu�̃Q�b�^�[
D3DXVECTOR3 Character::GetPos()
{
	return m_position;
}

//	��]�̃Q�b�^�[
D3DXVECTOR3 Character::GetRot()
{
	return m_rotation;
}

//	�ړ��̃Q�b�^�[
D3DXVECTOR3 Character::GetMove()
{
	return m_velocity;
}

//	�}�g���N�X�̃Q�b�^�[
D3DXMATRIX Character::GetMat()
{
	return m_mtxWorld;
}

//	���b�V���̃Q�b�^�[
LPD3DXMESH Character::GetMesh()
{
	return  m_pMesh;
}

//!	�X�e�[�g�p�֐�
//	�X�^�[�g��
void Character::Strat()
{
}

//	�𓚂܂�
void Character::Answerstay()
{
}

//	��
void Character::Answer()
{
}

//	�W�����v
void Character::Jump()
{
}

//	�X�e�[�g�I��
void Character::End()
{
}
