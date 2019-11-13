/*==================================
	
	[texture.cpp]
	Author : �o���đ�

==================================*/

//!	���̃\�[�X�R�[�h�͎g��Ȃ��I

//�C���N���[�h�t�@�C��
#include <d3dx9.h>
#include "main.h"
#include "texture.h"

//�}�N����`
#define TEXTURE_FILENAME_MAX (64)	//�t�@�C���̕�����

//TEXTURE�N���X
class TEXTURE
{
public:
	char filename[TEXTURE_FILENAME_MAX];	//�t�@�C����
	int width;								//�e�N�X�`���̉���
	int height;								//�e�N�X�`���̏c��
};

//�e�N�X�`���t�@�C���̈ꗗ
static const TEXTURE g_TextureFiles[] = 
{
    { "asset/texture/yukidaruma.tga"	, 256 , 256 },
	{ "asset/texture/bullet00.png"		, 32  , 32  },
	{ "asset/texture/bullet01.png"		, 32  , 32  },
	{ "asset/texture/exp.png"			, 128 , 128 },
	{ "asset/texture/number.tga"		, 320 , 32  },
	{ "asset/texture/title.png"			, 1024, 576 },
	{ "asset/texture/result.png"		, 1024, 576 },
	{ "asset/texture/kokosozai.png"		, 512 , 512 },
	{ "asset/texture/sousa.png"			, 1024, 576 },
	{ "asset/texture/rule.png"			, 1024, 576 },
};

static const int TEXTURE_FILE_COUNT = sizeof(g_TextureFiles) / sizeof(g_TextureFiles[0]);	//�e�N�X�`���t�@�C���𐔂���

static_assert(TEXTURE_INDEX_MAX == TEXTURE_FILE_COUNT, "TEXTURE_INDEX_MAX != TEXTURE_FILE_COUNT");	

static LPDIRECT3DTEXTURE9 g_pTextures[TEXTURE_FILE_COUNT] = {};	//�e�N�X�`�����i�[����C���X�^���X

//�e�N�X�`���t�@�C���̓ǂݍ���
int Texture_Load()
{   
    LPDIRECT3DDEVICE9 pDevice = GetD3DDevice();
	if( !pDevice ) {
		return TEXTURE_FILE_COUNT;
	}

	int failed_count = 0;

	for( int i = 0; i < TEXTURE_FILE_COUNT; i++ ) {
		
		if( FAILED(D3DXCreateTextureFromFile(pDevice, g_TextureFiles[i].filename, &g_pTextures[i])) ) {
            // DebugPrintf("�e�N�X�`���̓ǂݍ��݂Ɏ��s ... %s\n", g_TextureFiles[i].filename);
			failed_count++;
		}
	}

	return failed_count;
}

//�e�N�X�`���t�@�C���̉��
void Texture_Release()
{
	for( int i = 0; i < TEXTURE_FILE_COUNT; i++ ) {
		
		if( g_pTextures[i] ) {
			g_pTextures[i]->Release();
			g_pTextures[i] = NULL;
		}
	}
}

//�e�N�X�`���I�u�W�F�N�g���摜�t�@�C������ǂݍ��ފ֐�
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) {
        return NULL;
    }

	return g_pTextures[index];
}

//�e�N�X�`���̉���
int Texture_GetWidth(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) 
	{
        return NULL;
    }

	return g_TextureFiles[index].width;	//�e�N�X�`���̉����̒l�����^�[��
}

//�e�N�X�`���̏c��
int Texture_GetHeight(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) 
	{
        return NULL;
    }

	return g_TextureFiles[index].height;	//�e�N�X�`���̏c���̒l�����^�[��
}
