/*=====================================================

	[BeseScene.h]
	Author : �o���đ�

======================================================*/

#pragma once
#include "main.h"

//#	BaseScene�N���X : �e�N���X
class BaseScene
{
public:
	virtual ~BaseScene() {};
	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};
