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

enum GamePhase
{
	PHASE_FADE,
	PHASE_GAME,
	PHASE_CLEARCHECK,
};

//#	SceneGame�N���X:�e�N���X,SceneBase���p�������q�N���X
class SceneGame:public SceneBase
{
private:
	GamePhase		m_GamePhase;
	Character		m_Character;
	CharacterCamera	m_Camera;
	Field			m_Map;

	bool			EndCheck();
public:
	void Init();	//	�Q�[���̏���������	
	void Uninit();	//	�Q�[���̏I������
	void Update();	//	�Q�[���̍X�V����
	void Draw();	//	�Q�[���̕`�揈��
	Character*	SetCharacter();
	Field*		SetField();
};
