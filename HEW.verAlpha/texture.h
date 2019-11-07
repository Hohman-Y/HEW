/*==================================
	
	[texture.h]
	Author : �o���đ�

==================================*/

//!	���̃\�[�X�R�[�h�͎g��Ȃ��I

#pragma once

//�C���N���[�h�t�@�C��
#include <d3d9.h>

//�񋓌^�F�e�N�X�`���̎w��
typedef enum
{
	TEXTURE_INDEX_YUKIDARUMA,
	TEXTURE_INDEX_BULLET,
	TEXTURE_INDEX_LASER,
	TEXTURE_INDEX_EXPLOSION,
	TEXTURE_INDEX_NUMBER,
	TEXTURE_INDEX_TITLE,
	TEXTURE_INDEX_RESULT,
	TEXTURE_INDEX_TILEMAP,
	TEXTURE_INDEX_SOUSA,
	TEXTURE_INDEX_RULE,

    TEXTURE_INDEX_MAX
}TextureIndex;

int Texture_Load();			//�e�N�X�`���̃��[�h					
void Texture_Release();		//�e�N�X�`���̃����[�X
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index);	//�e�N�X�`���I�u�W�F�N�g���摜�t�@�C������ǂݍ��ފ֐�
int Texture_GetWidth(TextureIndex index);		//�e�N�X�`���̉���
int Texture_GetHeight(TextureIndex index);		//�e�N�X�`���̏c��
