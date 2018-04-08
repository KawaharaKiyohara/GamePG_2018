#include "stdafx.h"
#include "EnemyGenerator.h"
#include "Enemy.h"

EnemyGenerator::EnemyGenerator()
{
}


EnemyGenerator::~EnemyGenerator()
{
}

void EnemyGenerator::Update()
{
	m_timer++;
	if (m_timer == 60) {
		//60�t���[�����ƂɓG�@���쐬����B
		Enemy* enemy = NewGO<Enemy>(0, "Enemy");
		//X���W�͉�ʍۂɂ���B
		enemy->m_position.x = 9000.0f;
		//Y���W�������_���ɂ���B
		//GetRandDouble��0.0�`1.�������_���ɕԂ��Ă���֐��B
		float t = Random().GetRandDouble();
		//CMath::Leap�֐��͓�̒l�̊Ԃ���`�⊮����֐��B
		enemy->m_position.y = CMath::Lerp(t, -5625.0f, 5625.0f);
		m_timer = 0;
	}
}