/*====================================================

	[CharacterCamera.h]
	Author : �o���đ�

=====================================================*/

#pragma once
#include "main.h"
#include "Camera.h"

//#	CharacterCamera�N���X : ���N���XCamera�̔h��
/* �L�����N�^�[�ɂ���J���� */
class CharacterCamera :public Camera
{
public:
	void Init();
	void Uninit();
	void Update();
	void Set();
};

