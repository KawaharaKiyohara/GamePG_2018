#pragma once
class TitleScene : public IGameObject
{
public:
	TitleScene();
	~TitleScene();
	//IGameObject��Start�֐����I�[�o�[���C�h����B
	bool Start();
	//IGameObject��Update�֐����I�[�o�[���C�h����B
	void Update();
	//�X�v���C�g�����_���[�B
	prefab::CSpriteRender* m_spriteRender = nullptr;
};

