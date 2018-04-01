#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void MoveAndRotation();
	//////////////////////////////
	//�@�������烁���o�ϐ��B
	//////////////////////////////
	prefab::CSkinModelRender*  m_skinModelRenderer = nullptr;	//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero;						//���W�B
	int m_timer = 0;											//�^�C�}�[�B
};

