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
	position.x = 100.0f;
	position.y = 0.0f;
	position.z = 0.0f;
	skinModelRender->SetPosition(position);
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 180.0f);
	skinModelRender->SetRotation(qRot);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	return true;
}



void Player::Update()
{
	//�L�����N�^�[�̈ړ������B

	//Question 1 �L���������E�ɓ������Ă݂悤�B
	if (Pad(0).IsPress(enButtonRight)) { //�������Q�[���p�b�h�̉E�{�^����������Ă�����B
		position.x += 10.0f;//�L�[�{�[�h�̂U�L�[
	}
	if (Pad(0).IsPress(enButtonLeft)) {  //�������Q�[���p�b�h�̍��{�^����������Ă�����B
		position.x -= 10.0f; //�L�[�{�[�h�̂S�L�[
	}

	//Question 2 �L�����N�^�[�𕡐����Ă݂悤�B
	if (Pad(0).IsPress(enButtonSelect)) {//�������Q�[���p�b�h��Select�{�^����������Ă�����B
		NewGO<Player>(0); //�L�[�{�[�h�̃X�y�[�X�L�[
	}

	//���K�ۑ�

	//�u�������A�p�b�h�̏�{�^���������ꂽ��v�Ƃ���if����ǉ�����
	//�p�b�h�̏�{�^���������ꂽ��A��ʂ̉��Ɉړ�����
	if (Pad(0).IsPress(enButtonUp)) {
		position.z += 10.0f;
	}

	//���K�ۑ�
	//�u�������A�p�b�h�̉��{�^���������ꂽ��v�Ƃ���if����ǉ�����
	//�p�b�h�̉��{�^���������ꂽ��A��ʂ̎�O�Ɉړ�����
	if (Pad(0).IsPress(enButtonDown)) {
		position.z -= 10.0f;
	}

	//Question 3 �L�����N�^�[���W�����v�����Ă݂悤�B
	if (Pad(0).IsPress(enButtonA)) {  //�������Q�[���p�b�h��A�{�^����������Ă�����B
		position.y += 5.0f; //�L�[�{�[�h��J �L�[
	}


	//Question 4 �d�͂̉e����^����B
	position.y -= 0.5f;


	//�L�����N�^�[��Y���W��0��菬�����Ȃ�����
	//�W�����v�͂�0�ɂ��āA�L������Y���W��0�ɂ���B
	if (position.y <= 0.0f) {
		position.y = 0.0f;
	}
	//���f���ɍ��W�𔽉f������B
	skinModelRender->SetPosition(position);
}