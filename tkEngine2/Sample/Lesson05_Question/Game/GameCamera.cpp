#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
}


GameCamera::~GameCamera()
{
}

void GameCamera::Update()
{
	//�v���C���[�̃C���X�^���X�𖼑O�Ō�������B
	Player* pl = FindGO<Player>("UnityChan");
	
	//���K�ۑ�P�@�v���C���[����̃I�t�Z�b�g��ύX����ƁA
	//            �����_���ǂ̂悤�ɕς�邩�m�F���Ȃ����B
	//HandsOn 1 �����_�𓮂����B
	
	//���K�ۑ�Q�@�����_����̃I�t�Z�b�g��ύX����ƁA
	//            ���_���ǂ̂悤�ɕς�邩�m�F���Ȃ����B
	//HandsOn 2 ���_�𓮂����B
	
	//�J�����s����X�V����B
	MainCamera().Update();
}
