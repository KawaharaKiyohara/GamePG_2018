#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	//�X�L�����f�������_���[���쐬����B
	skinModelRenderer = NewGO<prefab::CSkinModelRender>(0);
	skinModelRenderer->Init(L"modelData/unityChan.cmo");
}


Player::~Player()
{
}
