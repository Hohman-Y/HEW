/*========================================================
	
	[Map.cpp]
	Author : �o���đ�

=========================================================*/

#include <map>
#include "main.h"
#include "Map.h"

//	�}�N����`
#define FILELIST 2	//	�ǂݍ��ރt�@�C���̐�

//	�O���[�o���ϐ�
extern std::map<std::string, XFile *>g_pXFileList;

//	����������
void Map::Init()
{
	//!	XFlie�̃��[�h����
	// �ǂݍ��݃t�@�C�������X�g
	std::string file_name_list[] =
	{
		"asset/model/ri.x",
		"asset/model/dai.x",
	};

	// XFile�ǂݍ���
	for (int i = 0; i < FILELIST; i++)
	{
		g_pXFileList[file_name_list[i]] = new XFile();
		g_pXFileList[file_name_list[i]]->Load(file_name_list[i]);
	}

	//	�C���X�^���X�����A�������̓��I�m�� (�����F�ʒu�A�傫���A��]�A�ǂݍ��ރt�@�C����)
	m_Actor[0] = new Model (D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 50.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), g_pXFileList["asset/model/dai.x"]);
}

//	�I������
void Map::Uninit()
{
	//	�q�[�v�̈�̃����������
	delete m_Actor[0];
}

//	�`�揈��
void Map::Draw()
{
	m_Actor[0]->Draw();	//	�W�����v�̕`��
}
