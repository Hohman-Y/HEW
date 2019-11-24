/*============================================

[Character.cpp]
Author :hohman yuushi

=============================================*/

#include "Character.h"
#include "Map.h"
#include "Controller.h"
#include "main.h"
#include <d3dx9.h>
#include <math.h>


/*--------------------------------------------------------------
enum
---------------------------------------------------------------*/
enum PLAYER_STATE		//Player�̏�ԑJ��
{
	PLAYER_WAIT,		//	�ҋ@
	PLAYER_START,		//	�J�n
	PLAYER_ANSWER,		//	��
	PLAYER_JUMP,		//	�W�����v
	PLAYER_FINISH		//	�I��(���n����)
};


enum LANE_STATE			//���[���̂Ȃ񂩂���
{
	LANE_START,


	LANE_SELECT,

	LANE_1,
	LANE_2,
	LANE_3,
	LANE_4,


	LANE_JUMP,

	LANE_END
};



/*---------------------------------------------------------------------------------
struct
---------------------------------------------------------------------------------*/
typedef struct
{
	D3DXVECTOR3 PPos;		//PlayerPoint(postion)
	float		P_x, P_y;	//Player�ɂ�����ړ���
	float		Speed;		//Player�̑��x
	int			Status;		//Player�̏��
}PlayerData;


/*---------------------------------------------------------------------------------
global
-----------------------------------------------------------------------------------*/
static PlayerData g_Player;		//�v���C���[�f�[�^
static HWND hWnd;				//���b�Z�[�W�\���Ɏg�p

static int	g_LaneStatus;			//���[���X�e�[�^�X
static int	g_count;				//��萔�J�E���^
static int	g_Q,g_A;				//����ԍ��i�[�A�񓚊i�[

static float		tmp;					//SPEED�ꎞ�ۑ�
static float		radian;


/*-----------------------------------------
�֐����X
-----------------------------------------*/
Character::Character()
{
	
}


Character::~Character()
{
	
}


void Character::Init()
{
	//�Ƃ肠���������ŏ�����
	g_Player.PPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//g_Player.PVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_Player.Speed = 0;
	g_Player.Status = PLAYER_WAIT;

	//���b�Z�[�W�ŗ��p���Ă邩��
	hWnd = GetHWND();


}


void Character::Uninit()
{
	
}


void Character::Update()
{
	//Player�̃X�e�[�^�X�Ŕ��f(�X�e�[�^�X�O�̐��l�̓G���[�Ή�)
	switch (g_Player.Status)
	{
		//�ҋ@���[�V�����ł����ꗬ���Ƃ��Ⴆ���񂿂Ⴄ�H
	case PLAYER_WAIT:

		//�����Ƀ��[�V��������

		if (KeyBoard::IsTrigger(DIK_E))
		{
			//�X�e�[�^�X�ύX
			g_Player.Status = PLAYER_START;
		}
		break;

		
	case PLAYER_START:		//�����J�n

		if (g_Player.Speed >= 5.0f)
		{
			tmp = g_Player.Speed;

			//�����ɂ�����ƃC���^�[�o�������΂�������
			g_Player.Status = PLAYER_ANSWER;
		}

		//����
		g_Player.Speed += 0.2f;

		break;

		
	case PLAYER_ANSWER:		//��

		//SPEED��ۑ����Ē�~
		tmp = g_Player.Speed;
		g_Player.Speed = 0.0f;

	if (KeyBoard::IsTrigger(DIK_A))
	{// ���ړ�

	}
	else if (KeyBoard::IsTrigger(DIK_D))
	{// �E�ړ�

	}

	//�Ƃ肠����Space�Ŏ���
	if (KeyBoard::IsTrigger(DIK_SPACE))
	{
		//����񓚂�����
		g_count++;

		//���x����
		g_Player.Speed = tmp;

		if (g_Q == g_A)
		{
			g_Player.Speed *= 0.3f;
		}
		
		if (g_count >= 3)
		{
			g_Player.Status = PLAYER_JUMP;
		}
		else
		{
			g_Player.Status = PLAYER_START;
		}
	}
		break;



		case PLAYER_JUMP:		//�W�����v

		//�����A�^�C�~���O�̌��ˍ����Ő��l���o��
		MessageBox(hWnd, "Jump����", "JUMP", MB_OK);	//...�w�W(��)���Ȃ��ƃ^�C�~���O�Ƃ�Ȃ���
		g_Player.Status = PLAYER_FINISH;

		break;

		
	case PLAYER_FINISH:		//�I��

		MessageBox(hWnd, "�I������", "END", MB_OK);

		break;


	default:
		//�G���[�Ή�
		MessageBox(hWnd, "���݂��Ȃ��v���C���[�X�e�[�^�X�ł�", "ERROR", MB_OK);
		exit(1);

		break;
	}

	getRadian(0.0f, 0.0f, 100.0f, -1000.0f);
	//�ړ�����
	g_Player.PPos.x += cosf(radian)*2.0f;
	g_Player.PPos.y += sinf(radian)*2.0f;
}

void Character::Draw()
{

}


float getRadian(float X1, float Y1, float X2, float Y2)
{
	float w = X2 - X1; // cos��
	float h = Y2 - Y1; // sin��

	return atan2f(h, w);
}


/*
��������

float getRadian(float X1,float Y1,float X2,float Y2)
{
float w = X2 - X1; // cos��
float h = Y2 - Y1; // sin��

return atan2f(h,w);
}

// �^�[�Q�b�g�̕����֐i��
m_x += cosf(radian);
m_y += sinf(radian);



��L�K�p�\���͍�

���炭
m_x += cosf(radian) * speed
�ő��x�����\
*/
