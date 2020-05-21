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
	//�A�j���[�V�����N���b�v�����[�h�B
	animationClips[enAnimationClip_run].Load(L"animData/run.tka");
	animationClips[enAnimationClip_run].SetLoopFlag(true);	//���[�v���[�V�����ɂ���B
	animationClips[enAnimationClip_idle].Load(L"animData/idle.tka");
	animationClips[enAnimationClip_idle].SetLoopFlag(true);	//���[�v���[�V�����ɂ���B
	animationClips[enAnimationClip_jump].Load(L"animData/jump.tka");

	//�X�L�����f�������_���[���쐬�B
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/unityChan.cmo", animationClips, enAnimationClip_num, CSkinModel::enFbxUpAxisY);
	
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;
	skinModelRender->SetPosition(position);
	rotation.SetRotationDeg(g_vec3AxisY, 180.0f);
	skinModelRender->SetRotation(rotation);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);




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
		isJump = false;
	}
	//���f���ɍ��W�𔽉f������B
	skinModelRender->SetPosition(position);
}

void Player::Rotation()
{
	//�p�b�h�̓��͂ŃL�����N�^�[�̉�]�����B

	//�L�����N�^�[���E�Ɍ������Ă݂悤�B
	if (g_pad[0]->IsPress(enButtonRight)) { //�������Q�[���p�b�h�̉E�{�^����������Ă�����B
		rotation.SetRotationDeg(g_vec3AxisY, 90.0f); //�L�[�{�[�h�̂U�L�[
		//rotation.SetRotation(g_vec3AxisY, 0.5 * CMath::PI); //Tips
	}

	//�L�����N�^�[�����Ɍ������Ă݂悤�B
	if (g_pad[0]->IsPress(enButtonLeft)) {  //�������Q�[���p�b�h�̍��{�^����������Ă�����B
		rotation.SetRotationDeg(g_vec3AxisY, 270.0f); //�L�[�{�[�h�̂S�L�[
	}

	//�L�����N�^�[�����Ɍ������Ă݂悤�B
	if (g_pad[0]->IsPress(enButtonUp)) {  //�������Q�[���p�b�h�̏�{�^����������Ă�����B
		rotation.SetRotationDeg(g_vec3AxisY, 0.0f); //�L�[�{�[�h�̂W�L�[
	}

	//�L�����N�^�[����O�Ɍ������Ă݂悤�B
	if (g_pad[0]->IsPress(enButtonDown)) {  //�������Q�[���p�b�h�̉��{�^����������Ă�����B
		rotation.SetRotationDeg(g_vec3AxisY, 180.0f); //�L�[�{�[�h�̂Q�L�[
	}

	//��]���G�`������ɋ�����B
	skinModelRender->SetRotation(rotation);
}


void Player::Update()
{
	//Move();
	//Rotation();
	
	//if (isJump == false) {
	//	//////////////////////////////////////////////////////////////////////////
	//	//���K�ۑ� 1 ���E�̃{�^���ł�����A�j���[�V�������Đ��ł���悤�ɂ��Ȃ����B
	//	//////////////////////////////////////////////////////////////////////////
	//	//HandsOn 1 ����A�j���[�V�������Đ����Ă݂悤�B
	//	if (g_pad[0]->IsPress(enButtonUp)) {
	//		//�Q�[���p�b�h�̏�{�^����������Ă���Ȃ�B
	//		//����A�j���[�V�������Đ�����B
	//		skinModelRender->PlayAnimation(enAnimationClip_run);
	//	}
	//	else if (g_pad[0]->IsPress(enButtonDown)) {
	//		//�Q�[���p�b�h�̉��{�^����������Ă���Ȃ�B
	//		//����A�j���[�V�������Đ�����B
	//		skinModelRender->PlayAnimation(enAnimationClip_run);
	//	}
	//	else if (g_pad[0]->IsPress(enButtonRight)) {
	//		//�Q�[���p�b�h�̉E�{�^����������Ă���Ȃ�B
	//		skinModelRender->PlayAnimation(enAnimationClip_run);
	//	}
	//	else if (g_pad[0]->IsPress(enButtonLeft)) {
	//		//�Q�[���p�b�h�̍��{�^����������Ă���Ȃ�B
	//		skinModelRender->PlayAnimation(enAnimationClip_run);
	//	}
	//	else {
	//		//�������͂���Ă��Ȃ���Η����A�j���[�V�������Đ�����B
	//		skinModelRender->PlayAnimation(enAnimationClip_idle);
	//	}
	//}
	////�W�����v���łȂ���΁B
	////HandsOn 2 �W�����v�A�j���[�V�������Đ����Ă݂悤�B
	//if (g_pad[0]->IsTrigger(enButtonA)) {
	//	skinModelRender->PlayAnimation(enAnimationClip_jump);
	//	isJump = true;	//�W�����v���̃t���O�𗧂Ă�B
	//}




}