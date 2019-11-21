/*===============================================

	[Camera.h]
	Author : �o���đ�

=================================================*/

#pragma once
#include "main.h"
#include "CameraBase.h"

//#	Camera�N���X
/* �J�����̐ݒ���Ǘ�����N���X */
class Camera : public CameraBase
{
protected:
	//�����o�ϐ�
	D3DXVECTOR3			posV;			// ���_�i�J�����̈ʒu�j
	D3DXVECTOR3			posR;			// �����_�i�J�����͂ǂ������Ă���̂��j
	D3DXVECTOR3			vecU;			// ������x�N�g���i�J�����̏�����͂����v���X�j���W�́i�O�C�P�C�O�j
	D3DXMATRIX			mtxProjection;	// �v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX			mtxView;		// �r���[�}�g���b�N�X
	LPDIRECT3DDEVICE9	pDevice;		//�@�f�o�C�X�̎擾�p�ϐ�

public:
	//�@�����o�֐�
	virtual void Init();		//�J�����̏�����
	virtual void Uninit();		//�J�����̏I������
	virtual void Update();
	virtual void Set();			//�J�����̐ݒ�
};



