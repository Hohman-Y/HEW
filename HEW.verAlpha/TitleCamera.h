/*=================================================

	[TitleCamera.h]
	Author : �o���đ�

=================================================*/

#pragma once
#include "main.h"
#include "Camera.h"

//# TitleCamera�N���X : ���N���XCamera�̔h�� 
/* �^�C�g���Ń}�b�v��`�悷�邽�߂̃J���� */
class TitleCamera :public Camera
{
private:
	static D3DXVECTOR3 m_Velocity;	//	�J�����̈ړ����x
public:
	void Init();	//	�J�����̏�����
	void Uninit();	//	�J�����̏I������
	void Update();	//	�J�����̍X�V����
	void Set();		//	�J�����̐ݒ�
};

