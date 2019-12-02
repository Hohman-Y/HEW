/*==============================================

	[SceneDebug.h]
	Author : �o���đ�

==============================================*/

#pragma once
#include "main.h"
#include "SceneBase.h"
#include "DebugCamera.h"
#include "Map.h"
#include "Character.h"
#include "sprite.h"
#include "mondai.h"

//# SceneDebug : �e�N���XSceneBase
class SceneDebug: public SceneBase
{
private:
	Character	m_Character;
	DebugCamera m_Camera;
	Map			m_Map;
	Sprite		m_Sprite;
	Mondai		m_mondai;

public:
	//SceneBase�̃����o�[�֐��̃I�[�o�[���C�h
	void Init();	//	�Q�[���̏���������	
	void Uninit();	//	�Q�[���̏I������
	void Update();	//	�Q�[���̍X�V����
	void Draw();	//	�Q�[���̕`�揈��
};

