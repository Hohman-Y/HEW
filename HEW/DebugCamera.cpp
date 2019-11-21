/*======================================================

	[debugCamera.cpp]
	Author : �o���đ�

======================================================*/

#include "main.h"
#include "input.h"
#include "debugproc.h"
#include "DebugCamera.h"
#include "Camera.h"

//�@�}�N����`
#define	CAM_POS_V_X		(0.0f)											// �J�����̎��_�����ʒu(X���W)
#define	CAM_POS_V_Y		(100.0f)										// �J�����̎��_�����ʒu(Y���W)
#define	CAM_POS_V_Z		(200.0f)										// �J�����̎��_�����ʒu(Z���W)
#define	CAM_POS_R_X		(0.0f)											// �J�����̒����_�����ʒu(X���W)
#define	CAM_POS_R_Y		(0.0f)											// �J�����̒����_�����ʒu(Y���W)
#define	CAM_POS_R_Z		(0.0f)											// �J�����̒����_�����ʒu(Z���W)
#define	VIEW_ANGLE		(D3DXToRadian(70.0f))							// �r���[���ʂ̎���p
#define	VIEW_ASPECT		((float)SCREEN_WIDTH / (float)SCREEN_HEIGHT)	// �r���[���ʂ̃A�X�y�N�g��
#define	VIEW_NEAR_Z		(10.0f)											// �r���[���ʂ�NearZ�l	�l���߂��ƕ`�悵�Ȃ�
#define	VIEW_FAR_Z		(10000.0f)										// �r���[���ʂ�FarZ�l	�l��艓���ƕ`�悵�Ȃ�
#define MOVE_CAMERA		(1.0f)
#define ROTATE_CAMERA	(D3DX_PI * 0.01f)
#define CAMERADISTANCE	(1.0f)

D3DXVECTOR3			DebugCamera::move;
D3DXVECTOR3			DebugCamera::rot;
float				DebugCamera::fDistance;

//#	�J�����̏�����
void DebugCamera::Init()
{
	Camera::Init();
	rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);						
	move = D3DXVECTOR3(5.0f, 5.0f, 5.0f);

	float x, z;
	x = posV.x - posR.x;
	z = posV.z - posR.z;
	fDistance = sqrtf(x * x + z * z);
}

//#	�J�����̏I������
void DebugCamera::Uninit()
{

}

//# �J�����̍X�V����
void DebugCamera::Update()
{
	if (Input::KB_IsPress(DIK_S))
	{
		posV.z += move.z;
		posR.z += move.z;
	}

	if (Input::KB_IsPress(DIK_W))
	{
		posR.z -= move.z;
		posV.z -= move.z;
	}

	if (Input::KB_IsPress(DIK_A))
	{
		posV.x += move.x;
		posR.x += move.x;
	}

	if (Input::KB_IsPress(DIK_D))
	{
		posV.x -= move.x;
		posR.x -= move.x;
	}
	if (Input::KB_IsPress(DIK_Z))
	{
		rot.y += ROTATE_CAMERA;
		if (rot.y > D3DX_PI)
		{
			rot.y -= D3DX_PI * 2.0f;
		}
		posR.x = posV.x - sinf(rot.y) * fDistance;
		posR.z = posV.z - cosf(rot.y) * fDistance;
	}

	if (Input::KB_IsPress(DIK_C))
	{
		rot.y -= ROTATE_CAMERA;
		if (rot.y < D3DX_PI)
		{
			rot.y += D3DX_PI * 2.0f;
		}
		posR.x = posV.x - sinf(rot.y) * fDistance;
		posR.z = posV.z - cosf(rot.y) * fDistance;
	}

	if (Input::KB_IsPress(DIK_Y))
	{
		posV.y += MOVE_CAMERA;
	}
	
	if (Input::KB_IsPress(DIK_N))
	{
		posV.y -= MOVE_CAMERA;
	}

	if (Input::KB_IsPress(DIK_E))
	{
		rot.y += ROTATE_CAMERA;
		if (rot.y > D3DX_PI)
		{
			rot.y -= D3DX_PI * 2.0f;
		}
		posR.x = posV.x - sinf(rot.y) * fDistance;
		posR.z = posV.z - cosf(rot.y) * fDistance;
	}
	
	if (Input::KB_IsPress(DIK_Q))
	{
		rot.y -= ROTATE_CAMERA;
		if (rot.y < D3DX_PI)
		{
			rot.y += D3DX_PI * 2.0f;
		}
		posR.x = posV.x + sinf(rot.y) * fDistance;
		posR.z = posV.z + cosf(rot.y) * fDistance;
	}

	if (Input::KB_IsPress(DIK_T))
	{
		posR.y += MOVE_CAMERA;
	}
	
	if (Input::KB_IsPress(DIK_B))
	{
		posR.y -= MOVE_CAMERA;
	}


	if (Input::KB_IsPress(DIK_U))
	{
		fDistance -= CAMERADISTANCE;
		if (fDistance < 100.0f)
		{
			fDistance = 100.0f;
		}
		posV.x = posR.x + sinf(rot.y) * fDistance;
		posV.z = posR.z + cosf(rot.y) * fDistance;
	}

	if (Input::KB_IsPress(DIK_M))
	{
		fDistance += CAMERADISTANCE;
		if (fDistance > 1000.0f)
		{
			fDistance = 1000.0f;
		}
		posV.x = posR.x + sinf(rot.y) * fDistance;
		posV.z = posR.z + cosf(rot.y) * fDistance;
	}

	if (Input::KB_IsPress(DIK_SPACE))
	{
		posV = D3DXVECTOR3(CAM_POS_V_X, CAM_POS_V_Y, CAM_POS_V_Z);	//	�J�����ʒu
		posR = D3DXVECTOR3(CAM_POS_R_X, CAM_POS_R_X, CAM_POS_R_X);	//	�����_
		vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);						//	�J�����̏�x�N�g��

		float x, z;
		x = posV.x - posR.x;
		z = posV.z - posR.z;
		fDistance = sqrtf(x * x + z * z);
	}

	DebugProc_Print((char*)"�J�����̎��_ [%f : %f : %f]\n", posV.x, posV.y, posV.z);
	DebugProc_Print((char*)"�J�����̒����_ [%f : %f : %f]\n", posR.x, posR.y, posR.z);
	DebugProc_Print((char*)"�J�����̌��� [%f]\n", rot.y);
	DebugProc_Print((char*)"�J�����̋���[%f]\n", fDistance);
	DebugProc_Print((char*)"\n");
}

//#	�J�����̐ݒ�
void DebugCamera::Set()
{
	Camera::Set();
}
