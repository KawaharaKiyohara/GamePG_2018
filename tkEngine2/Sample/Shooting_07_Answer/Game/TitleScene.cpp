#include "stdafx.h"
#include "TitleScene.h"
#include "GameScene.h"

// �R���X�g���N�^�B�C���X�^���X�����������Ƃ��ɌĂ΂�鏈���B
TitleScene::TitleScene()
{
}
// �f�X�g���N�^�B�C���X�^���X���j�������Ƃ��ɌĂ΂�鏈���B
TitleScene::~TitleScene()
{
	DeleteGO(m_spriteRender);
}
bool TitleScene::Start()
{
	//CSpriteRender�̃C���X�^���X���쐬
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//�^�C�g���摜�����[�h
	m_spriteRender->Init(L"sprite/Title.dds", 1280.0f, 720.0f);
	return true;
}
void TitleScene::Update()
{
	//������A�{�^���������ꂽ��B
	if (g_pad[0]->IsTrigger(enButtonA)) {
		//GameScene�̃C���X�^���X�𐶐��B
		NewGO<GameScene>(0, "GameScene");
		//�V�[�����؂�ւ��̂�TitleScene�̃C���X�^���X���폜�B
		DeleteGO(this);
	}

}

