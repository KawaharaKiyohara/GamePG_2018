#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
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
void Player::Update()
{
	//Question 1 �L���������E�ɓ������Ă݂悤�B
	
	
	//���K�ۑ� 1  �L������O��ɓ������Ă݂悤�B
	
	
	//Question 3 �L�����N�^���W�����v�����Ă݂悤�B
	
	
	//Question 4 �d�͂̉e����^���Ă݂悤�B
	
	
	//Y�����̑��x�����W�ɉ��Z����B
	position.y += ySpeed;
	//�L�����N�^�[��Y���W��0��菬�����Ȃ�����
	//�W�����v�͂�0�ɂ��āA�L������Y���W��0�ɂ���B
	if (position.y <= 0.0f) {
		ySpeed = 0.0f;
		position.y = 0.0f;
	}
	
	skinModelRender->SetPosition(position);
}