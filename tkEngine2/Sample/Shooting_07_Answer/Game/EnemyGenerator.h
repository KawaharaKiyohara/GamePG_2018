#pragma once
class EnemyGenerator : public IGameObject
{
public:
	EnemyGenerator();
	~EnemyGenerator();
	void Update();
	bool Start();
	///////////////////////////////
	// �������烁���o�ϐ�
	///////////////////////////////
	int m_timer = 0;		//�^�C�}�[�B
};


