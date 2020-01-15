/*==================================================
	
	[Sound.h]
	Author : �o���đ�

====================================================*/

#pragma once
#include <windows.h>
#include "xaudio2.h"	

//#	�T�E���h���x����
enum SOUND_LABEL
{
	SOUND_LABEL_001,	//�@�����

	SOUND_LABEL_MAX,

};

//#	Sound�N���X
/* ���y�t�@�C�����Ǘ�����N���X�@*/
class Sound
{
private:
	static IXAudio2 *m_pXAudio2;									// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	static IXAudio2MasteringVoice *m_pMasteringVoice;				// �}�X�^�[�{�C�X
	static IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX];	// �\�[�X�{�C�X
	static BYTE *m_apDataAudio[SOUND_LABEL_MAX];					// �I�[�f�B�I�f�[�^
	static DWORD m_aSizeAudio[SOUND_LABEL_MAX];						// �I�[�f�B�I�f�[�^�T�C�Y
public:	
	static bool Init(HWND hWnd);			//	������
	static void Uninit();					//	�I������
	static void Play(SOUND_LABEL label);	//	�Z�O�����g�Đ�(�����F���x����)
	static void Stop(SOUND_LABEL label);	//	�Z�O�����g��~(�����F���x����)
	static void Stop();						//	�Z�O�����g��~�F���ׂ�
};

