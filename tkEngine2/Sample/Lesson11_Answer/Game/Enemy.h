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
	CVector3 m_moveSpeed = CVector3::Zero;						//�G�l�~�[�̈ړ����x�B
	prefab::CSkinModelRender*	m_skinModelRender = nullptr;	//�X�L�����f�������_�[�B
	CVector3 m_position = CVector3::Zero;						//���W�B
};

