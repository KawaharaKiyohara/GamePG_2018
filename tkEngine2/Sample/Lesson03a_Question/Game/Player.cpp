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

	rotation.SetRotationDeg(g_vec3AxisY, 180.0f);

	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);

	
	return true;
}
//�L�����N�^�[�̈ړ������B
void Player::Move()
{
	if (g_pad[0]->IsPress(enButtonRight)) { //�������Q�[���p�b�h�̉E�{�^����������Ă�����B
		position.x += 10.0f;
	}
	if (g_pad[0]->IsPress(enButtonLeft)) {  //�������Q�[���p�b�h�̍��{�^����������Ă�����B
		position.x -= 10.0f;
	}
	if (g_pad[0]->IsPress(enButtonUp)) {
		position.z += 10.0f;
	}
	if (g_pad[0]->IsPress(enButtonDown)) {
		position.z -= 10.0f;
	}
	if (g_pad[0]->IsTrigger(enButtonA)) {
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
		isJump = false;
	}
	//���f���ɍ��W�𔽉f������B
	skinModelRender->SetPosition(position);
}
//�L�����N�^�[�̉�]�����B
void Player::Rotation()
{
	// �L�����N�^���E�Ɍ�������B
	if (g_pad[0]->IsPress(enButtonRight)) {
		rotation.SetRotationDeg(g_vec3AxisY, 90.0f);
		//rotation.SetRotation(CVector3::AxisY, CMath::PI * 0.5f);	//���W�A���P�ʂ̕ʉ��B
	}
	//�L�����N�^�����Ɍ�������B
	if (g_pad[0]->IsPress(enButtonLeft)) {
		rotation.SetRotationDeg(g_vec3AxisY, -90.0f);
		//rotation.SetRotation(CVector3::AxisY, CMath::PI * -0.5f);	//���W�A���P�ʂ̕ʉ��B
	}
	//�L�����N�^�����Ɍ�������B
	if (g_pad[0]->IsPress(enButtonUp)) {
		rotation.SetRotationDeg(g_vec3AxisY, 0.0f);
		//rotation.SetRotation(CVector3::AxisY, 0.0f);		//���W�A���P�ʂ̕ʉ��B
	}
	//�L�����N�^����O�Ɍ�������B
	if (g_pad[0]->IsPress(enButtonDown)) {
		rotation.SetRotationDeg(g_vec3AxisY, 180.0f);
		//rotation.SetRotation(CVector3::AxisY, CMath::PI);	//���W�A���P�ʂ̕ʉ��B
	}

	//���f���ɉ�]�𔽉f������B
	skinModelRender->SetRotation(rotation);

}
void Player::AnimationControl()
{
	
	//////////////////////////////////////////////////////////////////////////
	//���K�ۑ� 1 ���E�̃{�^���ł�����A�j���[�V�������Đ��ł���悤�ɂ��Ȃ����B
	//////////////////////////////////////////////////////////////////////////
	
	//HandsOn 1 ����A�j���[�V�������Đ����Ă݂悤�B	
	if (isJump == false) {
		if (g_pad[0]->IsPress(enButtonUp)) {
			//�Q�[���p�b�h�̏�{�^����������Ă���Ȃ�B
			//����A�j���[�V�������Đ�����B
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		if (g_pad[0]->IsPress(enButtonDown)) {
			//�Q�[���p�b�h�̉��{�^����������Ă���Ȃ�B
			//����A�j���[�V�������Đ�����B
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else {
			//�������͂���Ă��Ȃ���Η����A�j���[�V�������Đ�����B
			skinModelRender->PlayAnimation(enAnimationClip_idle);
		}
	}
	//HandsOn 2 �W�����v�A�j���[�V�������Đ����Ă݂悤�B
	if (g_pad[0]->IsTrigger(enButtonA)) {
		skinModelRender->PlayAnimation(enAnimationClip_jump);
		isJump = true;
	}
}
void Player::Update()
{
	Move();
	Rotation();
	AnimationControl();
}