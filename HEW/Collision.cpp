/*=================================================

	[Collision.cpp]
	Author : �o���đ�

==================================================*/

#include "Collision.h"
#include "debugproc.h"

BOOL Collision::Collide(D3DXVECTOR3 vStart, D3DXVECTOR3 vDir, Field* pField, FLOAT * pfDistance, D3DXVECTOR3 * pvNormal)
{
	BOOL boHit = false;
	D3DXMATRIX mWorld;
	D3DXVec3Normalize(&vDir, &vDir);

	// ���C�𓖂Ă郁�b�V���������Ă������]���Ă���ꍇ�ł��Ώۂ̃��[���h�s��̋t�s���p����ΐ��������C��������
	D3DXMatrixInverse(&mWorld, NULL, &pField->m_mtxWorldModel);
	D3DXVec3TransformCoord(&vStart, &vStart, &mWorld);

	DWORD dwPolyIndex;
	D3DXIntersect(pField->m_pMeshModel, &vStart, &vDir, &boHit, &dwPolyIndex, NULL, NULL, pfDistance, NULL, NULL);

	if (boHit == true)
	{
		//!	��ŏ���
		DebugProc_Print((char*)"�������Ă���");
		
		//�������Ă���|���S���̒��_��������
		D3DXVECTOR3 vVertex[3];
		Collision::FindVerticesOnPoly(pField->m_pMeshModel, dwPolyIndex, vVertex);
		D3DXPLANE p;
		
		//���̒��_���畽�ʕ������𓾂�
		D3DXPlaneFromPoints(&p, &vVertex[0], &vVertex[1], &vVertex[2]);
		
		//���ʕ������̌W�����@���̐���
		pvNormal->x = p.a;
		pvNormal->y = p.b;
		pvNormal->z = p.c;

		return true;
	}
	return false;
}

HRESULT Collision::FindVerticesOnPoly(LPD3DXMESH pMesh, DWORD dwPolyIndex, D3DXVECTOR3 * pvVertices)
{
	DWORD dwStride = pMesh->GetNumBytesPerVertex();
	DWORD dwVertexNum = pMesh->GetNumVertices();
	DWORD dwPolyNum = pMesh->GetNumFaces();
	WORD* pwPoly = NULL;
	pMesh->LockIndexBuffer(D3DLOCK_READONLY, (VOID**)&pwPoly);

	BYTE *pbVertices = NULL;
	FLOAT* pfVetices = NULL;
	LPDIRECT3DVERTEXBUFFER9 VB = NULL;
	pMesh->GetVertexBuffer(&VB);
	if (SUCCEEDED(VB->Lock(0, 0, (VOID**)&pbVertices, 0)))
	{
		pfVetices = (FLOAT*)&pbVertices[dwStride*pwPoly[dwPolyIndex * 3]];
		pvVertices[0].x = pfVetices[0];
		pvVertices[0].y = pfVetices[1];
		pvVertices[0].z = pfVetices[2];

		pfVetices = (FLOAT*)&pbVertices[dwStride*pwPoly[dwPolyIndex * 3 + 1]];
		pvVertices[1].x = pfVetices[0];
		pvVertices[1].y = pfVetices[1];
		pvVertices[1].z = pfVetices[2];

		pfVetices = (FLOAT*)&pbVertices[dwStride*pwPoly[dwPolyIndex * 3 + 2]];
		pvVertices[2].x = pfVetices[0];
		pvVertices[2].y = pfVetices[1];
		pvVertices[2].z = pfVetices[2];

		pMesh->UnlockIndexBuffer();
		VB->Unlock();
		VB->Release();
	}
	return S_OK;
}


D3DXVECTOR3 Collision::Slip(D3DXVECTOR3 L, D3DXVECTOR3 N)
{
	D3DXVECTOR3 S; //����x�N�g���i��������j

	//����x�N�g�� S=L-(N * L)/(|N|^2)*N
	S = L - ((D3DXVec3Dot(&N, &L)) / (pow(D3DXVec3Length(&N), 2))) * N;

	return S;
}

#if 0
//���C�ɂ��Փ˔���@���C�����胁�b�V���ƌ�������ꍇ�́ApfDistance�ɋ������ApvNormal�ɏՓ˖ʂ̖@��������true��Ԃ�
BOOL Collide(D3DXVECTOR3 vStart, D3DXVECTOR3 vDir,Field *pField, FLOAT* pfDistance, D3DXVECTOR3* pvNormal)
{
	BOOL boHit = false;
	D3DXMATRIX mWorld;
	D3DXVec3Normalize(&vDir, &vDir);

	// ���C�𓖂Ă郁�b�V���������Ă������]���Ă���ꍇ�ł��Ώۂ̃��[���h�s��̋t�s���p����ΐ��������C��������
	D3DXMatrixInverse(&mWorld, NULL, &pField->m_mtxWorldModel);
	D3DXVec3TransformCoord(&vStart, &vStart, &mWorld);

	DWORD dwPolyIndex;
	D3DXIntersect(pField->m_pMeshModel, &vStart, &vDir, &boHit, &dwPolyIndex, NULL, NULL, pfDistance, NULL, NULL);
	
	if (boHit == true)
	{
		/// <summary>
		///	�o�O�[�� true���Ԃ��Ă��Ȃ�
		DebugProc_Print((char*)"�������Ă���");
		
		//�������Ă���|���S���̒��_��������
		D3DXVECTOR3 vVertex[3];
		Collision::FindVerticesOnPoly(pField->m_pMeshModel, dwPolyIndex, vVertex);
		D3DXPLANE p;
		//���̒��_���畽�ʕ������𓾂�
		D3DXPlaneFromPoints(&p, &vVertex[0], &vVertex[1], &vVertex[2]);
		//���ʕ������̌W�����@���̐���
		pvNormal->x = p.a;
		pvNormal->y = p.b;
		pvNormal->z = p.c;

		return true;
	}
	return false;
}

//
//HRESULT FindVerticesOnPoly(LPD3DXMESH pMesh,DWORD dwPolyIndex,D3DXVECTOR3* pvVertices )
//���̃|���S���̒��_��������
HRESULT FindVerticesOnPoly(LPD3DXMESH pMesh, DWORD dwPolyIndex, D3DXVECTOR3* pvVertices)
{
	DWORD i, k;
	DWORD dwStride = pMesh->GetNumBytesPerVertex();
	DWORD dwVertexNum = pMesh->GetNumVertices();
	DWORD dwPolyNum = pMesh->GetNumFaces();
	WORD* pwPoly = NULL;
	pMesh->LockIndexBuffer(D3DLOCK_READONLY, (VOID**)&pwPoly);

	BYTE *pbVertices = NULL;
	FLOAT* pfVetices = NULL;
	LPDIRECT3DVERTEXBUFFER9 VB = NULL;
	pMesh->GetVertexBuffer(&VB);
	if (SUCCEEDED(VB->Lock(0, 0, (VOID**)&pbVertices, 0)))
	{
		pfVetices = (FLOAT*)&pbVertices[dwStride*pwPoly[dwPolyIndex * 3]];
		pvVertices[0].x = pfVetices[0];
		pvVertices[0].y = pfVetices[1];
		pvVertices[0].z = pfVetices[2];

		pfVetices = (FLOAT*)&pbVertices[dwStride*pwPoly[dwPolyIndex * 3 + 1]];
		pvVertices[1].x = pfVetices[0];
		pvVertices[1].y = pfVetices[1];
		pvVertices[1].z = pfVetices[2];

		pfVetices = (FLOAT*)&pbVertices[dwStride*pwPoly[dwPolyIndex * 3 + 2]];
		pvVertices[2].x = pfVetices[0];
		pvVertices[2].y = pfVetices[1];
		pvVertices[2].z = pfVetices[2];

		pMesh->UnlockIndexBuffer();
		VB->Unlock();
		VB->Release();
	}
	return S_OK;
}
// L:���˃x�N�g���i���C�j N : �|���S���̖@��
D3DXVECTOR3 Slip(D3DXVECTOR3 L, D3DXVECTOR3 N)
{
	D3DXVECTOR3 S; //����x�N�g���i��������j

	//����x�N�g�� S=L-(N * L)/(|N|^2)*N
	S = L - ((D3DXVec3Dot(&N, &L)) / (pow(D3DXVec3Length(&N), 2))) * N;

	return S;
}

//VOID RenderRay(LPDIRECT3DDEVICE9 pDevice,D3DXVECTOR3 vStart,D3DXVECTOR3 vDir)
//���C�����F�ł���悤�Ƀ��C�������_�����O����
VOID RenderRay(LPDIRECT3DDEVICE9 pDevice, D3DXVECTOR3 vStart, D3DXVECTOR3 vDir)
{
	pDevice->SetFVF(D3DFVF_XYZ);
	D3DXVECTOR3 vPnt[2];
	vPnt[0] = vStart;
	vPnt[1] = vDir * 100;
	vPnt[1].y = vPnt[0].y;

	D3DXMATRIX mWorld;
	D3DXMatrixIdentity(&mWorld);
	pDevice->SetTransform(D3DTS_WORLD, &mWorld);
	//���C�̃}�e���A���ݒ�@�i���ɐݒ�j
	D3DMATERIAL9 mtrl;
	ZeroMemory(&mtrl, sizeof(mtrl));
	mtrl.Diffuse.a = 255;
	mtrl.Diffuse.r = 255;
	mtrl.Diffuse.g = 255;
	mtrl.Diffuse.b = 255;
	mtrl.Ambient = mtrl.Diffuse;
	pDevice->SetMaterial(&mtrl);
	//���C�̃����_�����O
	pDevice->DrawPrimitiveUP(D3DPT_LINELIST, 1, vPnt, sizeof(D3DXVECTOR3));
}

#endif