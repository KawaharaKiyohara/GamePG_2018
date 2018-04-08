#include "stdafx.h"
#include "GameOver2D.h"
#include "GameScene.h"
#include "TitleScene.h"

GameOver2D::GameOver2D()
{
}


GameOver2D::~GameOver2D()
{
	//�X�v���C�g�����_���[���폜�B
	DeleteGO(m_spriteRender);
}

bool GameOver2D::Start()
{
	//CSpriteRender�̃C���X�^���X�𐶐�
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//�Q�c�����[�h�B
	m_spriteRender->Init(
		L"sprite/GAMEOVER.dds",		//�ǂݍ��ރt�@�C���̃t�@�C���p�X�B
		1105.0f,					//�X�v���C�g�̕��B
		115.0f						//�X�v���C�g�̍����B
	);
	return true;
}
void GameOver2D::Update()
{
	if (Pad(0).IsTrigger(enButtonA)) {
		//�Q�[���V�[�����폜����B
		GameScene* gameScene = FindGO<GameScene>("GameScene");
		DeleteGO(gameScene);		
		NewGO<TitleScene>(0);
	}
}