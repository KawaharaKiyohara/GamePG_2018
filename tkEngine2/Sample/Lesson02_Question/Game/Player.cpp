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
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 180.0f);
	skinModelRender->SetRotation(qRot);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	skinModelRender->SetPosition(position);

	return true;
}

void Player::Update()
{
<<<<<<< HEAD
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
	


=======
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
	if (Pad(0).IsPress(enButtonA)) {
		position.y += 5.0f;
	}

	//�d�͂̉e����^����B
	position.y -= 0.5f;

	//Y�����̑��x�����W�ɉ��Z����B
>>>>>>> b0a2522240711ef38451584b35669d5750297270
	//�L�����N�^�[��Y���W��0��菬�����Ȃ�����
	//�L������Y���W��0�ɂ���B
	if (position.y <= 0.0f) {
		position.y = 0.0f;
	}
	//���f���ɍ��W�𔽉f������B
	skinModelRender->SetPosition(position);
	
}