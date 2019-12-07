/*=================================================

	[Collision.cpp]
	Author : �o���đ�

==================================================*/

#include "Collision.h"

void Collision::Update()
{

}
#if 0


void Collision::Player_vs_Map()
{
	//	�����蔻��
	FLOAT fDistance = 0;
	D3DXVECTOR3 vNormal;

	if (Collide(m_Character.GetPos(), m_Character.GetMove(), &m_Actor[0], &fDistance, &vNormal) && fDistance <= 0.3)
	{
		//�������ԂȂ̂ŁA���点��
		Thing[1].vDir = Slip(Thing[1].vDir, vNormal);//����x�N�g�����v�Z

		//����x�N�g����̒n�ʓˋN�Ƃ̃��C���� �Q�d�ɔ���	
		if (Collide(Thing[1].vPosition, Thing[1].vDir, &Thing[0], &fDistance, &vNormal) && fDistance <= 0.2)
		{
			//�Q�i�ڂ̓������ԂȂ̂ŁA���点�� �����炭�オ�����		
			Thing[1].vDir = Slip(Thing[1].vDir, vNormal);//����x�N�g�����v�Z
		}
	}
	Thing[1].vPosition.y += 0.7;

	//���{�b�g�@�ʒu�X�V
	Thing[1].vPosition += Thing[1].vDir;
}
#endif // 0

HRESULT Collision::FindVerticesOnPoly(LPD3DXMESH pMesh, DWORD dwPolyIndex, D3DXVECTOR3 * pvVertices)
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

//���C�ɂ��Փ˔���@���C�����胁�b�V���ƌ�������ꍇ�́ApfDistance�ɋ������ApvNormal�ɏՓ˖ʂ̖@��������true��Ԃ�
BOOL Collision::Collide(D3DXVECTOR3 vStart, D3DXVECTOR3 vDir, Character *pChara, FLOAT * pfDistance, D3DXVECTOR3 * pvNormal)
{
	BOOL boHit = false;
	D3DXMATRIX mWorld;
	D3DXVec3Normalize(&vDir, &vDir);

	// ���C�𓖂Ă郁�b�V���������Ă������]���Ă���ꍇ�ł��Ώۂ̃��[���h�s��̋t�s���p����ΐ��������C��������
	D3DXMatrixInverse(&mWorld, NULL, &pChara->GetMat());
	D3DXVec3TransformCoord(&vStart, &vStart, &mWorld);

	DWORD dwPolyIndex;
	D3DXIntersect(pChara->GetMesh(), &vStart, &vDir, &boHit, &dwPolyIndex, NULL, NULL, pfDistance, NULL, NULL);
	if (boHit)
	{
		//�������Ă���|���S���̒��_��������
		D3DXVECTOR3 vVertex[3];
		FindVerticesOnPoly(pChara->GetMesh(), dwPolyIndex, vVertex);
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

// L:���˃x�N�g���i���C�j N : �|���S���̖@��
D3DXVECTOR3 Collision::Slip(D3DXVECTOR3 L, D3DXVECTOR3 N)
{
	D3DXVECTOR3 S; //����x�N�g���i��������j

	//����x�N�g�� S=L-(N * L)/(|N|^2)*N
	S = L - ((D3DXVec3Dot(&N, &L)) / (pow(D3DXVec3Length(&N), 2))) * N;

	return S;
}