/*=================================================

	[Character.cpp]
	Author : �o���đ�

=================================================*/

#include "Controller.h"
#include "Character.h"
#include "CharacterCamera.h"
#include "debugproc.h"
#include "Collision.h"
#include "SceneManager.h"
#include "Collision.h"
#include "Field.h"
#include "SceneGame.h"
#include "ObjectManager.h"

//	�}�N����`
#define	VALUE_MOVE_MODEL	(0.5f)					// �ړ����x
#define	RATE_MOVE_MODEL		(0.2f)					// �ړ������W��
#define	VALUE_ROTATE_MODEL	(D3DX_PI * 0.05f)		// ��]���x
#define	RATE_ROTATE_MODEL	(0.2f)					// ��]�����W��

// �X�^�e�B�b�N�ϐ�
LPDIRECT3DTEXTURE9	Character::m_pTexture = NULL;	//	�e�N�X�`���ւ̃|�C���^
LPD3DXMESH			Character::m_pMesh	= NULL;		//	���b�V�����ւ̃|�C���^
LPD3DXBUFFER		Character::m_pBuffMat = NULL;	// �}�e���A�����ւ̃|�C���^
DWORD				Character::m_nNumMat;			//	�}�e���A�����̑���
D3DXMATRIX			Character::m_mtxWorld;			//	���[���h�}�g���b�N�X
int					Character::m_count;				//	��萔�̃J�E���^�[

//	����������
HRESULT Character::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	m_pDevice = GetD3DDevice();

	//X�t�@�C���̓ǂݍ���
	if (FAILED(D3DXLoadMeshFromX("asset/model/ri.x", D3DXMESH_SYSTEMMEM, m_pDevice, NULL, &m_pBuffMat, NULL, &m_nNumMat, &m_pMesh)))
	{
		return E_FAIL;
	}
	
	///	<summary>
	///	�ϐ��̏�����
	///	</summary>
	m_position = pos;	//	�ʒu
	m_rotation = rot;	//	����
	m_rotDest = rot;	//	�ړI�̌���
	m_velocity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�x�N�g��
	m_grivity = 0.7f;
	m_pCamera = new CharacterCamera;
	m_count = 0;
	m_score = 0;

	return S_OK;
}

//	�I������
void Character::Uninit()
{
	delete m_pCamera;
	SAFE_RELEASE(m_pBuffMat);
	SAFE_RELEASE(m_pMesh);
	SAFE_RELEASE(m_pTexture);
}

//	�X�V����
void Character::Update()
{
	// �J�����̎擾
	m_pCamera = GetCharCam();

	if (KeyBoard::IsPress(DIK_D) || GamePad::IsPress(0, LEFTSTICK_LEFT))
	{
		if (KeyBoard::IsPress(DIK_W) || GamePad::IsPress(0, LEFTSTICK_UP))
		{// �����ړ�
			m_velocity.x += sinf(-D3DX_PI * 0.75f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(-D3DX_PI * 0.75f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;

			m_rotDest.y = m_pCamera->rot.y + D3DX_PI * 0.75f;
		}
		else if (KeyBoard::IsPress(DIK_S) || GamePad::IsPress(0, LEFTSTICK_DOWN))
		{// ����O�ړ�
			m_velocity.x += sinf(-D3DX_PI * 0.25f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(-D3DX_PI * 0.25f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;

			m_rotDest.y = m_pCamera->rot.y + D3DX_PI * 0.25f;
		}
		else
		{// ���ړ�
			m_velocity.x += sinf(-D3DX_PI * 0.50f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(-D3DX_PI * 0.50f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;

			m_rotDest.y = m_pCamera->rot.y + D3DX_PI * 0.50f;
		}
	}
	else if (KeyBoard::IsPress(DIK_A) || GamePad::IsPress(0, LEFTSTICK_RIGHT))
	{
		if (KeyBoard::IsPress(DIK_W) || GamePad::IsPress(0, LEFTSTICK_UP))
		{// �E���ړ�
			m_velocity.x += sinf(D3DX_PI * 0.75f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(D3DX_PI * 0.75f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;

			m_rotDest.y = m_pCamera->rot.y - D3DX_PI * 0.75f;
		}
		else if (KeyBoard::IsPress(DIK_S) || GamePad::IsPress(0, LEFTSTICK_DOWN))
		{// �E��O�ړ�
			m_velocity.x += sinf(D3DX_PI * 0.25f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(D3DX_PI * 0.25f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;

			m_rotDest.y = m_pCamera->rot.y - D3DX_PI * 0.25f;
		}
		else
		{// �E�ړ�
			m_velocity.x += sinf(D3DX_PI * 0.50f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(D3DX_PI * 0.50f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;

			m_rotDest.y = m_pCamera->rot.y - D3DX_PI * 0.50f;
		}
	}
	else if (KeyBoard::IsPress(DIK_S) || GamePad::IsPress(0, LEFTSTICK_UP))
	{// �O�ړ�
		m_velocity.x += sinf(D3DX_PI * 1.0f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
		m_velocity.z -= cosf(D3DX_PI * 1.0f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;

		m_rotDest.y = m_pCamera->rot.y + D3DX_PI * 1.0f;
	}
	else if (KeyBoard::IsPress(DIK_W) || GamePad::IsPress(0, LEFTSTICK_DOWN))
	{// ��ړ�
		m_velocity.x += sinf(D3DX_PI * 0.0f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
		m_velocity.z -= cosf(D3DX_PI * 0.0f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;

		m_rotDest.y = m_pCamera->rot.y + D3DX_PI * 0.0f;
	}

	if (KeyBoard::IsPress(DIK_Q) || GamePad::IsPress(0, PS4RIGHTSTICK_LEFT))
	{// ����]
		m_rotDest.y -= VALUE_ROTATE_MODEL;
		if (m_rotDest.y < -D3DX_PI)
		{
			m_rotDest.y += D3DX_PI * 2.0f;
		}
	}
	if (KeyBoard::IsPress(DIK_E) || GamePad::IsPress(0, PS4RIGHTSTICK_RIGHT))
	{// �E��]
		m_rotDest.y += VALUE_ROTATE_MODEL;
		if (m_rotDest.y > D3DX_PI)
		{
			m_rotDest.y -= D3DX_PI * 2.0f;
		}
	}
	float fDiffRotY;
	// �ړI�̊p�x�܂ł̍���
	fDiffRotY = m_rotDest.y - m_rotation.y;
	if (fDiffRotY > D3DX_PI)
	{
		fDiffRotY -= D3DX_PI * 2.0f;
	}
	if (fDiffRotY < -D3DX_PI)
	{
		fDiffRotY += D3DX_PI * 2.0f;
	}

	// �ړI�̊p�x�܂Ŋ�����������
	m_rotation.y += fDiffRotY * RATE_ROTATE_MODEL;
	if (m_rotation.y > D3DX_PI)
	{
		m_rotation.y -= D3DX_PI * 2.0f;
	}
	if (m_rotation.y < -D3DX_PI)
	{
		m_rotation.y += D3DX_PI * 2.0f;
	}

	// �ʒu�ړ�
	m_position.x += m_velocity.x;
	m_position.z += m_velocity.z;

	// �ړ��ʂɊ�����������
	m_velocity.x += (0.0f - m_velocity.x) * RATE_MOVE_MODEL;
	m_velocity.z += (0.0f - m_velocity.z) * RATE_MOVE_MODEL;

	/// <summary>�����蔻��</summary>
#if 0	
	// �����蔻��
	FLOAT fDistance = 0;
	D3DXVECTOR3 vNormal;

	if (m_Col.Collide(m_position, m_velocity, &m_XFile, &m_Model, &fDistance, &vNormal) && fDistance <= 0.3)
	{
		//�������ԂȂ̂ŁA���点��
		m_velocity = m_Col.Slip(m_velocity, vNormal);//����x�N�g�����v�Z

		//����x�N�g����̒n�ʓˋN�Ƃ̃��C���� �Q�d�ɔ���	
		if (m_Col.Collide(m_position, m_velocity, &m_XFile, &m_Model, &fDistance, &vNormal) && fDistance <= 0.2)
		{
			//�Q�i�ڂ̓������ԂȂ̂ŁA���点�� �����炭�オ�����		
			m_velocity = m_Col.Slip(m_velocity, vNormal);//����x�N�g�����v�Z
		}
		DebugProc_Print((char*)"�������Ă���");
		m_position += m_velocity;
	}

	//pos = m_Character.GetMove();
	//move = m_Character.GetMove();



	DebugProc_Print((char*)"Character [%f : %f : %f]\n", m_position.x, m_position.y, m_position.z);
	DebugProc_Print((char*)"\n");
#endif

	DebugProc_Print((char*)"%f,%f,%f",m_position.x,m_position.y,m_position.z);

	//RenderRay(m_pDevice, m_position, m_velocity);
	//m_position.y -= m_grivity;
	/// <summary> �����蔻��

	FLOAT fDistance=0;
	D3DXVECTOR3 vNormal;
	Field *field = ObjectManager::SetField();

	//	�d�͂�������
	if (KeyBoard::IsPress(DIK_SPACE))
	{
		m_position.y -= m_grivity;
	}

	if (KeyBoard::IsPress(DIK_Q))
	{
		m_position.y += m_grivity;
	}

	//m_position.y = -0.7f;
	if( Collision::Collide(m_position,m_velocity, field,&fDistance,&vNormal) && fDistance<=0.3)
	{
		//�������ԂȂ̂ŁA���点��
		m_velocity= Collision::Slip(m_velocity,vNormal);//����x�N�g�����v�Z

		//����x�N�g����̒n�ʓˋN�Ƃ̃��C���� �Q�d�ɔ���	
		if(Collision::Collide(m_position,m_velocity,field,&fDistance,&vNormal)&& fDistance<=0.2 )
		{				
			//�Q�i�ڂ̓������ԂȂ̂ŁA���点�� �����炭�オ�����		
			m_velocity= Collision::Slip(m_velocity,vNormal);//����x�N�g�����v�Z
		}		
	}
	//m_position.y = -0.7f;
	//���{�b�g�@�ʒu�X�V
	m_position += m_velocity;	

	///	<summary> 
	///	�X�e�[�g
	///	�����蔻�肪����������A���s
	///</summary>
#if 0
	//	�X�e�[�g
	switch (m_PlayerState)
	{
	case PLAYER_INIT:
		InitState();
		break;
	case PLAYER_MOVE:
		MoveState();
		break;
	case PlAYER_ANSWERSTAY:
		AnswerstayState();
		break;
	case PLAYER_ANSWER: 
		AnswerState();
		break;
	case PLAYER_JUMP:
		JumpState();
		break;
	case PLAYER_END:
		EndState();
		break;
	}
#endif // 0
}

//	�`�揈��
void Character::Draw()
{
	m_pDevice = GetD3DDevice();
	D3DXMATRIX mtxRot, mtxTranslate;
	D3DXMATERIAL *pD3DXMat;
	D3DMATERIAL9 matDef;

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//��]�𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rotation.y, m_rotation.x, m_rotation.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//�ړ��𔽉f
	D3DXMatrixTranslation(&mtxTranslate, m_position.x, m_position.y, m_position.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTranslate);

	//���[���h�}�g���b�N�X�̐ݒ�
	m_pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���݂̃}�e���A�����擾
	m_pDevice->GetMaterial(&matDef);

	//�}�e���A�����ɑ΂���|�C���^���擾
	pD3DXMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_nNumMat; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		m_pDevice->SetMaterial(&pD3DXMat[nCntMat].MatD3D);
		//�e�N�X�`���̐ݒ�
		m_pDevice->SetTexture(0, m_pTexture);
		//�`��
		m_pMesh->DrawSubset(nCntMat);

	}
	//�}�e���A�����f�t�H���g�ɖ߂�
	m_pDevice->SetMaterial(&matDef);
}

//!	�Q�b�^�[
//	�ʒu�̃Q�b�^�[
D3DXVECTOR3 Character::GetPos()
{
	return m_position;
}

//	��]�̃Q�b�^�[
D3DXVECTOR3 Character::GetRot()
{
	return m_rotation;
}

//	�ړ��̃Q�b�^�[
D3DXVECTOR3 Character::GetMove()
{
	return m_velocity;
}

//	�}�g���N�X�̃Q�b�^�[
D3DXMATRIX Character::GetMat()
{
	return m_mtxWorld;
}

//	���b�V���̃Q�b�^�[
LPD3DXMESH Character::GetMesh()
{
	return  m_pMesh;
}

//	�X�R�A�̃Q�b�^�[
int Character::Score()
{
	return m_score;
}

//	�X�e�[�g�̏�����
void Character::InitState()
{
	//!	�J�E���g�_�E��

	//if (�J�E���g���[���ɂȂ�����)
	{
		m_PlayerState = PLAYER_MOVE;
	}
}

//	�v���C���[�̃X�^�[�g
void Character::MoveState()
{
	/// <summary> �ړ��̏����@</summary>
	m_velocity.x += sinf(D3DX_PI * 0.0f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
	m_velocity.z -= cosf(D3DX_PI * 0.0f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
	m_rotDest.y = m_pCamera->rot.y + D3DX_PI * 0.0f;
	
	m_position.y -= m_velocity.y;	//	�d�͂̒l�����Z���
	m_position.z += m_velocity.z;
	m_velocity.z += (0.0f - m_velocity.z) * RATE_MOVE_MODEL;	//	����
	
	/// <summary>
	/// �֐��̌Ăяo���񐔂𐔂���
	///	</summary>
	m_count++;
	if (m_count >= 3)	//	4��ڂȂ�W�����v
	{
		m_PlayerState = PLAYER_JUMP;
	}
	else
	{
		m_PlayerState = PlAYER_ANSWERSTAY;
	}
}

void Character::AnswerstayState()
{
	float fDiffRotY;
	switch (m_AnsawerStayState)
	{
	case ANSWER_DROW:
		//!	��蕶�̕`��
		
		//!if ( ���̑I�o�A�`�悪���������� )
		{
			m_AnsawerStayState = ANSWER_SELECT;
		}
		break;

	case ANSWER_SELECT:

		//!	�J�E���g�_�E�����J�n

		//	�ړ�
		if (KeyBoard::IsPress(DIK_A) || GamePad::IsPress(0,LEFTSTICK_RIGHT))
		{
			m_velocity.x += sinf(D3DX_PI * 0.50f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(D3DX_PI * 0.50f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_rotDest.y = m_pCamera->rot.y - D3DX_PI * 0.50f;
		}
		if (KeyBoard::IsPress(DIK_D) || GamePad::IsPress(0, LEFTSTICK_LEFT))
		{
			m_velocity.x += sinf(-D3DX_PI * 0.50f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_velocity.z -= cosf(-D3DX_PI * 0.50f - m_pCamera->rot.y) * VALUE_MOVE_MODEL;
			m_rotDest.y = m_pCamera->rot.y + D3DX_PI * 0.50f;
		}
		m_position.x += m_velocity.x;	//	x���W�����ړ������Ȃ�

		//!if ( �J�E���g�_�E�����I�������� )
		{
			m_PlayerState = PLAYER_ANSWER;
		}
		break;

	}
}

void Character::AnswerState()
{
	/// <sumamry>
	///	�����蔻��̓R���W�����̃��^�[���t���O�Ŕ��ʂ���
	///	</summaey>
	//!if ( ���� )
	{
		//	�X�s�[�h�␳
		m_velocity.z *= 1.05f;
	}
	//!else	�s����
	{
		//	�������Ȃ�
	}
	m_PlayerState = PLAYER_MOVE;
}

void Character::JumpState()
{
	/// <summary>
	///	�֐������s���Ă���ԁA�X�V���� 
	///	60FPS = 1 �̍X�V���x
	///	</summary>
	m_score++;
	//!if ( �n�ʂɒ�������@= y�̍��W�l)
	{
		m_PlayerState = PLAYER_END;
	}
}

void Character::EndState()
{
	//!	�򋗗��̕`��

	//! if ( ���΂炭�������� )
	{
		SceneManager::ChangeSceneState();
	}
}
