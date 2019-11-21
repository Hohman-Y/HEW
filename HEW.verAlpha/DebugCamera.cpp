/*======================================================

	[debugCamera.cpp]
	Author : �o���đ�

======================================================*/

#include "DebugCamera.h"

#include "main.h"
#include "input.h"
#include "debugproc.h"


//�@�}�N����`
#define	CAM_POS_V_X		(0.0f)											// �J�����̎��_�����ʒu(X���W)
#define	CAM_POS_V_Y		(100.0f)										// �J�����̎��_�����ʒu(Y���W)
#define	CAM_POS_V_Z		(-200.0f)										// �J�����̎��_�����ʒu(Z���W)
#define	CAM_POS_R_X		(0.0f)											// �J�����̒����_�����ʒu(X���W)
#define	CAM_POS_R_Y		(0.0f)											// �J�����̒����_�����ʒu(Y���W)
#define	CAM_POS_R_Z		(0.0f)											// �J�����̒����_�����ʒu(Z���W)
#define	VIEW_ANGLE		(D3DXToRadian(70.0f))							// �r���[���ʂ̎���p
#define	VIEW_ASPECT		((float)SCREEN_WIDTH / (float)SCREEN_HEIGHT)	// �r���[���ʂ̃A�X�y�N�g��
#define	VIEW_NEAR_Z		(10.0f)											// �r���[���ʂ�NearZ�l	�l���߂��ƕ`�悵�Ȃ�
#define	VIEW_FAR_Z		(10000.0f)										// �r���[���ʂ�FarZ�l	�l��艓���ƕ`�悵�Ȃ�


D3DXVECTOR3 DebugCamera::m_Velocity;

//#	�J�����̏�����
void DebugCamera::Init()
{
	Camera::Init();
	m_Velocity = D3DXVECTOR3(5.0f, 5.0f, 5.0f);
}

//#	�J�����̏I������
void DebugCamera::Uninit()
{

}

//# �J�����̍X�V����
void DebugCamera::Update()
{
	if(Input::KB_IsPress(DIK_W))
	{
		posV.z += m_Velocity.z;
		posR.z += m_Velocity.z;
	}

	if (Input::KB_IsPress(DIK_S))
	{
		posR.z -= m_Velocity.z;
		posV.z -= m_Velocity.z;
	}

	if (Input::KB_IsPress(DIK_D))
	{
		posV.x += m_Velocity.x;
		posR.x += m_Velocity.x;
	}

	if (Input::KB_IsPress(DIK_A))
	{
		posV.x -= m_Velocity.x;
		posR.x -= m_Velocity.x;
	}
	
	if (Input::KB_IsPress(DIK_SPACE))
	{
		posV.y += m_Velocity.y;
		posR.y += m_Velocity.y;
	}

	if (Input::KB_IsPress(DIK_LSHIFT))
	{
		posV.y -= m_Velocity.y;
		posR.y -= m_Velocity.y;
	}
	
	if (Input::KB_IsPress(DIK_E))
	{
		posR.x += m_Velocity.x;
	}
	
	if (Input::KB_IsPress(DIK_Q))
	{
		posR.x -= m_Velocity.x;
	}

	if (Input::KB_IsPress(DIK_R))
	{
		posR.y += m_Velocity.y;
	}

	if (Input::KB_IsPress(DIK_F))
	{
		posR.y -= m_Velocity.y;
	}

	if (Input::KB_IsTrigger(DIK_Z))
	{
		Init();
	}
	DebugProc_Print((char*)"*** �R�c�|���S������ ***\n");
	DebugProc_Print((char*)"�ʒu [%f : %f : %f]\n", posV.x, posV.y, posV.z);
	DebugProc_Print((char*)"�O�ړ� : �v\n");
	DebugProc_Print((char*)"��ړ� : �r\n");
	DebugProc_Print((char*)"���ړ� : �`\n");
	DebugProc_Print((char*)"�E�ړ� : �c\n");
	DebugProc_Print((char*)"��ړ� : SPACE\n");
	DebugProc_Print((char*)"���ړ� : LSHIFT\n");
	DebugProc_Print((char*)"\n");

	DebugProc_Print((char*)"���� [%f : %f : %f]\n", posR.x, posR.y, posR.z);
	DebugProc_Print((char*)"X����] : Q / E\n");
	DebugProc_Print((char*)"Y����] : R / F\n");
	DebugProc_Print((char*)"\n");

	DebugProc_Print((char*)"�ʒu�E�������Z�b�g : Z\n");
}

//#	�J�����̐ݒ�
void DebugCamera::Set()
{
	Camera::Set();
}
