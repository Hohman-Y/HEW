/*==============================================
	
	[DebugCamera.h]
	Author : �o���đ�

==============================================*/

#pragma once
#include "main.h"
#include "Camera.h"

//# DebugCamera
/* �f�o�b�O�p�J���� */
class DebugCamera : public Camera
{
private:
	//�ÓI�����o�ϐ�
	static D3DXVECTOR3			m_Velocity;		//	�ړ�
	static D3DXVECTOR3			m_rot;			//	��]
	static float				m_fDistance;		//	���_�ƒ����_�̋���
public:
	//�@�����o�֐�
	void Init();		//	�J�����̏�����
	void Uninit();		//	�J�����̏I������
	void Update();		//	�J�����̍X�V
	void Set();			//	�J�����̐ݒ�
};

