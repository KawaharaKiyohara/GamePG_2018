#pragma once
class Bullet : public IGameObject
{
public:
	Bullet();
	~Bullet();
	bool Start();
	void Update();
	/////////////////////////////////
	// �������烁���o�ϐ��B
	/////////////////////////////////
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_�[	
	CVector3 m_position ;	//���W�B
	CVector3 m_moveSpeed;	//�ړ����x�B
	int m_timer = 0;						//�^�C�}�[�B
};

