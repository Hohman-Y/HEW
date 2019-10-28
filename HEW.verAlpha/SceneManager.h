/*======================================================

	[SceneManager.h]
	Author : �o���đ�

======================================================*/

#pragma once
#include "main.h"
#include "BaseScene.h"

//#	SceneManager�N���X
class SceneManager
{
private:
	static BaseScene			*scene[1];
	static SCENE_STATE			SceneState;
	static LPDIRECT3DDEVICE9	g_p3DDevice;
public:
	static void Init();
	static void Uninit();
	static void Update();
	static void Draw();
	static void ChangeSceneState();
};

