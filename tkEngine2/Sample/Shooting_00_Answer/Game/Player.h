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
//�X�L�����f�������_���[�B
	prefab::CSkinModelRender* m_skinModelRender = nullptr;

};


