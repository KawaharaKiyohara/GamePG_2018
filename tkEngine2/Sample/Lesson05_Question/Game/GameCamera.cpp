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
	
	//���K�ۑ�1�@�v���C���[����̃I�t�Z�b�g��ύX����ƁA
	//            �����_���ǂ̂悤�ɕς�邩�m�F���Ȃ����B
	//HandsOn 1 �����_�𓮂����B
	
	//���K�ۑ�2�@�����_����̃I�t�Z�b�g��ύX����ƁA
	//            ���_���ǂ̂悤�ɕς�邩�m�F���Ȃ����B
	//HandsOn 2 ���_�𓮂����B
	
	//HandsOn 3 �����ʂ�ݒ肷��B
	
	//HandsOn 4 ��p��ύX���Ă݂�B
	
	//�J�����s����X�V����B
	MainCamera().Update();
}
