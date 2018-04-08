#include "stdafx.h"
#include "TitleScene.h"
#include "GameScene.h"

TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
	DeleteGO(m_spriteRender);
}

bool TitleScene::Start()
{
	//CSpriteRender�̃C���X�^���X���쐬�B
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//�^�C�g���摜�����[�h�B
	m_spriteRender->Init(L"sprite/Title.dds", 1280.0f, 720.0f);
	return true;
}
void TitleScene::Update()
{
	//������A�{�^���������ꂽ��B
	if (Pad(0).IsTrigger(enButtonA)) {
		//GameScene�̃C���X�^���X�𐶐��B
		NewGO<GameScene>(0, "GameScene");
		//�V�[�����؂�ւ��̂�TitleScene�̃C���X�^���X���폜�B
		DeleteGO(this);
	}
}