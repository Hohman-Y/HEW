/*=======================================

	[main.cpp]
	Author : �o���đ�

========================================*/

//�C���N���[�h�t�@�C��
#include "main.h"
#include "myDirect3D.h"
#include "input.h"
#include "texture.h"
#include "camera.h"
#include "light.h"
#include "field.h"		//1���|���S��
#include "debugproc.h"	//�f�o�b�O�\���p
#include <time.h>

#define _USE_MATH_DEFINES
#include <math.h>

//�v���O�}�R�����g�F�����J�[�Ƀ��C�u�����t�@�C�����w��
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "winmm.lib")


//	�萔��`
#define CLASS_NAME     "GameWindow"       // �E�C���h�E�N���X�̖��O
#define WINDOW_CAPTION "�Q�[���E�B���h�E" // �E�B���h�E�̖��O


//   �O���[�o���ϐ��錾
static	HWND g_hWnd;            // �E�B���h�E�n���h��
bool	g_bDispDebug = true;	// �f�o�b�O�\��ON/OFF


//	�v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��(�R�[���o�b�N�֐�)
static bool WindowInit(HINSTANCE hInstance, int nCmdShow);		//�E�B���h�E�֐�
static bool Initialize(HINSTANCE hInst);	// �Q�[���̏�����
static void Finalize();					// �Q�[���̏I������
static void Update();					// �Q�[���̍X�V����
static void Draw();						// �Q�[���̕`��֐�


//�@���C���֐��F�G���g���[�|�C���g
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �g�p���Ȃ��ꎞ�ϐ��𖾎�
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//�\������E�B���h�E�̒�`�A�o�^�A�\��
	if (!WindowInit(hInstance, nCmdShow))		// InitApp�֐����Ăяo���A
	return false;								// ����ɏI������Ύ��Ƀ��b�Z�[�W���[�v��

	// �Q�[���̏�����
	Initialize(hInstance);

	//DWORD�^�cunsigned lond�^�i�����Ȃ��j
	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;
	DWORD dwCurrentTime;
	DWORD dwFrameCount;

	// ����\��ݒ�
	timeBeginPeriod(1);

	// �t���[���J�E���g������
	dwExecLastTime = dwFPSLastTime = timeGetTime();
	dwCurrentTime = dwFrameCount = 0;	//�����l��0�ɂ��邱�Ƃ�Y��Ȃ��悤�ɁiFPS���擾�����Ƃ��S�~�������邱�Ɩh�����߁j

	// Windows�Q�[���p���C�����[�v
	MSG msg = {}; 
	while (WM_QUIT != msg.message)
	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// ���b�Z�[�W������ꍇ�̓��b�Z�[�W������D��
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else 
		{
			dwCurrentTime = timeGetTime();
		
			if ((dwCurrentTime - dwFPSLastTime) >= 500)	// 0.5�b���ƂɎ��s
			{

				dwFPSLastTime = dwCurrentTime;
				dwFrameCount = 0;
			}

			//!	1�t���[�����ƂɎ��s�i����������҂��Ȃ��j60FPS�ɌŒ�@-> ���j�^�[�ɂ���Ď��s���x�̕ω���h��
			if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))
			{
				dwExecLastTime = dwCurrentTime;

				// �X�V����
				Update();

				// �`�揈��
				Draw();

				dwFrameCount++;
			}
		}
	}

	// �Q�[���̏I������
	Finalize();

	return (int)msg.wParam;
}

// �E�B���h�E�v���V�[�W��(�R�[���o�b�N�֐�)
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) 
	{
	//�L�[���������Ƃ�
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)//ESC�L�[ 
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0); // WM_CLOSE���b�Z�[�W�̑��M
		}
		break;

	//�J�[�\���̐ݒ�
	case WM_SETCURSOR:
		SetCursor(NULL);
		break;

	case WM_CLOSE:
		DestroyWindow(hWnd); // �w��̃E�B���h�E��WM_DESTROY���b�Z�[�W�𑗂�
		return 0; // DefWindowProc�֐��Ƀ��b�Z�[�W�𗬂����I�����邱�Ƃɂ���ĉ����Ȃ��������Ƃɂ���

	case WM_DESTROY: // �E�B���h�E�̔j�����b�Z�[�W
		PostQuitMessage(0); // WM_QUIT���b�Z�[�W�̑��M
		return 0;
	};

	// �ʏ탁�b�Z�[�W�����͂��̊֐��ɔC����
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
	

//�E�B���h�E�֐�
static bool WindowInit(HINSTANCE hInstance, int nCmdShow)
{
	// �E�B���h�E�N���X�\����
	WNDCLASSEX wc;

	// �E�B���h�E�N���X���`����
	wc.cbSize = sizeof(WNDCLASSEX);						// WNDCLASSEX�\���̂̃T�C�Y��ݒ�
	wc.style = NULL;									// �E�B���h�E�X�^�C���i�f�t�H���g�j
	wc.lpfnWndProc = WndProc;							// �E�B���h�E�v���V�[�W���̎w��
	wc.cbClsExtra = 0;									// �ʏ�͎g��Ȃ��i�O�ɂ��Ă����j
	wc.cbWndExtra = 0;									// �ʏ�͎g��Ȃ��i�O�ɂ��Ă����j
	wc.lpszClassName = CLASS_NAME;						// �N���X���̐ݒ�
	wc.hInstance = hInstance;							// �C���X�^���X�n���h���̎w��
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);	// �E�C���h�E�̃N���C�A���g�̈�̔w�i�F��ݒ�
	wc.hIcon = NULL;									// ���[�W�A�C�R���i�Ȃ��j
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// �J�[�\���X�^�C��
	wc.lpszMenuName = NULL;								// ���j���[�i�Ȃ��j
	wc.hIconSm = NULL;									// �X���[���A�C�R���i�Ȃ��j

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClassEx(&wc)) return false;

	//�E�B���h�E�𐶐�����
	if (WINMODE)//TRUE�̂Ƃ�
	{
		//"	�E�B���h�E���[�h
		g_hWnd = CreateWindow
		(
			CLASS_NAME,             // �E�B���h�E�N���X�̖��O
			WINDOW_CAPTION,         // �E�B���h�E�^�C�g��
			WS_OVERLAPPEDWINDOW,    // �E�B���h�E�X�^�C��
			0,                      // �E�B���h�E�̍��p�w���W
			0,                      // �E�B���h�E�̍��p�x���W
			CW_USEDEFAULT,          // �E�B���h�E�̕�
			CW_USEDEFAULT,          // �E�B���h�E�̍���
			NULL,                   // �e�E�B���h�E�i�Ȃ��j
			NULL,                   // ���j���[�i�Ȃ��j
			hInstance,              // ���̃v���O�����̃C���X�^���X�̃n���h��
			NULL                    // �ǉ������i�Ȃ��j
		);

		RECT wRect, cRect;  // �E�B���h�E�S�̂̋�`�A�N���C�A���g�̈�̋�`
		int ww, wh;         // �E�B���h�E�S�̂̕��A����
		int cw, ch;         // �N���C�A���g�̈�̕��A����

		// �E�B���h�E�S�̂̕��E�������v�Z
		GetWindowRect(g_hWnd, &wRect);
		ww = wRect.right - wRect.left;
		wh = wRect.bottom - wRect.top;
		// �N���C�A���g�̈�̕��E�������v�Z
		GetClientRect(g_hWnd, &cRect);
		cw = cRect.right - cRect.left;
		ch = cRect.bottom - cRect.top;
		// �N���C�A���g�̈�ȊO�ɕK�v�ȃT�C�Y���v�Z
		ww = ww - cw;
		wh = wh - ch;
		// �E�B���h�E�S�̂ɕK�v�ȃT�C�Y���v�Z
		ww = SCREEN_WIDTH + ww;
		wh = SCREEN_HEIGHT + wh;

		// �v�Z�������ƍ������E�B���h�E�ɐݒ�
		SetWindowPos(g_hWnd, HWND_TOP, 0, 0, ww, wh, SWP_NOMOVE);
	}
	else//FALSE�̂Ƃ�
	{
		//"	�t���X�N���[�����[�h
		g_hWnd = CreateWindow
		(
			CLASS_NAME,             // �E�B���h�E�N���X�̖��O
			WINDOW_CAPTION,         // �E�B���h�E�^�C�g��
			WS_VISIBLE | WS_POPUP,  // �E�B���h�E�X�^�C��
			0,                      // �E�B���h�E�̍��p�w���W
			0,                      // �E�B���h�E�̍��p�x���W
			SCREEN_WIDTH,           // �E�B���h�E�̕�
			SCREEN_HEIGHT,          // �E�B���h�E�̍���
			NULL,                   // �e�E�B���h�E�i�Ȃ��j
			NULL,                   // ���j���[�i�Ȃ��j
			hInstance,              // ���̃v���O�����̃C���X�^���X�̃n���h��
			NULL                    // �ǉ������i�Ȃ��j
		);
	}

	ShowWindow(g_hWnd, nCmdShow); // �E�B���h�E��\��
	ValidateRect(g_hWnd, 0);      // WM_PAINT���Ă΂�Ȃ��悤�ɂ���
	UpdateWindow(g_hWnd);         // �E�B���h�E�̍X�V

	return true;              // InitApp�֐��̐���I��
}

//�@�����������֐�
bool Initialize(HINSTANCE hInst)
{
	//�V�[�h�̏�����
	srand((unsigned int)time(NULL));

	// �Q�[���̏�����(Direct3D�̏�����)
	if (!D3D_Initialize(g_hWnd)){
		// �Q�[���̏������Ɏ��s����
		return false;
	}
	// �L�[�{�[�h�̏�����
	if (!Input::KB_Init(hInst, g_hWnd))
	{
		return false;
	}
	//	�Q�[���|�b�h�̏�����
	if (!Input::GP_Init(hInst, g_hWnd))
	{
		return false;
	}

	//�S�e�N�X�`���t�@�C���̃��[�h
	Texture_Load();

	// �f�o�b�O�\������ 
	DebugProc_Initialize();

	// �J�����̏���������
	Camera_Initialize();

	// ���C�g�̏���������
	Light_Initialize();

	// �n�ʂ̏���������
	Field_Initialize();

	return true;
}

//�@�I�������֐�
void Finalize(void)
{
	// �J�����̏I������
	Camera_Finalize();

	// ���C�g�̏I������
	Light_Finalize();

	// �n�ʂ̏I������
	Field_Finalize();

	// �e�N�X�`���̉��
	Texture_Release();

	// DirectInput�̏I������
	Input::Uninit();

	// �Q�[���̏I������(Direct3D�̏I������)
	D3D_Finalize();
}

// �X�V�����֐�
void Update(void)
{
	//�L�[�{�[�h�̏�Ԃ��X�V����
	Input::KB_Update();

	//�Q�[���p�b�h�̏�Ԃ��X�V����
	Input::GP_Update();

	// �J�����̍X�V����
	Camera_Update();

	// ���C�g�̍X�V����
	Light_Update();

	// �n�ʂ̍X�V����
	Field_Update();

}

// �`�揈���֐�
void Draw(void)
{
	LPDIRECT3DDEVICE9 pD3DDevice = GetD3DDevice();

	// ��ʂ̃N���A
	pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(50, 50, 50, 255), 1.0f, 0);

	// �`��o�b�`���߂̊J�n
	pD3DDevice->BeginScene();


	// �J�����̐ݒ�
	Camera_SetCamera();

	// �n�ʂ̕`�揈��
	Field_Draw();

	// �f�o�b�O�\���̕`�揈��
	if (g_bDispDebug)
	{
		DebugProc_Draw();
	}

	// �`��o�b�`���߂̏I��
	pD3DDevice->EndScene();

	// �o�b�N�o�b�t�@���t���b�v�i�^�C�~���O��D3DPRESENT_PARAMETERS�̐ݒ�ɂ��j
	pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

//�E�B���h�E�n���h���̃Q�b�^�[
HWND GetHWND()
{
	return g_hWnd;
}


double frand() 
{
	return (double)rand() / RAND_MAX;
}
