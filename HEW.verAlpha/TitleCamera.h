/*=================================================

	[TitleCamera.h]
	Author : �o���đ�

=================================================*/

#pragma once
#include "Camera.h"

//# TitleCamera�N���X : ���N���XCamera�̔h�� 
/*  */
class TitleCamera :public Camera
{
public:
	TitleCamera();
	~TitleCamera();
	void Init();
	void Uninit();
	void Update();
	void Set();
};

