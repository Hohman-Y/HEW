/*==================================================
	
	[Sound.h]
	Author : �o���đ�

====================================================*/

#pragma once
#include <windows.h>
#include "xaudio2.h"	

//#	�T�E���h���x����
typedef enum
{
	SOUND_LABEL_001,	//�@�����

	SOUND_LABEL_MAX,

} SOUND_LABEL;

//#	Sound�N���X
/* ���y�t�@�C�����Ǘ�����N���X�@*/
class Sound
{
private:
	char *pFilename;												// �t�@�C����
	int nCntLoop;													// ���[�v�J�E���g
	static IXAudio2 *g_pXAudio2;									// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	static IXAudio2MasteringVoice *g_pMasteringVoice;				// �}�X�^�[�{�C�X
	static IXAudio2SourceVoice *g_apSourceVoice[SOUND_LABEL_MAX];	// �\�[�X�{�C�X
	static BYTE *g_apDataAudio[SOUND_LABEL_MAX];					// �I�[�f�B�I�f�[�^
	static DWORD g_aSizeAudio[SOUND_LABEL_MAX];						// �I�[�f�B�I�f�[�^�T�C�Y
public:	
	static bool Init(HWND hWnd);			//	������
	static void Uninit();					//	�I������
	static void Play(SOUND_LABEL label);	//	�Z�O�����g�Đ�(�����F���x����)
	static void Stop(SOUND_LABEL label);	//	�Z�O�����g��~(�����F���x����)
	static void Stop();						//	�Z�O�����g��~�F���ׂ�
};

