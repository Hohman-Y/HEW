/*======================================================

	[debugCamera.cpp]
	Author : �o���đ�

======================================================*/

#include "DebugCamera.h"

#include "main.h"
#include "Camera.h"
#include "input.h"
#include "debugproc.h"

//#	�O���[�o���ϐ�
DebugCamera *g_camera = new DebugCamera;	//�C���X�^���X�̐���

//#	�J�����̏�����
void DebugCamera::Init()
{
	g_camera->posV = D3DXVECTOR3(CAM_POS_V_X, CAM_POS_V_Y, CAM_POS_V_Z);	//�J�����ʒu
	g_camera->posR = D3DXVECTOR3(CAM_POS_R_X, CAM_POS_R_X, CAM_POS_R_X);	//�����_
	g_camera->vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);							//�J�����̏�x�N�g��
	g_camera->move = D3DXVECTOR3(5.0f, 5.0f, 5.0f);
}

//#	�J�����̏I������
void DebugCamera::Uninit()
{
	delete g_camera;
}

void DebugCamera::Update()
{
	if(Input::KB_IsPress(DIK_W))
	{
		g_camera->posV.z += g_camera->move.z;
		g_camera->posR.z += g_camera->move.z;
	}

	if (Input::KB_IsPress(DIK_S))
	{
		g_camera->posR.z -= g_camera->move.z;
		g_camera->posV.z -= g_camera->move.z;
	}

	if (Input::KB_IsPress(DIK_D))
	{
		g_camera->posV.x += g_camera->move.x;
		g_camera->posR.x += g_camera->move.x;
	}

	if (Input::KB_IsPress(DIK_A))
	{
		g_camera->posV.x -= g_camera->move.x;
		g_camera->posR.x -= g_camera->move.x;
	}
	
	if (Input::KB_IsPress(DIK_SPACE))
	{
		g_camera->posV.y += g_camera->move.y;
		g_camera->posR.y += g_camera->move.y;
	}

	if (Input::KB_IsPress(DIK_LSHIFT))
	{
		g_camera->posV.y -= g_camera->move.y;
		g_camera->posR.y -= g_camera->move.y;
	}
	
	if (Input::KB_IsPress(DIK_E))
	{
		g_camera->posR.x += g_camera->move.x;
	}
	
	if (Input::KB_IsPress(DIK_Q))
	{
		g_camera->posR.x -= g_camera->move.x;
	}

	if (Input::KB_IsPress(DIK_R))
	{
		g_camera->posR.y += g_camera->move.y;
	}

	if (Input::KB_IsPress(DIK_F))
	{
		g_camera->posR.y -= g_camera->move.y;
	}

	if (Input::KB_IsTrigger(DIK_Z))
	{
		g_camera->Init();
	}
	DebugProc_Print((char*)"*** �R�c�|���S������ ***\n");
	DebugProc_Print((char*)"�ʒu [%f : %f : %f]\n", g_camera->posV.x, g_camera->posV.y, g_camera->posV.z);
	DebugProc_Print((char*)"�O�ړ� : �v\n");
	DebugProc_Print((char*)"��ړ� : �r\n");
	DebugProc_Print((char*)"���ړ� : �`\n");
	DebugProc_Print((char*)"�E�ړ� : �c\n");
	DebugProc_Print((char*)"��ړ� : SPACE\n");
	DebugProc_Print((char*)"���ړ� : LSHIFT\n");
	DebugProc_Print((char*)"\n");

	DebugProc_Print((char*)"���� [%f : %f : %f]\n", g_camera->posR.x, g_camera->posR.y, g_camera->posR.z);
	DebugProc_Print((char*)"X����] : Q / E\n");
	DebugProc_Print((char*)"Y����] : R / F\n");
	DebugProc_Print((char*)"\n");

	DebugProc_Print((char*)"�ʒu�E�������Z�b�g : Z\n");
}

//#	�J�����̐ݒ�
void DebugCamera::Set()
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
