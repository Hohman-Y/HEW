/*============================================

	[Character.h]
	Author : �o���đ�

=============================================*/

#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Model.h"

class Model;
//#	Character�N���X
/* �L�����N�^�[�̏����Ǘ�����N���X�@*/
class Character
{
private:
	D3DXVECTOR3 Position;			//	�ʒu
	Model		*pModel;			//	Model�^�|�C���^�ϐ�
	static LPDIRECT3DDEVICE9 g_pD3DDevice;	//	�f�o�C�X	
public:
	static void Init();
	static void Uninit();
	static void Update();
	static void Draw();
	
};

