#pragma once
class GameOver2D : public IGameObject
{
public:
	GameOver2D();
	~GameOver2D();
	bool Start();

	//IGameObject��Update�֐����I�[�o�[���C�h����B
	void Update();

	prefab::CSpriteRender* m_spriteRender = nullptr;	//Sprite�����_���[�B

};

