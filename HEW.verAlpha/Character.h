/*============================================

[Character.h]
Author : hohman yuushi

=============================================*/

#pragma once
#include "main.h"


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
float getRadian(float X1, float Y1, float X2, float Y2);

	//#	�L�����N�^�[�N���X :�@�e�N���X

	/* �L�����N�^�[�̏����Ǘ�����N���X�@*/
	class Character
{
public:
	Character();
	~Character();

	void Init();
	void Uninit();
	void Update();
	void Draw();
};



