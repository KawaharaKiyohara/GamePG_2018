#pragma once
class GameScene : public IGameObject
{
public:
	GameScene();
	~GameScene();
	//IGameObject��Start�֐����I�[�o�[���C�h����B
	bool Start();
	//IGameObject��Update�֐����I�[�o�[���C�h����B
	void Update();
};

