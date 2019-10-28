/*===============================================

	[Camera.h]
	Author : �o���đ�

=================================================*/

#pragma once
#include "main.h"

//�}�N����`
#define	CAM_POS_V_X		(0.0f)											// �J�����̎��_�����ʒu(X���W)
#define	CAM_POS_V_Y		(100.0f)										// �J�����̎��_�����ʒu(Y���W)
#define	CAM_POS_V_Z		(-200.0f)										// �J�����̎��_�����ʒu(Z���W)
#define	CAM_POS_R_X		(0.0f)											// �J�����̒����_�����ʒu(X���W)
#define	CAM_POS_R_Y		(0.0f)											// �J�����̒����_�����ʒu(Y���W)
#define	CAM_POS_R_Z		(0.0f)											// �J�����̒����_�����ʒu(Z���W)
#define	VIEW_ANGLE		(D3DXToRadian(45.0f))							// �r���[���ʂ̎���p
#define	VIEW_ASPECT		((float)SCREEN_WIDTH / (float)SCREEN_HEIGHT)	// �r���[���ʂ̃A�X�y�N�g��
#define	VIEW_NEAR_Z		(10.0f)											// �r���[���ʂ�NearZ�l	�l���߂��ƕ`�悵�Ȃ�
#define	VIEW_FAR_Z		(1000.0f)										// �r���[���ʂ�FarZ�l	�l��艓���ƕ`�悵�Ȃ�

class Camera
{
private:
	//�����o�ϐ�
	static D3DXVECTOR3 posV;			// ���_�i�J�����̈ʒu�j
	static D3DXVECTOR3 posR;			// �����_�i�J�����͂ǂ������Ă���̂��j
	static D3DXVECTOR3 vecU;			// ������x�N�g���i�J�����̏�����͂����v���X�j���W�́i�O�C�P�C�O�j
	static D3DXMATRIX mtxProjection;	// �v���W�F�N�V�����}�g���b�N�X
	static D3DXMATRIX mtxView;			// �r���[�}�g���b�N�X

public:
	//�����o�֐�
	Camera();					//�R���X�g���N�^
	~Camera();					//�f�X�g���N�^
	static void Init();			
	static void Uninit();
	static void Set();			//�J�����̐ݒ�
};

