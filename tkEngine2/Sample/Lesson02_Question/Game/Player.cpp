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
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;
	CQuaternion qRot;
	qRot.SetRotationDeg(g_vec3AxisY, 180.0f);
	skinModelRender->SetRotation(qRot);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	skinModelRender->SetPosition(position);

	return true;
}

void Player::Update()
{
	//�L�����N�^�[�̈ړ������B

	//Question 1 �L�����N�^�[�����E�ɓ������Ă݂悤�B





	//Question 2 �L�����N�^�[�𕡐����Ă݂悤�B
	



	//���K�ۑ�

	//�u�������A�p�b�h�̏�{�^���������ꂽ��v�Ƃ���if����ǉ�����
	//�p�b�h�̏�{�^���������ꂽ��A��ʂ̉��Ɉړ�����




	//���K�ۑ�
	//�u�������A�p�b�h�̉��{�^���������ꂽ��v�Ƃ���if����ǉ�����
	//�p�b�h�̉��{�^���������ꂽ��A��ʂ̎�O�Ɉړ�����




	//Question 3 �L�����N�^�[���W�����v�����Ă݂悤�B


	

	//Question 4 �d�͂̉e����^����B
	


	//�L�����N�^�[��Y���W��0��菬�����Ȃ�����
	//�L������Y���W��0�ɂ���B
	if (position.y <= 0.0f) {
		position.y = 0.0f;
	}
	//���f���ɍ��W�𔽉f������B
	skinModelRender->SetPosition(position);
	
}