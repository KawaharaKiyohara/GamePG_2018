#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	//�������烁���o�ϐ��B
	prefab::CSkinModelRender* skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 position = CVector3::Zero;
	float jumpPower = 0.0f;
};

