#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	//////////////////////////////
	//�@�������烁���o�ϐ��B
	//////////////////////////////
	prefab::CSkinModelRender*  m_skinModelRenderer = nullptr;	//�X�L�����f�������_���[�B
};

