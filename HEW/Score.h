/*=====================================================

	[Score.h]
	Author : �o���đ�

======================================================*/

#pragma once
#include "main.h"
#include "sprite.h"


#if 0
//	�N���X
class Score
{
		//<-���������Ȃ��ƃA�N�Z�X�w��q��private�ɂȂ�
	Sprite m_sprite;
	void Draw(float x, float y, int n);
public:
	void Draw(float x,float y,int score,int flg,bool bZero);
};
#else

//	�\����
struct Score
{
private:	//<-���������Ȃ��ƃA�N�Z�X�w��q��public�ɂȂ�
	Sprite m_sprite;
	void Draw(float x, float y, int n);
public:
	void Draw(float x, float y, int score, int flg, bool bZero);
};
#endif

//	�����@typedef�̈Ӗ� ����
/*

	���Ȃ݂�C����̂Ƃ���typedef�𓪂ɂ��Ă����B
	���̗��R�͍\���̂̕ϐ��錾�̂Ƃ��ɁA�ustruct�v�Ƃ����L�[���[�h��t����K�v������������
	������ȗ����邽�߂�typedef�����Ă���

	������typedef���g��Ȃ�������������
	struct Player							
	{											
		int a;								
	};

	������struct������
	struct Player g_player = { 10 };
	
	������typedef���g����������������
	typedef struct
	{
		int a;
	}Player;
	
	��struct�̃L�[���[�h���ȗ�
	Player g_player = { 10 };

	
	����typedef�̏�������C����̂Ƃ��ɕK�v���������̂�C++�ɂȂ��typedef�̋L�q�͕K�v�Ȃ��B
	��typedef�������Ȃ��Ă��A�ϐ��̑O�Ɂustruct�v�̃L�[���[�h������K�v���Ȃ��Ȃ����B

	������C++�̍\���̐錾������
	struct Player
	{
		int a;
	};
		
	Player g_player = { 10 };

*/

//	�����@C++�̍\���̂ƃN���X�̈Ⴂ ����
/*
	�\���̂ƃN���X�̈Ⴂ�͂�����B
	�A�N�Z�X�w��q�̃f�t�H���g���Ⴄ����
	�N���X��private�A�\���̂�public�ɂȂ�B
	�܂�c
	C++�Ȃ�A�\���̂ɂ��֐��������o�[�ɂł����ł��˂�

	���Ȃ݂ɁAC����̂Ƃ��A
	�\���̂̒��ɂ���ϐ��̂��Ƃ������o�[�ƌĂ�ł����B

	����1�N���̕��K����
	typedef struct
	{
		int a;�������o�[
	}Player;

	C++�ɂȂ����Ƃ����̃����o�[�Ɋ֐����ǉ����ꂽ�̂ŁA
	�ϐ��̓����o�[�ϐ��A�֐��̓����o�[�֐��Ǝg�������ČĂ�ł��邾��
	�Ȃ̂ŁA�������Ȃ��悤�ɁB

	struct Player
	{
		int Hensuu;		<-�����o�[�ϐ�
		void Kansuu();	<-�����o�[�֐�
	}

	�ȏ�A������Ƃ�������ł����B
*/
