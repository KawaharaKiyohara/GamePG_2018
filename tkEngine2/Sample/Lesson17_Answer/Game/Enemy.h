#pragma once
class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	///////////////////////////////
	// �������烁���o�ϐ�
	///////////////////////////////
	prefab::CSkinModelRender*	m_skinModelRender = nullptr;	//�X�L�����f�������_�[�B
	CVector3 m_position;						//���W�B
	CVector3 m_moveSpeed;						//�ړ����x�B
	int m_timer = 0;	//�^�C�}�[�B
};

