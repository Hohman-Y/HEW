/*==============================================

	[camera.cpp]										
	Author : �o���đ�									

===============================================*/
#include "main.h"
#include "Camera.h"

//�@�}�N����`
#define	CAM_POS_V_X		(0.0f)											// �J�����̎��_�����ʒu(X���W)
#define	CAM_POS_V_Y		(100.0f)										// �J�����̎��_�����ʒu(Y���W)
#define	CAM_POS_V_Z		(200.0f)										// �J�����̎��_�����ʒu(Z���W)
#define	CAM_POS_R_X		(0.0f)											// �J�����̒����_�����ʒu(X���W)
#define	CAM_POS_R_Y		(0.0f)											// �J�����̒����_�����ʒu(Y���W)
#define	CAM_POS_R_Z		(0.0f)											// �J�����̒����_�����ʒu(Z���W)
#define	VIEW_ANGLE		(D3DXToRadian(45.0f))							// �r���[���ʂ̎���p
#define	VIEW_ASPECT		((float)SCREEN_WIDTH / (float)SCREEN_HEIGHT)	// �r���[���ʂ̃A�X�y�N�g��
#define	VIEW_NEAR_Z		(10.0f)											// �r���[���ʂ�NearZ�l	�l���߂��ƕ`�悵�Ȃ�
#define	VIEW_FAR_Z		(10000.0f)										// �r���[���ʂ�FarZ�l	�l��艓���ƕ`�悵�Ȃ�

//#	�J�����̏�����
void Camera::Init()
{
	posV = D3DXVECTOR3(CAM_POS_V_X, CAM_POS_V_Y, CAM_POS_V_Z);	//�J�����ʒu
	posR = D3DXVECTOR3(CAM_POS_R_X, CAM_POS_R_X, CAM_POS_R_X);	//�����_
	vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);						//�J�����̏�x�N�g��
}

//#	�J�����̏I������
void Camera::Uninit()
{
	
}

void Camera::Update()
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