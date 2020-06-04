#pragma once
class Player;

class Star : public IGameObject
{
public:
	~Star();
	bool Start();
	void Update();
	//HandsOn 1 prefab::CSkinModelRender*�^�̃����o�ϐ���ǉ��B
	prefab::CSkinModelRender* skinModelRender = nullptr;
	CVector3 position ;
	float angle = 0.0f;	//��]�p�x�B
	Player* player = nullptr;
	int moveCount = 0;
	
};

