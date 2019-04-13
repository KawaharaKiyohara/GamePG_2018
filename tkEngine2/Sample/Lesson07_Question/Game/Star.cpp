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

	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/star.cmo");
	skinModelRender->SetPosition(position);
	//�X�^�[�̃��f�����������̂�20�{���炢�ɂ��Ă����B
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
	moveCount++;
	if (moveCount < 50) {
		//50��菬������Ώ�ɓ����B
		position.y += 1.0f;
	}
	else if(moveCount < 100){
		//50�ȏ�A100�ȉ��Ȃ牺�ɓ���
		position.y -= 1.0f;
	}
	else {
		//100�ȏ�ɂȂ�����J�E���g���O�ɖ߂��B
		moveCount = 0;
	}
	//�X�L�����f���ɍ��W��`����B
	skinModelRender->SetPosition(position);

	
	//�X�^�[����]������B
	angle += 3.0f; //���t���[��3���Â�]�����Z���Ă����B
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, angle); //��]�N�H�[�^�j�I�����쐬�B
	skinModelRender->SetRotation(qRot);

	
	CVector3 diff = player->position - position;
	if (diff.Length() < 130.0f) {
		//HandsOn 2 �R�C�����擾�����Ƃ��ɉ���炻���B
		prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);
		ss->Init("sound/coinGet.wav");
		ss->Play(false);

		DeleteGO(this);
	}
}