#include "stdafx.h"
#include "Player.h"


void Player::Update()
{
	//Hands-On 2 �v���C���[�𓮂����Ă݂悤
	position.x -= 1.0f;
	position.z += 1.0f;

	//���W���G�`������ɋ�����B
	skinModelRender->SetPosition(position);
}
bool Player::Start()
{
	//�X�L�����f�������_���[���쐬�B
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/unityChan.cmo");
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 180.0f);
	skinModelRender->SetRotation(qRot);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	return true;
}