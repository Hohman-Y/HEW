/*==================================
	
	[sprite.h]
	Author : �o���đ�

=================================*/

#pragma once
#include <d3d9.h>
#include "texture.h"

//Sprite�N���X
class Sprite
{
private:
	static LPDIRECT3DVERTEXBUFFER9	m_VertexBuffer;	//	���_�o�b�t�@
	static LPDIRECT3DINDEXBUFFER9	m_pIndexBuffer;	//	�C���f�b�N�X�o�b�t�@
	static LPDIRECT3DDEVICE9		pDevice;		//	�f�o�C�X
public:
	void SetColor(D3DCOLOR color);	//	�J���[�̐ݒ�		
	//!	Draw�֐��̃I�[�o�[���[�h
	//	�`�� (�����F�e�N�X�`���AX���W�AY���W)
	void Draw(TextureIndex texture_index, float dx, float dy);	
	//	�`�� (�����F�e�N�X�`���AX���W�AY���W�A�e�N�X�`��X���W�A�e�N�X�`��Y���W�A�e�N�X�`���̉����A�e�N�X�`���̏c��)
	void Draw(TextureIndex texture_index, float dx, float dy, int tx, int ty, int tw, int th);
	//	�`�� (�����F�e�N�X�`���AX���W�AY���W�A�e�N�X�`��X���W�A�e�N�X�`��Y���W�A�e�N�X�`���̉����A�e�N�X�`���̏c���A�e�N�X�`���̒��S���W�A�g��k���A��])
	void Draw(TextureIndex texture_index, float dx, float dy, int tx, int ty, int tw, int th, float cx, float cy, float sx, float sy, float rotation);
};