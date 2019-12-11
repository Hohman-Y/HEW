/*==================================
	
	[texture.h]
	Author : �o���đ�

==================================*/

#pragma once
#include <d3d9.h>

//�񋓌^�F�e�N�X�`���̎w��
typedef enum
{
	TEXTURE_INDEX_RESULT,
	TEXTURE_INDEX_MODESELECT,
	TEXTURE_INDEX_QUIZSAMPLE,
	TEXTURE_INDEX_SCENE_TUTORIAL,
	TEXTURE_INDEX_SCENE_GAME,

    TEXTURE_INDEX_MAX
}TextureIndex;

int Texture_Load();			//�e�N�X�`���̃��[�h					
void Texture_Release();		//�e�N�X�`���̃����[�X
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index);	//�e�N�X�`���I�u�W�F�N�g���摜�t�@�C������ǂݍ��ފ֐�
int Texture_GetWidth(TextureIndex index);		//�e�N�X�`���̉���
int Texture_GetHeight(TextureIndex index);		//�e�N�X�`���̏c��
