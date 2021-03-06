/*===================================================

	[SceneTitle.cpp]
	Author : 出合翔太

====================================================*/

#include "SceneTitle.h"
#include "SceneManager.h"
#include "Controller.h"

static bool SelectFlag;

static bool flg = true;

void SceneTitle::Init()
{
	SelectFlag = false;
	m_bEnd = false;
	Fade::Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
}

void SceneTitle::Uninit()
{

}

void SceneTitle::Update()
{
	//	チュートリアル選択
	if (KeyBoard::IsTrigger(DIK_Q))
	{
		SelectFlag = true;
	}
	//	ゲーム選択
	if (KeyBoard::IsTrigger(DIK_E))
	{
		SelectFlag = false;
	}
	if (!m_bEnd)
	{
		//	画面遷移
		if (KeyBoard::IsTrigger(DIK_T))
		{
			m_bEnd = true;
			Fade::Start(true, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
		}
	}
	else 
	{
		if (!Fade::IsFade())
		{
			SceneManager::ChangeSceneState();
		}
  }
}

void SceneTitle::Draw()
{
	m_Sprite.Draw(TEXTURE_UI, 640.0f, 740.0f, 30.0f, 660.0f, 1008.0f, 250.0f, 30.0f, 50.0f, 0.75f, 0.75f, 0.0f);//チュートリアルの描画

	if (flg == true)
	{
		m_Sprite.Draw(TEXTURE_UI, 640.0f, 540.0f, 30.0f, 360.0f, 1008.0f, 300.0f, 30.0f, 50.0f, 0.75f, 0.75f, 0.0f);//ゲームスタートの描画	
	}
	else if (flg == false)
	{
		m_Sprite.Draw(TEXTURE_UI, 640.0f, 540.0f, 30.0f, 360.0f, 1008.0f, 300.0f, 30.0f, 50.0f, 0.75f, 0.75f, 0.0f, 255, 255, 255, 0);//スタート画面、色の変更
	}	
}

bool GetFlag()
{
	return SelectFlag;
}
