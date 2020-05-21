#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Move();
	void Rotation();
	void AnimationControl();
	//�������烁���o�ϐ��B
	enum {
		enAnimationClip_idle,
		enAnimationClip_run,
		enAnimationClip_jump,
		enAnimationClip_num,
	};
	prefab::CSkinModelRender* skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CAnimationClip animationClips[enAnimationClip_num];		//�A�j���[�V�����N���b�v�B

	CVector3 position ;
	CQuaternion rotation;
	bool isJump = false;
	float ySpeed = 0.0f;
};

