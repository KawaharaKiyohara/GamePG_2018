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
    //�X�L�����f�������_�[
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position;	//���W�B
	CVector3 m_moveSpeed;	//�ړ����x�B
	int m_timer = 0; //�^�C�}�[�B
};

