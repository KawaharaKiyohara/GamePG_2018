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

	//HandsOn4 CCharacterController�N���X�̃I�u�W�F�N�g�̏�����
	

	
	return true;
}
//�L�����N�^�[�̈ړ������B�ʒu
void Player::MovePosition()
{
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
//�L�����N�^�[�̈ړ������B���x
void Player::MoveSpeed()
{
	// HandsOn6 �L�����N�^�[�̈ړ����x�����������悤�B



	
	//�@���K�ۑ� 1 B�{�^���������Ȃ���ړ�����ƁA�ړ����x���Q�{�ɂȂ�悤�ɂ��Ȃ����B


	//�@���K�ۑ� 2 Y�{�^���������Ȃ���ړ�����ƁA�ړ����x�������ɂȂ�悤�ɂ��Ȃ����B


	// HandsOn7 �L�����N�^�[�����E�ɓ������Ă݂悤�B





	// HandsOn8 �L�����N�^�[��O��ɓ������Ă݂悤�B





	// HandsOn9 �L�����N�^�[���W�����v�����āA�d�͂������悤�B
	



	//if (charaCon.IsJump() == false) {
	//	isJump = false;
	//}

	//�ړ��̓L�����N�^�[�R���g���[���[�Ɉړ����x��^���čs���B
	//�v���C���[�̓L�����N�^�R���g���[���[�ɂ��ړ����ʂ𓾂�̂݁B

	//HandsOn5 CCharacterController�N���X���g���āA�L�����N�^�[���ړ�������B
	
	
	//���f���ɍ��W�𔽉f������B
	skinModelRender->SetPosition(position);
}
//�L�����N�^�[�̉�]�����B
void Player::Rotation()
{
	
	if (g_pad[0]->IsPress(enButtonRight)) {
		rotation.SetRotationDeg(g_vec3AxisY, 90.0f);
		//rotation.SetRotation(g_vec3AxisY, CMath::PI * 0.5f);	//���W�A���P�ʂ̕ʉ��B
	}
	
	if (g_pad[0]->IsPress(enButtonLeft)) {
		rotation.SetRotationDeg(g_vec3AxisY, -90.0f);
		//rotation.SetRotation(g_vec3AxisY, CMath::PI * -0.5f);	//���W�A���P�ʂ̕ʉ��B
	}
	
	if (g_pad[0]->IsPress(enButtonUp)) {
		rotation.SetRotationDeg(g_vec3AxisY, 0.0f);
		//rotation.SetRotation(g_vec3AxisY, 0.0f);		//���W�A���P�ʂ̕ʉ��B
	}
	
	if (g_pad[0]->IsPress(enButtonDown)) {
		rotation.SetRotationDeg(g_vec3AxisY, 180.0f);
		//rotation.SetRotation(g_vec3AxisY, CMath::PI);	//���W�A���P�ʂ̕ʉ��B
	}

	//���f���ɉ�]�𔽉f������B
	skinModelRender->SetRotation(rotation);

}
void Player::AnimationControl()
{
	if (isJump == false) {
		
		//HandsOn 1 ����A�j���[�V�������Đ����Ă݂悤�B
		if (g_pad[0]->IsPress(enButtonUp)) {
			//�Q�[���p�b�h�̏�{�^����������Ă���Ȃ�B
			//����A�j���[�V�������Đ�����B
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else if (g_pad[0]->IsPress(enButtonDown)) {
			//�Q�[���p�b�h�̉��{�^����������Ă���Ȃ�B
			//����A�j���[�V�������Đ�����B
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else if (g_pad[0]->IsPress(enButtonRight)) {
			//�Q�[���p�b�h�̉E�{�^����������Ă���Ȃ�B
			//����A�j���[�V�������Đ�����B
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else if (g_pad[0]->IsPress(enButtonLeft)) {
			//�Q�[���p�b�h�̍��{�^����������Ă���Ȃ�B
			//����A�j���[�V�������Đ�����B
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else {
			//�������͂���Ă��Ȃ���Η����A�j���[�V�������Đ�����B
			skinModelRender->PlayAnimation(enAnimationClip_idle);
		}
	}
	//�W�����v���łȂ���΁B
	if (g_pad[0]->IsTrigger(enButtonA)) {
		//�W�����v�A�j���[�V�������Đ�����B
		skinModelRender->PlayAnimation(enAnimationClip_jump);
		isJump = true;
	}
}
void Player::Update()
{
	//MovePosition();
	MoveSpeed();
	Rotation();
	AnimationControl();
}