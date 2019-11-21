/*=====================================

	[Camera.h]
	Author : �o���đ�

=====================================*/

#pragma once
#include "main.h"
#include "CameraBase.h"

//# Camera�N���X : ���ۃN���X(CameraBase)
class Camera : public CameraBase
{
protected:
	static D3DXVECTOR3			posV;			//	���_�i�J�����̈ʒu�j
	static D3DXVECTOR3			posR;			//	�����_�i�J�����͂ǂ������Ă���̂��j
	static D3DXVECTOR3			vecU;			//	������x�N�g���i�J�����̏�����͂����v���X�j���W�́i�O�C�P�C�O�j
	static D3DXMATRIX			mtxProjection;	//	�v���W�F�N�V�����}�g���b�N�X
	static D3DXMATRIX			mtxView;		//	�r���[�}�g���b�N�X
	static LPDIRECT3DDEVICE9	pDevice;		//�@�f�o�C�X�̎擾�p�ϐ�
public:
	virtual void Init();
	virtual void Uninit();
	virtual void Update();
	virtual void Set();
};

