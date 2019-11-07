/*==============================================

	[XFile.h]
	Author : �o���đ�

===============================================*/

#pragma once
#include <string>
#include <d3d9.h>
#include <d3dx9.h>
#include <map>


// �ǂݍ��݃t�@�C�������X�g
std::string file_name_list[] =
{
	"ri.x",
};

//#	XFile�N���X
/* XFile�̃��[�h�A�A�����[�h���Ǘ�����N���X */
class XFile
{
private:
	DWORD						MeshNum;				//	���b�V����
	LPD3DXMESH					Mesh;					//	���b�V��
	D3DMATERIAL9				*pMeshMaterialList;		//	���b�V���}�e���A��
	LPDIRECT3DTEXTURE9			*pTextureList;			//	�e�N�X�`�����X�g
	std::map<int, std::string> m_TextureNameList;				// �e�N�X�`�������X�g
	static LPDIRECT3DDEVICE9	g_pD3Device;			//	�f�o�C�X
public:
	XFile():MeshNum(0),Mesh(NULL),pMeshMaterialList(NULL),pTextureList(NULL){}
	bool Load(std::string fliename);
	void Unload();
	void Draw();
};


