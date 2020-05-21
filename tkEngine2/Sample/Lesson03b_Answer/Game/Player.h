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

	//�������烁���o�ϐ��B
	prefab::CSkinModelRender* skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CVector3 position ;
	CQuaternion rotation ;
};

