#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
	//�X�v���C�g�����_���[�̃C���X�^���X���폜�B
	DeleteGO(m_spriteRender);
}
bool BackGround::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(
		L"sprite/background.dds", 
		MainCamera().GetWidth(),  //��s�@�̌��ɔw�i���������߂̏����B
		MainCamera().GetHeight(), //��s�@�̌��ɔw�i���������߂̏����B
		true
	);
	return true;
}
