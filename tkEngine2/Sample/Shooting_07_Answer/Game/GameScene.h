#pragma once
class GameScene : public IGameObject    // IGameObject���p��
{
public:
	GameScene();
	~GameScene();
	//IGameObject��Start�֐����I�[�o�[���C�h����B
	bool Start();
	//IGameObject��Update�֐����I�[�o�[���C�h����B
	void Update();
	//�I�[�o�[���C�h�Ƃ͎q�N���X�Őe�N���X�̃��\�b�h���Ē�`���邱��
};

