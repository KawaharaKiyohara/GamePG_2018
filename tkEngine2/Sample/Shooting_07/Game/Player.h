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
	//�X�L�����f�������_���[�B
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position ;	//���W�B
	int m_timer = 0;			//�^�C�}�[�B

};



