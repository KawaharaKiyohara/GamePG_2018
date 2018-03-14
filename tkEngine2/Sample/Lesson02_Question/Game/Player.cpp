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
//�L�����N�^�[�̈ړ������B
void Player::Move()
{
	if (Pad(0).IsPress(enButtonRight)) { //�������Q�[���p�b�h�̉E�{�^����������Ă�����B
		position.x += 10.0f;
	}
	if (Pad(0).IsPress(enButtonLeft)) {  //�������Q�[���p�b�h�̍��{�^����������Ă�����B
		position.x -= 10.0f;
	}
	if (Pad(0).IsPress(enButtonUp)) {
		position.z += 10.0f;
	}
	if (Pad(0).IsPress(enButtonDown)) {
		position.z -= 10.0f;
	}
	if (Pad(0).IsTrigger(enButtonA)) {
		ySpeed = 20.0f; //�������̑��x��ݒ肷��B
	}

	//�d�͂̉e����^����B
	ySpeed -= 1.0f;

	//Y�����̑��x�����W�ɉ��Z����B
	position.y += ySpeed;
	//�L�����N�^�[��Y���W��0��菬�����Ȃ�����
	//�W�����v�͂�0�ɂ��āA�L������Y���W��0�ɂ���B
	if (position.y <= 0.0f) {
		ySpeed = 0.0f;
		position.y = 0.0f;
	}
	//���f���ɍ��W�𔽉f������B
	skinModelRender->SetPosition(position);
}
//�L�����N�^�[�̉�]�����B
void Player::Rotation()
{
	//Question 1 �L�����N�^���E�Ɍ������Ă݂悤�B
	
	//���K�ۑ� 1 �L�����N�^�����Ɍ������Ă݂悤�B
	
	//���K�ۑ� 2 �L�����N�^�����Ɍ������Ă݂悤�B
	
	//���K�ۑ� 3 �L�����N�^����O�Ɍ������Ă݂悤�B
	

	//���f���ɉ�]�𔽉f������B
	skinModelRender->SetRotation(rotation);


}
void Player::Update()
{
	Move();
	Rotation();
}