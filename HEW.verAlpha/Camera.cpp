/*==============================================

	[camera.cpp]										//#	DirectX�͍�����W�n
	Author : �o���đ�									//#	OpenGL�͉E����W�n

===============================================*/
#include "main.h"
#include "Camera.h"

//#	�O���[�o���ϐ�
Camera *g_camera = new Camera;	//�C���X�^���X�̐���

//#	�J�����̏�����
void Camera::Init()
{
	g_camera->posV = D3DXVECTOR3(CAM_POS_V_X, CAM_POS_V_Y, CAM_POS_V_Z);	//�J�����ʒu
	g_camera->posR = D3DXVECTOR3(CAM_POS_R_X, CAM_POS_R_X, CAM_POS_R_X);	//�����_
	g_camera->vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);						//�J�����̏�x�N�g��
}

//#	�J�����̏I������
void Camera::Uninit()
{
	delete g_camera;
}

//#	�J�����̐ݒ�
void Camera::Set()
{
	//�f�o�C�X�̎擾
	g_camera->pDevice = GetD3DDevice();

	// �v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_camera->mtxProjection);

	// �v���W�F�N�V�����}�g���b�N�X�̍쐬
	D3DXMatrixPerspectiveFovLH(&g_camera->mtxProjection,
		VIEW_ANGLE,				// �r���[���ʂ̎���p
		VIEW_ASPECT,			// �r���[���ʂ̃A�X�y�N�g��
		VIEW_NEAR_Z,			// �r���[���ʂ�NearZ�l
		VIEW_FAR_Z);			// �r���[���ʂ�FarZ�l

	// �v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	g_camera->pDevice->SetTransform(D3DTS_PROJECTION, &g_camera->mtxProjection);

	// �r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_camera->mtxView);	//	�P�ʍs��:�s��̏���������Ƃ��Ɏg��

	// �r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&g_camera->mtxView,
		&g_camera->posV,		// �J�����̎��_
		&g_camera->posR,		// �J�����̒����_
		&g_camera->vecU);	// �J�����̏�����x�N�g��

	// �r���[�}�g���b�N�X�̐ݒ�
	g_camera->pDevice->SetTransform(D3DTS_VIEW, &g_camera->mtxView);
}
