#pragma once
class GameOver2D : public IGameObject
{
public:
	GameOver2D();
	~GameOver2D();
	bool Start();
	//IGameObject��Update�֐����I�[�o�[���C�h����B
	void Update();
	//�I�[�o�[���C�h�Ƃ͎q�N���X�Őe�N���X�̃��\�b�h���Ē�`���邱��

	prefab::CSpriteRender* m_spriteRender = nullptr;	//Sprite�����_���[�B

};

