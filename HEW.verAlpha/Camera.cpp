/*==============================================

	[camera.cpp]										
	Author : �o���đ�									

===============================================*/
#include "main.h"
#include "Camera.h"

//#	�O���[�o���ϐ�
D3DXVECTOR3			Camera::posV;			// ���_�i�J�����̈ʒu�j
D3DXVECTOR3			Camera::posR;			// �����_�i�J�����͂ǂ������Ă���̂��j
D3DXVECTOR3			Camera::vecU;			// ������x�N�g���i�J�����̏�����͂����v���X�j���W�́i�O�C�P�C�O�j
D3DXMATRIX			Camera::mtxProjection;	// �v���W�F�N�V�����}�g���b�N�X
D3DXMATRIX			Camera::mtxView;		// �r���[�}�g���b�N�X
LPDIRECT3DDEVICE9	Camera::pDevice;		//�@�f�o�C�X�̎擾�p�ϐ�

//#	�J�����̏�����
void Camera::Init()
{
	posV = D3DXVECTOR3(CAM_POS_V_X, CAM_POS_V_Y, CAM_POS_V_Z);	//�J�����ʒu
	posR = D3DXVECTOR3(CAM_POS_R_X, CAM_POS_R_X, CAM_POS_R_X);	//�����_
	vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);							//�J�����̏�x�N�g��
}

//#	�J�����̏I������
void Camera::Uninit()
{
	
}

//#	�J�����̐ݒ�
void Camera::Set()
{
	//�f�o�C�X�̎擾
	pDevice = GetD3DDevice();

	// �v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&mtxProjection);

	// �v���W�F�N�V�����}�g���b�N�X�̍쐬
	D3DXMatrixPerspectiveFovLH(&mtxProjection,
		VIEW_ANGLE,				// �r���[���ʂ̎���p
		VIEW_ASPECT,			// �r���[���ʂ̃A�X�y�N�g��
		VIEW_NEAR_Z,			// �r���[���ʂ�NearZ�l
		VIEW_FAR_Z);			// �r���[���ʂ�FarZ�l

	// �v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &mtxProjection);

	// �r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&mtxView);	//	�P�ʍs��:�s��̏���������Ƃ��Ɏg��

	// �r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&mtxView,
		&posV,		// �J�����̎��_
		&posR,		// �J�����̒����_
		&vecU);	// �J�����̏�����x�N�g��

	// �r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &mtxView);
}
