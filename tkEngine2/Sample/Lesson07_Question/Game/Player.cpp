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

	rotation.SetRotationDeg(CVector3::AxisY, 180.0f);

	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);

	charaCon.Init(
		20.0f,		//�L�����N�^�[�̔��a�B
		68.0f,		//�L�����N�^�[�̍����B
		position	//�L�����N�^�[�̏������W�B
	);
	
	return true;
}
//�L�����N�^�[�̈ړ������B
void Player::Move()
{
	float fSpeed = 20.0f;
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;
	

	if (Pad(0).IsPress(enButtonB)) {
		fSpeed *= 2.0f;
	}
	if (Pad(0).IsPress(enButtonRight)) { //�������Q�[���p�b�h�̉E�{�^����������Ă�����B
		moveSpeed.x = fSpeed;
	}
	if (Pad(0).IsPress(enButtonLeft)) {  //�������Q�[���p�b�h�̍��{�^����������Ă�����B
		moveSpeed.x -= fSpeed;
	}
	if (Pad(0).IsPress(enButtonUp)) {
		moveSpeed.z = fSpeed;
	}
	if (Pad(0).IsPress(enButtonDown)) {
		moveSpeed.z = -fSpeed;
	}
	if (Pad(0).IsTrigger(enButtonA)) {
		//�W�����v����B
		//���K�ۑ�@�W�����v�����Đ�����B
	

		moveSpeed.y = 40.0f;
	}

	//�d�͂̉e����^����B
	moveSpeed.y -= 2.0f;

	//�ړ��̓L�����N�^�[�R���g���[���[�Ɉړ����x��^���čs���B
	//�v���C���[�̓L�����N�^�R���g���[���[�ɂ��ړ����ʂ𓾂�̂݁B
	position = charaCon.Execute(1.0f, moveSpeed);
	
	//���f���ɍ��W�𔽉f������B
	skinModelRender->SetPosition(position);
}
//�L�����N�^�[�̉�]�����B
void Player::Rotation()
{
	
	if (Pad(0).IsPress(enButtonRight)) {
		rotation.SetRotationDeg(CVector3::AxisY, 90.0f);
	}
	
	if (Pad(0).IsPress(enButtonLeft)) {
		rotation.SetRotationDeg(CVector3::AxisY, -90.0f);
	}
	
	if (Pad(0).IsPress(enButtonUp)) {
		rotation.SetRotationDeg(CVector3::AxisY, 0.0f);
	}
	
	if (Pad(0).IsPress(enButtonDown)) {
		rotation.SetRotationDeg(CVector3::AxisY, 180.0f);
	}

	//���f���ɉ�]�𔽉f������B
	skinModelRender->SetRotation(rotation);

}
void Player::AnimationControl()
{
	if (charaCon.IsJump() == false) {
		if (Pad(0).IsPress(enButtonUp)) {
			//�Q�[���p�b�h�̏�{�^����������Ă���Ȃ�B
			//����A�j���[�V�������Đ�����B
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else if (Pad(0).IsPress(enButtonDown)) {
			//�Q�[���p�b�h�̉��{�^����������Ă���Ȃ�B
			//����A�j���[�V�������Đ�����B
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else if (Pad(0).IsPress(enButtonRight)) {
			//�Q�[���p�b�h�̉E�{�^����������Ă���Ȃ�B
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else if (Pad(0).IsPress(enButtonLeft)) {
			//�Q�[���p�b�h�̍��{�^����������Ă���Ȃ�B
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else {
			//�������͂���Ă��Ȃ���Η����A�j���[�V�������Đ�����B
			skinModelRender->PlayAnimation(enAnimationClip_idle);
		}
	}
	//�W�����v���łȂ���΁B
	if (Pad(0).IsTrigger(enButtonA)) {
		skinModelRender->PlayAnimation(enAnimationClip_jump);
	}
}
void Player::Update()
{
	Move();
	Rotation();
	AnimationControl();
}