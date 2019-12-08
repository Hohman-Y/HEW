/*=================================================

	[Character.h]
	Author : �o���đ�

=================================================*/

#pragma once
#include "main.h"
#include "Model.h"
#include "XFile.h"

//	�v���C���[�̃X�e�[�g�}�V���Ǘ��ϐ�
enum PlayerState
{
	PLAYER_INIT,		//	������
	PLAYER_STRAT,		//	�X�^�[�g
	PlAYER_ANSWERSTAY,	//	�𓚂܂�
	PLAYER_ANSWER,		//	��
	PLAYER_JUMP,		//	�W�����v
	PLAYER_END			//	�I��
};

class Character
{
private:
	static LPDIRECT3DTEXTURE9	m_pTexture;	//	�e�N�X�`���ւ̃|�C���^
	static LPD3DXMESH			m_pMesh;	//	���b�V�����ւ̃|�C���^
	static LPD3DXBUFFER			m_pBuffMat;	//	�}�e���A�����ւ̃|�C���^
	static DWORD				m_nNumMat;	//	�}�e���A�����̑���
	static D3DXMATRIX			m_mtxWorld;	//	���[���h�}�g���b�N�X
	LPDIRECT3DDEVICE9			m_pDevice;	//	�f�o�C�X
	D3DXVECTOR3					m_position;	//	���݂̈ʒu
	D3DXVECTOR3					m_rotation;	//	���݂̌���
	D3DXVECTOR3					m_rotDest;	//	�ړI�̌���
	D3DXVECTOR3					m_velocity;	//	�ړ���
	int							m_count;	//	��萔�̃J�E���^�[
	float						m_gravity;	//	�d��	
	PlayerState					m_state;	//	�X�e�[�g�ϐ�
	XFile						m_XFile;
	Model						m_Model;

public:
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot);	//	����������
	void Uninit();									//	�I������
	void Update();									//	�X�V����
	void Draw();									//	�`�揈��
	//	�Q�b�^�[
	D3DXVECTOR3	GetPos();							
	D3DXVECTOR3	GetRot();
	D3DXVECTOR3	GetMove();
	D3DXMATRIX	GetMat();
	LPD3DXMESH	GetMesh();
private:
	//	�X�e�[�g�֐�
	void Strat();								//	�X�^�[�g
	void Answerstay();							//	�𓚂܂�
	void Answer();								//	��
	void Jump();								//	�W�����v
	void End();									//	�I��
};

