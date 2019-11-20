/*===========================================

	[TitleCamera.cpp]
	Author : �o���đ�

===========================================*/

#include "main.h"
#include "TitleCamera.h"

//	�X�^�e�B�b�N�ϐ�
D3DXVECTOR3			Camera::posV;
D3DXVECTOR3			Camera::posR;
D3DXVECTOR3			Camera::vecU;
D3DXMATRIX			Camera::mtxProjection;
D3DXMATRIX			Camera::mtxView;
LPDIRECT3DDEVICE9	Camera::pDevice;
D3DXVECTOR3			TitleCamera::m_Velocity;

//	������
void TitleCamera::Init()
{
	m_Velocity = D3DXVECTOR3(1.0f, 1.0f, 1.0f);	//	�ړ����x�̏�����
	Camera::Init();								//	���N���X(Camera)��Init�֐����Ăяo��
	posV.y = -200.0f;							//	�J�����̎��_�����ʒu�iY���W�j��-200�ɐݒ�
}

void TitleCamera::Uninit()
{

}

//	�X�V����
void TitleCamera::Update()
{
	posV.x += m_Velocity.x;	//	�J������X���W�𓮂���
	if (posV.x > 100.0f)	//	100.0f�n�_�𒴂����Ƃ�
	{
		posV.x = 100.0f;	
		m_Velocity *= -1;	//	m_Velocity��-1����Z����@->�@�t�����Ɉړ�
	}
	else if(posV.x <-100.0f)
	{
		posV.x = -100.0f;
		m_Velocity *= -1;
	}
}

void TitleCamera::Set()
{
	Camera::Set();	//	���N���X(Camera)��Set�֐����Ăяo��
}
