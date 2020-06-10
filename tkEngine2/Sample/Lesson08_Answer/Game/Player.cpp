#include "stdafx.h"
#include "Player.h"

//////////////////////////////////////////////////////////
// �R���X�g���N�^�B�C���X�^���X�����������Ƃ��ɌĂ΂�鏈���B
//////////////////////////////////////////////////////////
Player::Player()
{
}
//////////////////////////////////////////////////////////
// �f�X�g���N�^�B�C���X�^���X���j�������Ƃ��ɌĂ΂�鏈���B
//////////////////////////////////////////////////////////
Player::~Player()
{
	//�X�L�����f�������_���[��j��
	DeleteGO(m_skinModelRenderer);
}
//////////////////////////////////////////////////////////
// ���߂�Update�֐����Ă΂�钼�O�ɁA��x�����Ă΂��֐��B
//////////////////////////////////////////////////////////
bool Player::Start()
{
	//�X�L�����f�������_���[���쐬�B
	m_skinModelRenderer = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRenderer->Init(L"modelData/AirPlane.cmo", NULL, 0, CSkinModel::enFbxUpAxisY);
	//���������������̂ŁAY�������-90���񂷁B
	CQuaternion qRot;
	qRot.SetRotationDeg(g_vec3AxisY, -90.0f);
	m_skinModelRenderer->SetRotation(qRot);
	return true;
}