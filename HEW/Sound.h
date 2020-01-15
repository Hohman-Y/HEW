//=============================================================================
//
// �T�E���h���� [sound.h]
//
//=============================================================================
#pragma once

#include <windows.h>
#include "xaudio2.h"						// �T�E���h�����ŕK�v

//	�����@������sound.cpp�ɏ������t�@�C�����ɑΉ��������x�����������@����
//	�����@�����̃��x������sound.cpp�̃t�@�C�����̐��͓����ɂ��Ȃ��ƃG���[�ɂȂ�@����

// �T�E���h�t�@�C��
enum  SOUND_LABEL
{
	SOUND_LABEL_game_01,		    // game
	SOUND_LABEL_lose_01,		    // lose
	SOUND_LABEL_win_01,		    // win
	SOUND_LABEL_���艹_01,		// ���艹
	//SOUND_LABEL_SE_HIT,		// �q�b�g��
	SOUND_LABEL_SE_EXPLOSION,	// ������

	SOUND_LABEL_MAX,//�������͐��Ɋ܂߂Ȃ�

};

class Sound
{
private:
	static IXAudio2 *m_pXAudio2;								// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	static IXAudio2MasteringVoice *m_pMasteringVoice;			// �}�X�^�[�{�C�X
	static IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX];	// �\�[�X�{�C�X
	static BYTE *m_apDataAudio[SOUND_LABEL_MAX];					// �I�[�f�B�I�f�[�^
	static DWORD m_aSizeAudio[SOUND_LABEL_MAX];					// �I�[�f�B�I�f�[�^�T�C�Y
public:
	static bool Init(HWND hWnd);
	static void Uninit();
	static void Play(SOUND_LABEL label);
	static void Stop(SOUND_LABEL label);
	static void Stop();
};