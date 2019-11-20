/*==============================================
	
	[DebugCamera.h]
	Author : �o���đ�

==============================================*/

#pragma once
#include "main.h"
#include "CameraBase.h"
#include "Camera.h"

//# DebugCamera�N���X�@�F�@���N���XCamera�̔h��
/* �f�o�b�O�p�J���� */
class DebugCamera : public Camera
{
private:
	//	�����o�[�ϐ�
	static D3DXVECTOR3			move;			//	�ړ�
	static D3DXVECTOR3			rot;			//	��]
	static float				fDistance;		//	���_�ƒ����_�̋���
public:
	//	�����o�[�֐�
	void Init();		//	�J�����̏�����
	void Uninit();		//	�J�����̏I������
	void Update();		//	�J�����̍X�V
	void Set();			//	�J�����̐ݒ�
};

