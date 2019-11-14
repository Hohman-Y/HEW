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
extern std::map<std::string, XFile *>g_pXFileList;	//	XFile�̃��X�g
Model *Map::Actor[ACTOR_NUM];						//	Model�^�|�C���^�z��
Field *Map::pField[1];								//	Field�^�|�C���^

void Map::Init()
{
	//!	XFlie�̃��[�h����
	// �ǂݍ��݃t�@�C�������X�g
	const std::string file_name_list[] =
	{
		"asset/model/ri.x",
	};

	// XFile�ǂݍ���
	for (int i = 0; i < FILELIST; i++)
	{
		g_pXFileList[file_name_list[i]] = new XFile();				//	XFile���i�[���郁�����̊m��
		g_pXFileList[file_name_list[i]]->Load(file_name_list[i]);	//	���[�h�֐��̌Ăяo��
	}
	
	//pField[0] = new Field;

	//pField[0]->Init();
}

//	�}�b�v�̏I������
void Map::Uninit()
{
	//!	�����������Y��Ȃ��悤�ɂ���
	//delete pField[0];
	delete Actor[0];	
}

//	�}�b�v�̕`��(3D���f���̔z�u�A�`��)
void Map::Draw()
{
	
	Actor[0] = new Model(D3DXVECTOR3(0.0f, 0.0f, -10.0f),D3DXVECTOR3(1.0f, 1.0f, 1.0f),D3DXVECTOR3(0.0f, 0.0f, 0.0f),g_pXFileList["asset/model/ri.x"]);
	Actor[0]->Draw();


	//pField[0]->Draw();
}
