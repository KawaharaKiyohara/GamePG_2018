#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}

bool BackGround::Start()
{
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/backGround.cmo");
	CQuaternion qRot;
	qRot.SetRotationDeg(g_vec3AxisY, 180.0f);
	skinModelRender->SetRotation(qRot);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	CVector3 pos = { 0.0f, -20.0f, 0.0f };//����͈ȉ��Ɠ���
	//pos.x =  0.0f;
	//pos.y =  -20.0f;
	//pos.z =  0.0f;
	skinModelRender->SetPosition(pos);

	//HandsOn2 CPhysicsStaticObject�N���X�̃I�u�W�F�N�g�̏�����
	m_physicsStaticObject.CreateMeshObject(skinModelRender, pos, qRot);

	return true;
}