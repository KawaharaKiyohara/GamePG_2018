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
  //�X�L�����f�������_�[�B
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position; //���W�B
	CVector3 m_moveSpeed;//�G�l�~�[�̈ړ����x�B
	
};



