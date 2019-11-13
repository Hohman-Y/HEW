/*========================================================

	[Map.h]
	Author : �o���đ�

=========================================================*/

#pragma once
#include "Field.h"
#include "Model.h"

//	�}�N����`
#define ACTOR_NUM 1	// 3D���f���̐�

//# Map�N���X
/* �}�b�v���Ǘ�����N���X */
class Map
{
private:
	static Model *Actor[ACTOR_NUM];		//	Model�^�|�C���^�z��
	static Field *pField[1];				//	Field�^�|�C���^
public:
	static void Init();
	static void Uninit();
	static void Draw();
};

