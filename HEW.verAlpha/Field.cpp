/*==========================================================

	[Field.cpp]
	Author : �o���đ�

===========================================================*/

#include <map>
#include "Field.h"
#include "Model.h"
#include "XFile.h"

//	�O���[�o���ϐ�
extern std::map<std::string, XFile *>g_pXFileList;	// �ǂݍ���XFile�̃��X�g

//	�}�b�v�̃��[�h
void Field::Load()
{
	// XFile�ǂݍ���
	for (int i = 0; i < 1; i++)
	{
		g_pXFileList[file_name_list[i]] = new XFile();
		g_pXFileList[file_name_list[i]]->Load(file_name_list[i]);
	}
}

//	�}�b�v�̕`��
void Field::Draw()
{
	//�`��T���v��
#if 0 
	// XFile�I�u�W�F�N�g�쐬
	Drawer obj1(
		D3DXVECTOR3(3.0f, 0.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		g_pXFileList["Sample01.x"]);
#endif
	Model sample(
		D3DXVECTOR3(3.0f, 0.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		g_pXFileList["ri.x"]);
	
}



