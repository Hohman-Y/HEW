/*============================================

[Character.h]
Author : hohman yuushi

=============================================*/

#pragma once
#include "main.h"
#include "CharacterCamera.h"


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
float getRadian(float X1, float Y1, float X2, float Y2);

//#	�L�����N�^�[�N���X
/* �L�����N�^�[�̏����Ǘ�����N���X�@*/
class Character
{
private:
	CharacterCamera m_Camera;	//	�L�����N�^�[�ɂ���J�����̃C���X�^���X
public:
	Character();
	~Character();

	void Init();
	void Uninit();
	void Update();
	void Draw();
};



