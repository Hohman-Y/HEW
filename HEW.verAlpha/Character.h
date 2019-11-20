/*============================================

	[Character.h]
	Author : 

=============================================*/

#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Model.h"

//#	Character�N���X
/* �L�����N�^�[�̏����Ǘ�����N���X�@*/
class Character
{
private:
	static Model *Actor[1];
	D3DXVECTOR3	position;					//	�ʒu
	D3DXVECTOR3	scale;						//	�傫��
	D3DXVECTOR3	angle;						//	��]
	D3DXVECTOR3 Velocity;					//	���x
	XFile *pmodel;							//	XFile�^�|�C���^�ϐ�
	static LPDIRECT3DDEVICE9 g_pD3DDevice;	//	�f�o�C�X
public:
	static void Init();
	static void Uninit();
	static void Update();
	static void Draw();
};

