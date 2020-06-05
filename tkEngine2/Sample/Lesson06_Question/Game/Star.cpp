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
	//�v���C���[�̃C���X�^���X�𖼑O�Ō�������B 
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
// �X�V�֐� 
// ���t���[�����̊Ԋu�ŌĂ΂��B 
///////////////////////////////////////////////// 
void Star::Update()
{

}

