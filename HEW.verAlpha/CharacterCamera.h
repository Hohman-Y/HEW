/*====================================================

	[CharacterCamera.h]
	Author : �o���đ�

=====================================================*/

#pragma once
#include "CameraBase.h"

//#	CharacterCamera�N���X
/* �L�����N�^�[�ɂ���J���� */
class CharacterCamera :public CameraBase
{
public:
	void Init();
	void Uninit();
	void Set();
};

