/*==================================

	[SceneGame.h]
	Author : �o���đ�

===================================*/

#pragma once
#include "main.h"
#include "SceneBase.h"
#include "Character.h"
#include "CharacterCamera.h"
#include "Field.h"

//#	SceneGame�N���X:�e�N���X,SceneBase���p�������q�N���X
class SceneGame:public SceneBase
{
private:
	Character		m_Character;
	CharacterCamera	m_Camera;
	Field			m_Map;
public:
	void Init();	//	�Q�[���̏���������	
	void Uninit();	//	�Q�[���̏I������
	void Update();	//	�Q�[���̍X�V����
	void Draw();	//	�Q�[���̕`�揈��
	Character*	SetCharacter();
	Field*		SetField();
};
