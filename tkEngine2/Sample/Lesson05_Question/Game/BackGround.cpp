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
	qRot.SetRotationDeg(CVector3::AxisY, 180.0f);
	skinModelRender->SetRotation(qRot);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	CVector3 pos = { 0.0f, -20.0f, 0.0f };
	skinModelRender->SetPosition(pos);

	//HandsOn 2 CPhysicsStaticObject�̏�����
	m_physicsStaticObject.CreateMeshObject(
		skinModelRender,
		pos,
		qRot
	);

	return true;
}