/*========================================================

	[Map.h]
	Author : �o���đ�

=========================================================*/

#pragma once
#include "Model.h"

//	�}�N����`
#define ACTOR_NUM 1	// 3D���f���̐�

//# Map�N���X
/* �}�b�v���Ǘ�����N���X */
class Map
{
private:
	static Model *Actor[ACTOR_NUM];		//	Model�^�|�C���^�z��
public:
	void Init();
	void Uninit();
	void Draw();
};

