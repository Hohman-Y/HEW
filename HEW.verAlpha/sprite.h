/*==================================
	
	[sprite.h]
	Author : �o���đ�

=================================*/

//!	���̃\�[�X�R�[�h�͎g��Ȃ��I

#pragma once

//�C���N���[�h�t�@�C��
#include <d3d9.h>
#include "texture.h"

//SPRITE�N���X
class SPRITE
{
public:
	//�����o�֐�
	static void SetColor(D3DCOLOR color);		
	static void Draw(TextureIndex texture_index, float dx, float dy);
	static void Draw(TextureIndex texture_index, float dx, float dy, int tx, int ty, int tw, int th);
	static void Draw(TextureIndex texture_index, float dx, float dy, int tx, int ty, int tw, int th, float cx, float cy, float sx, float sy, float rotation);
};