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
	skinModelRender->SetPosition(position);
	CQuaternion qRot;
	qRot.SetRotationDeg(g_vec3AxisY, 180.0f);
	skinModelRender->SetRotation(qRot);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);

	Rotation();

	return true;
}

void Player::Move() {
	//�L�����N�^�[�̈ړ������B

	if (g_pad[0]->IsPress(enButtonRight)) { //�������Q�[���p�b�h�̉E�{�^����������Ă�����B
		position.x += 10.0f;                      //�L�[�{�[�h�̂U�L�[
	}
	if (g_pad[0]->IsPress(enButtonLeft)) {  //�������Q�[���p�b�h�̍��{�^����������Ă�����B
		position.x -= 10.0f;                      //�L�[�{�[�h�̂S�L�[
	}
	if (g_pad[0]->IsPress(enButtonUp)) {  //�������Q�[���p�b�h�̏�{�^����������Ă�����B
		position.z += 10.0f;                    //�L�[�{�[�h�̂W�L�[
	}
	if (g_pad[0]->IsPress(enButtonDown)) {  //�������Q�[���p�b�h�̉��{�^����������Ă�����B
		position.z -= 10.0f;                      //�L�[�{�[�h�̂Q�L�[
	}

	//�L�����N�^�[�𕡐����Ă݂悤�B
	if (g_pad[0]->IsTrigger(enButtonSelect)) {//�������Q�[���p�b�h��Select�{�^����������Ă�����B
		NewGO<Player>(0);                           //�L�[�{�[�h�̃X�y�[�X�L�[
	}

	//�L�����N�^�[���W�����v�����Ă݂悤�B
	if (g_pad[0]->IsPress(enButtonA)) {  //�������Q�[���p�b�h��A�{�^����������Ă�����B
		position.y += 5.0f;                    //�L�[�{�[�h��J �L�[
	}
	//�d�͂̉e����^����B
	position.y -= 0.5f;


	//�L�����N�^�[��Y���W��0��菬�����Ȃ�����
	//�W�����v�͂�0�ɂ��āA�L������Y���W��0�ɂ���B
	if (position.y <= 0.0f) {
		position.y = 0.0f;
	}
	//���f���ɍ��W�𔽉f������B
	skinModelRender->SetPosition(position);
}

void Player::Rotation()
{
	//�L�����N�^�[�̉�]�����B

	//Question 1 �L�����N�^�[���E�Ɍ������Ă݂悤�B
	

	//Question 2 �L�����N�^�[�����Ɍ������Ă݂悤�B
	

	//Question 3 �L�����N�^�[�����Ɍ������Ă݂悤�B
	

	//Question 4 �L�����N�^�[����O�Ɍ������Ă݂悤�B
	

	//��]���G�`������ɋ�����B
	
}


void Player::Update()
{
	

	//�p�b�h�̓��͂ŃL�����N�^�[�̉�]�����B

	//Question 5 �L�����N�^�[���E�Ɍ������Ă݂悤�B
	

	//���K�ۑ�P �L�����N�^�[�����Ɍ������Ă݂悤�B
	

	//���K�ۑ�Q �L�����N�^�[�����Ɍ������Ă݂悤�B
	

	//���K�ۑ�R �L�����N�^�[����O�Ɍ������Ă݂悤�B
	

	//��]���G�`������ɋ�����B
	

}