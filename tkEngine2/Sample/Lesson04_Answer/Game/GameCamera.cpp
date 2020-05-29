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
	CVector3 cameraTarget;
	cameraTarget.x = pl->position.x;
	cameraTarget.y = pl->position.y + 100.0f;	//�v���C���[�̂�����Ə�ɂ���B
	cameraTarget.z = pl->position.z;
	//�����_���J�����ɓ`����B
	g_camera3D->SetTarget(cameraTarget);


	//HandsOn 2 ���_�𓮂����B
	//���_�͒����_����x�����Ɂ{�S�O�O�A�y�����Ɂ]�U�O�O�̏ꏊ�ɂ���B
	CVector3 cameraPos;
	cameraPos = cameraTarget;
	cameraPos.y += 400.0f;
	cameraPos.z -= 600.0f;
	//���_���J�����ɓ`����B
	g_camera3D->SetPosition(cameraPos);


	//HandsOn 3 �����ʂ�ݒ肷��B
	g_camera3D->SetFar(30000.0f);
	//���K�ۑ�P�@�����ʂ�1000.0f�ɕύX���Ȃ����B
	g_camera3D->SetFar(1000.0f);

	//HandsOn 4 ��p��ύX���Ă݂�B
	//��p��120�x�ɂ��Ă݂�B
	g_camera3D->SetViewAngle(CMath::DegToRad(120.0f));

	//���K�ۑ�Q�@��p��90.0f�ɕύX���Ȃ����B
	g_camera3D->SetViewAngle(CMath::DegToRad(90.0f));

	//�J�������X�V����B
	g_camera3D->Update();
}
