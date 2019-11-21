/*===============================================

	[CameraBase.h]
	Author : �o���đ�

=================================================*/

#pragma once

//#	CameraBase�N���X
/* �J�����̐ݒ���Ǘ����钊�ۃN���X */
class CameraBase
{
public:
	//	�������z�֐��w��
	virtual	void Init() = 0;		//	�J�����̏�����
	virtual	void Uninit() = 0;		//	�J�����̏I������
	virtual void Update() = 0;		//	�J�����̍X�V����
	virtual	void Set() = 0;			//	�J�����̐ݒ�
};



