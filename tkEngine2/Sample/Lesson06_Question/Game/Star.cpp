#include "stdafx.h"
#include "Star.h"
#include "Player.h"



/////////////////////////////////////////////////
// �f�X�g���N�^�B
// �C���X�^���X���j�������Ƃ��ɌĂ΂��B
/////////////////////////////////////////////////
Star::~Star()
{
	//�X�L�����f�������_���[���폜�B
	DeleteGO(skinModelRender);
}
/////////////////////////////////////////////////
// Start�֐��B
// ���߂�Update���Ă΂�钼�O�Ɉ�x�����Ă΂��B
/////////////////////////////////////////////////
bool Star::Start()
{
	//�v���C���[�̃C���X�^���X�𖼑O�Ō�������B
	player = FindGO<Player>("UnityChan");

	//HandsOn 2 �X�^�[�̃��f����ǂݍ���ŁASkinModelRender���쐬�B
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/star.cmo");
	skinModelRender->SetPosition(position);
	//�X�^�[���������̂�20�{�ɂ���B
	CVector3 scale = { 20.0f, 20.0f, 20.0f };
	skinModelRender->SetScale(scale);
	
	return true;
}
/////////////////////////////////////////////////
// �X�V�֐�
// ���t���[�����̊Ԋu�ŌĂ΂��B
/////////////////////////////////////////////////
void Star::Update()
{
	////////////////////////////////////////////
	// ���K�ۑ�@�X�^�[���㉺�ɓ������Ȃ����B
	////////////////////////////////////////////

	//HandsOn 3 �X�^�[����]������B
	angle += 3.0f;
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, angle);
	skinModelRender->SetRotation(qRot);
	//HandsOn 4 �v���C���[�Ƃ̋������v�Z���āA130cm�ȉ��Ȃ琯���폜����B
	
}