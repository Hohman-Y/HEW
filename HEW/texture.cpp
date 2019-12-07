/*==================================
	
	[texture.cpp]
	Author : �o���đ�

==================================*/

//�C���N���[�h�t�@�C��
#include <d3dx9.h>
#include "main.h"
#include "texture.h"

//�}�N����`
#define TEXTURE_FILENAME_MAX (64)	//�t�@�C���̕�����

//	TEXTURE�\����
struct TEXTURE
{
	char filename[TEXTURE_FILENAME_MAX];	//�t�@�C����
	int width;								//�e�N�X�`���̉���
	int height;								//�e�N�X�`���̏c��
};

//�e�N�X�`���t�@�C���̈ꗗ
static const TEXTURE g_TextureFiles[] = 
{
	{ "asset/texture/result.png",		1920, 1080 },	//	���U���g�w�i�e�N�X�`��
	{ "asset/texture/modeselect.png",	1920, 1080 },	//	���[�h�I��w�i�e�N�X�`��
	{ "asset/texture/quizsample.png",	1024, 256  },
	{ "asset/texture/su.png",	         640,  64  },
};

static const int TEXTURE_FILE_COUNT = sizeof(g_TextureFiles) / sizeof(g_TextureFiles[0]);	//�e�N�X�`���t�@�C���𐔂���

static_assert(TEXTURE_INDEX_MAX == TEXTURE_FILE_COUNT, "TEXTURE_INDEX_MAX != TEXTURE_FILE_COUNT");	

static LPDIRECT3DTEXTURE9 g_pTextures[TEXTURE_FILE_COUNT] = {};	//�e�N�X�`�����i�[����C���X�^���X

//�e�N�X�`���t�@�C���̓ǂݍ���
int Texture_Load()
{   
    LPDIRECT3DDEVICE9 m_Device = GetD3DDevice();
	if( !m_Device )
	{
		return TEXTURE_FILE_COUNT;
	}

	int failed_count = 0;

	for( int i = 0; i < TEXTURE_FILE_COUNT; i++ ) {
		
		if( FAILED(D3DXCreateTextureFromFile(m_Device, g_TextureFiles[i].filename, &g_pTextures[i])) ) {
            // DebugPrintf("�e�N�X�`���̓ǂݍ��݂Ɏ��s ... %s\n", g_TextureFiles[i].filename);
			failed_count++;
		}
	}

	return failed_count;
}

//�e�N�X�`���t�@�C���̉��
void Texture_Release()
{
	for( int i = 0; i < TEXTURE_FILE_COUNT; i++ )
	{
		SAFE_RELEASE(g_pTextures[i]);
	}
}

//�e�N�X�`���I�u�W�F�N�g���摜�t�@�C������ǂݍ��ފ֐�
LPDIRECT3DTEXTURE9 Texture_GetTexture(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) 
	{
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

	return g_TextureFiles[index].width;	//	�e�N�X�`���̉����̒l
}

//�e�N�X�`���̏c��
int Texture_GetHeight(TextureIndex index)
{
    if( index < 0 || index >= TEXTURE_INDEX_MAX ) 
	{
        return NULL;
    }

	return g_TextureFiles[index].height;	//	�e�N�X�`���̏c���̒l
}
