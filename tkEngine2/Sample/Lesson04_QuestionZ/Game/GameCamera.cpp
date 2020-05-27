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
	CVector3 cameraTarget;
	cameraTarget.x = pl->position.x;
	cameraTarget.y = pl->position.y + 100.0f;
	cameraTarget.z = pl->position.z;
	//�����_���J�����ɓ`����B
	MainCamera().SetTarget(cameraTarget);
	//���K�ۑ�2�@�����_����̃I�t�Z�b�g��ύX����ƁA
	//            ���_���ǂ̂悤�ɕς�邩�m�F���Ȃ����B
	//HandsOn 2 ���_�𓮂����B
	CVector3 cameraPos;
	cameraPos = cameraTarget;
	cameraPos.y += 400.0f;
	cameraPos.z += 600.0f;
	//���_���J�����ɓ`����B
	MainCamera().SetPosition(cameraPos);
	//HandsOn 3 �����ʂ�ݒ肷��B
	MainCamera().SetFar(2000.0f);
	//HandsOn 4 ��p��ύX���Ă݂�B
	MainCamera().SetViewAngle(CMath::DegToRad(120.0f));
	//�J�����s����X�V����B
	MainCamera().Update();
}
