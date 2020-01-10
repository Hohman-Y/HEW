/*=================================================

	[Character.h]
	Author : �o���đ�

=================================================*/

#pragma once
#include "main.h"
#include "CharacterCamera.h"
#include "Field.h"

///	<summary>
///	�v���C���[�̃X�e�[�g�}�V�����Ǘ�����
/// </summary>
enum PlayerState
{
	PLAYER_INIT,		//	������
	PLAYER_MOVE,		//	�ړ�
	PlAYER_ANSWERSTAY,	//	�𓚂܂�
	PLAYER_ANSWER,		//	��
	PLAYER_JUMP,		//	�W�����v
	PLAYER_END			//	�I��
};

///	<summary>
///	��蕶�̕`��A�𓚑I���Ȃǂ̃X�e�[�g�}�V�����Ǘ� 
///	</summary>
enum AnswerStayState
{
	ANSWER_DROW,
	ANSWER_SELECT,
};

///	<summary>
///	�L�����N�^�[�̊Ǘ�������N���X
/// </summary>
class Character
{
public:
	static LPDIRECT3DTEXTURE9	m_pTexture;	//	�e�N�X�`���ւ̃|�C���^
	static LPD3DXMESH			m_pMesh;	//	���b�V�����ւ̃|�C���^
	static LPD3DXBUFFER			m_pBuffMat;	//	�}�e���A�����ւ̃|�C���^
	static DWORD				m_nNumMat;	//	�}�e���A�����̑���
	static D3DXMATRIX			m_mtxWorld;	//	���[���h�}�g���b�N�X
	static int					m_count;	//	��萔�̃J�E���^�[
	LPDIRECT3DDEVICE9			m_pDevice;	//	�f�o�C�X
	D3DXVECTOR3					m_position;	//	���݂̈ʒu
	D3DXVECTOR3					m_rotation;	//	���݂̌���
	D3DXVECTOR3					m_rotDest;	//	�ړI�̌���
	D3DXVECTOR3					m_scale;	//	���f���̑傫��
	D3DXVECTOR3					m_velocity;	//	�ړ���
	float						m_grivity;	//	�d��
	int							m_score;	
	/// <summary>
	///	�v���C���[�Ɋւ���X�e�[�g�p�����o�[�ϐ�
	///	</summary>
	PlayerState					m_PlayerState;	
	///	<summary>
	///	�𓚂܂����ɉ񂷃X�e�[�g�p�ϐ�
	///	</summary>
	AnswerStayState				m_AnsawerStayState;
	CharacterCamera				*m_pCamera;
public:
	///	<summary>
	///	����������
	/// </summary>
	/// <return> �����ʒu�A�������� </return>
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	void Uninit();								
	void Update();								
	void Draw();								
	
	//	�Q�b�^�[
	D3DXVECTOR3	GetPos();	///	<return> m_position </return>
	D3DXVECTOR3	GetRot();	///	<return> m_rotation </return>
	D3DXVECTOR3	GetMove();	///	<return> m_velocity </return>
	D3DXMATRIX	GetMat();	///	<return> m_mtxworld </return>
	LPD3DXMESH	GetMesh();	///	<return> m_pMesh </return>
	int			Score();	///	<return> m_score </return

private:
	//	�X�e�[�g�֐�
	void InitState();			//	������
	void MoveState();			//	�X�^�[�g
	void AnswerstayState();		//	�𓚂܂�
	void AnswerState();			//	��
	void JumpState();			//	�W�����v
	void EndState();			//	�I��
};

