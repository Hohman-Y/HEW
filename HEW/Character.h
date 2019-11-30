/*============================================

[Character.h]
Author : hohman yuushi

=============================================*/

#pragma once
#include "main.h"
#include "CharacterCamera.h"
#include "Model.h"
#include <d3d9types.h>
#include <d3dx9tex.h>




//#	�L�����N�^�[�N���X :�@�e�N���X

class XFile;

/* �L�����N�^�[�̏����Ǘ�����N���X�@*/
class Character
{
private:
	//CharacterCamera m_Camera;	//	�L�����N�^�[�ɂ���J�����̃C���X�^���X
	static LPDIRECT3DTEXTURE9	m_pTextureModel;	// �e�N�X�`���ւ̃|�C���^
	static LPD3DXMESH			m_pMeshModel;		// ���b�V�����ւ̃|�C���^
	static LPD3DXBUFFER			m_pBuffMatModel;	// �}�e���A�����ւ̃|�C���^
	static DWORD				m_nNumMatModel;		// �}�e���A�����̑���
	static LPDIRECT3DDEVICE9	pDevice;
	static float				m_Velocity;
	D3DXMATRIX			mtxWorldModel;		// ���[���h�}�g���b�N�X
	D3DXVECTOR3			posModel;			// ���݂̈ʒu
	D3DXVECTOR3			rotModel;			// ���݂̌���
	D3DXVECTOR3			rotDestModel;		// �ړI�̌���
public:
	D3DXVECTOR3			moveModel;			// �ړ���
	

public:
	Character();
	~Character();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	void Uninit();
	void Update();
	void Draw();
};


/*
	//X�t�@�C���I�u�W�F�N�g�N���X
	class XFileObject
	{
		LPD3DXMESH	m_pMesh;
		DWORD		m_dwNumMaterials;

		LPDIRECT3DTEXTURE9*	m_ppTextures;
		D3DMATERIAL9*		m_pMatrs;

	public:
		XFileObject()
		{
			m_pMesh = NULL;
			m_dwNumMaterials = 0;
			m_ppTextures = NULL;
			m_pMatrs = NULL;

		}

		bool LoadXFile(LPCWSTR file);
		void Render();

		void Release();
	};
*/

	//�`��֘A�N���X
	class CGraphic
	{
		enum DisplayMode {
			FullScreen,
			WindowMode,
		};

		DisplayMode	m_currDisplayMode;//��ʃ��[�h
		DWORD		m_backColor;//�w�i�F

	public:
		CGraphic();
		~CGraphic();

		//�����Ɣj��
		bool Create(HWND hWnd);
		void Destroy();

		void ClearAndBegin();//Draw�O�ɌĂ�
		void EndAndPresent();//Draw��ɌĂ�
	};


	//CGraphic�N���X�̐����Ɣj���͂���ōs���B
	CGraphic*	CreateGraphic(HWND hWnd);
	CGraphic*	GetGraphic();
	void		ReleaseGraphic();