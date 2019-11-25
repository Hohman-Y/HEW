/*============================================

[Character.cpp]
Author :hohman yuushi

=============================================*/

#include "Character.h"
#include "Map.h"
#include "Model.h"
#include "input.h"
#include "main.h"
#include <d3dx9.h>
#include <math.h>
#include "Controller.h"


#define	VALUE_MOVE		(5.0f)							// �ړ���
#define	VALUE_ROTATE	(D3DX_PI * 0.02f)				// ��]��


#define	NUM_VERTEX		(60)		// ���_��
#define	NUM_POLYGON		(24)		// �|���S����


#define	BOX_WIDTH		(100.0f)						// �n�ʂ̕�(X����)
#define	BOX_DEPTH		(100.0f)						// �n�ʂ̉��s(Z����)
#define BOX_HEIGHT		(100.0f)						//�n�ʁ@�iY�����j

#define NUM_BOX			(2)								// 

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



CGraphic*				glbl_graphic = NULL;

LPDIRECT3D9				g_pD3D = NULL;			//D3D�C���^�[�t�F�[�X D3D�f�o�C�X�����̂ɕK�v
LPDIRECT3DDEVICE9		g_pD3DDevice = NULL;	//D3D�f�o�C�X �`��ȂǍL�͈͂ŕK�v�ɂȂ�B
IDirect3DVertexBuffer9* g_pVB = NULL;			//�|���S���̃o�b�t�@



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
	////Player�̃X�e�[�^�X�Ŕ��f(�X�e�[�^�X�O�̐��l�̓G���[�Ή�)
	//switch (g_Player.Status)
	//{
	//	//�ҋ@���[�V�����ł����ꗬ���Ƃ��Ⴆ���񂿂Ⴄ�H
	//case PLAYER_WAIT:

	//	//�����Ƀ��[�V��������

	//	if (Input::KB_IsTrigger(DIK_E))
	//	{
	//		//�X�e�[�^�X�ύX
	//		g_Player.Status = PLAYER_START;
	//	}
	//	break;

	//	
	//case PLAYER_START:		//�����J�n

	//	if (g_Player.Speed >= 5.0f)
	//	{
	//		tmp = g_Player.Speed;

	//		//�����ɂ�����ƃC���^�[�o�������΂�������
	//		g_Player.Status = PLAYER_ANSWER;
	//	}

	//	//����
	//	g_Player.Speed += 0.2f;

	//	break;

	//	
	//case PLAYER_ANSWER:		//��

	//	//SPEED��ۑ����Ē�~
	//	tmp = g_Player.Speed;
	//	g_Player.Speed = 0.0f;

	//if (Input::KB_IsTrigger(DIK_A))
	//{// ���ړ�

	//}
	//else if (Input::KB_IsTrigger(DIK_D))
	//{// �E�ړ�

	//}

	////�Ƃ肠����Space�Ŏ���
	//if (Input::KB_IsTrigger(DIK_SPACE))
	//{
	//	//����񓚂�����
	//	g_count++;

	//	//���x����
	//	g_Player.Speed = tmp;

	//	if (g_Q == g_A)
	//	{
	//		g_Player.Speed *= 0.3f;
	//	}
	//	
	//	if (g_count >= 3)
	//	{
	//		g_Player.Status = PLAYER_JUMP;
	//	}
	//	else
	//	{
	//		g_Player.Status = PLAYER_START;
	//	}
	//}
	//	break;



	//	case PLAYER_JUMP:		//�W�����v

	//	//�����A�^�C�~���O�̌��ˍ����Ő��l���o��
	//	MessageBox(hWnd, "Jump����", "JUMP", MB_OK);	//...�w�W(��)���Ȃ��ƃ^�C�~���O�Ƃ�Ȃ���
	//	g_Player.Status = PLAYER_FINISH;

	//	break;

	//	
	//case PLAYER_FINISH:		//�I��

	//	MessageBox(hWnd, "�I������", "END", MB_OK);

	//	break;


	//default:
	//	//�G���[�Ή�
	//	MessageBox(hWnd, "���݂��Ȃ��v���C���[�X�e�[�^�X�ł�", "ERROR", MB_OK);
	//	exit(1);

	//	break;
	//}


			
}

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexBox(LPDIRECT3DDEVICE9 pDevice);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffField = NULL;	// ���_�o�b�t�@�ւ̃|�C���^
static LPDIRECT3DINDEXBUFFER9	g_pIdxBuffField = NULL;
static int						g_NumIndexField = 36;

typedef struct
{
	D3DXMATRIX				g_mtxWorldField;		// ���[���h�}�g���b�N�X
	D3DXVECTOR3				g_posField;				// �n�ʂ̈ʒu
	D3DXVECTOR3				g_rotField;				// �n�ʂ̌���(��])
	D3DXVECTOR3				g_sclField;				// �n�ʂ̑傫��(�X�P�[��)
}BOX_T;

static BOX_T g_Box[NUM_BOX];

static float g_move_x = 0.01f;

//=============================================================================
// ����������
//=============================================================================
HRESULT Box_Initialize(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetD3DDevice();

	// ���_���̍쐬
	MakeVertexBox(pDevice);

	//// �ʒu�E��]�E�X�P�[���̏����ݒ�
	//g_posField = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//g_rotField = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//g_sclField = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void Box_Finalize(void)
{
	if (g_pIdxBuffField != NULL)
	{//
		g_pIdxBuffField->Release();
		g_pIdxBuffField = NULL;
	}


	if (g_pVtxBuffField != NULL)
	{// ���_�o�b�t�@�̊J��
		g_pVtxBuffField->Release();
		g_pVtxBuffField = NULL;
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void Box_Update(void)
{

	D3DXMATRIX mtxScl, mtxRot, mtxTranslate;

	//���[���h�}�g���b�N�X�̏�����
	for (int i = 0; i < NUM_BOX; i++)
	{
		D3DXMatrixIdentity(&g_Box[i].g_mtxWorldField);
	}

	//g_Box[0].g_rotField.y += 0.05f;

	//��]�𔽉f
	//D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Box[0].g_rotField.y, g_Box[0].g_rotField.x, g_Box[0].g_rotField.z);
	//D3DXMatrixMultiply(&g_Box[0].g_mtxWorldField, &g_Box[0].g_mtxWorldField, &mtxRot);

	//g_Box[0].g_posField.x = 100.0f;
	//g_Box[0].g_posField.y = 0.0f;
	//g_Box[0].g_posField.z = 100.0f;

	//�ړ��𔽉f
	//D3DXMatrixTranslation(&mtxTranslate, g_Box[0].g_posField.x, g_Box[0].g_posField.y, g_Box[0].g_posField.z);
	//D3DXMatrixMultiply(&g_Box[0].g_mtxWorldField, &g_Box[0].g_mtxWorldField, &mtxTranslate);


	//g_Box[1].g_posField.x = 100.0f;
	//g_Box[1].g_posField.y = 0.0f;
	//g_Box[1].g_posField.z = 100.0f;

	//�ړ��𔽉f
	//D3DXMatrixTranslation(&mtxTranslate, g_Box[1].g_posField.x, g_Box[1].g_posField.y, g_Box[1].g_posField.z);
	//D3DXMatrixMultiply(&g_Box[1].g_mtxWorldField, &g_Box[1].g_mtxWorldField, &mtxTranslate);

	//g_Box[1].g_rotField.y += 0.05f;

	//��]�𔽉f
	//D3DXMatrixRotationYawPitchRoll(&mtxRot, -g_Box[1].g_rotField.y, g_Box[1].g_rotField.x, g_Box[1].g_rotField.z);
	//D3DXMatrixMultiply(&g_Box[1].g_mtxWorldField, &g_Box[1].g_mtxWorldField, &mtxRot);

	//g_Box[1].g_posField.x += 100.0f;
	//g_Box[1].g_posField.z += 100.0f;

	//�ړ��𔽉f
	//D3DXMatrixTranslation(&mtxTranslate, g_Box[1].g_posField.x, g_Box[1].g_posField.y, g_Box[1].g_posField.z);
	//D3DXMatrixMultiply(&g_Box[1].g_mtxWorldField, &g_Box[1].g_mtxWorldField, &mtxTranslate);

	//��]�𔽉f
	//D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Box[1].g_rotField.y, g_Box[1].g_rotField.x, g_Box[1].g_rotField.z);
	//D3DXMatrixMultiply(&g_Box[1].g_mtxWorldField, &g_Box[1].g_mtxWorldField, &mtxRot);

	////�X�P�[���𔽉f
	//D3DXMatrixScaling(&mtxScl, g_sclField.x, g_sclField.y, g_sclField.z);
	//D3DXMatrixMultiply(&g_mtxWorldField, &g_mtxWorldField, &mtxScl);




		if (KeyBoard::IsPress(DIK_A))
		{
			if (KeyBoard::IsPress(DIK_W))
			{// �����ړ�
				g_Box[0].g_posField.x += sinf(-D3DX_PI * 0.75f) * VALUE_MOVE;
				g_Box[0].g_posField.z -= cosf(-D3DX_PI * 0.75f) * VALUE_MOVE;
			}
			else if (KeyBoard::IsPress(DIK_S))
			{// ����O�ړ�
				g_Box[0].g_posField.x += sinf(-D3DX_PI * 0.25f) * VALUE_MOVE;
				g_Box[0].g_posField.z -= cosf(-D3DX_PI * 0.25f) * VALUE_MOVE;
			}
			else
			{// ���ړ�
				g_Box[0].g_posField.x += sinf(-D3DX_PI * 0.50f) * VALUE_MOVE;
				g_Box[0].g_posField.z -= cosf(-D3DX_PI * 0.50f) * VALUE_MOVE;
			}
		}
		else if (KeyBoard::IsPress(DIK_D))
		{
			if (KeyBoard::IsPress(DIK_W))
			{// �E���ړ�
				g_Box[0].g_posField.x += sinf(D3DX_PI * 0.75f) * VALUE_MOVE;
				g_Box[0].g_posField.z -= cosf(D3DX_PI * 0.75f) * VALUE_MOVE;
			}
			else if (KeyBoard::IsPress(DIK_S))
			{// �E��O�ړ�
				g_Box[0].g_posField.x += sinf(D3DX_PI * 0.25f) * VALUE_MOVE;
				g_Box[0].g_posField.z -= cosf(D3DX_PI * 0.25f) * VALUE_MOVE;
			}
			else
			{// �E�ړ�
				g_Box[0].g_posField.x += sinf(D3DX_PI * 0.50f) * VALUE_MOVE;
				g_Box[0].g_posField.z -= cosf(D3DX_PI * 0.50f) * VALUE_MOVE;
			}
		}
		else if (KeyBoard::IsPress(DIK_W))
		{// ���ړ�
			g_Box[0].g_posField.x += sinf(D3DX_PI * 1.0f) * VALUE_MOVE;
			g_Box[0].g_posField.z -= cosf(D3DX_PI * 1.0f) * VALUE_MOVE;
		}
		else if (KeyBoard::IsPress(DIK_S))
		{// ��O�ړ�
			g_Box[0].g_posField.x += sinf(D3DX_PI * 0.0f) * VALUE_MOVE;
			g_Box[0].g_posField.z -= cosf(D3DX_PI * 0.0f) * VALUE_MOVE;
		}
	
	#if 1
		if (KeyBoard::IsPress(DIK_Q))
		{// Y������]
			g_Box[0].g_rotField.y -= VALUE_ROTATE;
			if(g_Box[0].g_rotField.y > D3DX_PI)
			{
				g_Box[0].g_rotField.y -= D3DX_PI * 2.0f;
			}
			if(g_Box[0].g_rotField.y < -D3DX_PI)
			{
				g_Box[0].g_rotField.y += D3DX_PI * 2.0f;
			}
		}
		if (KeyBoard::IsPress(DIK_E))
		{// Y���E��]
			g_Box[0].g_rotField.y += VALUE_ROTATE;
			if(g_Box[0].g_rotField.y > D3DX_PI)
			{
				g_Box[0].g_rotField.y -= D3DX_PI * 2.0f;
			}
			if(g_Box[0].g_rotField.y < -D3DX_PI)
			{
				g_Box[0].g_rotField.y += D3DX_PI * 2.0f;
			}
		}
	#endif
	
	#if 1
		if (KeyBoard::IsPress(DIK_UP))
		{// X���E��]
			g_Box[0].g_rotField.x += VALUE_ROTATE;
			if(g_Box[0].g_rotField.x > D3DX_PI)
			{
				g_Box[0].g_rotField.x -= D3DX_PI * 2.0f;
			}
			if(g_Box[0].g_rotField.x < -D3DX_PI)
			{
				g_Box[0].g_rotField.x += D3DX_PI * 2.0f;
			}
		}
		if (KeyBoard::IsPress(DIK_DOWN))
		{// X������]
			g_Box[0].g_rotField.x -= VALUE_ROTATE;
			if(g_Box[0].g_rotField.x > D3DX_PI)
			{
				g_Box[0].g_rotField.x -= D3DX_PI * 2.0f;
			}
			if(g_Box[0].g_rotField.x < -D3DX_PI)
			{
				g_Box[0].g_rotField.x += D3DX_PI * 2.0f;
			}
		}
	#endif
	
	#if 1
		if (KeyBoard::IsPress(DIK_LEFT))
		{// Z���E��]
			g_Box[0].g_rotField.z += VALUE_ROTATE;
			if(g_Box[0].g_rotField.z > D3DX_PI)
			{
				g_Box[0].g_rotField.z -= D3DX_PI * 2.0f;
			}
			if(g_Box[0].g_rotField.z < -D3DX_PI)
			{
				g_Box[0].g_rotField.z += D3DX_PI * 2.0f;
			}
		}
		if (KeyBoard::IsPress(DIK_RIGHT))
		{// Z������]
			g_Box[0].g_rotField.z -= VALUE_ROTATE;
			if(g_Box[0].g_rotField.z > D3DX_PI)
			{
				g_Box[0].g_rotField.z -= D3DX_PI * 2.0f;
			}
			if(g_Box[0].g_rotField.z < -D3DX_PI)
			{
				g_Box[0].g_rotField.z += D3DX_PI * 2.0f;
			}
		}
	#endif
	
		if (KeyBoard::IsPress(DIK_RETURN))
		{// ���Z�b�g
			g_Box[0].g_posField.x = 0.0f;
			g_Box[0].g_posField.y = 0.0f;
			g_Box[0].g_posField.z = 0.0f;
	
			g_Box[0].g_rotField.x = 0.0f;
			g_Box[0].g_rotField.y = 0.0f;
			g_Box[0].g_rotField.z = 0.0f;
		}

	/*DebugProc_Print((char*)"*** �R�c�|���S������ ***\n");
	DebugProc_Print((char*)"�ʒu [%f : %f : %f]\n", g_posField.x, g_posField.y, g_posField.z);
	DebugProc_Print((char*)"�O�ړ� : �v\n");
	DebugProc_Print((char*)"��ړ� : �r\n");
	DebugProc_Print((char*)"���ړ� : �`\n");
	DebugProc_Print((char*)"�E�ړ� : �c\n");
	DebugProc_Print((char*)"\n");

	DebugProc_Print((char*)"���� [%f : %f : %f]\n", g_rotField.x, g_rotField.y, g_rotField.z);
	DebugProc_Print((char*)"X����] : �� / ��\n");
	DebugProc_Print((char*)"Y����] : �p / �d\n");
	DebugProc_Print((char*)"Z����] : �� / ��\n");
	DebugProc_Print((char*)"\n");

	DebugProc_Print((char*)"�ʒu.�������Z�b�g : ENTER\n");*/
}

//=============================================================================
// �`�揈��
//=============================================================================
void Box_Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetD3DDevice();


	for (int i = 0; i < NUM_BOX; i++)
	{
		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &g_Box[i].g_mtxWorldField);

		//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���Ƀo�C���h
		pDevice->SetStreamSource(0, g_pVtxBuffField, 0, sizeof(VERTEX_3D));

		//�C���f�b�N�X�o�b�t�@�̃Z�b�g
		pDevice->SetIndices(g_pIdxBuffField);

		//���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_3D);

		//�|���S���̕`��
		pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, g_NumIndexField, 0, 12);
	}
}

//=============================================================================
// ���_�̍쐬
//=============================================================================
HRESULT MakeVertexBox(LPDIRECT3DDEVICE9 pDevice)
{
	if (FAILED(pDevice->CreateVertexBuffer(sizeof(VERTEX_3D)*NUM_VERTEX,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffField,
		NULL)))
	{
		return E_FAIL;
	}
	{
		VERTEX_3D *pVtx;

		g_pVtxBuffField->Lock(0, 0, (void**)&pVtx, 0);

		//���_���W�̐ݒ�
		//WIDTH�@X���@HEIGHT Y�� DEPTH Z��

		////���
		//pVtx[0].pos = D3DXVECTOR3(-BOX_WIDTH, BOX_HEIGHT, BOX_DEPTH);
		//pVtx[1].pos = D3DXVECTOR3(BOX_WIDTH, BOX_HEIGHT, BOX_DEPTH);
		//pVtx[2].pos = D3DXVECTOR3(-BOX_WIDTH, BOX_HEIGHT,-BOX_DEPTH);
		//pVtx[3].pos = D3DXVECTOR3(BOX_WIDTH, BOX_HEIGHT, BOX_DEPTH);
		//pVtx[4].pos = D3DXVECTOR3(BOX_WIDTH, BOX_HEIGHT, -BOX_DEPTH);
		//pVtx[5].pos = D3DXVECTOR3(-BOX_WIDTH, BOX_HEIGHT, -BOX_DEPTH);

		////����
		//pVtx[6].pos = D3DXVECTOR3(BOX_WIDTH, -BOX_HEIGHT, BOX_DEPTH);
		//pVtx[7].pos = D3DXVECTOR3(-BOX_WIDTH, -BOX_HEIGHT,BOX_DEPTH);
		//pVtx[8].pos = D3DXVECTOR3(-BOX_WIDTH, -BOX_HEIGHT,-BOX_DEPTH);
		//pVtx[9].pos = D3DXVECTOR3(-BOX_WIDTH, -BOX_HEIGHT,-BOX_DEPTH);
		//pVtx[10].pos = D3DXVECTOR3(BOX_WIDTH, -BOX_HEIGHT,-BOX_DEPTH);
		//pVtx[11].pos = D3DXVECTOR3(BOX_WIDTH, -BOX_HEIGHT, BOX_DEPTH);

		////����
		//pVtx[12].pos = D3DXVECTOR3(BOX_WIDTH, BOX_HEIGHT, BOX_DEPTH);
		//pVtx[13].pos = D3DXVECTOR3(-BOX_WIDTH, BOX_HEIGHT, BOX_DEPTH);
		//pVtx[14].pos = D3DXVECTOR3(-BOX_WIDTH, -BOX_HEIGHT, BOX_DEPTH);
		//pVtx[15].pos = D3DXVECTOR3(-BOX_WIDTH, -BOX_HEIGHT, BOX_DEPTH);
		//pVtx[16].pos = D3DXVECTOR3(BOX_WIDTH, -BOX_HEIGHT, BOX_DEPTH);
		//pVtx[17].pos = D3DXVECTOR3(BOX_WIDTH, BOX_HEIGHT, BOX_DEPTH);

		////�E��
		//pVtx[18].pos = D3DXVECTOR3(BOX_WIDTH, BOX_HEIGHT, -BOX_DEPTH);
		//pVtx[19].pos = D3DXVECTOR3(BOX_WIDTH, BOX_HEIGHT, BOX_DEPTH);
		//pVtx[20].pos = D3DXVECTOR3(BOX_WIDTH, -BOX_HEIGHT,-BOX_DEPTH);
		//pVtx[21].pos = D3DXVECTOR3(BOX_WIDTH, BOX_HEIGHT, BOX_DEPTH);
		//pVtx[22].pos = D3DXVECTOR3(BOX_WIDTH, -BOX_HEIGHT, BOX_DEPTH);
		//pVtx[23].pos = D3DXVECTOR3(BOX_WIDTH, -BOX_HEIGHT, -BOX_DEPTH);

		////����
		//pVtx[24].pos = D3DXVECTOR3(-BOX_WIDTH, BOX_HEIGHT, BOX_DEPTH);
		//pVtx[25].pos = D3DXVECTOR3(-BOX_WIDTH, BOX_HEIGHT, -BOX_DEPTH);
		//pVtx[26].pos = D3DXVECTOR3(-BOX_WIDTH, -BOX_HEIGHT, BOX_DEPTH);
		//pVtx[27].pos = D3DXVECTOR3(-BOX_WIDTH, BOX_HEIGHT, -BOX_DEPTH);
		//pVtx[28].pos = D3DXVECTOR3(-BOX_WIDTH, -BOX_HEIGHT, -BOX_DEPTH);
		//pVtx[29].pos = D3DXVECTOR3(-BOX_WIDTH, -BOX_HEIGHT, BOX_DEPTH);

		////����
		//pVtx[30].pos = D3DXVECTOR3(-BOX_WIDTH, BOX_HEIGHT, -BOX_DEPTH);
		//pVtx[31].pos = D3DXVECTOR3(BOX_WIDTH, BOX_HEIGHT, -BOX_DEPTH);
		//pVtx[32].pos = D3DXVECTOR3(-BOX_WIDTH, -BOX_HEIGHT,-BOX_DEPTH);
		//pVtx[33].pos = D3DXVECTOR3(BOX_WIDTH, BOX_HEIGHT, -BOX_DEPTH);
		//pVtx[34].pos = D3DXVECTOR3(BOX_WIDTH, -BOX_HEIGHT,-BOX_DEPTH);
		//pVtx[35].pos = D3DXVECTOR3(-BOX_WIDTH, -BOX_HEIGHT,-BOX_DEPTH);
		//
		////�@���x�N�g���̐ݒ�
		//pVtx[0].nor = D3DXVECTOR3( 0.0f,1.0f, 0.0f);
		//pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f);
		//pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f);
		//pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f);
		//pVtx[4].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[5].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//
		//pVtx[6].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[7].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[8].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[9].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[10].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[11].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//pVtx[12].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[13].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[14].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[15].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[16].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[17].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//pVtx[18].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[19].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[20].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[21].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[22].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[23].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//pVtx[24].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[25].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[26].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[27].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[28].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[29].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//pVtx[30].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[31].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[32].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[33].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[34].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		//pVtx[35].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		////���_�J���[�̐ݒ�
		//pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f,1.0f);
		//pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[4].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[5].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//pVtx[6].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[7].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[8].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[9].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[10].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[11].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//pVtx[12].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[13].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[14].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[15].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[16].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[17].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//pVtx[18].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[19].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[20].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[21].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[22].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[23].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//pVtx[24].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[25].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[26].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[27].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[28].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[29].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//pVtx[30].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[31].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[32].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[33].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[34].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		//pVtx[35].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		////�e�N�X�`�����W�̐ݒ�
		//pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		//pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		//pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		//pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
		//pVtx[4].tex = D3DXVECTOR2(1.0f, 0.0f);
		//pVtx[5].tex = D3DXVECTOR2(0.0f, 0.0f);

		//pVtx[6].tex = D3DXVECTOR2(0.0f, 0.0f);
		//pVtx[7].tex = D3DXVECTOR2(1.0f, 0.0f);
		//pVtx[8].tex = D3DXVECTOR2(0.0f, 1.0f);
		//pVtx[9].tex = D3DXVECTOR2(1.0f, 1.0f);
		//pVtx[10].tex = D3DXVECTOR2(1.0f, 0.0f);
		//pVtx[11].tex = D3DXVECTOR2(0.0f, 0.0f);

		//pVtx[12].tex = D3DXVECTOR2(0.0f, 0.0f);
		//pVtx[13].tex = D3DXVECTOR2(1.0f, 0.0f);
		//pVtx[14].tex = D3DXVECTOR2(0.0f, 1.0f);
		//pVtx[15].tex = D3DXVECTOR2(1.0f, 1.0f);
		//pVtx[16].tex = D3DXVECTOR2(1.0f, 0.0f);
		//pVtx[17].tex = D3DXVECTOR2(0.0f, 0.0f);

		//pVtx[18].tex = D3DXVECTOR2(0.0f, 0.0f);
		//pVtx[19].tex = D3DXVECTOR2(1.0f, 0.0f);
		//pVtx[20].tex = D3DXVECTOR2(0.0f, 1.0f);
		//pVtx[21].tex = D3DXVECTOR2(1.0f, 1.0f);
		//pVtx[22].tex = D3DXVECTOR2(1.0f, 0.0f);
		//pVtx[23].tex = D3DXVECTOR2(0.0f, 0.0f);

		//pVtx[24].tex = D3DXVECTOR2(0.0f, 0.0f);
		//pVtx[25].tex = D3DXVECTOR2(1.0f, 0.0f);
		//pVtx[26].tex = D3DXVECTOR2(0.0f, 1.0f);
		//pVtx[27].tex = D3DXVECTOR2(1.0f, 1.0f);
		//pVtx[28].tex = D3DXVECTOR2(1.0f, 0.0f);
		//pVtx[29].tex = D3DXVECTOR2(0.0f, 0.0f);

		//pVtx[30].tex = D3DXVECTOR2(0.0f, 0.0f);
		//pVtx[31].tex = D3DXVECTOR2(1.0f, 0.0f);
		//pVtx[32].tex = D3DXVECTOR2(0.0f, 1.0f);
		//pVtx[33].tex = D3DXVECTOR2(1.0f, 1.0f);
		//pVtx[34].tex = D3DXVECTOR2(1.0f, 0.0f);
		//pVtx[35].tex = D3DXVECTOR2(0.0f, 0.0f);

		pVtx[0].pos = D3DXVECTOR3(-BOX_WIDTH, BOX_HEIGHT, -BOX_DEPTH);
		pVtx[1].pos = D3DXVECTOR3(BOX_WIDTH, BOX_HEIGHT, -BOX_DEPTH);
		pVtx[2].pos = D3DXVECTOR3(-BOX_WIDTH, -BOX_HEIGHT, -BOX_DEPTH);
		pVtx[3].pos = D3DXVECTOR3(BOX_WIDTH, -BOX_HEIGHT, -BOX_DEPTH);
		pVtx[4].pos = D3DXVECTOR3(BOX_WIDTH, -BOX_HEIGHT, BOX_DEPTH);
		pVtx[5].pos = D3DXVECTOR3(-BOX_WIDTH, -BOX_HEIGHT, BOX_DEPTH);
		pVtx[6].pos = D3DXVECTOR3(BOX_WIDTH, BOX_HEIGHT, BOX_DEPTH);
		pVtx[7].pos = D3DXVECTOR3(-BOX_WIDTH, BOX_HEIGHT, BOX_DEPTH);

		pVtx[0].nor = D3DXVECTOR3(-1.0f, 1.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(1.0f, 1.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(1.0f, -1.0f, -1.0f);
		pVtx[4].nor = D3DXVECTOR3(1.0f, -1.0f, 1.0f);
		pVtx[5].nor = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
		pVtx[6].nor = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
		pVtx[7].nor = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);

		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[4].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[5].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[6].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[7].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
		pVtx[4].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[5].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[6].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[7].tex = D3DXVECTOR2(1.0f, 1.0f);

		g_pVtxBuffField->Unlock();
	}

	if (FAILED(pDevice->CreateIndexBuffer(sizeof(WORD) * 8,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&g_pIdxBuffField,
		NULL)))
	{
		return E_FAIL;
	}

	{
		WORD *pIdx;

		g_pIdxBuffField->Lock(0, 0, (void**)&pIdx, 0);

		//�O��
		pIdx[0] = 4;
		pIdx[1] = 1;
		pIdx[2] = 5;
		pIdx[3] = 1;
		pIdx[4] = 6;
		pIdx[5] = 2;


		pIdx[6] = 7;
		pIdx[7] = 3;
		pIdx[8] = 0;
		pIdx[9] = 6;
		pIdx[10] = 1;
		pIdx[11] = 0;

		//�E
		pIdx[12] = 1;
		pIdx[13] = 6;
		pIdx[14] = 3;
		pIdx[15] = 6;
		pIdx[16] = 4;
		pIdx[17] = 3;

		//��
		pIdx[18] = 3;
		pIdx[19] = 2;
		pIdx[20] = 4;
		pIdx[21] = 2;
		pIdx[22] = 5;
		pIdx[23] = 4;

		//��
		pIdx[24] = 2;
		pIdx[25] = 5;
		pIdx[26] = 0;
		pIdx[27] = 7;
		pIdx[28] = 0;
		pIdx[29] = 5;

		//�w��
		pIdx[30] = 5;
		pIdx[31] = 4;
		pIdx[32] = 7;
		pIdx[33] = 6;
		pIdx[34] = 7;
		pIdx[35] = 4;

		g_pIdxBuffField->Unlock();
	}


	return S_OK;

}


void Character::Draw()
{
}
