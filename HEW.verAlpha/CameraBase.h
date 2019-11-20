/*===============================================

	[CameraBase.h]
	Author : �o���đ�

=================================================*/

#pragma once
#include "main.h"

//�@�}�N����`
#define	CAM_POS_V_X		(0.0f)											// �J�����̎��_�����ʒu(X���W)
#define	CAM_POS_V_Y		(100.0f)										// �J�����̎��_�����ʒu(Y���W)
#define	CAM_POS_V_Z		(-200.0f)										// �J�����̎��_�����ʒu(Z���W)
#define	CAM_POS_R_X		(0.0f)											// �J�����̒����_�����ʒu(X���W)
#define	CAM_POS_R_Y		(0.0f)											// �J�����̒����_�����ʒu(Y���W)
#define	CAM_POS_R_Z		(0.0f)											// �J�����̒����_�����ʒu(Z���W)
#define	VIEW_ANGLE		(D3DXToRadian(45.0f))							// �r���[���ʂ̎���p
#define	VIEW_ASPECT		((float)SCREEN_WIDTH / (float)SCREEN_HEIGHT)	// �r���[���ʂ̃A�X�y�N�g��
#define	VIEW_NEAR_Z		(10.0f)											// �r���[���ʂ�NearZ�l	�l���߂��ƕ`�悵�Ȃ�
#define	VIEW_FAR_Z		(10000.0f)										// �r���[���ʂ�FarZ�l	�l��艓���ƕ`�悵�Ȃ�

//#	CameraBase�N���X
/* �J�����̐ݒ���Ǘ����钊�ۃN���X */
class CameraBase
{
public:
	//	�������z�֐��w��
	virtual	void Init() = 0;			//�J�����̏�����
	virtual	void Uninit() = 0;		//�J�����̏I������
	virtual	void Set() = 0;			//�J�����̐ݒ�
};



