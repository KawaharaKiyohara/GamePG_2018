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
	//HandsOn 1 �����_�𓮂����B
	

	//HandsOn 2 ���_�𓮂����B
	//���_�͒����_����x�����Ɂ{�S�O�O�A�y�����Ɂ]�U�O�O�̏ꏊ�ɂ���B


	//HandsOn 3 �����ʂ�ݒ肷��B
	//g_camera3D->SetFar(30000.0f);

	//HandsOn 4 ��p��ύX���Ă݂�B


	//�J�����s����X�V����B
	g_camera3D->Update();
}
