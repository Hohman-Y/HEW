/*===========================================================
	
	[Drawer.h]
	Author : �o���đ�

============================================================*/

#pragma once
#include "Model.h"

//#	Drawer�N���X
/* ���f����`�悷��N���X */
class Drawer: public Model
{
private:
	D3DXVECTOR3	position;
	D3DXVECTOR3	scale;
	D3DXVECTOR3	angle;
	Model *pmodel;

public:
	Drawer(D3DXVECTOR3	position,D3DXVECTOR3 scale,D3DXVECTOR3 angle,Model *pmodel) :position(position), scale(scale), angle(angle), pmodel(pmodel){}
	void Draw();
};

