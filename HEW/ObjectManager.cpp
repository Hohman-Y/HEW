/*============================================

	[ObjectManager.cpp]
	Author :�@�o���đ�

============================================*/

#include "ObjectManager.h"

Character * ObjectManager::SetCharacter()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->SetCharacter();
}

Field * ObjectManager::SetField()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->SetField();
}
