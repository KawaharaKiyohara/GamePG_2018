#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"

Enemy::Enemy()
{
}
Enemy::~Enemy()
{
	DeleteGO(m_skinModelRender);
}
//////////////////////////////////////////////////////////
// ���߂�Update�֐����Ă΂�钼�O�ɁA��x�����Ă΂��֐��B
//////////////////////////////////////////////////////////
bool Enemy::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/enemy.cmo", nullptr, 0, CSkinModel::enFbxUpAxisY);
	//���f�����������̂łP�O�{����B
	CVector3 scale;
	scale.x = 10.0f;
	scale.y = 10.0f;
	scale.z = 10.0f;
	m_skinModelRender->SetScale(scale);
	//���������������̂�Y�������90����]������B
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 90.0f);
	//�X�L�����f���ɉ�]�N�H�[�^�j�I����ݒ肷��B
	m_skinModelRender->SetRotation(qRot);
	return true;
}
//////////////////////////////////////////////////////////
// ���Ԋu�ŌĂ΂��X�V�����B
//////////////////////////////////////////////////////////
void Enemy::Update()
{
	//�X�L�����f�������_�[�ɍ��W��`����B
	m_skinModelRender->SetPosition(m_position);
	m_timer++;
	if (m_timer == 10) {
		Bullet* bullet = NewGO<Bullet>(0);
		bullet->m_position = m_position;
		bullet->m_moveSpeed.x = -400.0f;
		m_timer = 0.0f;
	}
}