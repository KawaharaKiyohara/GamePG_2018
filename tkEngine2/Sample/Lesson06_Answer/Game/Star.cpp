#include "stdafx.h"
#include "Star.h"
#include "Player.h" 

//////////////////////////////////////////////////////////  
// �f�X�g���N�^�B 
// ���C���������ɓW�J�����f�[�^���j�������Ƃ��ɌĂ΂��B 
//////////////////////////////////////////////////////////  
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
	//�L�����N�^�[�̃��C���������ɓW�J�����f�[�^�𖼑O�Ō�������B 
	player = FindGO<Player>("UnityChan");

	//�X�^�[�̃��f����ǂݍ���ŁASkinModelRender���쐬�B
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/star.cmo");
	position.x = 0.0f;
	position.y = 100.0f;
	position.z = 0.0f;
	skinModelRender->SetPosition(position);
	//�X�^�[�̃��f�����������̂�20�{���炢�ɂ��Ă����B
	CVector3 scale;
	scale.x = 20.0f;
	scale.y = 20.0f;
	scale.z = 20.0f;
	skinModelRender->SetScale(scale);


	return true;
}

///////////////////////////////////////////////// 
// Update�֐� 
// ���t���[�����̊Ԋu�ŌĂ΂��B 
///////////////////////////////////////////////// 
void Star::Update()
{
	//�X�^�[����]������B
	angle += 3.0f; //���t���[��3������]�����Z���Ă����B
	CQuaternion qRot;
	qRot.SetRotationDeg(g_vec3AxisY, angle); //��]�N�H�[�^�j�I�����쐬�B
	skinModelRender->SetRotation(qRot);


	//�X�^�[���㉺�ɓ������B 
	moveCount++;
	if (moveCount < 50) {
		//50��菬������Ώ�ɓ����B 
		position.y += 1.0f;
	}
	else if (moveCount < 100) {
		//50�ȏ�A100�ȉ��Ȃ牺�ɓ��� 
		position.y -= 1.0f;
	}
	else {
		//100�ȏ�ɂȂ�����J�E���g���O�ɖ߂��B 
		moveCount = 0;
	}
	//�X�L�����f���ɍ��W��`����B 
	skinModelRender->SetPosition(position);

	//�v���C���[�Ƃ̋������v�Z���āA130cm�ȉ��Ȃ琯���폜����B
	CVector3 diff = player->position - position;
	if (diff.Length() < 130.0f) {
		DeleteGO(this);
	}

}

