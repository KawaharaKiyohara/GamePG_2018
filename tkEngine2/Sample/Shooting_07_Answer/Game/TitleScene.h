#pragma once
class TitleScene : public IGameObject // IGameObject���p��
{
public:
	TitleScene();
	~TitleScene();
	//IGameObject��Start�֐����I�[�o�[���C�h����B
	bool Start();
	//IGameObject��Update�֐����I�[�o�[���C�h����B
	void Update();
	//�I�[�o�[���C�h�Ƃ͎q�N���X�Őe�N���X�̃��\�b�h���Ē�`���邱
	//�X�v���C�g�����_���[
	prefab::CSpriteRender* m_spriteRender = nullptr;

};

